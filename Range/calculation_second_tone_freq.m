function [ fv, Am, im ] = calculation_second_tone_freq( FftR, Fd, FftL )
%UNTITLED18 Summary of this function goes here
%   Detailed explanation goes here

[Am,im]=max(FftR);              % Maximum in the spectrum , where Am is the amplitude , im is the index in the array FftR starting from 1 and not from 0
fv=(im-1)*Fd/FftL;              % calculating tone frequency 2 , im-1 because i starts at 1 and not at 0

end

