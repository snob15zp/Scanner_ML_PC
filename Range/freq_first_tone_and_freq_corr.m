function [ f ] = freq_first_tone_and_freq_corr( FftS, FftL, Fd )
%UNTITLED11 Summary of this function goes here
%   Detailed explanation goes here

[Am,im]=max(FftS); % maximum in the spectrum , where Am is the amplitude of the match , im is the index in the array FftS starting from 1 and not from 0
f=(im-1)*Fd/FftL;  % calculating the frequency of the first tone, im-1 because i starts at 1 and not at 0


end

