echo "Generando analizador lexico..."
flex Lexico.l
echo "Se genero el archivo lex.yy.c"
pause
echo "Generando analizador sintactico..."
bison -dyv Sintactico.y
echo "Se generaron los archivos y.output, y.tab.c y y.tab.h"
pause
echo "Compilando el compilador..."
gcc lex.yy.c y.tab.c -o Compilador.exe
echo "Compilador compilado exitosamente, para probarlo ejecute Prueba.bat"
pause