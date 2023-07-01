clear;
f=1;
T=1/f;
tInterval=[-3:0.01:3];
amp=5;
dcBias=-3;
y=amp*square(2*pi*f*tInterval)+dcBias;
plot(tInterval,y)
hold on
title('Square Wave');
xlabel('t');
ylabel('y');

tInt = [0:0.01:T]; %interval of integration
y1=amp*square(2*pi*f*tInt)+dcBias;
a0 = (2/T)*trapz(tInt,y1)
sum=0;
% Harmonics to be included in the Fourier series
harmonics = [1, 5, 10, 20];
am = zeros(1, length(harmonics));
bm = zeros(1, length(harmonics));
for k=1:length(harmonics)
    am(k)=(2/T)*trapz(tInt,y1.*cos(harmonics(k)*2*pi*f*tInt));
    bm(k)=(2/T)*trapz(tInt,y1.*sin(harmonics(k)*2*pi*f*tInt));
    sum=sum+am(k)*cos(harmonics(k)*2*pi*f*tInterval)+bm(k)*sin(harmonics(k)*2*pi*f*tInterval);
end
s_t=a0/2+sum
plot(tInterval,s_t)
