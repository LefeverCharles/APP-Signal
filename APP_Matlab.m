
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



