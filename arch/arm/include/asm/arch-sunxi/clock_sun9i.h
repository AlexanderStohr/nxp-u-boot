/*
 * sun9i clock register definitions
 *
 * (C) Copyright 2015 Hans de Goede <hdegoede@redhat.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _SUNXI_CLOCK_SUN9I_H
#define _SUNXI_CLOCK_SUN9I_H

struct sunxi_ccm_reg {
	u32 pll1_c0_cfg;	/* 0x00 c0cpu# pll configuration */
	u32 pll2_c1_cfg;	/* 0x04 c1cpu# pll configuration */
	u32 pll3_audio_cfg;	/* 0x08 audio pll configuration */
	u32 pll4_periph0_cfg;	/* 0x0c peripheral0 pll configuration */
	u32 pll5_ve_cfg;	/* 0x10 videoengine pll configuration */
	u32 pll6_ddr_cfg;	/* 0x14 ddr pll configuration */
	u32 pll7_video0_cfg;	/* 0x18 video0 pll configuration */
	u32 pll8_video1_cfg;	/* 0x1c video1 pll configuration */
	u32 pll9_gpu_cfg;	/* 0x20 gpu pll configuration */
	u32 pll10_de_cfg;	/* 0x24 displayengine pll configuration */
	u32 pll11_isp_cfg;	/* 0x28 isp pll6 ontrol */
	u32 pll12_periph1_cfg;	/* 0x2c peripheral1 pll configuration */
	u8 reserved1[0x20];	/* 0x30 */
	u32 cpu_clk_source;	/* 0x50 cpu clk source configuration */
	u32 c0_cfg;		/* 0x54 cpu cluster 0 clock configuration */
	u32 c1_cfg;		/* 0x58 cpu cluster 1 clock configuration */
	u32 gtbus_cfg;		/* 0x5c gtbus clock configuration */
	u32 ahb0_cfg;		/* 0x60 ahb0 clock configuration */
	u32 ahb1_cfg;		/* 0x64 ahb1 clock configuration */
	u32 ahb2_cfg;		/* 0x68 ahb2 clock configuration */
	u8 reserved2[0x04];	/* 0x6c */
	u32 apb0_cfg;		/* 0x70 apb0 clock configuration */
	u32 apb1_cfg;		/* 0x74 apb1 clock configuration */
	u32 cci400_cfg;		/* 0x78 cci400 clock configuration */
	u8 reserved3[0x04];	/* 0x7c */
	u32 ats_cfg;		/* 0x80 ats clock configuration */
	u32 trace_cfg;		/* 0x84 trace clock configuration */
	u8 reserved4[0xf8];	/* 0x88 */
	u32 clk_output_a;	/* 0x180 clk_output_a */
	u32 clk_output_b;	/* 0x184 clk_output_a */
	u8 reserved5[0x278];	/* 0x188 */

	u32 nand0_clk_cfg0;	/* 0x400 nand0 clock configuration0 */
	u32 nand0_clk_cfg1;	/* 0x404 nand1 clock configuration */
	u8 reserved6[0x08];	/* 0x408 */
	u32 sd0_clk_cfg;	/* 0x410 sd0 clock configuration */
	u32 sd1_clk_cfg;	/* 0x414 sd1 clock configuration */
	u32 sd2_clk_cfg;	/* 0x418 sd2 clock configuration */
	u32 sd3_clk_cfg;	/* 0x41c sd3 clock configuration */
	u8 reserved7[0x08];	/* 0x420 */
	u32 ts_clk_cfg;		/* 0x428 transport stream clock cfg */
	u32 ss_clk_cfg;		/* 0x42c security system clock cfg */
	u32 spi0_clk_cfg;	/* 0x430 spi0 clock configuration */
	u32 spi1_clk_cfg;	/* 0x434 spi1 clock configuration */
	u32 spi2_clk_cfg;	/* 0x438 spi2 clock configuration */
	u32 spi3_clk_cfg;	/* 0x43c spi3 clock configuration */
	u8 reserved8[0x50];	/* 0x440 */
	u32 de_clk_cfg;		/* 0x490 display engine clock configuration */
	u8 reserved9[0x04];	/* 0x494 */
	u32 mp_clk_cfg;		/* 0x498 mp clock configuration */
	u32 lcd0_clk_cfg;	/* 0x49c LCD0 module clock */
	u32 lcd1_clk_cfg;	/* 0x4a0 LCD1 module clock */
	u8 reserved10[0x1c];	/* 0x4a4 */
	u32 csi_isp_clk_cfg;	/* 0x4c0 CSI ISP module clock */
	u32 csi0_clk_cfg;	/* 0x4c4 CSI0 module clock */
	u32 csi1_clk_cfg;	/* 0x4c8 CSI1 module clock */
	u32 fd_clk_cfg;		/* 0x4cc FD module clock */
	u32 ve_clk_cfg;		/* 0x4d0 VE module clock */
	u32 avs_clk_cfg;	/* 0x4d4 AVS module clock */
	u8 reserved11[0x18];	/* 0x4d8 */
	u32 gpu_core_clk_cfg;	/* 0x4f0 GPU core clock config */
	u32 gpu_mem_clk_cfg;	/* 0x4f4 GPU memory clock config */
	u32 gpu_axi_clk_cfg;	/* 0x4f8 GPU AXI clock config */
	u8 reserved12[0x10];	/* 0x4fc */
	u32 gp_adc_clk_cfg;	/* 0x50c General Purpose ADC clk config */
	u8 reserved13[0x70];	/* 0x510 */

	u32 ahb_gate0;		/* 0x580 AHB0 Gating Register */
	u32 ahb_gate1;		/* 0x584 AHB1 Gating Register */
	u32 ahb_gate2;		/* 0x588 AHB2 Gating Register */
	u8 reserved14[0x04];	/* 0x58c */
	u32 apb0_gate;		/* 0x590 APB0 Clock Gating Register */
	u32 apb1_gate;		/* 0x594 APB1 Clock Gating Register */
	u8 reserved15[0x08];	/* 0x598 */
	u32 ahb_reset0_cfg;	/* 0x5a0 AHB0 Software Reset Register */
	u32 ahb_reset1_cfg;	/* 0x5a4 AHB1 Software Reset Register */
	u32 ahb_reset2_cfg;	/* 0x5a8 AHB2 Software Reset Register */
	u8 reserved16[0x04];	/* 0x5ac */
	u32 apb0_reset_cfg;	/* 0x5b0 Bus Software Reset Register 3 */
	u32 apb1_reset_cfg;	/* 0x5b4 Bus Software Reset Register 4 */
};

