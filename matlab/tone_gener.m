function [ An ] = tone_gener( T )   % signal generation function from different tones
        %% Parameters changeable (input signal)
    A=[1 1E-2 ];      % amplitude array
    F=[300000 300001 ]; % frequency array
    P=[0 77 ];           % phase array
    An=7E-5;                        % noise amplitude
        %% Generation of working arrays (input signal)
    Signal=An*randn(1,length(T));   % random noise array with length equal to time array
    for i=1:length(F)
        Signal=Signal+A(i)*sind((F(i)*360).*T+P(i)); % signal array accumulation
    end
    writematrix(Signal,'Signal.txt'); % writing signal matrix to file
end
