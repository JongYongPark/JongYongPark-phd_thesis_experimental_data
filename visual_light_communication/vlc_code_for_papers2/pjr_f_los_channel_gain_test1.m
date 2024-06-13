%Program 3.1: MATLAB Codes to Calculate the LOS Channel Gain
clear all; close all; clc;


theta=70;
% semi-angle at half power

P_total=20;
%transmitted optical power by individual LED

Adet=1e-4;
%detector physical area of a PD

Ts=1;
%gain of an optical filter; ignore if no filter is used

index=1.5;
%refractive index of a lens at a PD; ignore if no lens is used

FOV_deg = 60;
%FOV of a receiver

lx=5; ly=5; lz=3;
% room dimension in metre

h=2.15;
%the distance between source and receiver plane

%[XT,YT]=meshgrid([-1.25 1.25],[-1.25 1.25]);

XT=0; YT=0;
XT1=1; YT1=0;
XT2=-1; YT2=0;
% position of LED;

Nx=lx*10; Ny=ly*10;
% number of grid in the receiver plane

%[x,y,P_rec] = f_los_channel_gain(theta,P_total,Adet,Ts,index,FOV_deg, lx, ly, lz, h, XT,YT,Nx,Ny );
%[x,y,P_rec1] = f_los_channel_gain(theta,P_total,Adet,Ts,index,FOV_deg, lx, ly, lz, h, XT1,YT1,Nx,Ny );
[x,y,P_rec2,XR,YR] = pjr_f_los_channel_gain(theta,P_total,Adet,Ts,index,FOV_deg, lx, ly, lz, h, XT2,YT2,Nx,Ny );

P_rec_dBm=10*log10(P_rec2);

meshc(x,y,P_rec_dBm);
xlabel('X (m)');
ylabel('Y (m)');
zlabel('Received power (dBm)');
axis([-lx/2 lx/2 -ly/2 ly/2 min(min(P_rec_dBm)) max(max(P_rec_dBm))]);

formatSpec = 'theta=%d;Ptotal=%d;FOVdeg=%d;lx=%d;ly=%d;lz=%d;h=%d;';
str = sprintf(formatSpec,theta,P_total,FOV_deg,lx,ly,lz,h);
title({'Program 3.1: MATLAB Codes to Calculate the LOS Channel Gain', str})

%title({'Program 3.1: MATLAB Codes to Calculate the LOS Channel Gain', 'theta=70;Ptotal=20;FOV=60;lx=5;ly=5;lz=3;h=2.15;'})

