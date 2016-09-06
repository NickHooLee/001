#ifndef _UI_H_
#define _UI_H_

#include "..\ProjectMain.h"
#include "..\Password\Password.h"

typedef struct{
	UINTN HexNumber;
	CHAR8 AsciiCode;  
}SCANF_CODE; 

CHAR8	ScanfInputKey(VOID);
//VOID DrawLogo(VOID);
#endif//#define _UI_H_
