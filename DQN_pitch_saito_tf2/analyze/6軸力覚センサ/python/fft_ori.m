function outputArg1 = untitled(target, title)
%UNTITLED この関数の概要をここに記述
%   詳細説明をここに記述

T = 0.00083; % サンプル周期
L = length(target); % 信号のポイント数(時間じゃないので注意！)
%t = (0:L-1)*T; % 時間ベクトル

Y = fft(target);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

Fs = 1/T;
F = Fs*(0:(L/2))/L;
plot(F,P1);
xlim([0 200]);
ylim([0 0.2]);

savefig(title + ".fig");


Th_l = 5;
Th_h = 15;
Th_lf = cast(Th_l*L/Fs, 'int32');
Th_hf = cast(Th_h*L/Fs, 'int32');
F3 = cast(Fs*(Th_lf:Th_hf),'double')/L;
P3 = P1(Th_lf:Th_hf);
[M,I] = max(P3);

outputArg1 = F3(I);

end

