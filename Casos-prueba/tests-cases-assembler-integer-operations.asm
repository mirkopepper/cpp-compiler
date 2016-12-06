.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "dosInteger: conversion en asignacion de double a entero correcta", 0
@cadena1 db "dosInteger: conversion en asignacion de double a entero incorrecta", 0
@cadena2 db "la division entre enteros no funciona", 0
@cadena3 db "la division entre enteros se efectuo de manera exitosa. Tambien la conversion funciona", 0
@cadena4 db "la multiplicacion entre enteros no funciona", 0
@cadena5 db "la multiplicacion entre enteros se efectuo de manera exitosa. Tambien la conversion funciona", 0
@cadena6 db "la resta entre enteros no funciona", 0
@cadena7 db "la resta entre enteros se efectuo de manera exitosa", 0
@cadena8 db "la suma entre enteros no funciona", 0
@cadena9 db "la suma entre enteros se efectuo de manera exitosa", 0
@cadena10 db "resRestaInteger: conversion en asignacion de double a entero correcta", 0
@cadena11 db "resRestaInteger: conversion en asignacion de double a entero incorrecta", 0
@cadena12 db "resSumaInteger: conversion en asignacion de double a entero correcta", 0
@cadena13 db "resSumaInteger: conversion en asignacion de double a entero incorrecta", 0
@cadena14 db "unoInteger: conversion en asignacion de double a entero correcta", 0
@cadena15 db "unoInteger: conversion en asignacion de double a entero incorrecta", 0
@cte0 dw 1
@cte1 dd 1.000000
@cte2 dd 100.000000
@cte3 dw 2
@cte4 dd 2.000000
@cte5 dw 30
@cte6 dd 30.000000
@cte7 dw 31
@cte8 dw 39
@cte9 dw 40
@cte10 dd 40.000000
@cte11 dw 50
@cte12 dw 60
@aux_0 dw 0
@aux_1 dw 0
@aux_2 dw 0
@aux_3 dw 0
@aux_4 dw 0
@aux_5 dw 0
@aux_6 dw 0
@aux_7 dd 0
@aux_8 dd 0

var@dosInteger dw 0
var@resDivInteger dw 0
var@resMulInteger dw 0
var@resRestaInteger dw 0
var@resSumaInteger dw 0
var@unoInteger dw 0
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
;INICIO CONV DOUBLE A INTEGER
;INICIO CHEQUEO POR RANGO POSITIVO
FLD @cte1
FIST @aux_0
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @aux_0
MOV var@unoInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO CONV DOUBLE A INTEGER
;INICIO CHEQUEO POR RANGO POSITIVO
FLD @cte4
FIST @aux_1
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @aux_1
MOV var@dosInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO CONV DOUBLE A INTEGER
;INICIO CHEQUEO POR RANGO POSITIVO
FLD @cte6
FIST @aux_2
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @aux_2
MOV var@resSumaInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO CONV DOUBLE A INTEGER
;INICIO CHEQUEO POR RANGO POSITIVO
FLD @cte10
FIST @aux_3
;FINAL CONV DOUBLE A INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @aux_3
MOV var@resRestaInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @cte11
MOV var@resMulInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @cte12
MOV var@resDivInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL INTEGER
MOV ax, var@unoInteger
CMP ax, @cte0
JNE @label_1
;INICIO COMP IGUAL INTEGER
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
;INICIO COMP IGUAL INTEGER
MOV ax, var@dosInteger
CMP ax, @cte3
JNE @label_3
;INICIO COMP IGUAL INTEGER
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
;INICIO COMP IGUAL INTEGER
MOV ax, var@resSumaInteger
CMP ax, @cte5
JNE @label_5
;INICIO COMP IGUAL INTEGER
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
;INICIO COMP IGUAL INTEGER
MOV ax, var@resRestaInteger
CMP ax, @cte9
JNE @label_7
;INICIO COMP IGUAL INTEGER
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
;INICIO SUMA INTEGER
MOV ax, var@resSumaInteger
ADD ax, var@unoInteger
MOV @aux_4, ax
;FINAL SUMA INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @aux_4
MOV var@resSumaInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO ASIGNACION RESTA INTEGER
MOV ax, var@resRestaInteger
SUB ax, var@unoInteger
MOV var@resRestaInteger, ax
;FINAL ASIGNACION RESTA INTEGER
;INICIO MUL INTEGER
MOV ax, var@resMulInteger
IMUL ax, var@dosInteger
MOV @aux_5, ax
;FINAL MUL INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @aux_5
MOV var@resMulInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO DIV INTEGER
;INICIO CHEQUEO CERO INTEGER
CMP var@dosInteger, 0
JE divZero
;FINAL CHEQUEO CERO INTEGER
MOV dx, 0
MOV ax, var@resDivInteger
IDIV var@dosInteger
MOV @aux_6, ax
;FINAL DIV INTEGER
;INICIO ASIGNACION INTEGER
MOV ax, @aux_6
MOV var@resDivInteger, ax
;FINAL ASIGNACION INTEGER
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL INTEGER
MOV ax, var@resSumaInteger
CMP ax, @cte7
JNE @label_9
;INICIO COMP IGUAL INTEGER
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
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL INTEGER
MOV ax, var@resRestaInteger
CMP ax, @cte8
JNE @label_11
;INICIO COMP IGUAL INTEGER
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
;INICIO DE IF
;INICIO DE COND IF
;INICIO CONV INTEGER A DOUBLE
FILD var@resMulInteger
FST @aux_7
;FINAL CONV INTEGER A DOUBLE
;INICIO COMP IGUAL DOUBLE
FLD @aux_7
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
;INICIO DE IF
;INICIO DE COND IF
;INICIO CONV INTEGER A DOUBLE
FILD var@resDivInteger
FST @aux_8
;FINAL CONV INTEGER A DOUBLE
;INICIO COMP IGUAL DOUBLE
FLD @aux_8
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