function [x,y, P_rec,XR,YR] = pjr_f_los_channel_gain(theta,P_total,Adet,Ts,index,FOV_deg, lx, ly, lz, h, XT,YT,Nx,Ny)
%f_los_channel_gain Summary of this function goes here
%   Detailed explanation goes here
% theta --- semi-angle at half power
% P_total --- transmitted optical power by individual LED
% Adet --- detector physical area of a PD
% Ts --- gain of an optical filter; ignore if no filter is used
% index --- refractive index of a lens at a PD; ignore if no lens is used
% FOV_deg --- FOV of a receiver in degree
% lx,ly,lz --- room dimension in metre
% h --- the distance between source and receiver plane


%[XT,YT]=meshgrid([-1.25 1.25],[-1.25 1.25]);
XT=0; YT=0;
% position of LED;

Nx=lx*10; Ny=ly*10;
% number of grid in the receiver plane

m=-log10(2)/log10(cosd(theta));
%Lambertian order of emission

FOV=FOV_deg*pi/180; %pjr - degree to radia
%FOV of a receiver

G_Con=(index^2)/sin(FOV);
%gain of an optical concentrator; ignore if no lens is used

x=-lx/2:lx/Nx:lx/2;
y=-ly/2:ly/Ny:ly/2;
[XR,YR]=meshgrid(x,y);
% receiver plane grid

D1=sqrt((XR-XT(1,1)).^2+(YR-YT(1,1)).^2+h^2);
% distance vector from source 1

cosphi_A1=h./D1;
% angle vector

H_A1=(m+1)*Adet.*cosphi_A1.^(m+1)./(2*pi.*D1.^2);
% channel DC gain for source 1
P_rec=P_total.*H_A1.*Ts.*G_Con;
% received power from source 1;

end