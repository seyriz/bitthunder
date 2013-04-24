/**
 *	LPC11xx Platform Machine Description.
 *
 *	@author		Robert Steinbauer
 *
 *	@copyright	(c)2013 Riegl Laser Measurement Systems GmBH
 *	@copyright	(c)2013 Robert Steinbauer <rsteinbauer@riegl.com>
 *
 **/


#include <bitthunder.h>

#include "rcc.h"
#include "ioconfig.h"

static const BT_RESOURCE oLPC11xx_gpio_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC11xx_GPIO_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC11xx_GPIO_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= BT_CONFIG_MACH_LPC11xx_TOTAL_GPIOS-1,
		.ulFlags			= BT_RESOURCE_IO,
	},
	{
		.ulStart			= 44,
		.ulEnd				= 47,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};


/**
 *	By using the BT_INTEGRATED_DEVICE_DEF macro, we ensure that this structure is
 *	placed into the device manager's integrated device table.
 *
 *	This allows it to be automatically enumerated without "registering" a driver.
 **/
BT_INTEGRATED_DEVICE_DEF oLPC11xx_gpio_device = {
	.name 					= "LPC11xx,gpio",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC11xx_gpio_resources),
	.pResources 			= oLPC11xx_gpio_resources,
};


static const BT_RESOURCE oLPC11xx_nvic_resources[] = {
	{
		.ulStart			= BT_CONFIG_ARCH_ARM_NVIC_BASE,
		.ulEnd				= BT_CONFIG_ARCH_ARM_NVIC_BASE + BT_SIZE_4K,
		.ulFlags			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= BT_CONFIG_ARCH_ARM_NVIC_TOTAL_IRQS - 1,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC11xx_nvic_device = {
	.name					= "arm,common,nvic",
	.ulTotalResources	   	= BT_ARRAY_SIZE(oLPC11xx_nvic_resources),
	.pResources				= oLPC11xx_nvic_resources,
};

static const BT_RESOURCE oLPC11xx_systick_resources[] = {
	{
		.ulStart 			= 0xE000E010,
		.ulEnd				= 0xE000E01F,
		.ulFlags			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 32,
		.ulEnd				= 32,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC11xx_systick_device = {
	.name					= "arm,cortex-mx,systick",
	.ulTotalResources		= BT_ARRAY_SIZE(oLPC11xx_systick_resources),
	.pResources				= oLPC11xx_systick_resources,
};

static BT_u32 lpc11xx_get_cpu_clock_frequency() {
	return BT_LPC11xx_GetSystemFrequency();
}


static BT_u32 lpc11xx_machine_init() {

	BT_LPC11xx_SetSystemFrequency(BT_CONFIG_MAINCLK_SRC,
								  BT_CONFIG_SYSCLK_CTRL,
								  BT_CONFIG_PLLCLK_SRC,
								  BT_CONFIG_PLLCLK_CTRL,
								  BT_CONFIG_WDTCLK_CTRL,
								  BT_CONFIG_SYSCLK_DIV);

#ifdef BT_CONFIG_PIO0_0_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_0, BT_CONFIG_PIO0_0_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_1_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_1, BT_CONFIG_PIO0_1_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_2_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_2, BT_CONFIG_PIO0_2_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_3_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_3, BT_CONFIG_PIO0_3_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_4_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_4, BT_CONFIG_PIO0_4_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_5_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_5, BT_CONFIG_PIO0_5_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_6_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_6, BT_CONFIG_PIO0_6_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_7_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_7, BT_CONFIG_PIO0_7_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_8_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_8, BT_CONFIG_PIO0_8_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_9_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_9, BT_CONFIG_PIO0_9_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_10_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_10, BT_CONFIG_PIO0_10_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_11_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_11, BT_CONFIG_PIO0_11_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_12_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_12, BT_CONFIG_PIO0_12_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_13_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_13, BT_CONFIG_PIO0_13_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_14_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_14, BT_CONFIG_PIO0_14_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_15_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_15, BT_CONFIG_PIO0_15_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_16_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_16, BT_CONFIG_PIO0_16_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_17_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_17, BT_CONFIG_PIO0_17_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_18_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_18, BT_CONFIG_PIO0_18_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_19_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_19, BT_CONFIG_PIO0_19_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_20_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_20, BT_CONFIG_PIO0_20_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_21_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_21, BT_CONFIG_PIO0_21_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_22_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_22, BT_CONFIG_PIO0_22_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_23_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_23, BT_CONFIG_PIO0_23_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_24_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_24, BT_CONFIG_PIO0_24_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_25_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_25, BT_CONFIG_PIO0_25_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_26_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_26, BT_CONFIG_PIO0_26_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_27_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_27, BT_CONFIG_PIO0_27_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_28_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_28, BT_CONFIG_PIO0_28_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_29_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_29, BT_CONFIG_PIO0_29_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_30_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_30, BT_CONFIG_PIO0_30_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO0_31_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO0_31, BT_CONFIG_PIO0_31_FUNCTION);
#endif


#ifdef BT_CONFIG_PIO1_0_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_0, BT_CONFIG_PIO1_0_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_1_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_1, BT_CONFIG_PIO1_1_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_2_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_2, BT_CONFIG_PIO1_2_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_3_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_3, BT_CONFIG_PIO1_3_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_4_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_4, BT_CONFIG_PIO1_4_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_5_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_5, BT_CONFIG_PIO1_5_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_6_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_6, BT_CONFIG_PIO1_6_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_7_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_7, BT_CONFIG_PIO1_7_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_8_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_8, BT_CONFIG_PIO1_8_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_9_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_9, BT_CONFIG_PIO1_9_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_10_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_10, BT_CONFIG_PIO1_10_FUNCTION);
#endif
#ifdef BT_CONFIG_PIO1_11_FUNCTION
	BT_LPC11xx_SetIOConfig(LPC11xx_PIO1_11, BT_CONFIG_PIO1_11_FUNCTION);
#endif

	return BT_ERR_NONE;
}

#ifdef BT_CONFIG_MACH_LPC11xx_UART_0
static const BT_RESOURCE oLPC11xx_uart0_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LPC11xx_UART0_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LPC11xx_UART0_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= 0,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 37,
		.ulEnd				= 37,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLPC11xx_uart0_device = {
	.name 					= "LPC11xx,usart",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLPC11xx_uart0_resources),
	.pResources 			= oLPC11xx_uart0_resources,
};

const BT_DEVFS_INODE_DEF oLPC11xx_uart0_inode = {
	.szpName = BT_CONFIG_MACH_LPC11xx_UART_0_INODE_NAME,
	.pDevice = &oLPC11xx_uart0_device,
};
#endif


BT_MACHINE_START(ARM, CORTEX_M0, "LPC Microcontroller Platform")
    .ulSystemClockHz 			= BT_CONFIG_MACH_LPC11xx_SYSCLOCK_FREQ,
	.pfnGetCpuClockFrequency 	= lpc11xx_get_cpu_clock_frequency,
	.pfnMachineInit				= lpc11xx_machine_init,
	.pInterruptController		= &oLPC11xx_nvic_device,

	.pSystemTimer 				= &oLPC11xx_systick_device,


#ifdef BT_CONFIG_MACH_LPC11xx_BOOTLOG_UART_NULL
	.pBootLogger				= NULL,
#endif
#ifdef BT_CONFIG_MACH_LPC11xx_BOOTLOG_UART_0
	.pBootLogger				= &oLPC11xx_uart0_device,
#endif
BT_MACHINE_END
