#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <bitthunder.h>

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#define configBITTHUNDER			1

#ifdef BT_CONFIG_KERNEL_FREERTOS_NEWLIB_REENTRANCY_SUPPORT
#define configUSE_NEWLIB_REENTRANT	1
#else
#define configUSE_NEWLIB_REENTRANT	0
#endif

#define configUSE_PREEMPTION		1
#define configUSE_IDLE_HOOK			0
#define configUSE_TICK_HOOK			0
#define configCPU_CLOCK_HZ			( ( unsigned long ) 24000000 )
#define configTICK_RATE_HZ			( ( portTickType ) 1000 )
#define configMAX_PRIORITIES		( 5 )
#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE		( ( size_t ) ( 4096 ) )
#define configMAX_TASK_NAME_LEN		( 16 )
#define configUSE_TRACE_FACILITY	0
#define configUSE_16_BIT_TICKS		0
#define configIDLE_SHOULD_YIELD		1
#define configUSE_APPLICATION_TASK_TAG	1
#define configGENERATE_RUN_TIME_STATS	0
#define configUSE_TASK_NOTIFICATIONS	1
#define configSUPPORT_DYNAMIC_ALLOCATION 1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1
#define	INCLUDE_xTaskGetSchedulerState	1
#define	INCLUDE_xTaskGetCurrentTaskHandle	1

#define	configUSE_MUTEXES				1
#define	configUSE_RECURSIVE_MUTEXES		1

/* This is the raw value as per the Cortex-M3 NVIC.  Values can be 255
(lowest) to 0 (1?) (highest). */
#define configKERNEL_INTERRUPT_PRIORITY 		255
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#ifdef BT_CONFIG_MACH_PRIORITY_BITS
	#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	((0x01 << BT_CONFIG_MACH_PRIORITY_BITS)-1) << (8-BT_CONFIG_MACH_PRIORITY_BITS) /* equivalent to 0xb0, or priority 11. */
#else
	#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	32 /* equivalent to 0xb0, or priority 11. */
#endif


/* This is the value being used as per the ST library which permits 16
priority values, 0 to 15.  This must correspond to the
configKERNEL_INTERRUPT_PRIORITY setting.  Here 15 corresponds to the lowest
NVIC value of 255. */
#define configLIBRARY_KERNEL_INTERRUPT_PRIORITY	31

#ifdef BT_CONFIG_USE_VIRTUAL_ADDRESSING
#define portCLEAN_UP_TCB(pxTCB) ({bt_thread_cleanup((struct bt_thread *) pxTCB->pxTaskTag); bt_paddr_t phys = bt_virt_to_phys(pxTCB->pxKernelStack); bt_page_free(phys, BT_PAGE_SIZE);})
#endif

#endif /* FREERTOS_CONFIG_H */

