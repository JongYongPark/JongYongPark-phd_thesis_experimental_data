function dxdt = springMassEqns(t,x,x0,k,m,c,F)
dxdt = zeros(2,1);
dxdt(1) = x(2);
dxdt(2) = F/m - k/m*(x(1)-x0) - c/m*x(2);
