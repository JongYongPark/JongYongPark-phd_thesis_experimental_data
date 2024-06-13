clear all; clc; close all;

P_LED = 1
%theta = 7;
theta = 15;
%P_block_total_sum =
%    1.0000
%theta = 30;
%theta = 90;
%P_block_total_sum =
%    0.3899

Adet_1d = 1e-1;
%x_pos=0;
%y_pos=0;

% LED 1
x1_pos=-1;
y1_pos=-1;
P_LED1 = 1;
%P_LED1 = 0;
% LED 2
x2_pos=1;
y2_pos=-1;
P_LED2 = 1;
%P_LED2 = 0;
% LED 3
x3_pos=-1;
y3_pos=1;
%P_LED3 = 1;
P_LED3 = 0;
% LED 4
x4_pos=1;
y4_pos=1;
%P_LED4 = 1;
P_LED4 = 0;

%FOV_deg is meaning less for solar panel
%FOV_deg = 10
FOV_deg=60
%FOV_deg=180
lx=5; 
ly=5;
lz=3;
h=2.15;
block_1d = 10; % 10cm * 10 = 1m 

% if P_LED1 > 0 
    [x,y, P_rec1, P_rec_dBm1,P_block_total1,H_A1] = pjr_RxSNR_Solar(P_LED1,theta,Adet_1d,block_1d,x1_pos,y1_pos,FOV_deg,lx,ly,lz,h );
%     P_rec = P_rec1;
%     P_rec_dBm = P_rec_dBm1;
%     H_A = H_A1;
%     P_block_total = P_block_total1;
% end
% if P_LED2 > 0 
    [x,y, P_rec2, P_rec_dBm2,P_block_total2,H_A2] = pjr_RxSNR_Solar(P_LED2,theta,Adet_1d,block_1d,x2_pos,y2_pos,FOV_deg,lx,ly,lz,h );
%     P_rec = P_rec2;
%     H_A = H_A2;
%     P_block_total = P_block_total2;
% end 
% if P_LED3 > 0 
    [x,y, P_rec3, P_rec_dBm3,P_block_total3,H_A3] = pjr_RxSNR_Solar(P_LED3,theta,Adet_1d,block_1d,x3_pos,y3_pos,FOV_deg,lx,ly,lz,h );
%     P_rec = P_rec3
%     P_rec_dBm = P_rec_dBm3;
%     H_A = H_A3;
%     P_block_total = P_block_total3;
% end 
% if P_LED4 > 0 
    [x,y, P_rec4, P_rec_dBm4,P_block_total4,H_A4] = pjr_RxSNR_Solar(P_LED4,theta,Adet_1d,block_1d,x4_pos,y4_pos,FOV_deg,lx,ly,lz,h );
%     P_rec = P_rec4;
%     P_rec_dBm = P_rec_dBm4;
%     H_A = H_A4;
%     P_block_total = P_block_total4;
% end 

P_rec = P_rec1 + P_rec2 + P_rec3 + P_rec4;
P_rec_dBm = P_rec_dBm1 + P_rec_dBm2 + P_rec_dBm3 + P_rec_dBm4;
H_A = H_A1 + H_A2 + H_A3 + H_A4;
P_block_total = P_block_total1 + P_block_total2 + P_block_total3 + P_block_total4;

%%%%%%%%%%%% draw
figure
meshc(x,y,P_rec_dBm);
xlabel('X (m)');
ylabel('Y (m)');
zlabel('Received power (dBm)');
axis([-lx/2 lx/2 -ly/2 ly/2 min(min(P_rec_dBm)) max(max(P_rec_dBm))]);

formatSpec = 'theta=%d;Ptotal=%d;FOVdeg=%d;lx=%d;ly=%d;lz=%d;h=%d;';
str = sprintf(formatSpec,theta,P_LED,FOV_deg,lx,ly,lz,h);
title({'LOS Channel Gain - dBm', str})

%%%%%%%%%%%%%%%%%%%
figure
meshc(x,y,P_rec);
xlabel('X (m)');
ylabel('Y (m)');
zlabel('Received power ');
axis([-lx/2 lx/2 -ly/2 ly/2 min(min(P_rec)) max(max(P_rec))]);


formatSpec = 'theta=%d;Ptotal=%d;FOVdeg=%d;lx=%d;ly=%d;lz=%d;h=%d;';
str = sprintf(formatSpec,theta,P_LED,FOV_deg,lx,ly,lz,h);
title({'LOS Channel Gain', str})

%%%%%%%%%%%%%%%%%%%
figure
% mirror Y
P_block_total_flip = flipud(P_block_total);
h_p = bar3(P_block_total_flip);
hh_p = get(h_p(3),'parent');
set(hh_p,'yticklabel',[2 1 0 -1 -2 ]);
set(hh_p,'xticklabel',[-2 -1 0 1 2 ]);

figure
bar3(H_A1);
H_A1_flip = flipud(H_A);
h_h = bar3(H_A1_flip);
hh_h = get(h_h(3),'parent');

%xxx = (-lx/2) + (Adet_1d/2) :  Adet_1d : (lx/2) - (Adet_1d/2);
%yyy = (-ly/2) + (Adet_1d/2) :  Adet_1d : (ly/2) - (Adet_1d/2);
%set(hh_h,'yticklabel',yyy);
%set(hh_h,'xticklabel',xxx);

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%55
% % Speed of Light
% c = 300E6; 
% % Time
% t = 0:0.01:4;
% 
% Prx_max = max(max(P_rec));
% timefunction = t.*exp(-2.*t);
% %timefunction_book = 2t / (t^3 * sin(FOV)^2); 
% 
% frequencyfunction = 1./(2 + (1./t)).^2;
% impulse_response_t = conv(Prx_max,timefunction)*0.01;
% impulse_response_f = Prx_max.*frequencyfunction;
% 
% figure
% plot(t,impulse_response_t,'black')
% xlabel('Time (ns)')
% ylabel('Output Signal y(t)')
% title('y(t)=x(t)*h(t)')
% 
% figure
% plot(1./t,impulse_response_f,'black')
% xlabel(texlabel('Frequency (Hz) [10^8]')) %axis according to the speed of light [3E8 m/s]
% ylabel('Output Signal Y(w)')
% title('Y(w)=X(w)H(w)')
