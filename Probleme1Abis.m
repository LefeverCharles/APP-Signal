
% I-A
% Lire le signal pendant 50ms
% Si la suite du signal est différente (supérieur en fréquence ou en
% amplitude moyenne)
% Alors dire que l'on détecte un signal
% Sinon absence de signal

isSignal = false;                       % On définit la variable boolean qui va dire s'il existe un signal ou non
[x,fs] = audioread('Allegretto.wav');          % On ouvre le fichier
te = 1/fs;
debut = 1;
fin = 0.05*fs;
fin = floor(fin);    % On converti la fréquence en période (échantillonnage)                        
puissanceBruit =0;
puissance =0; % On fait varier t de 0 à 50ms avec une période te (pour le bruit)

for t = debut:1:fin
    puissanceTest = x(t, 1)^2;
  if (puissanceTest > puissanceBruit)   % On compare les deux amplitudes
    puissanceBruit = puissanceTest;  
end   
end

taille = length(x);                   % On fait de même avec le reste du signal
for t2 = fin:1:taille
    puissance = puissance + x(t2, 1)^2;
end   
puissance = (1/(fin-debut+1)) * puissance;
if (puissance > puissanceBruit)   % On compare les deux amplitudes
    isSignal = true;                       % Si l'amplitude du signal est supérieure au bruit, on considère qu'il y a signal
end

y=0;
z=0;


figure;

z = x(:, 1);
plot(z,'r');

figure(1);
hold on;
xlabel("Temps");
ylabel("Signal");
grid on;
title("Probleme I-A");
y = zeros(taille, 1);
y(fin:taille, 1) = x(fin:taille, 1);
for t2 = fin:1:taille
  puissanceInst = y(t2, 1)^2;
  if (puissanceInst < puissanceBruit * 1.1)   % On compare les deux amplitudes
    y(t2, 1) = 0;                       % Si l'amplitude du signal est supérieure au bruit, on considère qu'il y a signal
  end
end 

plot(y, 'b');
plot(y,'b');

hold off;
plot(z.^2,'r');
hold on;
plot(y.^2,'b');
plot(y.^2,'b');
