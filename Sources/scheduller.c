/*
 * 
 * Inclusión de librerias
 * 
 */
#include "AppTypes.h"
#include "scheduller.h"
#include "Queue.h"
#include "RTOS.h"
//#include "task.h"

/*
 * 
 * DEFINICION DE VARIABLES GLOBALES INTERNAS EN EL MODULO
 * 
 */

extern T_TCB IdleTaskHandler;
T_QUEUE_HANDLER ReadyTaskList(RTOS_SYSTEM_PRIORITIES);


/*
 * Nombre		:Scheduller_Coperative
 * Descripción	:Función encargada de buscar la siguiente tarea a ser 
 * 				ejecutada y guardar el SP de la tarea que se estaba 
 * 				ejecutando.
 * Parámetros	:ActualStackSP - SP de la tarea actual en ejecución
 * Retonro		:u16 - El SP de la tarea que se va ejecutar
 * 
 */
u16 Scheduller_Init(void){
	u16 Res = SCHEDULLER_OK;
	u16 Count;
	for(Count = 0;Count < RTOS_SYSTEM_PRIORITIES; Count++){
		Res = Queue_Init(&ReadyTaskList(Count));
		if(Res != QUEUE_OK){
			break;
		}
	}
	return Res;
}

u16 Scheduller_Coperative(u16 ActualTaskSP){
    u16 Res;
    u16 Count;
    T_TCB_PTR Task =NULL;
    T_QUEUE_ELEMENT_PTR Element = NULL;
    Task = Task_Get_ActualTask();
    
    if(Task != NULL){
    	
    	if	(ActualTaskSP != 0){
    		Task ->TaskActualStack = ActualTaskSP;
    	}
        if(Task != &IdleTaskHandler){
			if(Task->Status == RUNNING){ //si la tarea está en running	
				Res = Scheduller_SetTaskToReadyQueue(Task);//Se pone la tarea que ya esta lista para ejecutarse
				}
        }
        else{
        	Task->Status = READY;
        }
    }
    Task = NULL;//se borra el apuntador de tarea

    for (Count = 0; Count < RTOS_SYSTEM_PRIORITIES; Count++)
    {//se recorre para ver si hay tareas listas para ejecutar
        if(Queue_GetCount(&ReadyTaskList[Count])>0){
            //se saca, se manda el handler de la cola donde se quiere desencolar
            Res = Queue_Dequeue(&ReadyTaskList[Count], &Element);
            if(Res == QUEUE_OK){
                if(Element != NULL){//SI LOGRÓ DESENCOLAR, EL APUNTADOR DE ELEMENTO SERA DIFERENTE A NULO 
                    Task = Element -> Data;//saca el TCB de la tarea y rompe el ciclo
                    break;
                	} 
            	}
        	}
    	}
    
    if(Task == NULL){
        
    	Task = &IdleTaskHandler; 
    }
    Task -> Status = RUNNING; //pasa a estado de ejecución
    Task_SetActualTask(Task);
    //se debe encontrar el stackpointer
    return Task->TaskActualStack;
    
}

u16 Scheduller_SetTaskToReadyQueue(T_TCB_PTR Task){
    u16 Res = SCHEDULLER_ERROR_NULL_PARAM; 
    if(Task != NULL){
        Task ->Status = READY;
        if(Task->TaskPriority< RTOS_SYSTEM_PRIORITIES){
            Task -> TaskQueueElement.Data = Task;
            Task -> TaskQueueElement.Data = NULL;
            Res  = Queue_Enqueue (&ReadyTaskList[Task->TaskPriority], &Task->TaskQueueElement);
        }
        else{
        	Res = SCHEDULLER_ERROR_PARAM_OUT_OF_RANGE;
        }
    }
    return Res;
    
}
