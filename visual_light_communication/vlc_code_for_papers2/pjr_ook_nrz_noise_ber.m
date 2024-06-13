% *************** Simulation BER of OOK-NRZ transmission over noise ******%
% with using Monte Carlo simulation

% ********************* Initialization ***********************************%
clc;
clear all;
%close all;

Po=1;
R=1;
Tbs=1;
%M=100000;  % Frame length (x_1 x_2 ... x_M)
M=10;
SNRdB=0:10; % SNR in dB
SNR=10.^(SNRdB/10);
Rate= zeros(1, length(SNRdB)); % 

%debug_snr = true
debug_snr = false 

if debug_snr
    % SNR=10.^(SNRdB/10)  ==> SNDdB = 10log10(SNR)
    figure
    plot(SNR,SNRdB,'--')
    hold on
    plot(SNRdB,SNR,'--o')
    %text(.5,.5,'$\frac{v}{w} \sin(t)$','interpreter','latex','FontSize',18)
    grid on;
    return
end
% ********************* Transmitter **************************************%
for dB= 1: 1 %length(SNRdB) % start looping by SNR 
    %dB
% ********************* OOK-NRZ signal generation ************************%    
	x_inp=round(rand(1,M)); % 
    s=x_inp.*2*Po;
    Es=2*Po^2*R^2*Tbs; % Es=Eb
    sigma=sqrt(Es/(2*SNR(dB)));
% ********************* Channel ******************************************%
    %y_channel=awgn(s,SNRdB(dB));% Additive White Guassiann Noise (AWGN)
    y_channel=s+sigma.*randn(1,M);% Additive White Guassiann Noise (AWGN)
% ********************* Receiver *****************************************% 
    y=y_channel./(2*Po);
    x_out= round(y); % 
% ********************* Bit Error Rate (BER) calulation ******************%    
    [err, rate]= symerr(x_inp, x_out);
    Rate(dB)= Rate(dB) + rate;
    end % end for loop
    Rate(dB)= Rate(dB); % 
% ********************* Plot the simulation result ***********************%
    f1 = figure(1);
    set(f1,'color',[1 1 1]);
    semilogy(SNRdB,Rate, 'b-*')
    hold on;
    axis([0 12 0.0001  1]);  
    xlabel( 'Signal-to-Noise Ratio (SNR) dB')
    ylabel( 'Bit Error Rate (BER)')
    title('Simulation OOK-NRZ transmission over noise');
    legend('BER simulation')
    grid on;