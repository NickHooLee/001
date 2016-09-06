#include "..\ProjectMain.h"
#include <stdio.h> 
#include <stdlib.h>

#ifndef _FILEIO_H_
#define _FILEIO_H_

#define FILE_READ_ONLY "r"
#define FILE_WRITE_CLEAR "w" //Empty the context and create a file if it unexist 
#define FILE_WRITE_END_ONLY "a" //Add context to the end of file  and create a file if it unexist 
#define FILE_READ_AND_WRITE "r+" //
#define FILE_READ_AND_WRITE_CLEAR "w+" //
#define FILE_READ_AND_WRITE_ADD "a+" //

#define FILE_BINARY_READ_ONLY "rb"
#define FILE_BINARY_WRITE_CLEAR "wb" //Empty the context and create a file if it unexist 
#define FILE_BINARY_WRITE_END_ONLY "ab" //Add context to the end of file  and create a file if it unexist 
#define FILE_BINARY_READ_AND_WRITE "rb+" //
#define FILE_BINARY_READ_AND_WRITE_CLEAR "wb+" //
#define FILE_BINARY_READ_AND_WRITE_ADD "ab+" //

EFI_STATUS FileExe(CHAR8* Attribute, CHAR8 *FileName, FILE *fp);


#endif//#ifndef _FILEIO_H_
