clc;
clear all;
close all;

%??? ? ???? ??? ????.
% 3x^5 + ...
p = [3 0 -2 0 1 5];
%polyder? ???? ???? ?????. ??? ???.

q = polyder(p)
%    15     0    -6     0     1
% 15x^4

% https://kr.mathworks.com/help/matlab/examples/differential-equations.html
tspan = [0, 20];
y0 = [2; 0];
Mu = 1;
ode = @(t,y) vanderpoldemo(t,y,Mu);
[t,y] = ode45(ode, tspan, y0);

% Plot of the solution
plot(t,y(:,1))
xlabel('t')
ylabel('solution y')
title('van der Pol Equation, \mu = 1')