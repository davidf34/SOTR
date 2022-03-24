
#include "AppTypes.h"
#include "portable.h"
/*
 * 
 * Definicion de variables globales internas del módulo
 * 
 */


#define Portable_SaveContext()			asm(TSX):\
										asm(STHX CurrentStackPtr)
#define Portable_RestoreContext()		asm(LDHX CurrentStackPtr):\
										asm(TXS)

extern 	u16 RTOS_Scheduller(u16 ActualStack);
/*extern	v	RTOS_DecrementTimers(v);*/


u16 CurrentStackPtr;//acá se almacena HX
u8  CriticalNesting = 0;


pu8 Portable_InitTaskContext (pu8 Stack, TaskFunction Function, void * Param) 
{
	if((!Stack)||(!Function))
	{
		return NULL;
	}
	Stack--;
	*Stack = (u8)((u16)Function & 0x00FF);		//Asignacion PC Low
	Stack--;
	*Stack = (u8)(((u16)Function >> 8)& 0x00FF);//Asignacion PC High
	Stack--;
	*Stack=	 (u8)((u16)Param & 0x00FF);;	//Asignacion X
	Stack--;
	*Stack=0;	//Asignación del A(acumulador)
	Stack--;
	*Stack=0;	//Asignación de CCR (código de condicion)
	Stack--;
	*Stack=  (u8)(((u16)Param >> 8)& 0x00FF);	//Asignación de H
	Stack--;
	*Stack=0;	//Asignación del Critical Nesting
	return Stack;
}

 

v Portable_RestoreManualContext(u16 Stack){
	
	CurrentStackPtr = Stack;
	asm{
		LDHX	CurrentStackPtr
		TXS	
		PULA
		STA		CriticalNesting
		PULH
		RTI
	}
}

v Portable_InitTickRTC(v){
	
	RTCSC = 0x00;
	RTCMOD = 0x01;
	RTCMOD = RTCMOD;
	RTCSC = 0x98;
}

v Portable_DisableInterrupts(v){
	asm(SEI);
	CriticalNesting++;
}

v Portable_EnableInterrupts(v){
	
	if(CriticalNesting){
		CriticalNesting--;
		
		if(!CriticalNesting){
			asm(CLI); 
		}
	}
}

__interrupt void ISR_SoftwareInterrupt(void){
	
	CriticalNesting ++;
	asm{
		LDA		CriticalNesting
		PSHA
		TSX
		STHX	CurrentStackPtr
	}
	
	CurrentStackPtr = Scheduller_Coperative(CurrentStackPtr);
	asm{
		LDHX	CurrentStackPtr
		TXS
		PULA
		STA		CriticalNesting
	}
	
}

__interrupt void ISR_TimerInterrupt(void){
	
	RTCSC |=0x80;								//quitar bandera de interrupcion del timer
	CriticalNesting ++;
	asm{										//guarda el contexto
		LDA		CriticalNesting
		PSHA
		TSX
		STHX	CurrentStackPtr
	}
	//RTOS_DecrementTimers(); 
	CurrentStackPtr = RTOS_Scheduller(CurrentStackPtr);
	asm{
		LDHX	CurrentStackPtr
		TXS
		PULA
		STA		CriticalNesting
	}
	
}




