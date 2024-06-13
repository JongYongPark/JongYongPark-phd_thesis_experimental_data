clear all; clc; close all;

echo off all
%e cho on all % ???? ???? ?? ???
%e cho on;

%print("======================\n");
syms x  theta
n = 2
a = 2
b = 1

diff(x^n)
diff(x^(-1))
diff(n^x)
diff(sin(a*theta+b))
diff(exp(-x^2))
diff(1/(1+x^2))


int(x^n)
int(x^(-1))
int(n^x)
int(sin(a*theta+b))
int(exp(-x^2))
int(1/(1+x^2))

k = sym(1/sqrt(2));
f = exp(-(k*x)^2);
ezplot(f)

syms k real % Be sure that x has been declared a sym.
y = int(f,x,-inf,inf)
simplify(y)
clear k
syms k unreal

syms w x y z real

syms k x
f = exp(-k*x)

int(f) 
int(f,k)
int(f,x,0,1)

syms k real
g = exp(-(k*x)^2)

int(g,x,-inf,inf)

syms x
g = exp(x*sin(x))
t = taylor(g,12,2)



collect((x-1)*(x-2)*(x-3))
expand((x-1)*(x-2)*(x-3))
factor(x^3 - 6*x^2 + 11*x - 6)

simplify(cos(x)^2 + sin(x)^2)
radsimp(cos(x)^2 + sin(x)^2)
combine(cos(x)^2 + sin(x)^2)
factor(cos(x)^2 + sin(x)^2)
convert(cos(x)^2 + sin(x)^2,exp)
