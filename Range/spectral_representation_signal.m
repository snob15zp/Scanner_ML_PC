function [ FftS ] = spectral_representation_signal( Signal, FftL )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here

FftS=abs(fft(Signal,FftL));     % Signal Fourier Transform Amplitudes
FftS=2*FftS./FftL;              % Spectrum normalization by amplitude
FftS(1)=FftS(1)/2;              % Normalization of the constant component in the spectrum

end

