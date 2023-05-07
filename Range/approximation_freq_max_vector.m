function [ f ] = approximation_freq_max_vector( Tm, Fd, Signal, f )
%UNTITLED13 Summary of this function goes here
%   Detailed explanation goes here

hf=0.01;
ff=0; % step and accuracy are optimized for speed, deviation ff reset

while abs(hf)>1E-6              % if the step has not reached the optimal accuracy, then
	f=f+hf;                     % frequency is incremented by a step
    sc=0;ss=0;                  % initial assignments to amounts
    for i=0:Tm*Fd               % number of time array indexes Tm*Fd+1
        sc=sc+Signal(i+1)*cosd(f*360*i/Fd); % the first sum of the vector
        ss=ss+Signal(i+1)*sind(f*360*i/Fd); % second vector sum
    end
    s=sc^2+ss^2;                % variance function - sum of squares of vector sums
    if s<ff                     % if the maximum value is skipped, then
        hf=-hf/2;               % dividing by 2 and reversing the step in the opposite direction
    end
    ff=s;                       % the past sum is equal to the current one
end                             % end of approximation in frequency

end

