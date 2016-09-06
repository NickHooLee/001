#include "Password.h"
#include <String.h>
#include <stdio.h>
#include <stdlib.h>

VOID PrintAskForPassword(UINT8 Type, VOID *Str){
	CHAR8 UserPassword[PASSWORD_MAX_LENGTH];
	UINTN Index;
	printf("-------------------------------------------------------------------------\n");
	printf("-----------------------------Password Page-------------------------------\n");
	printf("-------------------------------------------------------------------------\n\n");
	switch(Type){
		case OLD_PASSWORD:
			printf("请输入旧密码: ");
			break;
		case NEW_PASSWORD:
			printf("请输入新密码: ");
			break;
		default:
			break;		
	};
	
	
	for(Index=0; Index <PASSWORD_MAX_LENGTH; Index++){
		scanf("%c",&UserPassword[Index]); 
		if(UserPassword[Index] == '\n') break;
	}
	printf("\n");

	memcpy(Str,UserPassword,sizeof(CHAR8)*(Index+1));
	fflush(stdin);	
}

EFI_STATUS CmpPwd(CHAR8 *OldPassword, CHAR8 *NewPassword){
	UINTN Index;
	EFI_STATUS Status;
	CHAR8 OldDecrypt[16];
	CHAR8 NewDecrypt[16]; 
	
	MD5(OldPassword,OldDecrypt);   
	MD5(NewPassword,NewDecrypt);
	  
	for(Index=0; Index<MD5_SERIAL_CODE_LENGTH; Index++){
		if(OldDecrypt[Index] == NewDecrypt[Index]){
			continue;
		}else{
			break;
		}
	}
	
	if(Index == 16){
		Status = EFI_SUCCESS;
	}else{
		Status = EFI_FALSE;
	}
//	printf("%d\n",Index);
//	printf("Status = %d\n",Status);
	return Status;
}

VOID PrtCmpPwd(VOID){
	EFI_STATUS Status;
	CHAR8 *OldPassword = NULL;
	CHAR8 *NewPassword = NULL;
	OldPassword = malloc(sizeof(CHAR8)*PASSWORD_MAX_LENGTH);
	NewPassword = malloc(sizeof(CHAR8)*PASSWORD_MAX_LENGTH);
	PrintAskForPassword(OLD_PASSWORD,OldPassword);
	PrintAskForPassword(NEW_PASSWORD,NewPassword);
	Status = CmpPwd(OldPassword, NewPassword);
//	printf("Status = %d\n",Status);
	if(Status == EFI_SUCCESS){
		printf("ID Pass!\n");
	}else{
		printf("Password is uncorrect!\n");
	}
	
	free(OldPassword);
	free(NewPassword);
}

EFI_STATUS AskForUserNameRegister(CHAR8 *UserNameStr){
	
	CHAR8 UserName[USERNAME_MAX_LENGTH];
	UINTN Index;
	EFI_STATUS Status = EFI_FALSE;

	printf("请设置用户名: ");
	fflush(stdin);
	for(Index=0; Index <USERNAME_MAX_LENGTH; Index++){
		scanf("%c",&UserName[Index]); 
		if(Index == 0){
			if(UserName[Index] == '\n'){
				Status = EFI_FALSE;
				goto END;
			}
		}
		
		if(UserName[Index] == '\n'){
			break;	
		}
	}
	printf("\n");

	memcpy(UserNameStr,UserName,sizeof(CHAR8)*(Index+1));
	if(UserNameStr != NULL){
		Status = EFI_SUCCESS;
	}
	
END:
	fflush(stdin);	
	return Status;	
}

EFI_STATUS AskForPasswordRegister(CHAR8 *PasswordStr){
	
	CHAR8 UserPassword[PASSWORD_MAX_LENGTH];
	UINTN Index;
	EFI_STATUS Status = EFI_FALSE;

	printf("请设置密码: ");
	fflush(stdin);
	for(Index=0; Index <PASSWORD_MAX_LENGTH; Index++){
		scanf("%c",&UserPassword[Index]); 
		if(Index == 0){
			if(UserPassword[Index] == '\n'){
				Status = EFI_FALSE;
				goto END;
			}
		}
		
		if(UserPassword[Index] == '\n'){
			break;	
		}
	}
	printf("\n");
	memcpy(PasswordStr,UserPassword,sizeof(CHAR8)*(Index+1));
	if(PasswordStr != NULL){
		Status = EFI_SUCCESS;
	}
	
END:
	fflush(stdin);	
	return Status;	
}

