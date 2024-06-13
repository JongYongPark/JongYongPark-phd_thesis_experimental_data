%% Generate Source Code for a Spring Mass Damper System
% This example shows how to generate C source code for a spring mass damper
% system that you can then build and run on a Raspberry Pi. 

% Copyright 2018 The MathWorks, Inc.

%% The Spring Mass Damper Model 
% The spring mass system with damping is a fundamental system in mechanics
% and dynamics. By using the equations of motion you can solve for
% the displacement of the mass in response to different initial conditions
% and external forces. 
%
% The function |springMassEqns| encodes the equations 
% of motion in the form of two first order linear differential equations. 
% The variables |dxdt(1)| and
% |dxdt(2)| are the velocity and the acceleration of the mass,
% respectively. The variable |x(1)| represents the position of the mass.
%
% <include>springMassEqns.m</include>
%
%% MATLAB Algorithm
% To simulate the displacement as a function of time, the function
% |springMassStep| applies the ODE solver |ode45| to the equations of motion.
%
% <include>springMassStep.m</include>
%
%%
% The |springMassTakeStep| function calls the |springMassStep| function and returns
% the final displacement at the end of a fixed time interval. 
%
% <include>springMassTakeStep.m</include>
%
%% Algorithm Results
% To understand typical behavior of the model and the algorithm, the
% script |springMassSim| simulates the system over a typical parameter range.
% The output results show the displacement of the mass as a function of
% time. You can adjust the initial conditions, model parameters, and forcing
% function to see how the model responds.

springMassSim

%% Generate C Source Code
% After verifying that the MATLAB model works as expected, generate C 
% source code for deployment.

xi = 0.5; 
vi = 0;
ti = 0; 
dt = .01;
g = 0;

cfg = coder.config('lib','ecoder',false);
cfg.GenCodeOnly = true;
cfg.HardwareImplementation.ProdHWDeviceType = 'ARM Compatible->ARM Cortex';
codegen springMassTakeStep -args {xi,vi,ti,dt,g} -config cfg -report


