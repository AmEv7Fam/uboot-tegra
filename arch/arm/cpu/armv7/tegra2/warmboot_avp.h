/*
 * (C) Copyright 2010, 2011
 * NVIDIA Corporation <www.nvidia.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef _WARMBOOT_AVP_H_
#define _WARMBOOT_AVP_H_

/* Followings are used by warmboot_avp.S */

#define PMC_SCRATCH1_OFFSET			0x54
#define PMC_SCRATCH3_OFFSET			0x5c
#define PMC_SCRATCH41_OFFSET			0x140

#define PG_UP_TAG_OFFSET			0
#define TIMERUS_CNTR_1US_OFFSET			0

#define CSITE_CPUDBG0_LAR_OFFSET		0x10fb0
#define CSITE_CPUDBG1_LAR_OFFSET		0x12fb0

#define APB_MISC_PP_CONFIG_CTL_OFFSET		0x24
#define APB_MISC_PP_CONFIG_CTL_TBE_ENABLE		(1 << 7)
#define APB_MISC_PP_CONFIG_CTL_JTAG_ENABLE		(1 << 6)

#define CLK_RST_CTLR_RST_DEV_U_SET_OFFSET	0x310
#define CLK_RST_DEV_U_SET_SET_CSITE_RST			(1 << 9)

#define CLK_RST_CTLR_OSC_CTRL_OFFSET		0x50
#define CLK_RST_CTLR_OSC_CTRL_XOFS_MASK			(0x3f << 4)
#define CLK_RST_CTLR_OSC_CTRL_XOFS_VAL_4		(0x04 << 4)
#define CLK_RST_CTLR_OSC_CTRL_XOE_MASK			(0x01 << 0)
#define CLK_RST_CTLR_OSC_CTRL_XOE_ENABLE		(0x01 << 0)

#define PMC_PWRGATE_STATUS_OFFSET		0x38
#define PMC_PWRGATE_STATUS_CPU_MASK			(0x01 << 0)

#define PMC_PWRGATE_TOGGLE_OFFSET		0x30
#define PMC_PWRGATE_TOGGLE_PARTID_CPU			(0 << 0)
#define PMC_PWRGATE_TOGGLE_START_ENABLE			(1 << 8)

#define PMC_REMOVE_CLAMPING_CMD_OFFSET		0x34
#define PMC_REMOVE_CLAMPING_CMD_CPU_ENABLE		(1 << 0)

#define FLOW_CTLR_HALT_COP_EVENTS_OFFSET	0x4
#define FLOW_CTLR_HALT_COP_EVENTS_ZERO_VAL_20		(20 << 0)
#define FLOW_CTLR_HALT_COP_EVENTS_MSEC			(1 << 24)
#define FLOW_CTLR_HALT_COP_EVENTS_JTAG			(1 << 28)
#define FLOW_CTLR_HALT_COP_EVENTS_MODE_STOP		(2 << 29)

#define CLK_RST_CTLR_RST_DEV_L_SET_OFFSET	0x300
#define CLK_RST_CTLR_RST_DEV_L_SET_CPU_RST		(1 << 0)

#define CLK_RST_CTLR_RST_CPU_CMPLX_SET_OFFSET	0x340
#define CLK_RST_CTLR_RST_CPU_CMPLX_SET_CPURESET0	(1 << 0)
#define CLK_RST_CTLR_RST_CPU_CMPLX_SET_CPURESET1	(1 << 1)
#define CLK_RST_CTLR_RST_CPU_CMPLX_SET_DERESET0		(1 << 4)
#define CLK_RST_CTLR_RST_CPU_CMPLX_SET_DERESET1		(1 << 5)
#define CLK_RST_CTLR_RST_CPU_CMPLX_SET_DBGRESET0	(1 << 12)
#define CLK_RST_CTLR_RST_CPU_CMPLX_SET_DBGRESET1	(1 << 13)

#define FLOW_CTLR_HALT_CPU1_EVENTS_OFFSET	0x14
#define FLOW_CTLR_HALT_CPU1_EVENTS_MODE_FLOW_MODE_STOP	(2 << 29)

#define EVP_CPU_RESET_VECTOR_OFFSET		0x100

#define CLK_RST_CTLR_CCLK_BURST_POLICY_OFFSET	0x20
#define CLK_RST_CTLR_CCLK_CWAKE_FIQ_SOURCE_SHIFT	12
#define CLK_RST_CTLR_CCLK_CWAKE_IRQ_SOURCE_SHIFT	8
#define CLK_RST_CTLR_CCLK_CWAKE_RUN_SOURCE_SHIFT	4
#define CLK_RST_CTLR_CCLK_CWAKE_IDLE_SOURCE_SHIFT	0
#define CLK_RST_CTLR_CCLK_CPU_STATE_RUN			(2 << 28)

#define CLK_RST_CTLR_CPU_CMPLX_OFFSET		0x4c
#define CLK_RST_CTLR_CPU_CMPLX_CPU_BRIDGE_CLKDIV_BY_4	(3 << 0)
#define CLK_RST_CTLR_CPU_CMPLX_CPU0_CLK_STP_STOP	(1 << 8)
#define CLK_RST_CTLR_CPU_CMPLX_CPU0_CLK_STP_RUN		(0 << 8)
#define CLK_RST_CTLR_CPU_CMPLX_CPU1_CLK_STP_STOP	(1 << 9)
#define CLK_RST_CTLR_CPU_CMPLX_CPU1_CLK_STP_RUN		(0 << 9)

