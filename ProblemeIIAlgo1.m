[signal,Fe] = audioread('C:\Chemin\fichier.wav');
signal_fft = abs(fft(signal));
signal_fft = signal_fft(1:round(Fe/2));
[maxValueSignal, indexOfMaxValueSignal] = max(signal_fft);
bpm = indexOfMaxValueSignal*60; 
disp(bpm);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[signal,Fe] = Open_dat('C:\chemin\100.dat'); % Ne pas oublier Open_dat.m avec matlab
longueurFenetre = 2; % secondes
longueurFichier = size(signal)(2);
longueurFichier = longueurFichier / Fe; % en secondes
pasFenetres = longueurFenetre / 5;

for i = 0:pasFenetres:(longueurFichier - longueurFenetre)

  signal_fft = abs(fft(signal(1, round(i*Fe) + 1 : round((i + longueurFenetre)*Fe) - 1)));
  signal_fft = signal_fft(1:round(Fe/2));
  [maxValueSignal, indexOfMaxValueSignal] = max(signal_fft);
  bpm = indexOfMaxValueSignal*60;
  disp('Entre le temps t ci-dessus et (t + la longueur de la fenetre)');
  disp(i);
  disp('On a en BPM :');
  disp(bpm);
  disp(' ');

end
