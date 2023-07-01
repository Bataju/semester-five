tmin = -5;
dt = 0.1;
tmax = 5;
t = tmin:dt:tmax; %set a time vector

%unit impulse signal
x1 = 1;
x2 = 0;
x=x1.*(t==0)+x2.*(t==0);
subplot(3,3, 1);
plot(t, x);
xlabel('t');
ylabel('x(t)');
title('unit impulse signal');

%unit step signal
x1 = 1;
x2 = 0 ;
x=x1.*(t>=0)+x2.*(t<0);
subplot(3,3, 2);
plot(t, x);
xlabel('t');
ylabel('x(t)');
title('unit step signal');

%unit ramp signal
x1=t;
x2=0;
x=x1.*(t>=0)+x2.*(t<0);
subplot(3,3, 3);
plot(t, x);
xlabel('t');
ylabel('x(t)');
title('unit ramp signal');

%parabolic signal
A=0.4;
x1=A*(t.^2)/2;
x2=0;
x=x1.*(t>=0)+x2.*(t<0);
subplot(3,3, 4);
plot(t, x);
xlabel('t');
ylabel('x(t)');
title('parabolic signal');

%sinusoidal signal
T=2;
F=1/T;
x=sin(2*pi*F*t);
subplot(3,3, 5);
plot(t, x);
xlabel('t');
ylabel('x(t)');
title('sinusoidal signal');