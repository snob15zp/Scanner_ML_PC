function [ Signal, T, FftL ] = generation_test_signal( Tm, Fd, mz, Ak, A1, A2, F1, F2, P1, P2, An)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

FftL=Tm*Fd*mz;      % number of FFT samples

T=0:1/Fd:Tm;                    % Array of time samples
Noise=An*randn(1,length(T));    % An array of random noise with a length equal to the array of time
Signal=Ak+A1*sind((F1*360).*T+P1)+A2*sind((F2*360).*T+P2)+Noise; % Signal array (mix of 2 tones + constant)

end

