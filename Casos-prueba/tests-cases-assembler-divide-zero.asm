.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "division por cero en enteros: 1.0/0", 0
@cte0 dd 0.000000
@cte1 dd 1.000000
@aux_0 dd 0

var@i dd 0
maxInt dd 32768
minInt dd -32768
DivZero db "error de ejecucion: no se puede dividir por cero", 0
ConversionFailed db "error de ejecucion: no se puede realizar la conversion", 0

.code
divZero:
invoke MessageBox, NULL, addr DivZero, addr DivZero, MB_OK
invoke ExitProcess, 0

conversionFailed:
invoke MessageBox, NULL, addr ConversionFailed, addr ConversionFailed, MB_OK
invoke ExitProcess, 0

start:
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
;INICIO DIV DOUBLE
;INICIO CHQUEO CERO DOUBLE
FLDZ 
FLD @cte0
FCOM
FSTSW ax
SAHF
JE divZero
;FINAL CHEQUEO CERO DOUBLE
FLD @cte1
FDIV ST, ST(1)
FST @aux_0
;FINAL DIV DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_0
FSTP var@i
;FINAL ASIGNACION DOUBLE
invoke ExitProcess, 0
end start