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