EFI_STATUS AskForUserName(CHAR8 *UserNameStr){
	
	CHAR8 UserName[USERNAME_MAX_LENGTH];
	UINTN Index;
	EFI_STATUS Status = EFI_FALSE;

	printf("请输入用户名: ");
	fflush(stdin);
	for(Index=0; Index <USERNAME_MAX_LENGTH; Index++){
		scanf("%c",&UserName[Index]); 
		if(Index == 0){
			if(UserName[Index] == '\n'){
				Status = EFI_FALSE;
				goto END;
			}
		}
		if(UserName[Index] == '\n'){
			break;	
		}
	}
	printf("\n");

	memcpy(UserNameStr,UserName,sizeof(CHAR8)*(Index+1));
	if(UserNameStr != NULL){
		Status = EFI_SUCCESS;
	}
END:
	fflush(stdin);	
	return Status;	
}

EFI_STATUS AskForPassword(CHAR8 *PasswordStr){
	
	CHAR8 UserPassword[PASSWORD_MAX_LENGTH];
	UINTN Index;
	EFI_STATUS Status = EFI_FALSE;

	printf("请输入密码: ");
	fflush(stdin);
	for(Index=0; Index <PASSWORD_MAX_LENGTH; Index++){
		scanf("%c",&UserPassword[Index]); 
		if(Index == 0){
			if(UserPassword[Index] == '\n'){
				Status = EFI_FALSE;
				goto END;
			}
		}
		if(UserPassword[Index] == '\n'){
			break;	
		}
	}
	printf("\n");

	memcpy(PasswordStr,UserPassword,sizeof(CHAR8)*(Index+1));
	if(PasswordStr != NULL){
		Status = EFI_SUCCESS;
	}
END:
	fflush(stdin);	
	return Status;	
}



EFI_STATUS AskForLogOrRegister(VOID){

	EFI_STATUS Status = EFI_FALSE;
	EFI_STATUS Askstate = 1;
	EFI_STATUS Askquit;
	CHAR8 Input;
	
	printf("-------------------------------------------------------------------------\n");
	printf("-------------------------------Main Page---------------------------------\n");
	printf("-------------------------------------------------------------------------\n");
	
	
	
	do{	
		printf("==登录、注册，还是放弃本次操作?\n");
		printf("==[登录]请输入 L，[注册]请输入 R，[放弃]请输入 Q. \n>> ");
		
		do{
			//Important!!!! fflush(stdin);
			fflush(stdin);
			scanf("%c",&Input);
			
			switch(Input){
				case 'L':
				case 'l':
					Status = AskForLogin();
					if(Status == 0x88){
						do{
							Status = Ui();
						} while(Status == EFI_FALSE);
						
					}
					break;
					
				case'R':
				case'r':
					AskForRegister();
					break;
				
				case'Q':
				case'q':
					Askquit = AskForQuit();
					if(Askquit == 3){
						Askstate = 0;
					}else if(Askquit == 0){
						printf("返回错误信息！"); 
					}	 
					break;
					
				case '\n':
					printf(">> ");
					break;
					
				default:
					printf("输入有错，请重新输入！\n\n");
					break;
			}
		}while(Input == '\n');

	}while(Askstate);
	
	fflush(stdin);
	return Status;	
}

