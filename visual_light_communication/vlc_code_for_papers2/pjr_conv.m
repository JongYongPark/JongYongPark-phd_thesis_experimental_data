%% http://www.sharetechnote.com/

% https://www.sharetechnote.com/html/Communication_Convolution.html


%%

clear all; close all; clc;

%%

%{ 
https://en.wikipedia.org/wiki/Bit_rate#UNCODED

An exception from the above is some self-synchronizing line codes, for example Manchester coding and return-to-zero (RTZ) coding, where each bit is represented by two pulses (signal states), resulting in:

Gross bit rate  =  Symbol rate/2

https://en.wikipedia.org/wiki/Manchester_code


%}

%%

x = [0 1 0 1 0 1]; % Change this array if you want to change input sequence (transmitted data)
sf = 20; % samples per bit
p_x = x;

% conv_Identity(x,p_x,sf)
% conv_Reflection(x,p_x,sf)
% conv_Differentiator(x,p_x,sf)
% conv_Integrator(x,p_x,sf)

% conv_ExponentialDecaying(x,p_x,sf)

amplitude = 0.5;
loss = 0.5;
%pjr modify
%a = 0.1;
time_vector = 0:10;
k = 0.3;

conv_ExponentialDecaying_new(x,sf,amplitude,loss,k,time_vector)

%%
function conv_Identity(x,p_x,sf)

    if sf > 1
        for i = 2:sf
            p_x= [p_x ; x];
        end
        p_x = reshape(p_x,[],1);
    end
    chan = [0 0 0 0 1 0 0 0 0 0]; % Change this array if you want to change the characteristics of channel
    y = conv(p_x,chan);
    subplot(2,5,[1 2]);stem(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal");
    subplot(2,5,3);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -1.5 1.5]);title("chan");
    subplot(2,5,[4 5]);stem(y);axis([1 length(y) -1.5 1.5]);title("rx signal");
    subplot(2,5,[6 7]);plot(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal");
    subplot(2,5,8);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -1.5 1.5]);title("chan");
    subplot(2,5,[9 10]);plot(y);axis([1 length(y) -1.5 1.5]);title("rx signal");
end 

%% ================================

%Reflection (Echo)

function conv_Reflection(x,p_x,sf)

    if sf > 1
       for i = 2:sf
        p_x= [p_x ; x];
       end

       p_x = reshape(p_x,[],1);
    end

    chan = zeros(40,1);
    chan(1) = 1;
    chan(30) = 0.5;

    y = conv(p_x,chan);

    subplot(2,5,[1 2]);stem(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal");
    subplot(2,5,3);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -1.5 1.5]);title("chan");
    subplot(2,5,[4 5]);stem(y);axis([1 length(y) -1.5 1.5]);title("rx signal");
    subplot(2,5,[6 7]);plot(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal");
    subplot(2,5,8);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -1.5 1.5]);title("chan");
    subplot(2,5,[9 10]);plot(y);axis([1 length(y) -1.5 1.5]);title("rx signal");

end 

% ================================

% %Differentiator
%  
% x = [0 1 0 1 0 1 0];
%  
% sf = 20; % samples per bit
% p_x = x;

function conv_Differentiator(x,p_x,sf)

    if sf > 1
       for i = 2:sf
        p_x= [p_x ; x];
       end

       p_x = reshape(p_x,[],1);
    end

    chan = [0 1 -1 0 0 0 0 0 0 0];

    y = conv(p_x,chan);

    subplot(2,5,[1 2]);stem(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal");
    subplot(2,5,3);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -1.5 1.5]);title("chan");
    subplot(2,5,[4 5]);stem(y);axis([1 length(y) -1.5 15]);title("rx signal");
    subplot(2,5,[6 7]);plot(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal");
    subplot(2,5,8);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -1.5 1.5]);title("chan");
    subplot(2,5,[9 10]);plot(y);axis([1 length(y) -1.5 15]);title("rx signal");

end 
% ================================

