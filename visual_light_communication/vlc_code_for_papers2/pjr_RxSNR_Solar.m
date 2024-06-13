function [x,y, P_rec, P_rec_dBm,P_block_total,H_A1 ] = pjr_RxSNR_solar(P_LED,theta,Adet_1d,block_1d,x_pos,y_pos,FOV_deg,lx,ly,lz,h )

% P_LED = 1
% theta = 7;
% P_block_total_sum =
%    1.0000
% theta = 30;
% theta = 90;
% P_block_total_sum =
%    0.3899
% 
% Adet_1d = 1e-1;
% x_pos=0;
% y_pos=0;
% 
% FOV_deg is meaning less for solar panel
% FOV_deg = 10
% FOV_deg=60
% FOV_deg=180
% lx=5; 
% ly=5;
% lz=3;
% h=2.15;
% block_1d = 10; % 10cm * 10 = 1m 

index=1;
m=-log10(2)/log10(cosd(theta));
Adet = Adet_1d^2; % 10cm*10cm
Ts=1;
FOV=FOV_deg*pi/180; 
%G_Con=(index^2)/sin(FOV);
G_Con = 1; % ignore it - this cause result more than p_LED
% position of LED;
%Nx=lx*grid_num; Ny=ly*grid_num;
% number of grid in the receiver plane
%x=-lx/2:lx/Nx:lx/2;
%y=-ly/2:ly/Ny:ly/2;
x = (-lx/2) + (Adet_1d/2) :  Adet_1d : (lx/2) - (Adet_1d/2);
y = (-ly/2) + (Adet_1d/2) :  Adet_1d : (ly/2) - (Adet_1d/2);

[XR,YR]=meshgrid(x,y);
D1=sqrt((XR-x_pos).^2+(YR-y_pos).^2+h^2);
cosphi_A1=h./D1;
H_A1=(m+1)*Adet.*cosphi_A1.^(m+1)./(2*pi.*D1.^2);
P_rec=P_LED.*H_A1.*Ts.*G_Con;

if (P_LED > 0) 
    P_rec_dBm=10*log10(P_rec);
else
    P_rec_dBm=P_rec;
    H_A1=P_rec;
end    
P_rec_sum = sum(sum(P_rec))

P_block_avg = blkproc(P_rec, [ block_1d , block_1d ], 'mean2')
P_block_avg_sum = sum(sum(P_block_avg))
P_block_total = P_block_avg * block_1d * block_1d;
P_block_total_sum = sum(sum(P_block_total))

