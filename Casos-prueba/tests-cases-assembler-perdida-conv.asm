.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "chequear codigo!!", 0
@cadena1 db "es igual a 2", 0
@cadena2 db "es igual a 3", 0
@cadena3 db "si se imprime esto, no funciona el chequeo por perdida de informacion en conversiones", 0
@cte0 dw 2
@cte1 dd 2.500000
@cte2 dw 3
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
FLD @cte1
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
FLD @cte1
FICOM @aux_0
JE conversionFailed
;FIN DE CHEQUEO DE PARTE DECIMAL
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @aux_0
MOV var@i, dx
;FINAL ASIGNACION INTEGER
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL INTEGER
MOV ax, var@i
CMP ax, @cte0
JNE @label_1
;FIN COMP IGUAL INTEGER
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena1, addr @cadena1, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_2
@label_1:
;INICIO BLOQUE ELSE
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL INTEGER
MOV ax, var@i
CMP ax, @cte2
JNE @label_3
;FIN COMP IGUAL INTEGER
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena2, addr @cadena2, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_4
@label_3:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_4:
;FIN IF
;FIN BLOQUE ELSE
@label_2:
;FIN IF
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena3, addr @cadena3, MB_OK
;FINAL PRINT
invoke ExitProcess, 0
end start