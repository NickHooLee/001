#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "Library\Lib.h"
#ifndef _PROJECT_MAIN_H_
#define _PROJECT_MAIN_H_

#define EFIAPI

//refer to  stdint.h
typedef uint8_t CHAR8;
typedef uint16_t CHAR16;
typedef int8_t INT8;
typedef uint8_t UINT8;
typedef int16_t  INT16;
typedef uint16_t  UINT16;
typedef int32_t  INT32;
typedef uint32_t  UINT32;
typedef int64_t  INT64;
typedef uint64_t  UINT64;
typedef int64_t  INTN;
typedef uint64_t  UINTN;
typedef int8_t BOOLEAN;
//Compatible start
typedef int8_t BOOLEN;
//Compatoble end

#define IN
#define OUT
#define OPTIONAL

#define CONST const
#define STATIC static
#define VOID void
#define VOLATILE volatile

#ifndef TRUE
#define TRUE ((BOOLEAN)(1 == 1))
#endif

#ifndef FALSE
#define FALSE ((BOOLEAN)(1 == 0))
#endif

#ifndef NULL
#define NULL ((VOID*)0)
#endif

#ifndef EFI_SUCCESS
#define EFI_SUCCESS 0
#endif

#ifndef EFI_FALSE
#define EFI_FALSE 1
#endif

typedef UINTN EFI_STATUS;
typedef VOID *EFI_HANDLE;

typedef struct{
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8 Data4[8];
	
}EFI_GUID;

#endif//#ifndef _PROJECT_MAIN_H_
