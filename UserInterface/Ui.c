#include "Ui.h"
//#include<window.h>


SCANF_CODE InputKey[]= {
	{0x20,' '},{0x21,'!'},{0x22,'\"'},{0x23,'#'},{0x24,'$'},{0x25,'%'},{0x26,'&'},{0x27,'\''},{0x28,'('},{0x29,')'},{0x2a,'*'},{0x2b,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'/'},
	{0x30,'0'},{0x31,'1'},{0x32,'2'},{0x33,'3'},{0x34,'4'},{0x35,'5'},{0x36,'6'},{0x37,'7'},{0x38,'8'},{0x39,'9'},{0x3a,':'},{0x3b,';'},{0x3c,'<'},{0x3d,'='},{0x3e,'>'},{0x3f,'?'},
	{0x40,'@'},{0x41,'A'},{0x42,'B'},{0x43,'C'},{0x44,'D'},{0x45,'E'},{0x46,'F'},{0x47,'G'},{0x48,'H'},{0x49,'I'},{0x4a,'J'},{0x4b,'K'},{0x4c,'L'},{0x4d,'M'},{0x4e,'N'},{0x4f,'O'},
	{0x50,'P'},{0x51,'Q'},{0x52,'R'},{0x53,'S'},{0x54,'T'},{0x55,'U'},{0x56,'V'},{0x57,'W'},{0x58,'X'},{0x59,'Y'},{0x5a,'Z'},{0x5b,'['},{0x5c,'\\'},{0x5d,']'},{0x5e,'^'},{0x5f,'_'},
	{0x60,'`'},{0x61,'a'},{0x62,'b'},{0x63,'c'},{0x64,'d'},{0x65,'e'},{0x66,'f'},{0x67,'g'},{0x68,'h'},{0x69,'i'},{0x6a,'j'},{0x6b,'k'},{0x6c,'l'},{0x6d,'m'},{0x6e,'n'},{0x6f,'o'},
	{0x70,'p'},{0x71,'q'},{0x72,'r'},{0x73,'s'},{0x74,'t'},{0x75,'u'},{0x76,'v'},{0x77,'w'},{0x78,'x'},{0x79,'y'},{0x7a,'z'},{0x7b,'{'},{0x7c,'|'},{0x7d,'}'},{0x7e,'~'}
	/*
	,{0x7f,''},
	{0x80,' '},{0x81,' '},{0x82,' '},{0x83,' '},{0x84,' '},{0x85,' '},{0x86,' '},{0x87,' '},{0x88,' '},{0x89,' '},{0x8a,'*'},{0x8b,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'//'},
	{0x90,' '},{0x91,' '},{0x92,' '},{0x93,' '},{0x94,' '},{0x95,' '},{0x96,' '},{0x97,' '},{0x98,' '},{0x99,' '},{0x9a,'*'},{0x9b,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'//'},
	{0xa0,' '},{0xa1,' '},{0xa2,' '},{0xa3,' '},{0xa4,' '},{0xa5,' '},{0xa6,' '},{0xa7,' '},{0xa8,' '},{0xa9,' '},{0xaa,'*'},{0xab,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'//'},
	{0xb0,' '},{0xb1,' '},{0xb2,' '},{0xb3,' '},{0xb4,' '},{0xb5,' '},{0xb6,' '},{0xb7,' '},{0xb8,' '},{0xb9,' '},{0xba,'*'},{0x2b,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'//'},
	{0xc0,' '},{0xc1,' '},{0xc2,' '},{0xc3,' '},{0xc4,' '},{0xc5,' '},{0xc6,' '},{0xc7,' '},{0xc8,' '},{0xc9,' '},{0xca,'*'},{0x2b,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'//'},
	{0xd0,' '},{0xd1,' '},{0xd2,' '},{0xd3,' '},{0xd4,' '},{0xd5,' '},{0xd6,' '},{0xd7,' '},{0xd8,' '},{0xd9,' '},{0xda,'*'},{0x2b,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'//'},
	{0xe0,' '},{0xe1,' '},{0xe2,' '},{0xe3,' '},{0xe4,' '},{0xe5,' '},{0xe6,' '},{0xe7,' '},{0xe8,' '},{0xe9,' '},{0xea,'*'},{0x2b,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'//'},
	{0xf0,' '},{0xf1,' '},{0xf2,' '},{0xf3,' '},{0xf4,' '},{0xf5,' '},{0xf6,' '},{0xf7,' '},{0xf8,' '},{0xf9,' '},{0xfa,'*'},{0x2b,'+'},{0x2c,'\''},{0x2d,'-'},{0x2e,'.'},{0x2f,'//'},
	*/
};


