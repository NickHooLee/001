#include "FileIo.h"
 

EFI_STATUS FileExe(CHAR8* Attribute, CHAR8 *FileName, FILE *fp){

	EFI_STATUS Status = EFI_FALSE;
	
	printf("DEBUG: FileExe start\n");
	fp = fopen((CONST CHAR8*)FileName, (CONST CHAR8*)Attribute);

	printf("DEBUG: FileExe start 1\n");
	if(fp != NULL){
		Status = EFI_SUCCESS;
		
	} 
	printf("1:%p\n",fp);
	printf("DEBUG: FileExe end\n");
	return Status;
}

