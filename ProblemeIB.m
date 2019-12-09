
Aref = rand(1,1)*0.9 + 0.1;             %randi(génère entre 0.1 et 1,1 ligne 1 colonne)
A = randi(100,1,1)/100;
fref = 16.35*((2^(1/12))^randi(12*11 - 1 , 1, 1)); % Signal entre 16Hz et 31.6Hz
f = 130*((2^(1/12))^(12*5 - 1))*(1 + 0.02*rand(1,1));    % rand(nombre d'élement,intervalle entre 0.000 et 1.000)
phi =  2*pi.*rand(1,1);              % génère aléatoirement un déphasage aléatoire

#Qu'ils aient le même nombre de points
longEchantillon = 100 * max(1/fref, 1/f);
x =  0 : 1/16000 : longEchantillon;

f = fref * (2^(1/12));
signal1 = Aref*sin(2*pi*fref*x);
signal2 = A*sin(2*pi*f*x + phi);

# On normalise à 1 pour qu'ils aient tous les 2 la même
# amplitude et que ça n'influe pas sur l'intercorrelation
signal1Norm = signal1 / max(signal1);
signal2Norm = signal2 / max(signal2);

# On va faire une fonction produit scalaire légèrement modifiée
# On prend la sqrt pour que la comparaison ne dépende pas beaucoup
# de la hauteur de la fréquence car si on fait 4000*4000 ça sera non lineairement
# plus grand que 130 * 130 
# abs( ) nous assure de pas avoir de complexes
function out = my_dot(x, y)
  out = 0;
  for i = 1 : 1 : length(x)
    out += sqrt(abs(x(i)*y(i)));
  end
end

frequenceComparaison = round(length(x) / 5);

# Autocorrelation : Somme du carré des éléments
autoCorr = my_dot(signal1Norm(1:frequenceComparaison), signal1Norm(1:frequenceComparaison)); # Produit scalaire

# Intercorrelation
maxiCorr = 0;
for k = 1 : 1 : frequenceComparaison
  temp = my_dot(signal1Norm(1:frequenceComparaison), signal2Norm(k + 1 : frequenceComparaison + k));
  if (temp > maxiCorr)
    maxiCorr = temp;
  end
end

pourcentageCorr = maxiCorr / autoCorr;

if (pourcentageCorr > 0.5)
  disp(1);
else
  disp(0);
end

