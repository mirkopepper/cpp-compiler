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
@cte0 dd -32768.000000
@aux_0 dw ?

var@i dw ?
maxInt dd 32768
minInt dd -32768
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
FLD @cte0
;INICIO CHEQUEO POR RANGO POSITIVO
FICOM maxInt
JG conversionFailed
;FIN CHEQUEO POR RANGO POSITIVO
;INICIO CHEQUEO POR RANGO NEGATIVO
FICOM minInt
JL conversionFailed
;FIN CHEQUEO POR RANGO NEGATIVO
FISTP @aux_0
;INICIO DE CHEQUEO DE PARTE DECIMAL
FLD @cte0
FICOM @aux_0
JE conversionFailed
;FIN DE CHEQUEO DE PARTE DECIMAL
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