#define CLK_RST_CTLR_CLK_ENB_L_SET_OFFSET	0x320
#define CLK_RST_CTLR_CLK_ENB_L_SET_CLK_ENB_CPU		(1 << 0)

#define CLK_RST_CTLR_RST_DEV_U_CLR_OFFSET	0x314
#define CLK_RST_CTLR_RST_DEV_U_CLR_CSITE_RST_MASK	(1 << 9)

#define TIMERUS_USEC_CFG_OFFSET			0x4
#define TIMERUS_USEC_CFG_USEC_DIVISOR_MASK		0xff

#define CLK_RST_CTLR_PLLX_BASE_OFFSET		0xe0
#define CLK_RST_CTLR_PLLX_MISC_OFFSET		0xe4
#define CLK_RST_CTLR_PLLX_BASE_BYPASS_ENABLE		(1 << 31)
#define CLK_RST_CTLR_PLLX_BASE_ENABLE_ENABLE		(1 << 30)
#define CLK_RST_CTLR_PLLX_BASE_ENABLE_DISABLE		(0 << 30)
#define CLK_RST_CTLR_PLLX_BASE_REF_DIS_REF_ENABLE	(0 << 29)
#define CLK_RST_CTLR_PLLX_BASE_DIVP_SHIFT		20
#define CLK_RST_CTLR_PLLX_BASE_DIVN_SHIFT		8

#define CLK_RST_CTLR_PLLX_MISC_DCCON_DEFAULT		(1 << 20)
#define CLK_RST_CTLR_PLLX_MISC_CPCON_SHIFT		8
#define CLK_RST_CTLR_PLLX_MISC_LFCON_SHIFT		4

#define PMC_SCRATCH3_PLLX_MISC_CPCON_SHIFT		22
#define PMC_SCRATCH3_PLLX_MISC_CPCON_MASK		0xf
#define PMC_SCRATCH3_PLLX_MISC_LFCON_SHIFT		18
#define PMC_SCRATCH3_PLLX_MISC_LFCON_MASK		0xf
#define PMC_SCRATCH3_PLLX_BASE_DIVP_SHIFT		15
#define PMC_SCRATCH3_PLLX_BASE_DIVM_MASK		0x1f
#define PMC_SCRATCH3_PLLX_BASE_DIVN_SHIFT		5
#define PMC_SCRATCH3_PLLX_BASE_DIVM_SHIFT		0
#define PMC_SCRATCH3_PLLX_BASE_DIVN_MASK		0x3ff
#define PMC_SCRATCH3_PLLX_BASE_DIVN_SHIFT		5
#define PMC_SCRATCH3_PLLX_BASE_DIVP_MASK		0x07

#define FLOW_CTLR_HALT_CPU_EVENTS_OFFSET	0x0

#define CLK_RST_CTLR_RST_CPU_CMPLX_CLR_OFFSET	0x344
#define CLK_RST_CTLR_RST_CPU_CMPLX_CLR_CPURESET0	(1 << 0)
#define CLK_RST_CTLR_RST_CPU_CMPLX_CLR_CPURESET1	(1 << 1)
#define CLK_RST_CTLR_RST_CPU_CMPLX_CLR_DERESET0		(1 << 4)
#define CLK_RST_CTLR_RST_CPU_CMPLX_CLR_DERESET1		(1 << 5)
#define CLK_RST_CTLR_RST_CPU_CMPLX_CLR_DBGRESET0	(1 << 12)
#define CLK_RST_CTLR_RST_CPU_CMPLX_CLR_DBGRESET1	(1 << 13)

#define CLK_RST_CTLR_PLLM_OUT_OFFSET		0x94
#define CLK_RST_CTLR_PLLM_OUT1_RSTN_RESET_DISABLE	(1 << 0)
#define CLK_RST_CTLR_PLLM_OUT1_CLKEN_ENABLE		(1 << 1)
#define CLK_RST_CTLR_PLLM_OUT1_RATIO_VAL_8		(8 << 8)

#define CLK_RST_CTLR_SCLK_BURST_POLICY_OFFSET	0x28
#define CLK_RST_CTLR_SCLK_SYS_STATE_IDLE		(1 << 28)
#define CLK_RST_CTLR_SCLK_SWAKE_FIQ_SOURCE_PLLM_OUT1	(7 << 12)
#define CLK_RST_CTLR_SCLK_SWAKE_IRQ_SOURCE_PLLM_OUT1	(7 << 8)
#define CLK_RST_CTLR_SCLK_SWAKE_RUN_SOURCE_PLLM_OUT1	(7 << 4)
#define CLK_RST_CTLR_SCLK_SWAKE_IDLE_SOURCE_PLLM_OUT1	(7 << 0)

#define CLK_RST_CTLR_RST_DEV_L_CLR_OFFSET	0x304
#define CLK_RST_CTLR_RST_DEV_L_CLR_CPU_RST		(1 << 0)

#define CLK_RST_CTLR_RST_DEVICES_L_OFFSET	0x4
#define CLK_RST_CTLR_RST_DEVICES_L_SWR_TRIG_SYS_RST	(1 << 2)

#endif
