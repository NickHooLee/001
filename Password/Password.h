#include "..\ProjectMain.h"
#include "..\Hash\MD5.h"
#include "..\FileIo\FileIo.h"

#ifndef _PASSWORD_H_
#define _PASSWORD_H_

#define PASSWORD_MAX_LENGTH 20
#define USERNAME_MAX_LENGTH 20
#define OLD_PASSWORD 0
#define NEW_PASSWORD 1

#define QUIT_REQUEST 1
#define CONTINUE_REQUEST 2
#define INPUT_ERR_REQUEST 3

VOID PrintAskForPassword(UINT8 Type, VOID *Str);
EFI_STATUS CmpPwd(CHAR8 *OldPassword, CHAR8 *NewPassword);
VOID PrtCmpPwd(VOID);
EFI_STATUS AskForUserNameRegister(CHAR8 *UserNameStr);
EFI_STATUS AskForPasswordRegister(CHAR8 *PasswordStr);
EFI_STATUS AskForUserName(CHAR8 *UserNameStr);
EFI_STATUS AskForPassword(CHAR8 *PasswordStr);
EFI_STATUS AskForLogOrRegister(VOID);
EFI_STATUS AskForLogin(VOID);
EFI_STATUS AskForRegister(VOID);
EFI_STATUS AskForQuit(VOID);
EFI_STATUS ConvertStringsToMD5(CHAR8 *OriStr, CHAR8 *MD5Str);
EFI_STATUS GetUserNameFromFile(CHAR8 *UserName);
EFI_STATUS PreserveUserNameToFile(CHAR8 *UseNameToMD5);
EFI_STATUS GetPasswordFromFile(CHAR8 *Password);
EFI_STATUS PreservePasswordToFile(CHAR8 *PasswordToMD5);
EFI_STATUS CompareMD5String(CHAR8 *OldStr, CHAR8 *NewStr);
EFI_STATUS ScanfInputYesNo(VOID);

#endif//#ifndef _PASSWORD_H_
