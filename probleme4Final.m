%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Début de la version finale

clear all;

close all;

% Notes

note2 = [130.81 ,138.59 , 146.83 , 155.56 , 164.81 ,174.61 , 185 , 196 ,207.65,220,233.06,246.94];

note3 = [261.63 ,277.18 , 293.66 , 311.13 , 329.63 ,349.23 , 369.99 , 392 ,415.30,440,466.16,493.88];

note4 = [523.25 ,544.37 , 587.33 , 622.25 , 659.26 ,698.46 , 739.99 , 783.99 ,830.61,880,932.33,987.77];

note5 = [1046.50 ,1108.73 , 1174.66 , 1244.51 , 1318.51 ,1396.91 , 1479.98 , 1567.98 ,1661.22,1760,1864.66,1975.53];

note6 = [2093 ,2217.46 , 2349.32 , 2489.02 , 2637.02 ,2793.83 , 2959.96 , 3135.96 ,3322.44 ,3520,3729.31,3951.07];

% Création des signaux

fnote = note2(5); % On peut le changer comme on veut

fe = 16000;

te = 1/fe;

longueurSignal = 7; % en secondes

t = 0:te:longueurSignal;

y_sin = sin(2*pi*fnote*t);
y_carre = square(2*pi*fnote*t);

A =  randi([1 3]);
bruit=A*randn(1,length(t));

Y1bruit = y_sin+bruit;
Y2bruit = y_carre+bruit;


% FIGURE 1

figure(1);

% Sinus

subplot(2,2,1);

plot(t,y_sin);

title('Sinus');

axis([0 10/fnote -1.5 1.5]);

% Sinus + bruit

subplot(2,2,2);

plot(t,bruit);

title('Sinus + bruit');

axis([0 10/fnote -10 10]);

% FFT Sinus

subplot(2,2,3);

ySinusBruitFFt = abs(fft(y_sin));

plot(ySinusBruitFFt);

title('FFT Sinus');

% FFT Sinus + bruit filtré

yFiltre = load('Lowpass.mat');

Y1bruitFiltre = filter(yFiltre.Num,1,Y1bruit);

subplot(2,2,4);

Y1BruitFiltreFFT = abs(fft(Y1bruitFiltre));

plot(Y1BruitFiltreFFT);

title('FFT Sinus + bruit filtré');

xlabel('Frequence');

ylabel('Amplitude');

 
% FIGURE 2

figure(2);

% Carré

subplot(2,2,1);

plot(t,y_carre);

axis([0 10/fnote -1.5 1.5]);

title('Carré');

% Carré + bruit

subplot(2,2,2);

plot(t,Y2bruit);

title('Carré + bruit');

axis([0 10/fnote -10 10]);

% FFT Carré

Y_fftSinCarre = abs(fft(y_carre));

subplot(2,2,3);

plot(Y_fftSinCarre);

title('FFT Carré');

% FFT Carré + bruit filtré

Y2bruitFiltre = filter(yFiltre.Num,1,Y2bruit);

Y2BruitFiltreFFT = abs(fft(Y2bruitFiltre));

subplot(2,2,4);

plot(Y2BruitFiltreFFT);

title('FFT Carré + bruit filtré');

% Calcul du score

scoreSinus = calculScore(fnote, Y1BruitFiltreFFT(1: fe/2), longueurSignal)
scoreCarre = calculScore(fnote, Y2BruitFiltreFFT(1: fe/2), longueurSignal)

function score = calculScore (fref, signalFFT, sizeSignal)
  [maxValue, indMaxValue] = max(signalFFT);
  indMaxValue = indMaxValue / sizeSignal;
  score = (log2(fref) - abs(log2(fref) - log2(indMaxValue))) / log2(fref);
  score = score * 100;
end

% Fin de la version finale
