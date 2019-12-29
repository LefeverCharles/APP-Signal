[signal,Fe] = audioread('C:\Chemin\fichier.wav');
signal_fft = abs(fft(signal));
signal_fft = signal_fft(1:round(Fe/2));
[maxValueSignal, indexOfMaxValueSignal] = max(signal_fft);
bpm = indexOfMaxValueSignal*60; 
disp(bpm);