% https://kr.mathworks.com/help/supportpkg/raspberrypiio/ref/getting-started-with-deploying-a-matlab-function-on-the-raspberry-pi-hardware.html
% https://kr.mathworks.com/help/supportpkg/raspberrypiio/ug/check-the-matlab-function-using-code-analyzer.html
% https://kr.mathworks.com/videos/deploy-matlab-algorithms-on-raspberry-pi-1591965724601.html
% https://kr.mathworks.com/help/supportpkg/raspberrypiio/ref/getting-started-with-deploying-a-matlab-function-on-the-raspberry-pi-hardware.html

% arduino
% https://kr.mathworks.com/help/supportpkg/arduinoio/ug/getting-started-with-matlab-support-package-for-arduino-hardware.html?searchHighlight=matlab%20support%20packages&s_tid=srchtitle_matlab%20support%20packages_9

% mingw
% https://kr.mathworks.com/help/matlab/matlab_external/install-mingw-support-package.html?searchHighlight=matlab%20support%20packages&s_tid=srchtitle_matlab%20support%20packages_3#bu0q2t0

% rpi
% https://kr.mathworks.com/help/coder/ug/deploy-generated-c-code-to-external-hardware-raspberry-pi-examples.html
% https://kr.mathworks.com/help/coder/ug/package-code-for-other-development-environments.html

% incremetal learning
% https://kr.mathworks.com/help/stats/code-generation-for-incremental-learning.html

function blinkLED() %#codegen
% Create a Raspberry Pi object
r= raspi();
% Blink the LED for 100 cycles
for count = 1:100
    % Turn on the LED
    writeLED(r,"LED0", 1);
    % Pause for 0.5 seconds
    pause(0.5);
    % Turn off the LED
    writeLED(r,"LED0", 0);
    % Pause for 0.5 seconds
    pause(0.5);
end
end