function conv_Integrator(x,p_x,sf)

 
    if sf > 1
       for i = 2:sf
        p_x= [p_x ; x];
       end

       p_x = reshape(p_x,[],1);
    end

    chan = [0 1 1 1 1 1 1 1 1 1 1 1 1 1 1];

    y = conv(p_x,chan);

    subplot(2,5,[1 2]);stem(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal");
    subplot(2,5,3);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -1.5 1.5]);title("chan");
    subplot(2,5,[4 5]);stem(y);axis([1 length(y) -1.5 15]);title("rx signal");
    subplot(2,5,[6 7]);plot(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal");
    subplot(2,5,8);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -1.5 1.5]);title("chan");
    subplot(2,5,[9 10]);plot(y);axis([1 length(y) -1.5 15]);title("rx signal");

end 
%% ================================

%Exponential Decaying
%There would be no real system (no real channel) which is simple as simple as described above, but the example shown above would be a good example to help you understand very basic properties of Convolution.
%Now I will give you some examples with a little bit more complicated channels.
 
function conv_ExponentialDecaying(x,p_x,sf) 

% SymbolStream  SymbolRate ChannelProperty 

    if sf > 1
       for i = 2:sf
        p_x= [p_x ; x];
       end

       p_x = reshape(p_x,[],1);
    end

    a = 0.5;
    loss = 0.5;
    %pjr modify
    %a = 0.1;
    t = 0:10;
    k = 0.3;
    chan = a*exp(-k*t);  % Try applying different functions here.
    chan = [[0 0 0 0 0] chan];  % Change this array if you want to change the characteristics of channel
    chan_old = chan;
    chan_sum = sum(chan);
    %pjr comment out
    chan = chan/sum(chan);
    chan = chan * loss;
    y = conv(p_x,chan);


    subplot(2,5,[1 2]);stem(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal"); grid on
    subplot(2,5,3);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -0.5 0.5]);title("chan"); grid on
    subplot(2,5,[4 5]);stem(y);axis([1 length(y) -1.5 1.5]);title("rx signal"); grid on
    subplot(2,5,[6 7]);plot(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal"); grid on
    subplot(2,5,8);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -0.5 0.5]);title("chan"); grid on
    subplot(2,5,[9 10]);plot(y);axis([1 length(y) -1.5 1.5]);title("rx signal"); grid on
end
 
function out = vlc_sample_stream(x, sampleFreq)
    out = x;
    if sampleFreq > 1 
       for i = 2:sampleFreq
        out = [out ; x];
       end

       out = reshape(out,[],1);
    end
end 

function chan = vlc_cannel_property_stream( amplitude, loss, k, time_vector)
    chan = amplitude*exp(-k*time_vector);  % Try applying different functions here.
    chan = [[0 0 0 0 0] chan];  % Change this array if you want to change the characteristics of channel
    chan_old = chan;
    chan_sum = sum(chan);
    %pjr comment out
    chan = chan/sum(chan);
    chan = chan * loss;
end 

function conv_ExponentialDecaying_new(x,sampleFreq,amplitude,loss,k,time_vector) 

    p_x = vlc_sample_stream(x, sampleFreq)
    chan = vlc_cannel_property_stream( amplitude, loss, k, time_vector)
    y = conv(p_x,chan);


    subplot(2,5,[1 2]);stem(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal"); grid on
    subplot(2,5,3);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -0.5 0.5]);title("chan"); grid on
    subplot(2,5,[4 5]);stem(y);axis([1 length(y) -1.5 1.5]);title("rx signal"); grid on
    subplot(2,5,[6 7]);plot(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal"); grid on
    subplot(2,5,8);stem(chan,'MarkerFaceColor',[0 0 1]);axis([1 length(chan) -0.5 0.5]);title("chan"); grid on
    subplot(2,5,[9 10]);plot(y);axis([1 length(y) -1.5 1.5]);title("rx signal"); grid on
end
%One simple example is as follows. As you see, the input is the same as the ones we used in previous examples. You would notice that the values in channel is much more complex than the ones we saw in previous examples. And the result is as shown below. If you already have gone through any basic electronic course, you would notice that the output is very similar to the case where a rectangular pulse is going through a capacitance circuit.
%Let me give you another example. As you see, the input is the same as the ones we used in previous examples. You would notice that the values in channel is similar to previous example and the only difference is that you have some zeros at the beginning of channel sequence. And the result is as shown below. You see the overal shape of the output (rx signal) is same as the one you saw in previous example, but you would notice that a delay was introduced in this example.
 
% ================================
% ================================
% ================================