function [x] = springMassStep(xi,vi,ti,dt,g) %#codegen
% Set spring equilibrium position 
x0 = 1; 
% Set spring, mass, damper constants
k = 1000;
m = 10; 
c = 25; 
% Scale acceleration g like a gravity force
F = m*g;
% Solve ODE for displacement at ti + dt
initCond = [xi vi];
tspan = [ti ti+dt];
[~,x] = ode45(@(t,x) springMassEqns(t,x,x0,k,m,c,F),tspan,initCond);