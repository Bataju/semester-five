clear;
L=5;
t=[-L:0.01:L];
y=-t.^4+17*t.^3-t.^2-47;
plot(t,y)
hold on
title('Given function');
xlabel('t');
ylabel('y');

y1=-t.^4+17*t.^3-t.^2-47;
a0 = (1/L)*trapz(t,y1)
sum=0;
% Harmonics to be included in the Fourier series
harmonics = [1, 5, 10, 20];
am = zeros(1, length(harmonics));
bm = zeros(1, length(harmonics));
for k=1:length(harmonics)
    am(k)=(1/L)*trapz(t,y1.*cos(harmonics(k)*pi*t/L));
    bm(k)=(1/L)*trapz(t,y1.*sin(harmonics(k)*pi*t/L));
    sum=sum+am(k)*cos(harmonics(k)*pi*t/L)+bm(k)*sin(harmonics(k)*pi*t/L);
end
s_t=a0/2+sum
plot(t,s_t)
