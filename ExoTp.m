A = 1;
f = 1000;
Fe = 16000;
Te = 1/Fe;


x = 0: Te : 5/f;

b = 8;

y =  sin(2*pi*f*x);
xq = round(y*(2^(b-1))) / 2^(b-1);

figure
plot(x, y, '-o')
xlabel('seconds')
ylabel('volt')
title('Signal in the time domain - 5 periods')
