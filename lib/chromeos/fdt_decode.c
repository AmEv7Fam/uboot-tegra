/*
 * Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Alternatively, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 */

#include <common.h>
#include <libfdt.h>
#include <chromeos/common.h>
#include <chromeos/fdt_decode.h>
#include <linux/string.h>

#define PREFIX "chromeos/fdt_decode: "

static int fdt_relpath_offset(const void *fdt, int offset, const char *path)
{
	const char *sep;

	/* skip leading '/' */
	while (*path == '/')
		path++;

	for (sep = path; *sep; path = sep + 1) {
		/* this is equivalent to strchrnul() */
		sep = strchr(path, '/');
		if (!sep)
			sep = path + strlen(path);

		offset = fdt_subnode_offset_namelen(fdt, offset, path,
				sep - path);
		if (offset < 0)
			return offset;
	}

	return offset;
}

static int fdt_decode_fmap_entry(const void *fdt, int offset, const char *path,
		struct fdt_fmap_entry *config)
{
	int length;
	uint32_t *property;

	offset = fdt_relpath_offset(fdt, offset, path);
	if (offset < 0)
		return offset;

	property = (uint32_t *)fdt_getprop(fdt, offset, "reg", &length);
	if (!property)
		return length;

	config->offset = fdt32_to_cpu(property[0]);
	config->length = fdt32_to_cpu(property[1]);

	return 0;
}

static int fdt_decode_block_lba(const void *fdt, int offset, const char *path,
		uint64_t *out)
{
	int length;
	uint32_t *property;

	offset = fdt_relpath_offset(fdt, offset, path);
	if (offset < 0)
		return offset;

	property = (uint32_t *)fdt_getprop(fdt, offset, "block-lba", &length);
	if (!property)
		return length;

	*out = fdt32_to_cpu(*property);
	return 0;
}

#define LIST_OF_ENTRIES \
	ACT_ON_ENTRY("/onestop-layout", onestop_layout.onestop_layout); \
	ACT_ON_ENTRY("/firmware-image", onestop_layout.fwbody); \
	ACT_ON_ENTRY("/verification-block", onestop_layout.vblock); \
	ACT_ON_ENTRY("/firmware-id", onestop_layout.fwid); \
	ACT_ON_ENTRY("/readonly", readonly.readonly); \
	ACT_ON_ENTRY("/ro-firmware-image", readonly.ro_firmware_image); \
	ACT_ON_ENTRY("/ro-firmware-id", readonly.ro_firmware_id); \
	ACT_ON_ENTRY("/fmap", readonly.fmap); \
	ACT_ON_ENTRY("/gbb", readonly.gbb); \
	ACT_ON_ENTRY("/readwrite-a", readwrite_a.readwrite_a); \
	ACT_ON_ENTRY("/rw-a-onestop", readwrite_a.rw_a_onestop); \
	ACT_ON_ENTRY("/readwrite-b", readwrite_b.readwrite_b); \
	ACT_ON_ENTRY("/rw-b-onestop", readwrite_b.rw_b_onestop);

int fdt_decode_twostop_fmap(const void *fdt, struct fdt_twostop_fmap *config)
{
	int fmap_offset, offset;

	fmap_offset = fdt_node_offset_by_compatible(fdt, -1,
			"chromeos,flashmap");
	if (fmap_offset < 0) {
		VBDEBUG(PREFIX "no compatible node exists\n");
		return fmap_offset;
	}

#define ACT_ON_ENTRY(path, entry) \
	offset = fdt_decode_fmap_entry(fdt, fmap_offset, path, \
			&config->entry); \
	if (offset < 0) { \
		VBDEBUG(PREFIX "failed to load %s\n", path); \
		return offset; \
	}

	LIST_OF_ENTRIES

#undef ACT_ON_ENTRY

	offset = fdt_decode_block_lba(fdt, fmap_offset, "/readwrite-a",
			&config->readwrite_a.block_lba);
	if (offset < 0) {
		VBDEBUG(PREFIX "failed to load LBA of slot A\n");
		return offset;
	}

	offset = fdt_decode_block_lba(fdt, fmap_offset, "/readwrite-b",
			&config->readwrite_b.block_lba);
	if (offset < 0) {
		VBDEBUG(PREFIX "failed to load LBA of slot B\n");
		return offset;
	}

	return 0;
}

void dump_fmap(struct fdt_twostop_fmap *config)
{
#define ACT_ON_ENTRY(path, entry) \
	VBDEBUG(PREFIX "%-20s %08x:%08x\n", path, \
			config->entry.offset, config->entry.length)

	LIST_OF_ENTRIES

#undef ACT_ON_ENTRY

	VBDEBUG(PREFIX "readwrite-a: block %08llx\n",
			config->readwrite_a.block_lba);
	VBDEBUG(PREFIX "readwrite-b: block %08llx\n",
			config->readwrite_b.block_lba);
}