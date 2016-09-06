;;#################################################################
;;
;;Copyright (c) 2006-2015, ZD Technology (Beijing) Co., Ltd.. All
;;Rights Reserved.
;;
;;You may not reproduce, distribute, publish, display, perform, modify, adapt,
;;transmit, broadcast, present, recite, release, license or otherwise exploit
;;any part of this publication in any form, by any means, without the prior
;;written permission of ZD Technology (Beijing) Co., Ltd..
;;
;;#################################################################

COMMENT MARK

  title   CpuIoAccess.asm
;------------------------------------------------------------------------------
;

;
;
; Module Name:
;
;   CpuIoAccess.asm
; 
; Abstract:
; 
;   Supports IA32 CPU IO operation
;
;------------------------------------------------------------------------------

  .686
  .MODEL FLAT,C
  .CODE


UINT8    TYPEDEF    BYTE
UINT16   TYPEDEF    WORD
UINT32   TYPEDEF    DWORD
UINT64   TYPEDEF    QWORD
UINTN    TYPEDEF    UINT32



;------------------------------------------------------------------------------
;  UINT8
;  CpuIoRead8 (
;    IN  UINT16  Port
;    )
;------------------------------------------------------------------------------
CpuIoRead8 PROC    PUBLIC Port:UINT16
    push   edx
    mov    dx,  Port
    in     al,  dx
    pop    edx
    ret
CpuIoRead8  ENDP

;------------------------------------------------------------------------------
;  UINT16
;  CpuIoRead16 (
;    IN  UINT16  Port
;    )
;------------------------------------------------------------------------------
CpuIoRead16 PROC    PUBLIC Port:UINT16
    push   edx
    mov    dx,  Port
    in     ax,  dx
    pop    edx
    ret
CpuIoRead16  ENDP

;------------------------------------------------------------------------------
;  UINT32
;  CpuIoRead32 (
;    IN  UINT16  Port
;    )
;------------------------------------------------------------------------------
CpuIoRead32 PROC    PUBLIC Port:UINT16
    push  edx
    mov   dx,  Port
    in    eax, dx
    pop   edx
    ret
CpuIoRead32  ENDP



;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite8 (
;    IN  UINT16  Port,
;    IN  UINT32  Data
;    )
;------------------------------------------------------------------------------
CpuIoWrite8 PROC    PUBLIC Port:UINT16, Data:UINT32
    pushad
    mov    eax, Data
    mov    dx,  Port
    out    dx,  al
    popad
    ret
CpuIoWrite8  ENDP


;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite16 (
;    IN  UINT16  Port,
;    IN  UINT32  Data
;    )
;------------------------------------------------------------------------------
CpuIoWrite16 PROC    PUBLIC Port:UINT16, Data:UINT32
    pushad
    mov    eax, Data
    mov    dx,  Port
    out    dx,  ax
    popad
    ret
CpuIoWrite16  ENDP


;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite32 (
;    IN  UINT16  Port,
;    IN  UINT32  Data
;    )
;------------------------------------------------------------------------------
CpuIoWrite32 PROC    PUBLIC Port:UINT16, Data:UINT32
    pushad
    mov    eax, Data
    mov    dx,  Port
    out    dx,  eax
    popad
    ret
CpuIoWrite32  ENDP


END

MARK
