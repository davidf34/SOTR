#ifndef __APP_TYPES_H__
#define __APP_TYPES_H__
#ifndef NULL
#define NULL ((void*) 0)
#endif


typedef     signed char    s8;
typedef     unsigned char  u8;
typedef     signed char*   ps8;
typedef     unsigned char* pu8;
typedef     signed short   s16;
typedef     unsigned short u16;
typedef     signed short*  ps16;
typedef     unsigned short* pu16;
typedef     signed long    s32;
typedef     unsigned long  u16;
typedef     signed long*   ps32;
typedef     float          f;
typedef     float *        pf;
typedef     double         d;
typedef     double *       pd;
typedef     void           v;
typedef     void *         pv;
#endif


#define MAIN_BASE_ERROR					0x0100
#define QUEUE_BASE_ERROR				0x0200
#define RTOS_BASE_ERROR					0x0300
#define SCHEDULLER_BASE_ERROR			0x0400
#define TASK_BASE_ERROR					0x0500
#define SEMAPHORE_BASE_ERROR			0x0600
#define MUTEX_BASE_ERROR				0x0700
#define EVENT_BASE_ERROR				0x0800

#define	BASE_ERROR_UNKNOW				0x00FF
#define	BASE_ERROR_NULL_PARAM			0x00FE
#define	BASE_ERROR_EMPTY				0x00FD
#define BASE_ERROR_PARAM_OUT_OF_RANGE	0x00FC
