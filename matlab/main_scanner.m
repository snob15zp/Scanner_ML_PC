function [ Out ] = main_scanner( Tm, Fd, mz, FftL, T, Signal ) % scanner function
    Am=1;a=0;f=0;p=0;i=0;           % initial assignments to enter the search and subtract tone loop
    Out=zeros(3,100);
        %% The main cycle of searching and subtracting the tone of maximum amplitude
    while Am>1E-4                   % if the amplitude of the subtraction is greater than the specified threshold , then we look for and subtract the next tone
        [ Signal, FftS, Am, a, f, p ] = tone_search( Tm, Fd, mz, FftL, T, Signal, a, f, p ); % tone search and subtraction function
        i=i+1;Out(1,i)=a;Out(2,i)=f;Out(3,i)=p; % fill the output array : amplitude , frequency , phase
        if coder.target('MATLAB')   % if there is a generation in C code, then the following does not need to be generated
            disp([i]);              % subtracted tone counter
            [ F ] = tone_graph( T, Signal, Fd, mz, FftL, FftS ); % plotting function
        end
    end