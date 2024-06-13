

clc;
clear all;
close all;

%%%%%%%%%%%%%

func_rectpulse_test()

%%%%%%%%%%%%

function [] = func_rectpulse_test()
    nsamp = 4; % Number of samples per symbol
    nsymb = 3; % Number of symbols
    s = RandStream('mt19937ar', 'Seed', 0)
    ch1 = randi(s, [0 1], nsymb, 1); % Random binary channel
    ch2 = [1:nsymb]';
    x = [ch1 ch2] % Two-channel signal
    y = rectpulse(x,nsamp)
end 