
Aref = rand(1,1)*0.9 + 0.1;             %randi(génère entre 0.1 et 1,1 ligne 1 colonne)
A = randi(100,1,1)/100;
fref = 16.35*((2^(1/12))^randi(12*11 - 1 , 1, 1)); % Signal entre 16Hz et 31.6Hz
f = 130*((2^(1/12))^(12*5 - 1))*(1 + 0.02*rand(1,1));    % rand(nombre d'élement,intervalle entre 0.000 et 1.000)
phi =  2*pi.*rand(1,1);              % génère aléatoirement un déphasage aléatoire

# Qu'ils aient le même nombre de points
longEchantillon = 10/fref;
x =  0 : 1/16000 : longEchantillon;

f = fref / (2^(1/12))
signal1 = Aref*sin(2*pi*fref*x);
signal2 = A*sin(2*pi*f*x + phi);

# On normalise à 1 pour qu'ils aient tous les 2 la même
# amplitude et que ça n'influe pas sur l'intercorrelation
signal1Norm = signal1 / max(signal1);
signal2Norm = signal2 / max(signal2);

frequenceComparaison = 2*round(length(x) * 0.2); # 2/10

disp('Calculating autoCorr...')
# Autocorrelation : Somme du carré des éléments
autoCorr = dot(signal1Norm(1:frequenceComparaison), signal1Norm(1:frequenceComparaison)); # Produit scalaire

# Intercorrelation
maxiCorr = 0;
disp('Calculating interCorr...')
for k = 1 : 1 : frequenceComparaison
  temp = dot(signal1Norm(1 : frequenceComparaison), signal2Norm(k + 1 : frequenceComparaison + k));
  if (temp > maxiCorr)
    maxiCorr = temp;
  end
end

disp('Calculating pourcentageCorr...')
pourcentageCorr = sqrt(maxiCorr / autoCorr);

disp('Resultat :')
# Pour f = fref */ 2^(1/12) on est souvent au dessus de 0.90
# On met donc le seuil à 0.89
if (pourcentageCorr > 0.89)
  disp(1);
else
  disp(0);
end

