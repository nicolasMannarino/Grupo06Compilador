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
JB parteVerdadera1
FLD var4 
FCOMP var3 
FSTSW ax 
FSHF 
JNA parteVerdadera1
JMP finIf1
parteVerdadera1
FLD 16
FSTP var1
READ var3 
JMP finElse1
finIf1
WRITE var1 
FLD 9999999999999999999999999.99
FSTP var111
FLD var1
FSTP var111
finElse1
inicioWhile0
FLD var4 
FCOMP var3 
FSTSW ax 
FSHF 
JA finWhile0
FLD var11
FSTP var111
FLD var4
FSTP var3
FLD 1111
FSTP var11
JMP inicioWhile0
finWhile0
FLD 6.000000
FSTP var111
