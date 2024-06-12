function [yData, ymax, ymin, yr, xData, xmax, xmin, xr] = minmax_norm_new(y,x)
    xmax = max(max(x));
    xmin = min(min(x));
    xr = xmax - xmin; % 각 column의 max, min 값을 구한다 => 결국 열 한개로 변환
    xData = (x - xmin)./xr; % 최대 1로 해서 각 값들의 비율을 구한다.
    
    ymax = max(y);
    ymin = min(y);
    yr = ymax - ymin;
    yData = (y - ymin)./yr; % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.

    % yback = ynorm * yrate + ymin
    % xback = xnorm * xrate + xmin
end    