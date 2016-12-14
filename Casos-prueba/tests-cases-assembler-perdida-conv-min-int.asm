.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "si se imprime esto, no funciona el chequeo por perdida de informacion en conversiones", 0
@cte0 dd -40000.000000
@aux_0 dw ?

var@i dw ?
maxInt dd 32768.0
minInt dd -32768.0
DivZero db "error de ejecucion: no se puede dividir por cero", 0
ConversionFailed db "error de ejecucion: no se puede realizar la conversion", 0
MatOutOfRange db "error de ejecucion: matriz fuera de rango", 0

.code
divZero:
invoke MessageBox, NULL, addr DivZero, addr DivZero, MB_OK
invoke ExitProcess, 0

conversionFailed:
invoke MessageBox, NULL, addr ConversionFailed, addr ConversionFailed, MB_OK
invoke ExitProcess, 0

matrixOutOfRange:
invoke MessageBox, NULL, addr MatOutOfRange, addr MatOutOfRange, MB_OK
invoke ExitProcess, 0

start:
;INICIO CONV DOUBLE A INTEGER
;INICIO CHEQUEO POR RANGO
FLD @cte0
FABS
FCOMP maxInt
FSTSW ax
SAHF
JAE conversionFailed
;FIN CHEQUEO POR RANGO
FLD @cte0
FIST @aux_0
;INICIO CHEQUEO PARTE DECIMAL
FABS
FICOMP @aux_0
FSTSW ax
SAHF
JNE conversionFailed
;FIN CHEQUEO PARTE DECIMAL
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @aux_0
MOV var@i, dx
;FINAL ASIGNACION INTEGER
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
invoke ExitProcess, 0
end start