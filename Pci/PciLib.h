#ifndef _PCI_LIB_H_
#define _PCI_LIB_H_
#include "..\ProjectMain.h"
//
// Pci Io Register Access Methods
//
#define PCI_ADDRESS_INDEX	0xcf8
#define PCI_DATA_INDEX	0xcfc

#define PCI_ADDRESS_ENABLE_BIT	0x80000000 //IO access through 0xcf8/0xcfc
#define PCI_BASE_ADDRESS	0xE0000000	//MMIO access

typedef enum{
  EfiPciWidthUint8,
  EfiPciWidthUint16,
  EfiPciWidthUint32,
  EfiPciWidthUint64
}EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH;

#define PCI_CONFIG_ADDRESS(Bus,Dev,Fun,Reg)\
	(UINT32)((UINT32)PCI_ADDRESS_ENABLE_BIT + (((UINT32)Bus)<<16) + (((UINT32)Dev)<<11) + (((UINT32)Fun)<<8) + ((UINT32)Reg))
#define PCI_EXPRESS_CONFIG_ADDRESS(Bus,Dev,Fun,Reg)\
	(UINTN)((UINTN)PCI_BASE_ADDRESS + (((UINTN)Bus)<<20) + (((UINTN)Dev)<<15) + (((UINTN)Fun)<<12) + ((UINTN)Reg))
	
#define PCI_MAX_BUS_NUMBER	256
#define PCI_MAX_DEV_NUMBER	32
#define PCI_MAX_FUN_NUMBER	8


//Function declaration as below

EFI_STATUS
PciIoRW (
  IN BOOLEAN                                Write,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN UINT32                                 Address,
  IN OUT VOID                               *Buffer
  );
  
EFI_STATUS
PciIoRead (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN UINT32                                 Address,
  IN OUT VOID                               *Buffer
  );
  
EFI_STATUS
PciIoWrite (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN UINT32                                 Address,
  IN OUT VOID                               *Buffer
  );




























#endif

