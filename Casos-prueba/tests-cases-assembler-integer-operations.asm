.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "la division entre enteros no funciona", 0
@cadena1 db "la division entre enteros se efectuo de manera exitosa. Tambien la conversion funciona", 0
@cadena2 db "la multiplicacion entre enteros no funciona", 0
@cadena3 db "la multiplicacion entre enteros se efectuo de manera exitosa. Tambien la conversion funciona", 0
@cadena4 db "la resta entre enteros no funciona", 0
@cadena5 db "la resta entre enteros se efectuo de manera exitosa", 0
@cadena6 db "la suma entre enteros no funciona", 0
@cadena7 db "la suma entre enteros se efectuo de manera exitosa", 0
@cte0 dw 1
@cte1 dd 100.000000
@cte2 dw 2
@cte3 dd 30.000000
@cte4 dw 31
@cte5 dw 39
@cte6 dd 40.000000
@cte7 dw 50
@cte8 dw 60
@aux_0 dw ?
@aux_1 dw ?
@aux_2 dw ?
@aux_3 dw ?
@aux_4 dw ?
@aux_5 dd ?
@aux_6 dd ?

var@resDivInteger dw ?
var@resMulInteger dw ?
var@resRestaInteger dw ?
var@resSumaInteger dw ?
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
FLD @cte3
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
FICOMP @aux_0
FSTSW ax
SAHF
JNE conversionFailed
;FIN DE CHEQUEO DE PARTE DECIMAL
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @aux_0
MOV var@resSumaInteger, dx
;FINAL ASIGNACION INTEGER
;INICIO CONV DOUBLE A INTEGER
FLD @cte6
;INICIO CHEQUEO POR RANGO POSITIVO
FICOM maxInt
JG conversionFailed
;FIN CHEQUEO POR RANGO POSITIVO
;INICIO CHEQUEO POR RANGO NEGATIVO
FICOM minInt
JL conversionFailed
;FIN CHEQUEO POR RANGO NEGATIVO
FISTP @aux_1
;INICIO DE CHEQUEO DE PARTE DECIMAL
FICOMP @aux_1
FSTSW ax
SAHF
JNE conversionFailed
;FIN DE CHEQUEO DE PARTE DECIMAL
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @aux_1
MOV var@resRestaInteger, dx
;FINAL ASIGNACION INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @cte7
MOV var@resMulInteger, dx
;FINAL ASIGNACION INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @cte8
MOV var@resDivInteger, dx
;FINAL ASIGNACION INTEGER
;INICIO SUMA INTEGER
MOV ax, var@resSumaInteger
ADD ax, @cte0
MOV @aux_2, ax
;FINAL SUMA INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @aux_2
MOV var@resSumaInteger, dx
;FINAL ASIGNACION INTEGER
;INICIO ASIGNACION RESTA INTEGER
MOV dx, var@resRestaInteger
SUB dx, @cte0
MOV var@resRestaInteger, dx
;FINAL ASIGNACION RESTA INTEGER
;INICIO MUL INTEGER
MOV ax, var@resMulInteger
IMUL ax, @cte2
MOV @aux_3, ax
;FINAL MUL INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @aux_3
MOV var@resMulInteger, dx
;FINAL ASIGNACION INTEGER
;INICIO DIV INTEGER
;INICIO CHEQUEO CERO INTEGER
CMP @cte2, 0
JE divZero
;FINAL CHEQUEO CERO INTEGER
MOV dx, 0
MOV ax, var@resDivInteger
IDIV @cte2
MOV @aux_4, ax
;FINAL DIV INTEGER
;INICIO ASIGNACION INTEGER
MOV dx, @aux_4
MOV var@resDivInteger, dx
;FINAL ASIGNACION INTEGER
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL INTEGER
MOV ax, var@resSumaInteger
CMP ax, @cte4
JNE @label_1
;FIN COMP IGUAL INTEGER
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena7, addr @cadena7, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_2
@label_1:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena6, addr @cadena6, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_2:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL INTEGER
MOV ax, var@resRestaInteger
CMP ax, @cte5
JNE @label_3
;FIN COMP IGUAL INTEGER
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena5, addr @cadena5, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_4
@label_3:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena4, addr @cadena4, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_4:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO CONV INTEGER A DOUBLE
FILD var@resMulInteger
FSTP @aux_5
;FINAL CONV INTEGER A DOUBLE
;INICIO COMP IGUAL DOUBLE
FLD @aux_5
FCOMP @cte1
FSTSW ax
SAHF
JB @label_5
JA @label_5
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena3, addr @cadena3, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_6
@label_5:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena2, addr @cadena2, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_6:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO CONV INTEGER A DOUBLE
FILD var@resDivInteger
FSTP @aux_6
;FINAL CONV INTEGER A DOUBLE
;INICIO COMP IGUAL DOUBLE
FLD @aux_6
FCOMP @cte3
FSTSW ax
SAHF
JB @label_7
JA @label_7
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena1, addr @cadena1, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_8
@label_7:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_8:
;FIN IF
invoke ExitProcess, 0
end start