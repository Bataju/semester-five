tmin = -10;
dt = 1;
tmax = 20;
t = tmin:dt:tmax; %set a time vector

x = -0.92*sin(0.1 *pi*t-3*pi/4);
subplot(2,1, 1);
stem(t, x);
xlabel('t');
ylabel('x(t)');
title('-0.92*sin(0.1 *pi*t-3*pi/4)');

tmin = 0;
dt = 1;
tmax = 50;
t = tmin:dt:tmax; %set a time vector

x=-0.93.^t.*exp(i*pi*t/sqrt(350));
subplot(2,1, 2);
stem(t, x);
xlabel('t');
ylabel('x(t)');
title('-0.93^t*exp(i*pi*t/sqrt(350))');