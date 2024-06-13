% https://kr.mathworks.com/matlabcentral/fileexchange/36046-lambertian-emission-of-1-led/content/Lambertian_1LED.m

clc;
clear all;
close all;

% Note that Transmitter == Tx and Reciever == Rx
% Positions are denoted as [x,y,z]


% Dimensions of the room

length = 10;							% Length of Room [m]
breadth = 10;						% Breadth of Room [m]
height = 5;					    	% height of Room [m]
Rx_height = 0;				     	% Height of the Reciever from ground of Room [m]





% Power emitted by LED (mW)
PLED = 30*4;    

% <Find out what is it called> ????
LED_VA = 60;

r_Rx = 0.5E-2;		% Radius of Receiver
% Detector area, Area_Rx (or photodiode active area) -- was ARX(temp info)
Area_Rx = pi*(r_Rx^2);

%FOV (field of view) of detector, psi_c
Rx_FOV = 60;
psi_c = (Rx_FOV*pi)/180;





% Let the position of Tx be Pos_Tx
Pos_Tx = [5 5 5];
% Let the position of Rx be Pos_Rx
i=0; j=0; k=0;

for i=0:1E-1:10
	for j=0:1E-1:10

	Pos_Rx = [i j k];

% Direction from Tx to Rx
DD_Tx_Rx = Pos_Rx - Pos_Tx;

% Direction from Rx to Tx
DD_Rx_Tx = Pos_Tx - Pos_Rx;


% Distance between Tx and Rx
R = sqrt((Pos_Tx(1,1) - Pos_Rx(1,1)).^2 +(Pos_Tx(1,2) - Pos_Rx(1,2)).^2 +(Pos_Tx(1,3) - Pos_Rx(1,3)).^2);


% Angle between plane (normal) of Tx and direction
Ntx = [0 0 -1];

Phi = acosd( dot(DD_Tx_Rx,Ntx)./(R.*(sqrt((Ntx(1,1)^2 + Ntx(1,2)^2 + Ntx(1,3)^2)))));

% Angle between plane (normal) of Rx and direction
Rtx = [0 0 1];

Psi = acosd( dot(DD_Rx_Tx,Rtx)./(R.*(sqrt((Rtx(1,1)^2 + Rtx(1,2)^2 + Rtx(1,3)^2)))));


%angle of irradiance (half phi)
phi = (Phi*pi)/180;

%angle of incidence (half psi)
psi = (Psi*pi)/180;



%order of Lambertian emission
% m = real(-log(2)/log(cos(phi)));     % This looks faulty, as the 'phi-1/2' here should be the transmitter's semiangle (at half power)...
m=4;
% Lambertian radiant intensity (or transmitter radiant intensity)
Ro = real(((m+1)/(2*pi))*cos(phi)^m);


% Transmitted power, P_Tx   ---- previously PTX (temp)
P_Tx = PLED;


% LOS (line of sight) propagation path channel transfer function - HLOS
if (psi>=0) && (psi<=psi_c) && (Phi<=LED_VA)
    HLOS = (Area_Rx/R^2)*Ro*cos(psi);
elseif (psi>psi_c)
    HLOS = 0.0;
elseif (Phi>LED_VA)
    HLOS = 0.0;
elseif (Psi>Rx_FOV)||(Phi>Rx_FOV)
    HLOS = 0.0;
end;


%number of LEDs per led array - NoLEDs
NoLEDs = 1;
%total power of i LEDs in the directed path - PRXLOS
P_Rx_LOS = NoLEDs * P_Tx * HLOS;



		
		plot3(i,j,P_Rx_LOS,'.b');
		hold on;
		grid on;
	end
end