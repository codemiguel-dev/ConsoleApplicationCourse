@echo off
:start
cls
echo Calculadora Simple
set /p num1=Introduce el primer n�mero: 
set /p op=Introduce la operaci�n (+, -, *, /): 
set /p num2=Introduce el segundo n�mero: 
set /a result=num1 %op% num2
echo El resultado es: %result%
set /p choice=�Quieres realizar otro c�lculo? (s/n): 
if /i "%choice%"=="s" goto start
exit
