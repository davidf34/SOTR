#include "Queue.h"
#include "AppTypes.h"
u16 Queue_init (T_QUEUE_HANDLER_PTR Queue)
	{
	u16 Res = Queue_ERR_NULL;
	if (Queue)
		{
			Queue -> Count = 0;
			Queue -> Head = NULL;
			Queue -> Tail = NULL;
			Res = Queue_OK;
		}
	return Res;
	}
u16 Queue_GET_Count (T_QUEUE_HANDLER_PTR Queue)
	{
		if(Queue)
			{
				return Queue -> Count;
			}
			return 0;
	}
u16 Queue_Enqueue (T_QUEUE_HANDLER_PTR Queue, T_Queue_Element_PTR Element)
	{
	u16 Res = Queue_ERROR_NULL_PARAM;
	Portable_DisableInterrupts();
	if ((Queue)&&(Element))
		{
		Element->Next = NULL;
		if(Queue->Tail)
			{
				((T_QUEUE_ELEMENT_PTR)Queue->Tail)->Next = Element;
				/*Queue -> Tail = Element;
				Element -> Next = NULL;
				Queue -> Count++;*/
			}
		else
			{
				Queue->Head = Element;
				/*Element -> Next = NULL;
				Queue -> Head = Element;
				Queue -> Tail = Element;
				Queue -> Count = 1;*/
			}
			Queue -> Head = Element;
			Queue -> Count ++;
			Res = QUEUE_OK;
		}
	Portable_EnableInterrupts();
	return Res;
	}

u16 Queue_Dequeue (T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR Element)
	{
	u16 Res = QUEUE_ERR_NULL;
	if ( Queue && Element ) {
		if (Queue -> Head) {
		*Element = (Queue -> Head);
		Queue -> Count--;
		if (Queue -> Head == Queue -> Tail) {
			Queue -> Head = NULL;
			Queue -> Tail = NULL;
		}
		else
		{
			Queue -> Head = Queue -> Head -> Next;
		}
		Res = Queue_OK;
		}
	}

}
