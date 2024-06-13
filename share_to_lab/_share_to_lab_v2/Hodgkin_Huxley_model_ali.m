%===============================  NERVE ACTION POTENTIAL SIMULATION ========================================
% A Quantitative Description of  Membrane Current and its Application to Conduction and Excitation in Nerve
%Hodgkin Huxley Model (Nobel Prize 1963)
% Simulation of Hodgkin Huxley Model
% Assumption: I am not taking into account Leakage Current
% ALIARSHAD KOTHAWALA
% IIT-MADRAS,INDIA
%============================================================================================================
close all;clear all;clc;
%============================================================================================================
%                                         Given Parameters for simulation
%============================================================================================================
E_rest=-68;
E_K=-74.7;
E_Na=54.2;
C=1;
G_K=12;
G_Na=30;
n_init=0.3;
m_init=0.065;
h_init=0.6;
%==========================================================================================================
%                                          Determining the Initial values
%                                             Set the initial states
%===========================================================================================================
V =0; % baseline voltage
alpha_n=0.01*(10-V)/(exp((10-V)/10)-1);
beta_n=0.125*exp(-V/80);
alpha_m=0.1*(25-V)/(exp((25-V)/10)-1);
beta_m=4*exp(-V/18);
alpha_h=0.07*exp(-V/20);
beta_h=1/(exp((30-V)/10)+1);
n(1)=alpha_n/(alpha_n+beta_n);
m(1)=alpha_m/(alpha_m+beta_m);
h(1)=alpha_h/(alpha_h+beta_h);
%=========================================================================================================
%                                  Defining the time vector for simulation
%===========================================================================================================
Total_time=10;  %10 ms
deltaT=0.01;
t=0:deltaT:Total_time;
%============================================================================================================
%                                               Defining the Current
%===============================================================================================================
I=zeros(1,numel(t));
I(1,1:80)=75; % % micro amp current

%===========================================================================================================
%                            Computing coefficients, currents, and derivates at each time step
%===========================================================================================================
for i=1:numel(t)-1

    %---calculate the coefficients---%

    %Equations here are same as above, just calculating at each time step
    alpha_n(i) = .01 * ( (10-V(i)) / (exp((10-V(i))/10)-1) );
    beta_n(i) = .125*exp(-V(i)/80);
    alpha_m(i) = .1*( (25-V(i)) / (exp((25-V(i))/10)-1) );
    beta_m(i) = 4*exp(-V(i)/18);
    alpha_h(i) = .07*exp(-V(i)/20);
    beta_h(i) = 1/(exp((30-V(i))/10)+1);


    %---calculate the currents---%

    I_Na = (m(i)^3) *G_Na * h(i) * (V(i)-E_Na); %Equations 3 and 14
    I_K = (n(i)^4) * G_K * (V(i)-E_K); %Equations 4 and 6
    I_ion = I(i) - I_K - I_Na ;

    %---calculate the derivatives using Euler first order approximation---%
    V(i+1) = V(i) + deltaT*I_ion/C;
    n(i+1) = n(i) + deltaT*(alpha_n(i) *(1-n(i)) - beta_n(i) * n(i)); %Equation 7
    m(i+1) = m(i) + deltaT*(alpha_m(i) *(1-m(i)) - beta_m(i) * m(i)); %Equation 15
    h(i+1) = h(i) + deltaT*(alpha_h(i) *(1-h(i)) - beta_h(i) * h(i)); %Equation 16

end

V = V-70; %Set resting potential to -70mv


%============================================================================================================
                                                 % Plot the Voltage
%============================================================================================================
plot(t,V,'LineWidth',3)
hold on
legend({'Voltage'})
ylabel('Voltage (mV)')
xlabel('time (ms)')
title('Volatge over time in simulated neuron');
%============================================================================================================
                                                 %Plot the Conductance
%============================================================================================================
figure
p1 = plot(t,G_K*n.^4,'m','LineWidth',2);
hold on
p2 = plot(t,G_Na*(m.^3).*h,'g','LineWidth',2);
legend([p1, p2], 'Conductance for Potassium', 'Conductance for Sodium')
ylabel('Conductance')
xlabel('time (ms)')
title('Conductance for Potassium and Sodium Ions in Simulated Neuron')
 

% Published with MATLAB® R2014a