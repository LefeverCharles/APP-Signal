clear all;
close all;
 
note2 = [130.81 ,138.59 , 146.83 , 155.56 , 164.81 ,174.61 , 185 , 196 ,207.65,220,233.06,246.94];
note3 = [261.63 ,277.18 , 293.66 , 311.13 , 329.63 ,349.23 , 369.99 , 392 ,415.30,440,466.16,493.88];
note4 = [523.25 ,544.37 , 587.33 , 622.25 , 659.26 ,698.46 , 739.99 , 783.99 ,830.61,880,932.33,987.77];
note5 = [1046.50 ,1108.73 , 1174.66 , 1244.51 , 1318.51 ,1396.91 , 1479.98 , 1567.98 ,1661.22,1760,1864.66,1975.53];
note6 = [2093 ,2217.46 , 2349.32 , 2489.02 , 2637.02 ,2793.83 , 2959.96 , 3135.96 ,3322.44 ,3520,3729.31,3951.07];
 
fnote = note2(5);%On peut le changer comme on veut

fe = 16000;
te = 1/fe;
 
t = 0:te:2;

A =  randi([1 5]);
y_sin = sin(2*pi*fnote*t);
y_carre = square(2*pi*fnote*t);
 

bruit=A*randn(1,length(t));%Bruit
 
Y1 = y_sin+bruit;%Sin + bruit

figure(1);
subplot(2,2,3);
plot(t,abs(fft(Y1)));%Figure de Sin + bruit
title('FFT signal');
axis([0 fnote/10 0 20000]);
%yfiltre = load('Bandpass.mat');%Fs=10000 Fstop1=125 Fpass1 =128 Fpass2 =3952 Fstop2 = 4000
yfiltre = load('Lowpass.mat');
Yfiltre = filter(yfiltre.Num,1,Y1);%Filtre de sin+bruit
 
subplot(2,2,4);%On figure le fft de sin+bruit
Yf_fft = abs(fft(Yfiltre));
plot(Yf_fft);
title('fft de signal + bruit');
xlabel('Frequence');
ylabel('Amplitude');
 
subplot(2,2,2);%On figure le bruit
plot(t,bruit);
title('bruit');
axis([0 10/fnote -10 10]);

subplot(2,2,1);%On figure le sin
plot(t,y_sin);
title('sin');
axis([0 10/fnote -10 10]);

figure(2);
subplot(2,2,1);%On figure le filtre de sin+bruit
plot(t,Y1);
title('Filtre de sin+bruit');
axis([0 0.25/fnote -10 10]);
 
Y_fftFiltre = abs(fft(Y1));

subplot(2,2,3);%On figure le fft de filtre de sin+bruit
plot(Y_fftFiltre);
title('fft de filtre');
 
subplot(2,2,2);%On figure le carré comme le modèle
plot(t,y_carre);
axis([0 10/fnote -1.5 1.5]);
title('Carr de sin');
 
Y_fftSinCarre = abs(fft(y_carre));
subplot(2,2,4);%On figure le fft de carré de sin
plot(Y_fftSinCarre);
title('fft de carré de sin');

disp(lince(max(Y_fftFiltre)))
disp(lince(max(Y_fftSinCarre)))
 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all;

close all;

 

note2 = [130.81 ,138.59 , 146.83 , 155.56 , 164.81 ,174.61 , 185 , 196 ,207.65,220,233.06,246.94];

note3 = [261.63 ,277.18 , 293.66 , 311.13 , 329.63 ,349.23 , 369.99 , 392 ,415.30,440,466.16,493.88];

note4 = [523.25 ,544.37 , 587.33 , 622.25 , 659.26 ,698.46 , 739.99 , 783.99 ,830.61,880,932.33,987.77];

note5 = [1046.50 ,1108.73 , 1174.66 , 1244.51 , 1318.51 ,1396.91 , 1479.98 , 1567.98 ,1661.22,1760,1864.66,1975.53];

note6 = [2093 ,2217.46 , 2349.32 , 2489.02 , 2637.02 ,2793.83 , 2959.96 , 3135.96 ,3322.44 ,3520,3729.31,3951.07];

 

fnote = note2(5);%On peut le changer comme on veut



fe = 16000;

te = 1/fe;

 

t = 0:te:2;



A =  randi([1 5]);

y_sin = sin(2*pi*fnote*t);

y_carre = square(2*pi*fnote*t);

 



bruit=A*randn(1,length(t));%Bruit



 

Y1 = y_sin+bruit;%Sin + bruit
Y2 = y_carre+bruit; %sin carre + bruit


figure(1);

subplot(2,2,3);

ySinusBruitFFt = abs(fft(y_sin));

plot(ySinusBruitFFt);%plot(t,abs(fft(Y1)));%Figure de Sin + bruit

title('FFT signal');

%axis([0 fnote/10 0 20000]);

%yfiltre = load('Bandpass.mat');%Fs=10000 Fstop1=125 Fpass1 =128 Fpass2 =3952 Fstop2 = 4000

yfiltre = load('Lowpass.mat');

Yfiltre = filter(yfiltre.Num,1,Y1);%Filtre de sin+bruit

 

subplot(2,2,4);%On figure le fft de sin+bruit

Yf_fft = abs(fft(Yfiltre));

plot(Yf_fft);

title('fft de signal + bruit');

xlabel('Frequence');

ylabel('Amplitude');

 

subplot(2,2,2);%On figure le bruit

plot(t,bruit);

title('bruit');

axis([0 10/fnote -10 10]);



