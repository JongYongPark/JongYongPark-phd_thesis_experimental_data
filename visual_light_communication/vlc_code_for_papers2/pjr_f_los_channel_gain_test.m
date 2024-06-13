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
XT1=-2; YT1=0;
XT2=2; YT2=0;
% position of LED;

Nx=lx*10; Ny=ly*10;
% number of grid in the receiver plane

%[x,y,P_rec,XR,YR] = f_los_channel_gain(theta,P_total,Adet,Ts,index,FOV_deg, lx, ly, lz, h, XT,YT,Nx,Ny );
[x,y,P_rec,XR,YR] = pjr_f_los_channel_gain(theta,P_total,Adet,Ts,index,FOV_deg, lx, ly, lz, h, XT1,YT1,Nx,Ny );
%[x,y,P_rec,XR,YR] = f_los_channel_gain(theta,P_total,Adet,Ts,index,FOV_deg, lx, ly, lz, h, XT2,YT2,Nx,Ny );

P_rec_dBm=10*log10(P_rec);

figure
meshc(x,y,P_rec_dBm);
xlabel('X (m)');
ylabel('Y (m)');
zlabel('Received power (dBm)');
axis([-lx/2 lx/2 -ly/2 ly/2 min(min(P_rec_dBm)) max(max(P_rec_dBm))]);

formatSpec = 'theta=%d;Ptotal=%d;FOVdeg=%d;lx=%d;ly=%d;lz=%d;h=%d;';
str = sprintf(formatSpec,theta,P_total,FOV_deg,lx,ly,lz,h);
title({'Program 3.1: MATLAB Codes to Calculate the LOS Channel Gain', str})

%title({'Program 3.1: MATLAB Codes to Calculate the LOS Channel Gain', 'theta=70;Ptotal=20;FOV=60;lx=5;ly=5;lz=3;h=2.15;'})


figure
x=XR;
y=YR;
z=P_rec;
%x,y,z = XR,YR,P_rec;
surf(x,y,z);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
% http://www.peteryu.ca/tutorials/matlab/image_in_3d_surface_plot_with_multiple_colormaps

[x,y,z] = peaks;
%z = P_rec_dBm;
%z = P_rec;
 
% get the corners of the domain in which the data occurs.
min_x = min(min(x));
min_y = min(min(y));
max_x = max(max(x));
max_y = max(max(y));
 
% the image data you want to show as a plane.
planeimg = abs(z);
 
% set hold on so we can show multiple plots / surfs in the figure.
figure; hold on;
 
% do a normal surface plot.
surf(x,y,z);

% set a colormap (but this has no effect because the next colormap
% command overwrites it)
colormap(gray);
 
% desired z position of the image plane.
imgzposition = -10;
 
% plot the image plane using surf.
surf([min_x max_x],[min_y max_y],repmat(imgzposition, [2 2]),  planeimg,'facecolor','texture')
%surf(x,y,repmat(imgzposition, [2 2]),  planeimg,'facecolor','texture');
    
% set a colormap for the figure.
colormap(jet);
 
% set the view angle.
view(45,30);
 
% labels
 
xlabel('x');
ylabel('y');
zlabel('z');
