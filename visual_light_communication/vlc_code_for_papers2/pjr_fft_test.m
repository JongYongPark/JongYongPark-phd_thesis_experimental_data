clear all; clc; close all;


%{
http://blog.naver.com/PostView.nhn?blogId=horgan&logNo=40011894016

Matlab을 이용한 FFT의 올바른 이해  Matlab ( 매트랩 )   
2005. 4. 5. 20:33
복사http://blog.naver.com/horgan/40011894016
번역하기
첨부파일 (2)

공학에서 FFT만큼 많이 나오는 용어도 흔치 않으리라 보입니다. 왜냐하면 공학에서 현상을 해석할 때에는 시간에 대한 해석 뿐만이 아니라 주파수에 대한 해석도 병행하기 때문입니다.(근래에는 두가지 영역을 동시에 해석하려는 시도도 나오고 있습니다.) 그런데 대다수의 사람들이 FFT를 많이들 어려워합니다. 본 강의는 FFT의 특성을 Matlab™ 을 통해 그래픽적으로 분석함으로서 정확한 FFT의 이해를 목적으로 합니다.먼저 강의를 진행하기 전에 일러둘 것이 있습니다. 강의에서 다룰 것은 실제적으로는 DFT(Discrete Fourier Transform)라는 것입니다.DFT는 FFT와 여러모로 유사하지만 다른 점이 있다면 FFT는 속도개선 차원의 알고리즘이 더 들어가 있다고 보시면 됩니다. FFT의 속도 향상에 관심이 있으신 분들은 다음 책과 사이트에서 도움을 받으실 수 있을 것입니다.
[출처] Matlab을 이용한 FFT의 올바른 이해|작성자 일편단심


%}

N=8;
fs=8000;
ts=1/fs;
for n=1:1:N
    x(n)=sin(2*pi*1000*(n-1)*ts)+0.5*sin(2*pi*2000*(n-1)*ts+3*pi/4);
end
for m=1:1:N
    temp=0;
    X=0;
    for n=1:1:N
        X=x(n)*(cos(2*pi*(n-1)*(m-1)/N)-j*sin(2*pi*(n-1)*(m-1)/N));
        X=X+temp;
        temp=X;
    end
    XX(m)=X;
end
m=0:1:N-1;
subplot(2,2,1)
stem(m,abs(XX));
subplot(2,2,2)
stem(m,phase(XX)*180/pi);




%Matlab Internal function(fft)
%figure


N=8;
%N=16;
%N=32;

fs=8000;
ts=1/fs;
for n=1:1:N
    x(n)=sin(2*pi*1000*(n-1)*ts)+0.5*sin(2*pi*2000*(n-1)*ts+3*pi/4);
end
XX=fft(x);    %% or, XX=fft(x,N);
m=0:1:N-1;
subplot(2,2,3)
stem(m,abs(XX));
subplot(2,2,4)
stem(m,phase(XX)*180/pi);


figure
Y=XX;
L=N;
Fs=fs;

P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs*(0:(L/2))/L;
subplot(2,2,1)
stem(f,P1) 
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')

subplot(2,2,2)
stem(f,phase(P1)*180/pi);

subplot(2,2,3)

fs = 100;
t = 0:1/fs:1-1/fs;
x = cos(2*pi*15*t - pi/4) - sin(2*pi*40*t);

y = fft(x);
z = fftshift(y);

ly = length(y);
f = (-ly/2:ly/2-1)/ly*fs;

stem(f,abs(z))
xlabel 'Frequency (Hz)'
ylabel '|y|'
grid

subplot(2,2,4)
tol = 1e-6;
z(abs(z) < tol) = 0;

theta = angle(z);

stem(f,theta/pi)
xlabel 'Frequency (Hz)'
ylabel 'Phase / \pi'
grid