% https://www.diva-portal.org/smash/get/diva2:830371/FULLTEXT01.pdf

clc;
clear all;
close all;


%% Matlab file to model a lossy cable: 
clear all 
close all 
  
n=100; 
CC=(101e-12)*100/n; 
L=(252e-9)*100/n; 
R=50; 
R1=252e-6*100/n; 
G=101e-8*100/n; 
A=zeros((2*n),(2*n)); 
B=zeros((2*n),1); 
C=zeros(1,(2*n)); 
B((n+1),1)=1/L; 
C(1,n)=1; 
D=0; 
  
for i=1:n; 
    A(i,i)=-G/CC; 
    A(i,(n+i))=1/CC; 
    A((i+n),i)=-1/L; 
end; 
  
for i=1:(n-1); 
    A(i,(i+n+1))=-1/CC; 
    A((i+n+1),i)=1/L; 
end; 

for i=(n+2):2*n; 
    A(i,i)=-R1/L; 
end; 
A((n+1),(n+1))=-(R+R1)/L; 
  
C0=zeros(1,2*n); 
C0(1,1)=1; 
  
sim('endwith',0.000006); 
figure(1) 
plot(time,u0,'r'); 
hold on 
plot(time,u1,'b'); 
grid on,title('lossy cable'); 
grid on,title('lossy cable'); 
xlabel('time(s)'); 
ylabel('voltage(V)'); 
legend('input signal','output signal'); 

 
%%

 