EFI_STATUS AskForLogin(VOID){
	
	CHAR8 Input;
	EFI_STATUS Status;
	EFI_STATUS ScanfCode = 0;
	CHAR8 *UserName,*UserNameToMD5,*CompUserNameInFile;
	CHAR8 *Password,*PasswordToMD5,*CompPasswordInFile;
	
	printf("-------------------------------------------------------------------------\n");
	printf("---------------------------------Login-----------------------------------\n");
		
	do{
		ScanfCode = 0;
		
		UserName 			= malloc(sizeof(CHAR8)*USERNAME_MAX_LENGTH);
		UserNameToMD5 		= malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
		CompUserNameInFile 	=  malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
	
		Password 			= malloc(sizeof(CHAR8)*PASSWORD_MAX_LENGTH);
		PasswordToMD5		= malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
		CompPasswordInFile 	= malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
	
		Status = AskForUserName(UserName);
		if(Status == EFI_SUCCESS){
			ConvertStringsToMD5(UserName, UserNameToMD5);
		} else{
			printf("用户名错误！\n");
			ScanfCode = ScanfInputYesNo();
			goto END;
		}
	
		Status = GetUserNameFromFile(CompUserNameInFile);
		if(Status == EFI_SUCCESS){
			Status = CompareMD5String(CompUserNameInFile,UserNameToMD5);
			if(Status != EFI_SUCCESS){
				printf("用户名错误！\n");
				ScanfCode = ScanfInputYesNo();
				goto END;
			}
		}else{
			printf("用户名不存在！请先注册！\n");
			ScanfCode = QUIT_REQUEST;
			goto END;
		}
		
		Status = AskForPassword(Password);
		if(Status == EFI_SUCCESS){
		ConvertStringsToMD5(Password, PasswordToMD5);
		} else{
			printf("密码错误！\n");
			ScanfCode = ScanfInputYesNo();
			goto END;
		}
	
		Status = GetPasswordFromFile(CompPasswordInFile);
		if(Status == EFI_SUCCESS){
			Status = CompareMD5String(CompPasswordInFile,PasswordToMD5);
			if(Status != EFI_SUCCESS){
				printf("输入密码错误！\n");
				ScanfCode = ScanfInputYesNo();
				goto END;
			}
		}else{
			printf("输入密码错误!\n");
				ScanfCode = ScanfInputYesNo();
				goto END;	
		} 
		
END:
		//continue
		if(ScanfCode == CONTINUE_REQUEST){
			free(UserName);
			free(UserNameToMD5);
			free(CompUserNameInFile);
			free(Password);
			free(PasswordToMD5);
			free(CompPasswordInFile);
		}
	
		if(ScanfCode == QUIT_REQUEST){	
			free(UserName);
			free(UserNameToMD5);
			free(CompUserNameInFile);
			free(Password);
			free(PasswordToMD5);
			free(CompPasswordInFile);
			Status = 0x77; 
			return Status;
		}	
	}while(ScanfCode == CONTINUE_REQUEST);
	
	printf("Login........Wait..........\n");
	Status = 0x88;
	free(UserName);
	free(UserNameToMD5);
	free(CompUserNameInFile);
	free(Password);
	free(PasswordToMD5);
	free(CompPasswordInFile);
	
	printf("\n");
	return Status;

}


