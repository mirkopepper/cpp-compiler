.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "cargo 1 en 0,0 !!!", 0
@cadena1 db "cargo 2 en 0,1 !!!", 0
@cadena2 db "cargo 3 en 0,2 !!!", 0
@cadena3 db "cargo 4 en 1,0 !!!", 0
@cadena4 db "cargo 5 en 1,1 !!!", 0
@cadena5 db "cargo 6 en 1,2 !!!", 0
@cadena6 db "termino", 0
@cte0 dw 0
@cte1 dw 1
@cte2 dd 1.000000
@cte3 dw 2
@cte4 dd 2.000000
@cte5 dd 3.000000
@cte6 dd 4.000000
@cte7 dd 5.000000
@cte8 dd 6.000000
@aux_0 dd ?
@aux_1 dd ?
@aux_10 dd ?
@aux_11 dd ?
@aux_2 dd ?
@aux_3 dd ?
@aux_4 dd ?
@aux_5 dd ?
@aux_6 dd ?
@aux_7 dd ?
@aux_8 dd ?
@aux_9 dd ?

mat@matDou dd 6 DUP(?)
var@a dw ?
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
;INICIO ASIGNACION DOUBLE
FLD @cte2
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 3
ADD ax, @cte0
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
FSTP DWORD PTR [ebx]
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte4
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte1
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 3
ADD ax, @cte1
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
FSTP DWORD PTR [ebx]
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte5
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte3
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 3
ADD ax, @cte3
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
FSTP DWORD PTR [ebx]
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte6
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 3
ADD ax, @cte0
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
FSTP DWORD PTR [ebx]
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte7
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte1
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 3
ADD ax, @cte1
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
FSTP DWORD PTR [ebx]
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte8
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte3
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 3
ADD ax, @cte3
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
FSTP DWORD PTR [ebx]
;FINAL ASIGNACION DOUBLE
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 3
ADD ax, @cte0
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_6, eax
FLD @aux_6
FCOMP @cte2
FSTSW ax
SAHF
JB @label_1
JA @label_1
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
@label_1:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte1
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 3
ADD ax, @cte1
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_7, eax
FLD @aux_7
FCOMP @cte4
FSTSW ax
SAHF
JB @label_2
JA @label_2
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena1, addr @cadena1, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
@label_2:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte3
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 3
ADD ax, @cte3
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_8, eax
FLD @aux_8
FCOMP @cte5
FSTSW ax
SAHF
JB @label_3
JA @label_3
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena2, addr @cadena2, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
@label_3:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 3
ADD ax, @cte0
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_9, eax
FLD @aux_9
FCOMP @cte6
FSTSW ax
SAHF
JB @label_4
JA @label_4
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena3, addr @cadena3, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
@label_4:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte1
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 3
ADD ax, @cte1
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_10, eax
FLD @aux_10
FCOMP @cte7
FSTSW ax
SAHF
JB @label_5
JA @label_5
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena4, addr @cadena4, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
@label_5:
;FIN IF
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte3
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 3
ADD ax, @cte3
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_11, eax
FLD @aux_11
FCOMP @cte8
FSTSW ax
SAHF
JB @label_6
JA @label_6
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena5, addr @cadena5, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
@label_6:
;FIN IF
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena6, addr @cadena6, MB_OK
;FINAL PRINT
invoke ExitProcess, 0
end start