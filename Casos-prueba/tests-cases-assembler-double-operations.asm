.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "dosDouble: conversion en asignacion de entero a double correcta", 0
@cadena1 db "dosDouble: conversion en asignacion de entero a double incorrecta", 0
@cadena2 db "la division entre doubles no funciona", 0
@cadena3 db "la division entre doubles se efectuo de manera exitosa", 0
@cadena4 db "la multiplicacion entre doubles no funciona", 0
@cadena5 db "la multiplicacion entre doubles se efectuo de manera exitosa", 0
@cadena6 db "la resta entre doubles no funciona", 0
@cadena7 db "la resta entre doubles se efectuo de manera exitosa. Tambien la conversion funciona", 0
@cadena8 db "la suma entre doubles no funciona", 0
@cadena9 db "la suma entre doubles se efectuo de manera exitosa. Tambien la conversion funciona", 0
@cadena10 db "resDivDouble: conversion en asignacion de entero a double correcta", 0
@cadena11 db "resDivDouble: conversion en asignacion de entero a double incorrecta", 0
@cadena12 db "resMulDouble: conversion en asignacion de entero a double correcta", 0
@cadena13 db "resMulDouble: conversion en asignacion de entero a double incorrecta", 0
@cadena14 db "unoDouble: conversion en asignacion de entero a double correcta", 0
@cadena15 db "unoDouble: conversion en asignacion de entero a double incorrecta", 0
@cte0 dw 1
@cte1 dd 1.000000
@cte2 dd 10.000000
@cte3 dw 2
@cte4 dd 2.000000
@cte5 dw 3
@cte6 dd 3.000000
@cte7 dw 4
@cte8 dw 5
@cte9 dd 5.000000
@cte10 dw 6
@cte11 dd 6.000000
@aux_0 dd 0
@aux_1 dd 0
@aux_10 dd 0
@aux_2 dd 0
@aux_3 dd 0
@aux_4 dd 0
@aux_5 dd 0
@aux_6 dd 0
@aux_7 dd 0
@aux_8 dd 0
@aux_9 dd 0

var@dosDouble dd 0
var@resDivDouble dd 0
var@resMulDouble dd 0
var@resRestaDouble dd 0
var@resSumaDouble dd 0
var@unoDouble dd 0
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
;INICIO CONV INTEGER A DOUBLE
FILD @cte0
FST @aux_0
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_0
FSTP var@unoDouble
;FINAL ASIGNACION DOUBLE
;INICIO CONV INTEGER A DOUBLE
FILD @cte3
FST @aux_1
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_1
FSTP var@dosDouble
;FINAL ASIGNACION DOUBLE
;INICIO CONV INTEGER A DOUBLE
FILD @cte5
FST @aux_2
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_2
FSTP var@resSumaDouble
;FINAL ASIGNACION DOUBLE
;INICIO CONV INTEGER A DOUBLE
FILD @cte7
FST @aux_3
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_3
FSTP var@resRestaDouble
;FINAL ASIGNACION DOUBLE
;INICIO CONV INTEGER A DOUBLE
FILD @cte8
FST @aux_4
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_4
FSTP var@resMulDouble
;FINAL ASIGNACION DOUBLE
;INICIO CONV INTEGER A DOUBLE
FILD @cte10
FST @aux_5
;FINAL CONV INTEGER A DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_5
FSTP var@resDivDouble
;FINAL ASIGNACION DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@unoDouble
FCOM @cte1
FSTSW ax
SAHF
JB @label_1
JA @label_1
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena14, addr @cadena14, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_2
@label_1:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena15, addr @cadena15, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_2:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@dosDouble
FCOM @cte4
FSTSW ax
SAHF
JB @label_3
JA @label_3
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_4
@label_3:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena1, addr @cadena1, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_4:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@resMulDouble
FCOM @cte9
FSTSW ax
SAHF
JB @label_5
JA @label_5
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena12, addr @cadena12, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_6
@label_5:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena13, addr @cadena13, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_6:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@resDivDouble
FCOM @cte11
FSTSW ax
SAHF
JB @label_7
JA @label_7
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena10, addr @cadena10, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_8
@label_7:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena11, addr @cadena11, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_8:
;FIN IF
;INICIO SUMA DOUBLE
FLD var@resSumaDouble
FADD var@unoDouble
FST @aux_6
;FINAL SUMA DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_6
FSTP var@resSumaDouble
;FINAL ASIGNACION DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO CONV INTEGER A DOUBLE
FILD @cte7
FST @aux_7
;FINAL CONV INTEGER A DOUBLE
;INICIO COMP IGUAL DOUBLE
FLD var@resSumaDouble
FCOM @aux_7
FSTSW ax
SAHF
JB @label_9
JA @label_9
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena9, addr @cadena9, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_10
@label_9:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena8, addr @cadena8, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_10:
;FIN IF
;INICIO ASIGNACION RESTA DOUBLE
FLD var@resRestaDouble
FSUB var@unoDouble
FSTP var@resRestaDouble
;FINAL ASIGNACION RESTA DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO CONV INTEGER A DOUBLE
FILD @cte5
FST @aux_8
;FINAL CONV INTEGER A DOUBLE
;INICIO COMP IGUAL DOUBLE
FLD var@resRestaDouble
FCOM @aux_8
FSTSW ax
SAHF
JB @label_11
JA @label_11
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena7, addr @cadena7, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_12
@label_11:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena6, addr @cadena6, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_12:
;FIN IF
;INICIO MUL DOUBLE
FLD var@resMulDouble
FMUL var@dosDouble
FST @aux_9
;FINAL MUL DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_9
FSTP var@resMulDouble
;FINAL ASIGNACION DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@resMulDouble
FCOM @cte2
FSTSW ax
SAHF
JB @label_13
JA @label_13
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena5, addr @cadena5, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_14
@label_13:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena4, addr @cadena4, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_14:
;FIN IF
;INICIO DIV DOUBLE
;INICIO CHQUEO CERO DOUBLE
FLDZ 
FLD var@dosDouble
FCOM
FSTSW ax
SAHF
JE divZero
;FINAL CHEQUEO CERO DOUBLE
FLD var@resDivDouble
FDIV ST, ST(1)
FST @aux_10
;FINAL DIV DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_10
FSTP var@resDivDouble
;FINAL ASIGNACION DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@resDivDouble
FCOM @cte6
FSTSW ax
SAHF
JB @label_15
JA @label_15
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena3, addr @cadena3, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
JMP @label_16
@label_15:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena2, addr @cadena2, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_16:
;FIN IF
invoke ExitProcess, 0
end start