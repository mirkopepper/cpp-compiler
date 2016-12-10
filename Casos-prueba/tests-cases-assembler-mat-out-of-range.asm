.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "si se imprime esto, no funciona el chequeo por limites de arreglo", 0
@cte0 dw 1
@cte1 dw 2
@cte2 dw 3
@aux_0 dw ?

mat@matInt dw 4 DUP(?)
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
;INICIO ASIGNACION INTEGER
MOV dx, @cte2
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
IMUL ax, 2
;FIN CALCULO POS ARRAY
MOV ebx, OFFSET mat@matInt
MOV ecx, 0
MOV cx, ax
MOV eax, ecx
ADD ebx, eax
MOV [ebx], dx
;FINAL ASIGNACION INTEGER
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
invoke ExitProcess, 0
end start