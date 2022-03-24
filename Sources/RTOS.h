/*
 * RTOS.h
 *
 *  Created on: Mar 13, 2022
 *      Author: User
 */

#ifndef RTOS_H_
#define RTOS_H_

/*
 * 
 * INCLUSI�N DE LIBRER�AS
 * 
 */
#include "AppTypes.h"
#include "scheduller.h"
#include "Queue.h"

/*
 * 
 * DEFINICI�N DE COSNTANTES DEL M�DULO
 * 
 */
#define RTOS_SYSTEM_PRIORITIES  	8
#define RTOS_MIN_PRIORITY       	RTOS_SYSTEM_PRIORITIES - 1
#define RTOS_MAX_PRIORITY       	0

#define	RTOS_MIN_STACK_SIZE			64 //Preferiblemnte de 64



#define RTOS_IDLE_TASK_PRIORITY		RTOS_SYSTEM_PRIORITIES
#define	RTOS_IDLE_TASK_STACK_SIZE	RTOS_MIN_STACK_SIZE
#define	RTOS_IDLE_TASK_ID			255
#define RTOS_IDLE_TASK_NAME			"Idle Task"


u16 RTOS_Init(v);
u16 RTOS_Start(v);
#endif /* RTOS_H_ */
/*
 * 
 * DEFINICI�N DE VARIABLES GLOBALES INTERNAS DEL M�DULO
 * 
 */
T_QUEUE_HANDLER ReadyTaskList[RTOS_SYSTEM_PRIORITIES];


