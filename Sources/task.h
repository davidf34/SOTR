/*
 * task.h
 *
 *  Created on: Mar 13, 2022
 *      Author: User
 */

#ifndef TASK_H_
#define TASK_H_

#include "AppTypes.h"
#include "Queue.h"
#include "portable.h"



#define TASK_OK			0
#define	TASK_ERROR_UNKNOW						TASK_BASE_ERROR | BASE_ERROR_UNKNOW
#define	TASK_ERROR_NULL_PARAM					TASK_BASE_ERROR | BASE_ERROR_NULL_PARAM
#define	TASK_ERROR_EMPTY						TASK_BASE_ERROR | BASE_ERROR_EMPTY
#define TASK_ERROR_PARAM_OUT_OF_RANGE			TASK_BASE_ERROR | BASE_ERROR_PARAM_OUT_OF_RANGE


typedef enum{
	RUNNING = 0,
	READY,
	BLOCKED
}TaskStatus,* TaskStatus_PTR;


typedef struct{
	u16 Id;
	char * TaskName;
	TaskStatus	Status;
	u8	TaskPriority;
	void * TaskParam;
	TaskFunction	TaskCallback;
	T_QUEUE_ELEMENT TaskQueueElement;
	pu8	TaskStack;
	u16	TaskStackSize;
	u16	TaskActualStack;
	u16	TaskSleepTime;
	u16 TaskActualTask;
	
}T_TCB,* T_TCB_PTR;

/**
 * 
 * DEFINICION DE FUNCIONES DEL MODULO
 * 
 */

T_TCB_PTR Task_GetActualTask(void);
v Task_SetActualTask(T_TCB_PTR Task);
u16 Task_Create(T_TCB_PTR TaskHandler, u16 Id, char * Name, u8 Priority, pu8 Stack, u16 StackSize, TaskFunction Function, void * Param );

#endif /* TASK_H_ */
