.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "conversion exitosa!", 0
@cadena1 db "conversion fallida", 0
@cadena2 db "si se imprime esta linea, entonces no funciona el chequeo de conversiones de doubles con parte decimal!!", 0
@cte0 dw 3
@cte1 dd 3.000000
@cte2 dd 3.100000
@aux_0 dw ?
@aux_1 dw ?

var@a dw ?
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
FLD @cte1
FABS
FCOMP maxInt
FSTSW ax
SAHF
JAE conversionFailed
;FIN CHEQUEO POR RANGO
FLD @cte1
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
MOV var@a, dx
;FINAL ASIGNACION INTEGER
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL INTEGER
MOV ax, var@a
CMP ax, @cte0
JNE @label_1
;FIN COMP IGUAL INTEGER
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_2
@label_1:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena1, addr @cadena1, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_2:
;FIN IF
;INICIO CONV DOUBLE A INTEGER
;INICIO CHEQUEO POR RANGO
FLD @cte2
FABS
FCOMP maxInt
FSTSW ax
SAHF
JAE conversionFailed
;FIN CHEQUEO POR RANGO
FLD @cte2
FIST @aux_1
;INICIO CHEQUEO PARTE DECIMAL
FABS
FICOMP @aux_1
FSTSW ax
SAHF
JNE conversionFailed
;FIN CHEQUEO PARTE DECIMAL
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @aux_1
MOV var@a, dx
;FINAL ASIGNACION INTEGER
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena2, addr @cadena2, MB_OK
;FINAL PRINT
invoke ExitProcess, 0
end start