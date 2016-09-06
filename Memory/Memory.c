#include "Memory.h"

//STATIC
EFI_STATUS
ConvertDramTempValueToString(
	IN	UINT16	Temp
)
{
	/*
	CHAR16		TempString[20];
	CHAR16		*pTempString;
	UINT16		Temperature;
	UINT16 		Integer, Decimal;
	UINT16 		DecimalPart;
	UINT16 		Remainder;
	BOOLEN		Negative;
	UINT8 Index;
	Integer = Decimal =0;
	pTempString = TempString;
	Temperature = Temp;
*/
	CHAR8		TempString[20] ={0};
	CHAR8		Buffer[20]={0};
	CHAR8		*pTempString,*pBuffer;
	UINT16		Temperature;
	UINT16 		Integer, Decimal;
	UINT16 		DecimalPart;
	UINT8 		Remainder;
	BOOLEN		Negative;
	UINT8 Count = 0;
	UINT8 Index;
	Integer = Decimal =0;
	pTempString = TempString;
	pBuffer = Buffer;
	Temperature = Temp;
	
	//Deal with Decimal part (bit0~bit3)
	DecimalPart = (UINT16)(Temperature&0x000f);
	if(DecimalPart&0x01)	Decimal += 625;
	if(DecimalPart&0x02)	Decimal += 1250;
	if(DecimalPart&0x04)	Decimal += 2500;
	if(DecimalPart&0x08)	Decimal += 5000;
	do{
		Remainder = Decimal%10;
		*(pTempString++) = (CHAR8)(Remainder + '0');
		Decimal = Decimal/10;
		Count++;
	}while(Decimal != 0);
	
	//Plus '.' between Decimal and Integer
//	*(pTempString) = (CHAR16)('.');
	*(pTempString++) = (CHAR8)('.');
	Count++;
	//Deal with Integer part (bit4~bit11)
	Integer = (UINT16)((Temperature&0x0ff0)>>4);
	do{
		Remainder = Integer%10;
		*(pTempString++) = (CHAR8)(Remainder + '0');
		Integer = Integer/10;
		Count++;
	}while(Integer != 0);

//As impossible to be Negative, so ignore it.
	//Deal with (bit12 --> sign)
	if(Temperature&0x1000){
		Negative = TRUE;
	}else{
		Negative = FALSE;
	}
	//Reverse tempstring into Buffer.
	//As default accuracy is 0.25, so ignore the lowest 8 bits whatever
	Count -= 2;
	while (Count) {
    *(pBuffer++) = *(--pTempString);
    Count--;
  }
  
	for(Index=0; Index<20; Index++){
		printf("%c",Buffer[Index]);
	}
	//printf("%s\n",pTempString);
/*
	if(Negative){
		*(pTempString++)  = '-';
	}else{
		*(pTempString++)  = ' ';
	}
*/	
	return 0;
}
