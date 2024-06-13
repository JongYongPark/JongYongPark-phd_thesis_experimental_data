% http://www.sharetechnote.com/

clear all; close all; clc;

% ================================
x = [0 1 0 1 0 1];
 
sf = 20; % samples per bit
p_x = x;
 
if sf > 1
   for i = 2:sf
    p_x= [p_x ; x];
   end
 
   p_x = reshape(p_x,[],1);
end
 
a = 0.5;
%pjr add
loss = 0.5;

t = 0:10;
k = 0.3;
%chan = 0.5*exp(-k*t); % this is to create the characteristic response (impulse response) of a channel
chan = a*exp(-k*t); % this is to create the characteristic response (impulse response) of a channel
chan = chan/sum(chan);

%pjr add
chan = chan * loss;

w = conv(p_x,chan); % this create the distorted signal by convoluting the original signal and the channel
y = deconv(w,chan); % this recovers the original signal by decovoluting the distorted signal and the channel
 
subplot(2,5,[1 2]);stem(w);axis([1 length(w) -1.5 1.5]);title("rx signal");
subplot(2,5,3);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -0.5 0.5]);title("chan");
subplot(2,5,[4 5]);stem(y);axis([1 length(y) -1.5 1.5]);title("deconvoluted signal");
subplot(2,5,[6 7]);plot(w);axis([1 length(w) -1.5 1.5]);title("rx signal");
subplot(2,5,8);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -0.5 0.5]);title("chan");
subplot(2,5,[9 10]);plot(y);axis([1 length(y) -1.5 1.5]);title("deconvoluted signal");
 
% ================================
% ================================
% ================================