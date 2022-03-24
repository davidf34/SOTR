/*
 * RTOS.c
 *
 *  Created on: Mar 14, 2022
 *      Author: User
 */
#include "AppTypes.h"
#include "RTOS.h"
#include "scheduller.h"

T_TCB	IdleTaskHandler;
u8		IdleTaskStack[RTOS_IDLE_TASK_STACK_SIZE];

v IdleTask(pv Param){
	for(;;){
		
	}
}

u16 RTOS_Init(v)
{
	return Scheduller_init();
}
u16 RTOS_Start(v)
{
	u16	Res;
	u16	FirstTaskSP;
	Res = Task_Create(&IdleTaskHandler, RTOS_IDLE_TASK_ID, RTOS_IDLE_TASK_NAME, RTOS_IDLE_TASK_PRIORITY, IdleTaskStack, RTOS_IDLE_TASK_STACK_SIZE, IdleTask, NULL);
	
	if(Res){
		
		return Res;
	}
	IdleTaskHandler.TaskPriority = RTOS_IDLE_TASK_PRIORITY;
	FirstTaskSP = Scheduller_Coperative(0);
	Portable_InitTickRTC();
	Portable_RestoreManualContext(FirstTaskSP);
	return Res;
	
}


v IdleTask(pv Param)
{
	for(;;){}
}
