.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "la division entre doubles no funciona", 0
@cadena1 db "la division entre doubles se efectuo de manera exitosa", 0
@cadena2 db "la multiplicacion entre doubles no funciona", 0
@cadena3 db "la multiplicacion entre doubles se efectuo de manera exitosa", 0
@cadena4 db "la resta entre doubles no funciona", 0
@cadena5 db "la resta entre doubles se efectuo de manera exitosa. Tambien la conversion funciona", 0
@cadena6 db "la suma entre doubles no funciona", 0
@cadena7 db "la suma entre doubles se efectuo de manera exitosa. Tambien la conversion funciona", 0
@cte0 dd 1.000000
@cte1 dd 10.000000
@cte2 dd 2.000000
@cte3 dw 3
@cte4 dd 3.000000
@cte5 dw 4
@cte6 dw 5
@cte7 dw 6
@aux_0 dd ?
@aux_1 dd ?
@aux_2 dd ?
@aux_3 dd ?
@aux_4 dd ?
@aux_5 dd ?
@aux_6 dd ?
@aux_7 dd ?
@aux_8 dd ?

var@resDivDouble dd ?
var@resMulDouble dd ?
var@resRestaDouble dd ?
var@resSumaDouble dd ?
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
;INICIO CONV INTEGER A DOUBLE
FILD @cte3
FSTP @aux_0
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_0
FSTP DWORD PTR var@resSumaDouble
;FINAL ASIGNACION DOUBLE
;INICIO CONV INTEGER A DOUBLE
FILD @cte5
FSTP @aux_1
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_1
FSTP DWORD PTR var@resRestaDouble
;FINAL ASIGNACION DOUBLE
;INICIO CONV INTEGER A DOUBLE
FILD @cte6
FSTP @aux_2
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_2
FSTP DWORD PTR var@resMulDouble
;FINAL ASIGNACION DOUBLE
;INICIO CONV INTEGER A DOUBLE
FILD @cte7
FSTP @aux_3
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_3
FSTP DWORD PTR var@resDivDouble
;FINAL ASIGNACION DOUBLE
;INICIO SUMA DOUBLE
FLD var@resSumaDouble
FADD @cte0
FSTP @aux_4
;FINAL SUMA DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_4
FSTP DWORD PTR var@resSumaDouble
;FINAL ASIGNACION DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO CONV INTEGER A DOUBLE
FILD @cte5
FSTP @aux_5
;FINAL CONV INTEGER A DOUBLE
;INICIO COMP IGUAL DOUBLE
FLD var@resSumaDouble
FCOMP @aux_5
FSTSW ax
SAHF
JB @label_1
JA @label_1
;FINAL COMP IGUAL DOUBLE
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
;INICIO ASIGNACION RESTA DOUBLE
FLD var@resRestaDouble
FSUB @cte0
FSTP DWORD PTR var@resRestaDouble
;FINAL ASIGNACION RESTA DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO CONV INTEGER A DOUBLE
FILD @cte3
FSTP @aux_6
;FINAL CONV INTEGER A DOUBLE
;INICIO COMP IGUAL DOUBLE
FLD var@resRestaDouble
FCOMP @aux_6
FSTSW ax
SAHF
JB @label_3
JA @label_3
;FINAL COMP IGUAL DOUBLE
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
;INICIO MUL DOUBLE
FLD var@resMulDouble
FMUL @cte2
FSTP @aux_7
;FINAL MUL DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_7
FSTP DWORD PTR var@resMulDouble
;FINAL ASIGNACION DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@resMulDouble
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
;INICIO DIV DOUBLE
;INICIO CHQUEO CERO DOUBLE
FLD @cte2
FTST
FSTSW ax
SAHF
JE divZero
;FINAL CHEQUEO CERO DOUBLE
FLD var@resDivDouble
FDIV ST, ST(1)
FSTP @aux_8
;FINAL DIV DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_8
FSTP DWORD PTR var@resDivDouble
;FINAL ASIGNACION DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@resDivDouble
FCOMP @cte4
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