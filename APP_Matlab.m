
x1 = 0: 1/20000 : 5*10^(-2);
y1 =  sin(2*pi*1000*x1);
figure
plot(x1,y1)
xlabel('temps')
ylabel('amplitude')


x = 0 : 1/20000 : 5*10^(-3);
y = 2*sin(2*pi*1000*x);
figure
plot(x,y)
xlabel('seconds')
ylabel('volt')
title('Signal in the time domain - 5 periods')

moyenne = 0;
for compteur = 1 : 1 : length(x)
    moyenne = moyenne + x(1,compteur);
end
moyenne = moyenne/length(x);
moyenne

puissance = 0;
for compteur = 1 : 1 : length(x)
    puissance = puissance + x(1,compteur)^2;
end
puissance = puissance/length(x);
puissance

valeff = sqrt(puissance);
valeff









--------------------

%I.B

Aref = rand(1,1)*0.9 + 0.1;             %randi(génère entre 0.1 et 1,1 ligne 1 colonne)
A = randi(100,1,1)/100;
fref = 16.35*((2^(1/12))^randi(12*11 - 1 , 1, 1))
f = 130 + (4000-130).*rand(1,1);    %rand(nombre d'élement,intervalle entre 0.000 et 1.000)
phi =  2*pi.*rand(1,1);              % génère aléatoirement un déphasage aléatoire

longEchantillon = max(5/fref, 5/f)
xref = 0 : 1/16000 : longEchantillon;
x =  0 : 1/16000 : longEchantillon;

signal1 = Aref*sin(2*pi*fref*xref)
signal2 = A*sin(2*pi*f*x + phi)

%plot(xref,signal1)




