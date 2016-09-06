#ifndef _CPU_IO_H_
#define _CPU_IO_H_
#include "..\ProjectMain.h"

UINT8
EFIAPI
CpuIoRead8 (
  IN  UINT16  Port
  ){
  }
/*++
Routine Description:
  Cpu I/O read port
Arguments:
   Port: - Port number to read
Returns:
   Return read 8 bit value
--*/
;


UINT16
EFIAPI
CpuIoRead16 (
  IN  UINT16  Port
  ){
  }
/*++
Routine Description:
  Cpu I/O read port
Arguments:
   Port: - Port number to read
Returns:
   Return read 16 bit value
--*/
;


UINT32
EFIAPI
CpuIoRead32 (
  IN  UINT16  Port
  ){
  }
/*++
Routine Description:
  Cpu I/O read port
Arguments:
   Port: - Port number to read
Returns:
   Return read 32 bit value
--*/
;

VOID
EFIAPI
CpuIoWrite8 (
  IN  UINT16  Port,
  IN  UINT32  Data
  ){
  }
/*++
Routine Description:
  Cpu I/O write 8 bit data to port
Arguments:
   Port: - Port number to read
   Data: - Data to write to the Port
Returns:
   None
--*/
;

VOID
EFIAPI
CpuIoWrite16 (
  IN  UINT16  Port,
  IN  UINT32  Data
  ){
  }
/*++
Routine Description:
  Cpu I/O write 16 bit data to port
Arguments:
   Port: - Port number to read
   Data: - Data to write to the Port
Returns:
   None
--*/
;

VOID
EFIAPI
CpuIoWrite32 (
  IN  UINT16  Port,
  IN  UINT32  Data
  ){
  }
/*++
Routine Description:
  Cpu I/O write 32 bit data to port
Arguments:
   Port: - Port number to read
   Data: - Data to write to the Port
Returns:
   None
--*/
;

#endif
