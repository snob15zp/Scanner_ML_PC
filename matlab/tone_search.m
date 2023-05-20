function [ Signal, FftS, Am, a, f, p ] = tone_search( Tm, Fd, mz, FftL, T, Signal, a, f, p ) % search and delete tones function
    Signal=Signal-a*sind((f*360).*T+p); % calculate the difference signal
        %% Spectral representation of the input signal
    FftS=abs(fft(Signal,FftL));     % signal Fourier transform amplitude
    FftS=2*FftS./FftL;              % amplitude normalization of the spectrum
        %% Tone frequency search and calculation
    [Am,im]=max(FftS);              % maximum in the spectrum , where Am is the amplitude of the match , im is the index in the array FftS starting from 1 and not from 0
    f=(im-1)*Fd/FftL;               % calculating the tone frequency, im-1 because i starts at 1 and not at 0
        %% Approximation of the residue frequency by the maximum of the vector
    hf=0.01;ff=0;                   % step and error optimized for speed, deviation ff reset
    while abs(hf)>1E-6              % if the step did not reach the optimal error, then
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
        %% Calculation of the amplitude and phase of the residue by the vector method, provided that the frequency is known
    cs=0;cc=0;ss=0;yc=0;ys=0;       % initial assignments to amounts
    for i=0:Fd*Tm                   % number of time array indexes
        cs=cs+sind(f*720*i/Fd)/2;   % simplification cos(x)*sin(x)=sin(2*x)/2
        cc=cc+cosd(f*360*i/Fd)^2;   % time starts from zero,
        ss=ss+sind(f*360*i/Fd)^2;   % and the index starts from one
        yc=yc+Signal(i+1)*cosd(f*360*i/Fd); % so in sines and cosines is i
        ys=ys+Signal(i+1)*sind(f*360*i/Fd); % and the signal contains the index i + 1
    end                             % end of accumulation of sums for the matrix
    A=[cc cs                        % solution of a system of linear equations
       cs ss];                      % assigning sums to matrix A
    B=[yc; ys;];                    % assign sums to matrix B
    X=A\B;                          % solution vector
    an=(mean(FftS(1:29999*mz))+mean(FftS(30005*mz:Fd*mz/2)))/2; % average noise amplitude
    a=sqrt(X(1)^2+X(2)^2)-an;       % subtraction signal amplitude
    p=90*(2-sign(X(1)))-acotd(X(1)/X(2)); % subtraction signal phase 0...360
end