EFI_STATUS AskForRegister(VOID){
	
	CHAR8 Input;	
	EFI_STATUS		Status;
	EFI_STATUS  	ScanfCode;
	CHAR8 			*UserName, *UserNameToMD5, *CompUserNameInFile;
	CHAR8 			*Password, *PasswordToMD5;
	
	
	
	printf("-------------------------------------------------------------------------\n");
	printf("---------------------------------Register--------------------------------\n");
	
	do{	
		ScanfCode = 0;
		
		UserName 		= malloc(sizeof(CHAR8)*USERNAME_MAX_LENGTH);
		UserNameToMD5 	= malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
		CompUserNameInFile =  malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
	
		Password 		= malloc(sizeof(CHAR8)*PASSWORD_MAX_LENGTH);
		PasswordToMD5	= malloc(sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
		
		do{	
			ScanfCode = 0;		
			Status = AskForUserNameRegister(UserName);
			if(Status == EFI_SUCCESS){
				ConvertStringsToMD5(UserName, UserNameToMD5);
			} else{
				printf("用户名无效\n");
				ScanfCode = ScanfInputYesNo();
			} 
		}while(ScanfCode == CONTINUE_REQUEST);

		if(ScanfCode == QUIT_REQUEST){
			goto END;
		} 
		
		Status = GetUserNameFromFile(CompUserNameInFile);
		if(Status == EFI_SUCCESS){
			Status = CompareMD5String(CompUserNameInFile,UserNameToMD5);
			if(Status == EFI_SUCCESS){			
				printf("用户名已经存在！\n");
				ScanfCode = ScanfInputYesNo();
				if(ScanfCode == QUIT_REQUEST){
					remove("C:\\Users\\Nick\\Desktop\\NickProject\\Password\\UserNameBackup.txt");	
					goto END;
				}
			}else{
				PreserveUserNameToFile(UserNameToMD5);
			} 
		}else{
			PreserveUserNameToFile(UserNameToMD5);
		}
	}while(ScanfCode == CONTINUE_REQUEST);
	
	
	if(ScanfCode == 0){//UserName has been input
		do{
			ScanfCode = 0;
			Status = AskForPasswordRegister(Password);
			if(Status == EFI_SUCCESS){
			ConvertStringsToMD5(Password, PasswordToMD5);
			Status = PreservePasswordToFile(PasswordToMD5);
			} else{
				printf("密码输入有误！继续输入/退出注册？\n");
				ScanfCode = ScanfInputYesNo();
				if(ScanfCode == QUIT_REQUEST){
					remove("C:\\Users\\Nick\\Desktop\\NickProject\\Password\\PasswordBackup.txt");
					goto END; 
				}
			} 		
		}while(ScanfCode == CONTINUE_REQUEST); 	
	}
	
END:
	free(UserName);
	free(UserNameToMD5);
	free(CompUserNameInFile);
	free(Password);
	free(PasswordToMD5);
	
	printf("\n");
	return Status;		
}


EFI_STATUS ConvertStringsToMD5(CHAR8 *OriStr, CHAR8 *MD5Str){
	EFI_STATUS Status;
	Status = MD5(OriStr, MD5Str);
	return Status;
}



EFI_STATUS GetUserNameFromFile(CHAR8 *UserName){
	FILE *fp;
	UINTN Index;
	EFI_STATUS Status = EFI_SUCCESS;
	CHAR8 UserNameTem[MD5_SERIAL_CODE_LENGTH];
	
	fp = fopen("C:\\Users\\Nick\\Desktop\\NickProject\\Password\\UserNameBackup.txt", FILE_READ_ONLY);
	
	if(fp == NULL){
		//printf("ERROR: 无该用户\n");
		Status = EFI_FALSE;
		//exit(1);	
		return Status;
	}
	

	for(Index=0;Index<16;Index++){
  		if((fscanf(fp,"%02x",&UserNameTem[Index])) == 1){
  			continue;
		}else{
		  	break;
		}
 	}

	if(Index == MD5_SERIAL_CODE_LENGTH){
	 	memcpy(UserName, UserNameTem, sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
	}else{
	 	Status = EFI_FALSE;
	}
	
 
	fclose(fp);
	return Status;
}

EFI_STATUS PreserveUserNameToFile(CHAR8 *UseNameToMD5){
	FILE *fp;
	UINTN Index = 0;
	EFI_STATUS Status;

	if(UseNameToMD5 == NULL){
		Status = EFI_FALSE;
	}
	//BUGBUG:fp return NULL!!
	//Status = FileExe("a+", "PasswordBackup.txt", fp);
	fp = fopen("C:\\Users\\Nick\\Desktop\\NickProject\\Password\\UserNameBackup.txt", "w");
	
	if(fp == NULL){
		printf("ERROR: cannot open file UserNameBackup.txt!!\n");
		Status = EFI_FALSE;
		//exit(1);	
		return Status;
	}
	
	for(Index=0;Index<16;Index++){
  		fprintf(fp,"%02x",UseNameToMD5[Index]);
 	}
	
	fclose(fp);
	return Status;
}

EFI_STATUS GetPasswordFromFile(CHAR8 *Password){
	FILE *fp;
	UINTN Index;
	EFI_STATUS Status = EFI_SUCCESS;
	CHAR8 PasswordTem[MD5_SERIAL_CODE_LENGTH];
	
	fp = fopen("C:\\Users\\Nick\\Desktop\\NickProject\\Password\\PasswordBackup.txt", FILE_READ_ONLY);
	
	if(fp == NULL){
		printf("ERROR: cannot open file!!\n");
		exit(1);	
	}
	

	for(Index=0;Index<16;Index++){
  		if((fscanf(fp,"%02x",&PasswordTem[Index])) == 1){
  			continue;
		}else{
		  	break;
		}
 	}

	if(Index == MD5_SERIAL_CODE_LENGTH){
	 	memcpy(Password, PasswordTem, sizeof(CHAR8)*MD5_SERIAL_CODE_LENGTH);
	}else{
	 	Status = EFI_FALSE;
	}
	
 
	fclose(fp);
	return Status;
}

EFI_STATUS PreservePasswordToFile(CHAR8 *PasswordToMD5){
	FILE *fp;
	UINTN Index = 0;
	EFI_STATUS Status;

	if(PasswordToMD5 == NULL){
		Status = EFI_FALSE;
	}
	//BUGBUG:fp return NULL!!
	//Status = FileExe("a+", "PasswordBackup.txt", fp);
	fp = fopen("C:\\Users\\Nick\\Desktop\\NickProject\\Password\\PasswordBackup.txt", "w");

	if(fp == NULL){
		printf("ERROR: cannot open file PasswordBackup!!\n");
		exit(1);
	}
	
	for(Index=0;Index<16;Index++){
  		fprintf(fp,"%02x",PasswordToMD5[Index]);
 	}
	
	fclose(fp);
	return Status;
}

EFI_STATUS CompareMD5String(CHAR8 *OldStr, CHAR8 *NewStr){
	UINTN Index;
	EFI_STATUS Status;

#if EFI_DEBUG	
	printf("Debug++++++++++++++++++++++++++++++++Debug\n");		
	printf("The OLD MD5：\n");	
	for(Index=0; Index<MD5_SERIAL_CODE_LENGTH; Index++){
		printf("%02x",OldStr[Index]);
	}
	printf("\n");
	printf("The NEW MD5：\n");	
	for(Index=0; Index<MD5_SERIAL_CODE_LENGTH; Index++){
		printf("%02x",NewStr[Index]);
	}
	printf("\n");		
	printf("Debug++++++++++++++++++++++++++++++++Debug\n");		
#endif
		
	for(Index=0; Index<MD5_SERIAL_CODE_LENGTH; Index++){
		if(OldStr[Index] == NewStr[Index]){
			continue;
		}else{
			break;
		}
	}
	
	if(Index == MD5_SERIAL_CODE_LENGTH){
		Status = EFI_SUCCESS;
	}else{
		Status = EFI_FALSE;
	}

	return Status;
}

EFI_STATUS ScanfInputYesNo(VOID){
	EFI_STATUS Status;
	EFI_STATUS QuitState, ContinueState, InputErrState;
	CHAR8 Input;

	printf("继续/退出？ \n");

	do{
		QuitState = FALSE;
		ContinueState = FALSE;
		InputErrState = FALSE;
	
		printf("退出[Y] / 继续[N] \n>> ");
		fflush(stdin);
		scanf("%c",&Input);
		switch(Input){
			case 'Y':
			case 'y':
				printf("退出....\n");
				QuitState = TRUE;
				break;
				
			case 'N':
			case 'n':
				printf("继续....\n");
				ContinueState = TRUE;
				break;
				
			default:
				printf("输入错误！请重新输入！\n"); 
				InputErrState = TRUE;
				break; 
		}	
	}while(InputErrState == TRUE);

	fflush(stdin);
	
	if(QuitState == FALSE && ContinueState == FALSE && InputErrState == FALSE){
		Status = 0;
	}else{
		if(QuitState == TRUE){
			Status = QUIT_REQUEST;
		}else if(ContinueState == TRUE){
			Status = CONTINUE_REQUEST;
		}		
	}
				
	return Status;
}

EFI_STATUS AskForQuit(VOID){
	
	CHAR8 Input;
	EFI_STATUS Askforquitstate;
	EFI_STATUS Returnstate;
	EFI_STATUS Status = EFI_SUCCESS;
		
	do{
		Askforquitstate = 0; 
		Returnstate = 0;
		
		printf("是否选择放弃本次操作？[Y/N]: ");
		fflush(stdin);
		scanf("%c",&Input);
		
		switch(Input){
			case 'Y':
			case 'y':
				printf("退出....\n");
				Returnstate = 3;
				break;
				
			case 'N':
			case 'n':
				printf("继续....\n");
				Returnstate = 4;
				break;
					
			default:
				printf("输入错误！请重新输入！\n"); 
				Askforquitstate = 1; 
				break; 
		}
	}while(Askforquitstate);
	
	printf("\n");
	fflush(stdin);
	//return Status;
	return Returnstate;
}				
