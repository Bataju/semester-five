%the og square signal
freq = 5;
amp = 19;
Fs = 1000; %sampling frequency
t = [0:1/Fs:3];

g_t = amp*square(2*pi*freq*t);
subplot(3,1, 1);
plot(t, g_t);
title('Square wave');
xlabel('Time(seconds)');
ylabel('Amplitude(volts)');

%fft on the square signal
N = length(g_t);
g_t_fft = fft(g_t);

%frequency axis
f = [-Fs/2:Fs/N:Fs/2-Fs/N];

subplot(3,1, 2);
plot(f, abs(g_t_fft));
xlabel('Frequency (Hz)');
ylabel('Magnitude');
title('Magnitude Spectrum');

%ifft on the fft signal resulting in the og square signal
g_t_fft_ifft = ifft(g_t_fft);

subplot(3,1, 3);
plot(t, g_t_fft_ifft);
xlabel('Time (seconds)');
ylabel('Amplitude (volts)');
title('Square wave again');


