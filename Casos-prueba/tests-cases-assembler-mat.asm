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
@cadena2 db "cargo 3 en 1,1 !!!", 0
@cadena3 db "cargo 6 en 1,0 !!!", 0
@cadena4 db "termino", 0
@cte0 dw 0
@cte1 dw 1
@cte2 dd 1.000000
@cte3 dd 2.000000
@cte4 dd 3.000000
@cte5 dd 6.000000
@aux_0 dd ?
@aux_1 dd ?
@aux_10 dd ?
@aux_11 dd ?
@aux_12 dd ?
@aux_13 dd ?
@aux_14 dd ?
@aux_2 dd ?
@aux_3 dd ?
@aux_4 dd ?
@aux_5 dd ?
@aux_6 dd ?
@aux_7 dd ?
@aux_8 dd ?
@aux_9 dd ?

mat@matDou dd 4 DUP(?)
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
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 2
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
;INICIO SUMA DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 2
ADD ax, @cte0
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_2, eax
FLD @aux_2
FADD @cte2
FST @aux_3
;FINAL SUMA DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_3
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 2
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
;INICIO MUL DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 2
ADD ax, @cte0
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_5, eax
FLD @aux_5
FMUL @cte4
FST @aux_6
;FINAL MUL DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_6
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 2
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
;INICIO DIV DOUBLE
;INICIO CHQUEO CERO DOUBLE
FLDZ 
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 2
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
FCOM
FSTSW ax
SAHF
JE divZero
;FINAL CHEQUEO CERO DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 2
ADD ax, @cte1
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
FDIV ST, ST(1)
FST @aux_10
;FINAL DIV DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @aux_10
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 2
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
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 2
ADD ax, @cte0
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
FCOM @cte2
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
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 2
ADD ax, @cte0
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_12, eax
FLD @aux_12
FCOM @cte3
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
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte0
IMUL ax, 2
ADD ax, @cte1
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_13, eax
FLD @aux_13
FCOM @cte5
FSTSW ax
SAHF
JB @label_3
JA @label_3
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena3, addr @cadena3, MB_OK
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
MOV ax, @cte1
CMP ax, 2
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
MOV ax, @cte1
IMUL ax, 2
ADD ax, @cte1
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV eax, [ebx]
MOV @aux_14, eax
FLD @aux_14
FCOM @cte4
FSTSW ax
SAHF
JB @label_4
JA @label_4
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena2, addr @cadena2, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
@label_4:
;FIN IF
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena4, addr @cadena4, MB_OK
;FINAL PRINT
invoke ExitProcess, 0
end start