
[dat1,Fe] = Open_dat('/Users/xsl/desktop/Signal/100.dat');
[dat2,Fe] = Open_dat('/Users/xsl/desktop/Signal/101.dat');
[dat3,Fe] = Open_dat('/Users/xsl/desktop/Signal/102.dat');
[dat4,Fe] = Open_dat('/Users/xsl/desktop/Signal/103.dat');
[dat5,Fe] = Open_dat('/Users/xsl/desktop/Signal/104.dat');
[dat6,Fe] = Open_dat('/Users/xsl/desktop/Signal/105.dat');
[dat7,Fe] = Open_dat('/Users/xsl/desktop/Signal/106.dat');
[dat8,Fe] = Open_dat('/Users/xsl/desktop/Signal/107.dat');
[dat9,Fe] = Open_dat('/Users/xsl/desktop/Signal/108.dat');
[dat10,Fe] = Open_dat('/Users/xsl/desktop/Signal/109.dat');
fcar1 = frequence(dat1,Fe);
fcar2 = frequence(dat2,Fe);
fcar3 = frequence(dat3,Fe);
fcar4 = frequence(dat4,Fe);
fcar5 = frequence(dat5,Fe);
fcar6 = frequence(dat6,Fe);
fcar7 = frequence(dat7,Fe);
fcar8 = frequence(dat8,Fe);
fcar9 = frequence(dat9,Fe);
fcar10 = frequence(dat10,Fe);

function fcar = frequence(dat,Fe)
temps = length(dat)/Fe;
for i = 1:temps
     n = 1:i*Fe;
    Dat = dat(n);
    seuil = (max(Dat)-min(Dat))*0.75+min(Dat);%seuil 75%
    
    [datp,loc] = findpeaks(Dat,Fe,'MinPeakDistance',0.5,'MinPeakHeight',seuil);%Trouver les pics
    fcar = length(datp)/i*60;%calcul la fréquence cardiaque 
    fprintf('la frequence cardiaque des ');
    disp(i);
    fprintf('eme seconds est ')
    disp(fcar)
end
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% 2e algo %%% (celui du screen)

clear all;
close all;
clc;

[signal,Fe] = Open_dat('ECG/101.dat'); % Ne pas oublier Open_dat.m avec matlab
longueurFenetre = 3; % secondes
longueurFichier = size(signal);
longueurFichier = longueurFichier(2);
longueurFichier = longueurFichier / Fe; % en secondes
pasFenetres = 0.5;%longueurFenetre / 5;

for i = 0:pasFenetres:(longueurFichier - longueurFenetre)
    
  signalFenetre = signal(1, round(i*Fe) + 1 : round((i + longueurFenetre)*Fe));
  signalFenetre = signalFenetre - mean(signalFenetre);
  sizeSignalFenetre = size(signalFenetre);
  sizeSignalFenetre = sizeSignalFenetre(2);
  signal_fft = abs(fft(signalFenetre, Fe*longueurFenetre*100));
  signal_fft = signal_fft(1:round(Fe/2));
  
  [maxValueSignal, indexOfMaxValueSignal] = max(signal_fft);
  bpm = (indexOfMaxValueSignal)*0.6; % 60/100 = 0.6
  disp('Entre le temps t ci-dessus et (t + la longueur de la fenetre)');
  disp(i);
  disp('On a en BPM :');
  disp(bpm);
  disp(' ');

end

%%%%%%%%%%%%%%%%%%%%%%%%ù

%%% Open_dat.m %%%

function [x,Fe] = Open_dat(filename)
 
fid=fopen(filename,'r');
time=10;
f=fread(fid,2*360*time,'ubit12');
fclose(fid);
x=f(1:2:length(f));
 
x = x(:)';
Fe = 360;
end






