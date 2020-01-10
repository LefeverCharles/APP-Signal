freq = 440;
Fe = 16000;
duree = 5; % en secondes

t = 1:Fe:duree;
signal = sin(2*pi*freq*t);

ampli2 = 0.2 + 1.3*rand();
freq2 = freq * (0.95 + 0.1*rand());
duree = round(20 + 80*rand())/10; % en secondes entre 2.0 et 10.0

t2 = 1:Fe:duree;
freqBruit1 = 50;
freqBruit2 = 14000;
freqBruit3 = 18000;
signalRep = amplitude*(sin(2*pi*freq2*t2) + 0.01*sin(2*pi*freqBruit1*t2) + 0.01*sin(2*pi*freqBruit2*t2) + 0.01*sin(2*pi*freqBruit3*t2));

signalFFT = abs(fft(signalRep));
signalFFT = signalFFT(1:round(Fe/2));
f = (0:N-1)*Fe/N;
t = (0:N-1)*Te;%*/N
