
#include "ProjectMain.h"
#include "Password\Password.h"
#include "Hash\MD5.h"
#include "FileIo\FileIo.h"
#include "Memory\Memory.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("%u\n",(unsigned int)-1
	);
	//AskForLogOrRegister();
	//printf(L"Hello\n");
	//UINT16	Temp = 0x198;
	//ConvertDramTempValueToString(Temp);
/*	CHAR8 *Password,*CompPassword, *PasswordToMD5,*CompPasswordInFile;
	CHAR8 CompPasswordToMD5[16];
	UINTN Index;
	EFI_STATUS Status;
	
	Password = malloc(sizeof(CHAR8)*PASSWORD_MAX_LENGTH);
	PasswordToMD5 =  malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
	
	CompPassword = malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
	CompPasswordInFile =  malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
	
	Status = AskForPassword(Password);
	if(Status == EFI_SUCCESS){
		Status = ConvertPasswordToMD5(Password, PasswordToMD5);
		if(Status == EFI_SUCCESS){
			Status = PreservePasswordToFile(PasswordToMD5);
			if(Status == EFI_SUCCESS){
				printf("Preserve Password to file success!!\n");
			}
		}
		
	}
	
	Status = GetPasswordFromFile(CompPasswordInFile);
	if(Status == EFI_SUCCESS){
		printf("Locate password in file SUCCESS!!\n");
	}

	Status = AskForPassword(CompPassword);
	if(Status == EFI_SUCCESS){
		Status = ConvertPasswordToMD5(CompPassword, CompPasswordToMD5);
	}
	
	printf("-----------\n");
	for(Index=0;Index<16;Index++){
  		printf("%02x",CompPasswordInFile[Index]);
 	}
 	
 	printf("\n");
 	for(Index=0;Index<16;Index++){
  		printf("%02x",CompPasswordToMD5[Index]);
 	}
 	printf("-----------\n");
 	
	if(Status == EFI_SUCCESS){
		Status = ComparePassword(CompPasswordInFile,CompPasswordToMD5);
		if(Status == EFI_SUCCESS){
			printf("Password Success Compared!!Logging...Please Wait...\n");
		}
	}
		
	free(Password);
	free(PasswordToMD5);
	free(CompPassword);
	free(CompPasswordInFile);
	//PrtCmpPwd();
	//printf("%s\n",Password);
	//MD5(Password);
*/
	return 0;
}
