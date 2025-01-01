@echo off
:start
cls
echo Calculadora Simple
set /p num1=Introduce el primer número: 
set /p op=Introduce la operación (+, -, *, /): 
set /p num2=Introduce el segundo número: 
set /a result=num1 %op% num2
echo El resultado es: %result%
set /p choice=¿Quieres realizar otro cálculo? (s/n): 
if /i "%choice%"=="s" goto start
exit
