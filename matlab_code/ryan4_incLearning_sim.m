% % https://kr.mathworks.com/help/coder/ug/deploy-generated-c-code-to-external-hardware-raspberry-pi-examples.html

%% Script to simulate spring mass code
% Set initial conditions
xi = 0.5; 
vi = 0;
ti = 0; 
gi = 0;

% Set time step and total time window
Tmax = 5;
dt = .01; 
N = Tmax/dt;

% Initialize output vectors
g = zeros(N,1);
x = zeros(N,1);
t = zeros(N,1);

% Iterate the code
for i = 1:N
    x(i) = xi;
    t(i) = ti;
    [xf, vf] = springMassTakeStep(xi,vi,ti,dt,gi);
    g(i) = -9.8; % set forcing function as desired
    gi = g(i);
    xi = xf; 
    vi = vf;
    ti = ti + dt;
end

% Plot displacement vs time results
plot(t,x(:,1));
xlabel('Time [s]')
ylabel('Displacement [m]')
grid on