clear all                       % clearing memory
    %% Parameters are unchanged (specified by the customer)
Tm=1;                           % duration of the measured signal seconds
Fd=2500000;                     % sampling frequency Hertz
mz=20;                          % zero padding multiplier - limited by the speed of the customer's computer
    %% Input signal (generate , or load from file)
FftL=Tm*Fd*mz;                  % number of FFT samples
T=0:1/Fd:Tm;                    % array of timings
% [ An ] = tone_gener( T );       % input matrix generation
Signal=readmatrix('Signal.txt'); % load input signal matrix
[ Out ] = main_scanner( Tm, Fd, mz, FftL, T, Signal ); % function to compile to C
writematrix(Out,'Out.txt');     % write output matrix to file