#include "AppTypes.h"
#ifndef __QUEUE_H__
#define __QUEUE_H__
#define QUEUE_BASE_ERR 			0x0500
#define QUEUE_OK 				0
#define QUEUE_ERR_NULL 			0x00F
#define QUEUE_ERR_OUT_OF_RANGE 	0x00EF

typedef struct QUEUE_ELEMENT
	{	
	pv	Data;
	struct QUEUE_ELEMENT* Next;
	}T_QUEUE_ELEMENT, *T_QUEUE_ELEMENT_PTR;

typedef struct
	{
		u16 Count;
		T_QUEUE_ELEMENT_PTR Head;
		T_QUEUE_ELEMENT_PTR Tail;
	}T_QUEUE_HANDLER, *T_QUEUE_HANDLER_PTR;


u16 Queue_Init (T_QUEUE_HANDLER_PTR Queue);
u16 Queue_GET_Count (T_QUEUE_HANDLER_PTR Queue);
u16 Queue_Enqueue (T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR ELEMENT);
u16 Queue_Dequeue (T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR* ELEMENT);
#endif
