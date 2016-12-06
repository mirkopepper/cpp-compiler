.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data
@cadena0 db "entro al else del if interior", 0
@cadena1 db "entro al then del if exterior", 0
@cadena2 db "entro al then del if interior", 0
@cadena3 db "entro whileExterior", 0
@cadena4 db "entro whileInterior", 0
@cadena5 db "if exterior entra al then con un while de 2 iteraciones anidado", 0
@cadena6 db "if interior", 0
@cadena7 db "salio if exterior", 0
@cadena8 db "salio if interior", 0
@cadena9 db "salio whileExterior", 0
@cadena10 db "salio whileInterior", 0
@cadena11 db "while exterior de 2 iteraciones con if anidado (1ra iteracion entra al then, en la 2da al else", 0
@cadena12 db "while interior", 0
@cte0 dd 1.000000
@cte1 dd 2.000000
@cte2 dd 3.000000
@cte3 dd 4.000000
@cte4 dd 5.000000

var@i dd 0
var@ifExterior dd 0
var@ifInterior dd 0
var@j dd 0
var@whileExterior dd 0
var@whileInterior dd 0
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
;INICIO ASIGNACION DOUBLE
FLD @cte0
FSTP var@i
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte1
FSTP var@j
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte2
FSTP var@whileExterior
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte3
FSTP var@ifExterior
;FINAL ASIGNACION DOUBLE
;INICIO ASIGNACION DOUBLE
FLD @cte4
FSTP var@whileInterior
;FINAL ASIGNACION DOUBLE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena11, addr @cadena11, MB_OK
;FINAL PRINT
;INICIO DE WHILE
@label_1:
;INICIO DE SENTENCIAS CONDICION WHILE
;INICIO COMP DISTINTO DOUBLE
FLD var@whileExterior
FCOM @cte0
FSTSW ax
SAHF
JE @label_2
;FINAL COM DISTINTO DOUBLE
;FIN DE SENTENCIAS CONDICION WHILE
;INICIO DE SENTENCIAS CUERPO WHILE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena3, addr @cadena3, MB_OK
;FINAL PRINT
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena6, addr @cadena6, MB_OK
;FINAL PRINT
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@whileExterior
FCOM @cte2
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
JMP @label_4
@label_3:
;INICIO BLOQUE ELSE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena0, addr @cadena0, MB_OK
;FINAL PRINT
;FIN BLOQUE ELSE
@label_4:
;FIN IF
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena8, addr @cadena8, MB_OK
;FINAL PRINT
;INICIO ASIGNACION RESTA DOUBLE
FLD var@whileExterior
FSUB var@i
FSTP var@whileExterior
;FINAL ASIGNACION RESTA DOUBLE
;FIN DE SENTENCIAS CUERPO WHILE
JMP @label_1
@label_2:
;FIN DE WHILE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena9, addr @cadena9, MB_OK
;FINAL PRINT
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena5, addr @cadena5, MB_OK
;FINAL PRINT
;INICIO DE IF
;INICIO DE COND IF
;INICIO COMP IGUAL DOUBLE
FLD var@ifExterior
FCOM @cte3
FSTSW ax
SAHF
JB @label_5
JA @label_5
;FINAL COMP IGUAL DOUBLE
;FIN DE COND IF
;INICIO BLOQUE THEN
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena1, addr @cadena1, MB_OK
;FINAL PRINT
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena12, addr @cadena12, MB_OK
;FINAL PRINT
;INICIO DE WHILE
@label_6:
;INICIO DE SENTENCIAS CONDICION WHILE
;INICIO COMP DISTINTO DOUBLE
FLD var@whileInterior
FCOM @cte2
FSTSW ax
SAHF
JE @label_7
;FINAL COM DISTINTO DOUBLE
;FIN DE SENTENCIAS CONDICION WHILE
;INICIO DE SENTENCIAS CUERPO WHILE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena4, addr @cadena4, MB_OK
;FINAL PRINT
;INICIO ASIGNACION RESTA DOUBLE
FLD var@whileInterior
FSUB var@i
FSTP var@whileInterior
;FINAL ASIGNACION RESTA DOUBLE
;FIN DE SENTENCIAS CUERPO WHILE
JMP @label_6
@label_7:
;FIN DE WHILE
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena10, addr @cadena10, MB_OK
;FINAL PRINT
;FIN BLOQUE THEN
@label_5:
;FIN IF
;INICIO PRINT
invoke MessageBox, NULL, addr @cadena7, addr @cadena7, MB_OK
;FINAL PRINT
invoke ExitProcess, 0
end start