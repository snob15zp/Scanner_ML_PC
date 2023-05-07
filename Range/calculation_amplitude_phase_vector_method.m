function [ a, p, RS, FftR ] = calculation_amplitude_phase_vector_method( Tm, Fd, Signal, FftL, FftS, T, f )
%UNTITLED15 Summary of this function goes here
%   Detailed explanation goes here

cs=0;
cc=0;
ss=0;
yc=0;
ys=0;  % initial assignments to amounts

for i=0:Fd*Tm                   % number of time array indexes
    cs=cs+sind(f*720*i/Fd)/2;   % simplification cos(x)*sin(x)=sin(2*x)/2
    cc=cc+cosd(f*360*i/Fd)^2;   % time starts from zero,
    ss=ss+sind(f*360*i/Fd)^2;   % and the index starts from one
    yc=yc+Signal(i+1)*cosd(f*360*i/Fd); % so in sines and cosines is i
    ys=ys+Signal(i+1)*sind(f*360*i/Fd); % and the signal contains the index i + 1
end                             % end of accumulation of sums for the matrix
A=[cc cs                        % solution of a system of linear equations (SLE)
   cs ss];                      % assigning sums to matrix A
B=[yc; ys;];                    % assign sums to matrix B
X=A\B;                          % SLE decision vector
a=sqrt(X(1)^2+X(2)^2)-mean(FftS); % subtraction signal amplitude
p=180+sign(X(1))*(acosd(sign(X(2))/sqrt(1+(X(1)/X(2))^2))-180); % subtraction signal phase 0...360
RS=Signal-a*sind((f*360).*T+p); % calculate the difference signal
FftR=abs(fft(RS,FftL));         % difference signal match amplitude
FftR=2*FftR./FftL;              % Spectrum normalization by amplitude

end

