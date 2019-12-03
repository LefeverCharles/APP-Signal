% Exercice A
fe = 16000;     % Fréquence d'échantillonnage
t = (0:1/fe:5); % Axe horizontal du temps
A = 2;          % Amplitude du signal
f0 = 1000; 
signal = A*sin(2*pi*t); % signal

plot(t, signal);    % Tracer le signal
grid;               % Afficher la grille

% Titres et axes
figure(1,1);
xlabel("Temps en secondes"); 
ylabel("Volt");
title("Signal in the domain -5 periods");

disp("################################");

% Exercice B
N1 = 0;
N2 = 1;
% Calcul de la valeur moyenne
valeurMoyenne = 0;
compteur = 0;
for compteur = N1:1/fe:N2
    valeurMoyenne = valeurMoyenne + A*sin(2*pi*compteur);
end
valeurMoyenne = valeurMoyenne * (1/(N2-N1+1));
disp("Valeur moyenne = ")
disp(valeurMoyenne);

% Calcul de la puissance en W
Acarre=A*A;
puissance = 0;
compteur = 0;
for compteur = N1:1/fe:N2
    puissance = puissance + Acarre*sin(2*pi*compteur)*sin(2*pi*compteur);
end
puissance = puissance * (1/(N2-N1+1));
disp("Puissance en W =");
disp(puissance);

% Puissance en dBm
puissanceDBM = 10 * log10(puissance/(0.001));
disp("Puissance en dBm =");
disp(puissanceDBM);

% Valeur efficace
valEfficace = sqrt(puissance);
disp("valEfficace =");
disp(valEfficace);    

disp("################################");




% Exercice C
% Deuxieme signal
N1 = 0;
N2 = 1/2;
% Calcul de la valeur moyenne du deuxieme signal
valeurMoyenne2 = 0;
for compteur2 = N1:1/fe:N2
    valeurMoyenne2 = valeurMoyenne2 + abs(compteur2);
end
valeurMoyenne2 = valeurMoyenne2 * (1/(N2-N1+1));
disp("Valeur moyenne deuxieme signal =")
disp(valeurMoyenne2);

% Calcul de la puissance en W du deuxieme signal
puissance2 = 0;
compteur2 = 0;
for compteur2 = N1:1/fe:N2
    puissance2 = puissance2 + abs(compteur2)*abs(compteur2);
end
puissance2 = puissance2 * (1/(N2-N1+1));
disp("Puissance en W deuxieme signal =");
disp(puissance2);

% Puissance en dBm du deuxieme signal
puissanceDBM2 = 10 * log10(puissance2/(0.001));
disp("Puissance en dBm deuxieme signal =");
disp(puissanceDBM2);

% Valeur efficace du deuxieme signal
valEfficace2 = sqrt(puissance2);
disp("valEfficace deuxieme signal =");
disp(valEfficace2); 


% Troisieme signal
N1 = 0;
N2 = 1;
% Calcul de la valeur moyenne du troisieme signal
valeurMoyenne3 = 0;
for compteur3 = N1:1/fe:N2
    if (mod(compteur3, 1/f0) < 1/(2*f0) && mod(compteur3, 1/f0)>0)
        valeurMoyenne3 = valeurMoyenne3 + 2;
    else
        valeurMoyenne3 = valeurMoyenne3 + 0.5;
    end
end
valeurMoyenne3 = valeurMoyenne3 * (1/(N2-N1+1));
disp("Valeur moyenne du troisieme signal =")
disp(valeurMoyenne3);

% Calcul de la puissance en W du troisieme signal
puissance3 = 0;
compteur3 = 0;
for compteur3 = N1:1/fe:N2
    if (mod(compteur3, 1/f0) < 1/(2*f0) && mod(compteur3, 1/f0)>0)
        puissance3 = valeurMoyenne3 + 2*2;
    else
        puissance3 = valeurMoyenne3 + 0.5*0.5;
    end
end
puissance3 = puissance3 * (1/(N2-N1+1));
disp("Puissance en W troisieme signal =");
disp(puissance3);


% Puissance en dBm du troisieme signal
puissanceDBM3 = 10 * log10(puissance3/(0.001));
disp("Puissance en dBm troisieme signal =");
disp(puissanceDBM3);

% Valeur efficace du troisieme signal
valEfficace3 = sqrt(puissance3);
disp("valEfficace troisieme signal =");
disp(valEfficace3); 



disp("################################");

% Exercice D
fe = 16000;     % Fréquence d'échantillonnage
t = (0:1/fe:5); % Axe horizontal du temps
B = 2;          % Amplitude du signal
f0 = 1000; 
signal2 = B*sin(2*pi*t+pi/3); % signal

plot(t, signal2);    % Tracer le signal
grid;               % Afficher la grille

% Titres et axes
figure(1,2);
xlabel("Temps en secondes"); 
ylabel("Volt");
title("Deuxieme graphique");

disp("################################");

