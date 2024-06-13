% for my project

clear all;
close all;
%Nb is the number of bits to be transmitted
%Nb=10000; % org
Nb=100;
% Generate Nb bits randomly
b=rand(1,Nb)>0.5;  % [0,1] - 1 * Nb bit

%Rb is the bit rate in bits/second
Rb=10;

%Since each waveform is represented by 10 samples so sampling
%frequency is 10 times the bit rate
sample_per_bit = 10;  % shobud be even value = x%2 = 0
fs=sample_per_bit * Rb;
Manchester_out=[];

%Vp is the peak voltage +v of the waveform
Vp=3;
%Here we encode input bitstream as Bipolar NRZ-L waveform

% size(b,2) = num of demention of column = 100
% size(b,1) = num of demention of row = 1
 

%Here we encode input bitstream as Manchester-L waveform
for index=1:size(b,2)
 if b(index)==1
 Manchester_out=[Manchester_out [ ones(1,sample_per_bit/2) zeros(1,sample_per_bit/2) ]*Vp];
 elseif b(index)==0
 Manchester_out=[Manchester_out [ zeros(1,sample_per_bit/2) ones(1,sample_per_bit/2)  ]*Vp];
 end
end
 
%Now we draw the PSD spectrum of Manchester-L using Welch PSD
%estimation method
stem_div = 10 ; %org 
%stem_div = 10000;
h = spectrum.welch;
Hpsd=psd(h,Manchester_out,'Fs',fs);
handle3=plot(Hpsd)
set(handle3,'LineWidth',2.5,'Color','k')
legend('Unipolar NRZ Manchester');
hold off;


figure;
new_X = (1:Nb*sample_per_bit)/stem_div;
%hold on;
subplot(3,1,1);
plot(new_X,Manchester_out);
%xlabel('bits-->');
ylabel('Amplitude (volts)','FontSize',8);
title('Manchester NRZ encoded bit stream');
xlim([0,10]);
%hold off;

suptitle('Lide Code >> encoded bit stream')

