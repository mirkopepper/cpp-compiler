.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "termino", 0
@cadena1 db "ax es igual a 2", 0
@cte0 dw 0
@cte1 dw 1
@cte2 dw 2
@cte3 dd 2.000000
@aux_0 dd ?
@aux_1 dd ?

mat@matDou dd 6 DUP(?)
mat@matDou1 dd 6 DUP(?)
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
;INICIO ASIGNACION DOUBLE
FLD @cte3
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte2
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
;FILAS!!!!!!!!!!!!!!!!
MOV ax, @cte0
IMUL ax, 3
ADD ax, @cte2
;-------------------------------
CMP ax, 2
JNE label_1
invoke MessageBox, NULL, addr @cadena1, addr @cadena1, MB_OK
label_1:
;-------------------------------
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
FLD @cte3
;INICIO CHEQUEO LIMITES ARRAY
MOV ax, @cte0
CMP ax, 2
JGE matrixOutOfRange
MOV ax, @cte2
CMP ax, 3
JGE matrixOutOfRange
;FIN CHEQUEO LIMITES ARRAY
;INICIO CALCULO POS ARRAY
;COLUMNAS!!!!!!!!!!!!!!!!
MOV ax, @cte2
IMUL ax, 2
ADD ax, @cte0
IMUL ax, 4
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matDou1
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
FSTP DWORD PTR [ebx]
;FINAL ASIGNACION DOUBLE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
invoke ExitProcess, 0
end start