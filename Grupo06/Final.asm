include macros2.asm
include number.asm

.MODEL LARGE    ; Modelo de Memoria
.386            ; Tipo de Procesador
.STACK 200h     ; Bytes en el Stack

.DATA 
var111                           dd                                                ? 
var11                            dd                                                ? 
var1                             dd                                                ? 
var2                             dd                                                ? 
var4                             dd                                                ? 
var3                             dd                                                ? 
_1                               dd                                                1 
_103                             dd                                              103 
_5                               dd                                                5 
_HolaMundo                       db                                      "HolaMundo" 
_16                              dd                                               16 
_9999999999999999999999999_99    dd                     9999999999999999999999999.99 
_1111                            dd                                             1111 
_3                               dd                                                3 
_2                               dd                                                2 
_2_000000                        dd                                         2.000000 
_4_000000                        dd                                         4.000000 
_6_000000                        dd                                         6.000000 

.CODE

mov AX,@DATA
mov DS,AX
mov es,ax

FLD _1
FSTP var1
FLD _103
FLD _1
FADD 
FLD _5
FADD 
FSTP var1
displayString var3 
displayString _HolaMundo 
displayString var1 
FLD var1 
FCOMP var11 
FSTSW ax 
SAHF 
JB _parteVerdadera1
FLD var4 
FCOMP var3 
FSTSW ax 
SAHF 
JNA _parteVerdadera1
JMP _finIf1
_parteVerdadera1:
FLD _16
FSTP var1
displayString var3 
JMP _finElse1
_finIf1:
displayString var1 
FLD _9999999999999999999999999_99
FSTP var111
FLD var1
FSTP var111
_finElse1:
_inicioWhile0:
FLD var4 
FCOMP var3 
FSTSW ax 
SAHF 
JA _finWhile0
FLD var11
FSTP var111
FLD var4
FSTP var3
FLD _1111
FSTP var11
JMP _inicioWhile0
_finWhile0:
FLD _6_000000
FSTP var111

mov ax,4c00h
int 21h

END