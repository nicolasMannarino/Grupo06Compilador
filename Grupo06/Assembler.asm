include macros2.asm
include number.asm

.MODEL LARGE	; Modelo de Memoria
.386	        ; Tipo de Procesador
.STACK 200h		; Bytes en el Stack

.DATA 
var111                           dd                                                  
var11                            dd                                                  
var1                             dd                                                  
var2                             dd                                                  
var4                             dd                                                  
var3                             dd                                                  
_1                               dd                                                1 
_103                             dd                                              103 
_5                               dd                                                5 
_HolaMundo                       dd                                        HolaMundo 
_16                              dd                                               16 
_9999999999999999999999999.99    dd                     9999999999999999999999999.99 
_1111                            dd                                             1111 
_3                               dd                                                3 
_2                               dd                                                2 
_12                              dd                                               12 
_48                              dd                                               48 
_2.3                             dd                                              2.3 
_1.22                            dd                                             1.22 

.CODE

.mov AX,@DATA
mov DS,AX
mov es,ax ;

FLD 1
FSTP var1
FLD 103 
FLD 1
FADD 
FLD 5
FADD 
FSTP var1
READ var3 
WRITE HolaMundo 
WRITE var1 
FLD var1 
FCOMP var11 
FSTSW ax 
FSHF 
JAE finIf
FLD 16
FSTP var1
READ var3 
WRITE var1 
FLD 9999999999999999999999999.99
FSTP var111
FLD var1
FSTP var111
FLD var11
FSTP var111
FLD var4
FSTP var3
FLD 1111
FSTP var11
FLD 6.000000
FSTP var111
FLD 2 
FLD var111 
FSUB 
FLD 3 
FLD var111 
FMUL 
FLD 1
FSTP var111
FLD var111
FSTP var111

mov ax,4c00h
int 21h

End