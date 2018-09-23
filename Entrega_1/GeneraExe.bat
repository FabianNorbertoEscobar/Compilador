flex Lexico.l
pause
bison -dyv Sintactico.y
pause
gcc lex.yy.c y.tab.c -o Primera.exe
pause
Primera.exe Prueba.txt
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del Primera.exe
del tiraDeTokens.txt
del ts.txt
pause