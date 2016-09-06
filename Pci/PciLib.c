#include "PciLib.h" 
#include "CpuIo.h" 

//Note due to embedded Assembly isn't supported by DEV-C++ 
//So use portb
EFI_STATUS
PciIoRW (
  IN BOOLEAN                                Write,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN UINT32                                 Address,
  IN OUT VOID                               *Buffer
  )
{
	UINTN                             PciData;

	PciData = 0xcfc + (Address & 0x03);
	Address &= ~0x03;
	CpuIoWrite32(0xcf8, Address);
	if (Write)
	{
		switch (Width)
		{
		  case EfiPciWidthUint8:
		    CpuIoWrite8((UINT16)PciData, *(UINT8*)Buffer);
		    break;
		  case EfiPciWidthUint16:
		    CpuIoWrite16((UINT16)PciData, *(UINT16*)Buffer);
		    break;
		  case EfiPciWidthUint32:
		    CpuIoWrite32((UINT16)PciData, *(UINT32*)Buffer);
		    break;
		}
	}else{
		switch (Width)
		{
		  case EfiPciWidthUint8:
		    *(UINT8*)Buffer = CpuIoRead8((UINT16)PciData);
		    break;
		  case EfiPciWidthUint16:
		    *(UINT16*)Buffer = CpuIoRead16((UINT16)PciData);
		    break;
		  case EfiPciWidthUint32:
		    *(UINT32*)Buffer = CpuIoRead32((UINT16)PciData);
		    break;
		}
	}
	return EFI_SUCCESS;
}


EFI_STATUS
PciIoRead (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN UINT32                                 Address,
  IN OUT VOID                               *Buffer
  )
{
	PciIoRW(FALSE, Width, Address, Buffer);
}


EFI_STATUS
PciIoWrite (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN UINT32                                 Address,
  IN OUT VOID                               *Buffer
  )
{
  	PciIoRW(TRUE, Width, Address, Buffer);	
}
