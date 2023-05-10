function [ An ] = tone_gener( T )   % функция генерации сигнала из разных тонов
        %% Параметры изменяемые (входной сигнал)
    Ak=0;                           % Постоянная составляющая
    % A1=1;                           % Амплитуда первого тона
    % A2=1E-5;                        % Амплитуда второго тона
    % F1=300000;                      % Частота первго тона (Гц)
    % F2=300001;                      % Частота второго тона (Гц)
    % P1=234;                         % Начальная фаза первого тона (Градусов)
    % P2=345;                         % Начальная фаза второго тона (Градусов)
    A=[1 1E-2 1E-2 1E-2 1E-2];      % массив амплитуд
    F=[300000 300001 300002 300003 300004]; % массив частот
    P=[0 99 111 222 333];           % массив фаз
    An=7E-5;                        % амплитуда шума
        %% Генерация рабочих массивов (входного сигнала)
    Signal=Ak+An*randn(1,length(T)); % массив случайного шума длиной равной массиву времени
    for i=1:length(F)
        Signal=Signal+A(i)*sind((F(i)*360).*T+P(i)); % накопление массива сигнала
    end
    writematrix(Signal,'Signal.txt'); % запись матрицы сигнала в файл
end