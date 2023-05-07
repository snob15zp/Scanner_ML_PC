clear all           % Clearing memory
    %% Parameters unchanged (set by the customer)
Tm=0.9;             % Duration of the measured signal (s)
Fd=2500000;         % Sampling frequency (Hz)
mz=20;              % zero padding multiplier - limited by the speed of the customer's computer
    %% Parameters changeable (input signal)
Ak=0;               % DC
A1=1;               % Amplitude of the first tone
A2=5E-7;            % Amplitude of the second tone
F1=300000;          % First tone frequency (Hz)
F2=300001;          % Second tone frequency (Hz)
P1=237;             % Initial phase of the first tone (Degrees)
P2=0;               % Initial phase of the second tone (Degrees)
An=7E-5 ;           % noise level
    %% Generation of working arrays (input signal)
[ Signal, T, FftL ] = generation_test_signal( Tm, Fd, mz, Ak, A1, A2, F1, F2, P1, P2, An);
%-------------------------------- Signal
figure                          % Create a new window
plot(T, Signal);                % Building a signal
xlim([0 0.00003]);              % time interval on the x-axis
title('Signal');                % Graph caption
xlabel('Time (s)');             % Plot x-axis label
ylabel('V');                    % Chart y-axis label
    %% Spectral representation of the input signal
[ FftS ] = spectral_representation_signal( Signal, FftL );
%-------------------------------- Range
figure                          % Create a new window
F=0:Fd/FftL:Fd/2;               % Array of frequencies of the calculated spectrum
stem(F,FftS(1:length(F)),'k.'); % draw...
xlim([299990 300010]);          % X-axis frequency interval
title('Range');                 % Graph caption
xlabel('Hz');                   % Chart x-axis label
ylabel('V');                    % Chart y-axis label
    %% Search for the frequency of the first tone and calculate the frequency correction factor
[ f ] = freq_first_tone_and_freq_corr( FftS, FftL, Fd );
    %% Approximation of the residue frequency by the maximum of the vector
[ f ] = approximation_freq_max_vector( Tm, Fd, Signal, f );
    %% Calculation of the amplitude and phase by the vector method, provided that the frequency is known
[ a, p, RS, FftR ] = calculation_amplitude_phase_vector_method( Tm, Fd, Signal, FftL, FftS, T, f );
%-------------------------------- Signal
figure                          % Create a new window
plot(T,RS);                     % Construction - difference signal
xlim([0 0.00003]);              % time interval on the x-axis
title('Signal');                % Graph caption
xlabel('Time (s)');             % Plot x-axis label
ylabel('V');                    % Chart y-axis label
%-------------------------------- Range
figure                          % Create a new window
F=0:Fd/FftL:Fd/2;               % Array of frequencies of the calculated spectrum
stem(F,FftR(1:length(F)),'k.'); % draw...
xlim([299990 300010]);          % X-axis frequency interval
title('Range');                 % Graph caption
xlabel('Hz');                   % Chart x-axis label
ylabel('V');                    % Chart y-axis label
    %% Second tone frequency calculation
[ fv ] = calculation_second_tone_freq( FftR, Fd, FftL );
disp([A1-a,F1-f,P1-p,F2-fv]);   % results in absolute errors to the input data
