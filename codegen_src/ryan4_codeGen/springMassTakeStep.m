function [xf, vf] = springMassTakeStep(xi,vi,ti,dt,g) %#codegen
% Function springMassTakeStep acts as a wrapper for the ODE solving function, step.
% It takes the same input parameters as springMassStep, but only outputs the final 
% position and velocity. 
x = springMassStep(xi,vi,ti,dt,g);
xf = x(end,1);
vf = x(end,2);