/*
 * Copyright 2013-2015 Freescale Semiconductor, Inc.
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

#ifndef __ASM_ARCH_CLOCK_H
#define __ASM_ARCH_CLOCK_H

#include <common.h>

enum mxc_clock {
	MXC_ARM_CLK = 0,
	MXC_BUS_CLK,
	MXC_PERIPHERALS_CLK,
	MXC_UART_CLK,
	MXC_FEC_CLK,
	MXC_I2C_CLK,
};

/* PLL0 => PLL_SYS; PLL_LINFLEX; PLL_DDR; PLL_ENET */
/* PLL1 => NOT USED YET */
/* PLL2 => NOT USED YET */
/* PLL3 => NOT USED YET */

enum clocks {
	FIRC = 0,
	FXOSC,
	RESERVED1,
	RESERVED2,
	PLL0,
	PLL1,
	PLL2,
	PLL3,
};

unsigned int mxc_get_clock(enum mxc_clock clk);

#define imx_get_fecclk() mxc_get_clock(MXC_FEC_CLK)

#endif /* __ASM_ARCH_CLOCK_H */
