function [ F ] = tone_graph( T, Signal, Fd, mz, FftL, FftS ) % plotting function
        %% Plotting
     %-------------------------------- Signal
%     figure                          % Create a new window
%     plot(T,Signal);                 % draw...
%     xlim([0 0.00003]);              % time interval on the x-axis
%     title('Signal');                % Graph caption
%     xlabel('Second');               % Plot x-axis label
%     ylabel('V');                    % Chart axis label
    %-------------------------------- Range
    figure                          % Create a new window
    F=0:Fd/FftL:Fd/2;               % Array of frequencies of the calculated spectrum
    stem(F,mz*FftS(1:length(F)),'k.'); % draw...
    xlim([299990 300010]);          % X-axis frequency interval
    title('Spectrum');              % Graph caption
    xlabel('Hz');                   % Plot x-axis label
    ylabel('V');             	    % Chart y-axis label
end
