/*
 * main.h
 *
 *  Created on: Mar 7, 2025
 *      Author: danilo
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASKS                   5 // 4 user tasks + 1 idle task

#define DUMMY_XPSR                  0x01000000U

#define SIZE_TASK_STACK             1024U
#define SIZE_SCHEDULER_STACK        1024U

#define SRAM_START                  0x20000000U
#define SIZE_OF_SRAM                ( (128) * (1024) )
#define SRAM_END                    ((SRAM_START) + (SIZE_OF_SRAM))

#define T1_STACK_START              SRAM_END
#define T2_STACK_START              ((SRAM_END) - 1 *(SIZE_TASK_STACK))
#define T3_STACK_START              ((SRAM_END) - 2 * (SIZE_TASK_STACK))
#define T4_STACK_START              ((SRAM_END) - 3 * (SIZE_TASK_STACK))
#define IDLE_STACK_START              ((SRAM_END) - 4 * (SIZE_TASK_STACK))
#define SCHEDULER_STACK_START       ((SRAM_END) - 5 * (SIZE_TASK_STACK))

#define TASK_READY_STATE          0x00
#define TASK_BLOCKER_STATE          0xFF

#define INTERUPT_DISABLE()  do{__asm volatile("MOV R0,#0x1"); __asm volatile("MSR PRIMASK, R0");} while(0)
#define INTERUPT_ENABLE()  do{__asm volatile("MOV R0,#0x0"); __asm volatile("MSR PRIMASK, R0");} while(0)

#define TICK_HZ                     1000U

#define HSI_CLK                     16000000

#define SYSTICK_TIM_CLK             HSI_CLK



#endif /* MAIN_H_ */