CHAR8
ScanfInputKey(VOID){
	EFI_STATUS Status;
	CHAR8 Input, Key;
	UINTN Index;

	fflush(stdin);
	scanf("%c",&Input);
	for(Index=0; Index<0x7f; Index++){
		if(Input == InputKey[Index].AsciiCode){
			Key = Input;
			break;
		}
	}
	fflush(stdin);					
	return Key;
}

EFI_STATUS CompareString(CHAR8 *Dst, CHAR8 *Src){

	EFI_STATUS Status;
	UINTN Index;
	CHAR8 *DstCmp, *SrcCmp;
	
	DstCmp = Dst;
	SrcCmp = Src;
	

#if EFI_DEBUG	
	printf("Debug++++++++++++++++++++++++++++++++Debug\n");		
	printf("The Source Strings：\n");
	Index = 0;
	while(Src[Index]){
		printf("%02x",Src[Index]);
		Index++;
	}	

	printf("\n");
	printf("The Destination Strings：\n");	
	Index = 0;
	while(Dst[Index]){
		printf("%02x",Dst[Index]);
		Index++;
	}
	printf("\n");		
	printf("Debug++++++++++++++++++++++++++++++++Debug\n");		
#endif
		
	while(*DstCmp && *SrcCmp){
		if(*DstCmp == *SrcCmp){
			DstCmp++;
			SrcCmp++;
			continue;
		}else{
			Status = EFI_FALSE;
		}		
	}
	
	if(!*DstCmp && !*SrcCmp)
		Status = EFI_SUCCESS;
	else
		Status = EFI_FALSE;

	return Status;
}


EFI_STATUS
Ui(VOID){
	EFI_STATUS Status = EFI_FALSE;
	EFI_STATUS ContinueProcess;
	CHAR8 Input, Key, *Str;
	
	printf("\n");
	printf("-------------------------------------------------------------------------\n");
	printf("-----------------------------User Page-----------------------------------\n");
	printf("-------------------------------------------------------------------------\n");
	printf("Command List：\n");
	printf("<1>.修改用户名和密码 \n");
	printf("<2>.退出当前用户 \n");
	printf("<3>.重启计算机 \n");
	printf("<4>.关闭计算机 \n");
	printf("<5>.退出当前界面 \n");
	printf(">> ");
	
	do{
		ContinueProcess = 0;
		fflush(stdin);
		scanf("%c",&Input);
		
		//Key = ScanfInputKey();
		switch(Input){
			case '1':
				break;
				
			case '2':
				break;
				
			case '3':
				system("shutdown -r -t 60");
				printf("计算机将于 60s 后重启\n");
				while(1){
					printf("您可以在重启计算机前输入\"exit\", 结束定时重启！\n"); 
					fflush(stdin);
					gets(Str); //输入存储指令
					//if(CompareString(Str,"exit")==EFI_SUCCESS) //满足条件结束定时关机
					if(strcmp(Str,"exit")==0) //满足条件结束定时关机
					{ 
						system("shutdown -a");
						printf("定时关机结束！\n"); 
						break; 
					} 
				} 
				break;
				
			case '4':
				system("shutdown -s -t 60");
				printf("计算机将于 60s 后关机\n");
				while(1){
					printf("您可以在关闭计算机前输入\"exit\", 结束定时关机！\n"); 
					fflush(stdin);
					gets(Str); //输入存储指令
					//if(CompareString(Str,"exit")==EFI_SUCCESS) //满足条件结束定时关机
					if(strcmp(Str,"exit")==0) //满足条件结束定时关机
					{ 
						system("shutdown -a");
						printf("定时关机结束！\n"); 
						break; 
					} 
				} 
				break;
				
			case '5':
				printf("正在退出当前用户页面......\n");
				Status = EFI_SUCCESS;
				break;
			case '\n':
				printf(">> ");
				ContinueProcess = 1;
				break;
				
			default:
				printf("输入错误！请重新输入！\n");
				printf(">> ");
				ContinueProcess = 1;
				break;
		};
		
		fflush(stdin);
	}while(ContinueProcess);

	
	return Status;
}