subplot(2,2,1);%On figure le sin

plot(t,y_sin);

title('sin');

axis([0 10/fnote -10 10]);



figure(2);

subplot(2,2,1);%On figure le sinus carre + bruit

plot(t,Y2);

title('sin carre et bruit');

axis([0 0.25/fnote -10 10]);

 

Y_fftFiltre = abs(fft(Y1));



subplot(2,2,3);%On figure le fft de filtre de sin+bruit

plot(Y_fftFiltre);

title('fft de filtre de sin+bruit');

 

subplot(2,2,2);%On figure le carré comme le modèle

plot(t,y_carre);

axis([0 10/fnote -1.5 1.5]);

title('Carr de sin');

 

Y_fftSinCarre = abs(fft(y_carre));

subplot(2,2,4);%On figure le fft de carré de sin

plot(Y_fftSinCarre);

title('fft de carré de sin');


%{
disp(lince(max(Y_fftFiltre)))

disp(lince(max(Y_fftSinCarre)))
%}

function score = calculScore (fref, signalFFT)
  [maxValue, indMaxValue] = max(signalFFT);
  score = (fref - abs(fref - indMaxValue)) / fref;
endfunction

scoreSinus = calculScore(fnote, ySinusBruitFFt(1: fe/2));
scoreCarre = calculScore(fnote, Y_fftSinCarre(1: fe/2));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   V3


clear all;

close all;

 

note2 = [130.81 ,138.59 , 146.83 , 155.56 , 164.81 ,174.61 , 185 , 196 ,207.65,220,233.06,246.94];

note3 = [261.63 ,277.18 , 293.66 , 311.13 , 329.63 ,349.23 , 369.99 , 392 ,415.30,440,466.16,493.88];

note4 = [523.25 ,544.37 , 587.33 , 622.25 , 659.26 ,698.46 , 739.99 , 783.99 ,830.61,880,932.33,987.77];

note5 = [1046.50 ,1108.73 , 1174.66 , 1244.51 , 1318.51 ,1396.91 , 1479.98 , 1567.98 ,1661.22,1760,1864.66,1975.53];

note6 = [2093 ,2217.46 , 2349.32 , 2489.02 , 2637.02 ,2793.83 , 2959.96 , 3135.96 ,3322.44 ,3520,3729.31,3951.07];

 

fnote = note2(5);%On peut le changer comme on veut



fe = 16000;

te = 1/fe;

 

t = 0:te:2;



A =  randi([1 3]);

y_sin = sin(2*pi*fnote*t);

y_carre = square(2*pi*fnote*t);

 



bruit=A*randn(1,length(t));%Bruit



 

Y1bruit = y_sin+bruit;%Sin + bruit
Y2bruit = y_carre+bruit; %sin carre + bruit


% FIGURE 1

figure(1);

% Sinus

subplot(2,2,1);

plot(t,y_sin);

title('Sinus');

axis([0 10/fnote -1.5 1.5]);

% Sinus + bruit

subplot(2,2,2);%On figure le bruit

plot(t,bruit);

title('Sinus + bruit');

axis([0 10/fnote -10 10]);

% FFT Sinus

subplot(2,2,3);

ySinusBruitFFt = abs(fft(y_sin));

plot(ySinusBruitFFt);%plot(t,abs(fft(Y1)));%Figure de Sin + bruit

title('FFT Sinus');

%axis([0 fnote/10 0 20000]);

%yfiltre = load('Bandpass.mat');%Fs=10000 Fstop1=125 Fpass1 =128 Fpass2 =3952 Fstop2 = 4000


% FFT Sinus + bruit filtré

yFiltre = load('Lowpass.mat');

Y1bruitFiltre = filter(yFiltre.Num,1,Y1bruit);%Filtre de sin+bruit

subplot(2,2,4);%On figure le fft de sin+bruit

Y1BruitFiltreFFT = abs(fft(Y1bruitFiltre));

plot(Y1BruitFiltreFFT);

title('FFT Sinus + bruit filtré');

xlabel('Frequence');

ylabel('Amplitude');

 
% FIGURE 2

figure(2);

% Carré

subplot(2,2,1);%On figure le carré comme le modèle

plot(t,y_carre);

axis([0 10/fnote -1.5 1.5]);

title('Carré');

% Carré + bruit

subplot(2,2,2);%On figure le sinus carre + bruit

plot(t,Y2bruit);

title('Carré + bruit');

axis([0 10/fnote -10 10]);

% FFT Carré

Y_fftSinCarre = abs(fft(y_carre));

subplot(2,2,3);%On figure le fft de carré de sin

plot(Y_fftSinCarre);

title('FFT Carré');

% FFT Carré + bruit filtré

Y2bruitFiltre = filter(yFiltre.Num,1,Y2bruit);

Y2BruitFiltreFFT = abs(fft(Y2bruitFiltre));

subplot(2,2,4);%On figure le fft de filtre de sin+bruit

plot(Y2BruitFiltreFFT);

title('FFT Carré + bruit filtré');

 


%{
disp(lince(max(Y_fftFiltre)))
disp(lince(max(Y_fftSinCarre)))
%}


scoreSinus = calculScore(fnote, ySinusBruitFFt(1: fe/2));
scoreCarre = calculScore(fnote, Y_fftSinCarre(1: fe/2));

function score = calculScore (fref, signalFFT)
  [maxValue, indMaxValue] = max(signalFFT);
  score = (fref - abs(fref - indMaxValue)) / fref;
end











