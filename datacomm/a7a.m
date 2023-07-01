tmin = -5;
dt = 0.1;
tmax = 5;
t = tmin:dt:tmax; %set a time vector

x = 5*sin(2*pi*t).*cos(pi*t-8);
subplot(2,1, 1);
plot(t, x);
xlabel('t');
ylabel('x(t)');
title('5*sin(2*pi*t)*cos(pi*t-8)');

tmin = -10;
dt = 0.1;
tmax = 10;
t = tmin:dt:tmax; %set a time vector

x=5*exp(-0.2*t).*sin(2*pi*t);
subplot(2,1, 2);
plot(t, x);
xlabel('t');
ylabel('x(t)');
title('5*exp(-0.2*t)*sin(2*pi*t)');