/* pll4_periph0_cfg */
#define PLL4_CFG_DEFAULT		0x90002800 /* 960 MHz */

#define CCM_PLL4_CTRL_N_SHIFT		8
#define CCM_PLL4_CTRL_N_MASK		(0xff << CCM_PLL4_CTRL_N_SHIFT)
#define CCM_PLL4_CTRL_P_SHIFT		16
#define CCM_PLL4_CTRL_P_MASK		(0x1 << CCM_PLL4_CTRL_P_SHIFT)
#define CCM_PLL4_CTRL_M_SHIFT		18
#define CCM_PLL4_CTRL_M_MASK		(0x1 << CCM_PLL4_CTRL_M_SHIFT)

/* sd#_clk_cfg fields */
#define CCM_MMC_CTRL_M(x)		((x) - 1)
#define CCM_MMC_CTRL_OCLK_DLY(x)	((x) << 8)
#define CCM_MMC_CTRL_N(x)		((x) << 16)
#define CCM_MMC_CTRL_SCLK_DLY(x)	((x) << 20)
#define CCM_MMC_CTRL_OSCM24		(0 << 24)
#define CCM_MMC_CTRL_PLL_PERIPH0	(1 << 24)
#define CCM_MMC_CTRL_ENABLE		(1 << 31)

/* ahb_gate0 fields */
/* On sun9i all sdc-s share their ahb gate, so ignore (x) */
#define AHB_GATE_OFFSET_MMC(x)		8

/* apb1_gate fields */
#define APB1_GATE_UART_SHIFT		16
#define APB1_GATE_UART_MASK		(0xff << APB1_GATE_UART_SHIFT)
#define APB1_GATE_TWI_SHIFT		0
#define APB1_GATE_TWI_MASK		(0xf << APB1_GATE_TWI_SHIFT)

/* ahb_reset0_cfg fields */
/* On sun9i all sdc-s share their ahb reset, so ignore (x) */
#define AHB_RESET_OFFSET_MMC(x)		8

/* apb1_reset_cfg fields */
#define APB1_RESET_UART_SHIFT		16
#define APB1_RESET_UART_MASK		(0xff << APB1_RESET_UART_SHIFT)
#define APB1_RESET_TWI_SHIFT		0
#define APB1_RESET_TWI_MASK		(0xf << APB1_RESET_TWI_SHIFT)


#ifndef __ASSEMBLY__
unsigned int clock_get_pll4_periph0(void);
#endif

#endif /* _SUNXI_CLOCK_SUN9I_H */