function [yData,  xData ] = minmax_norm_new_with_param(y,x, ymin, yr, xmin, xr)
    xData = (x - xmin)./xr; % 최대 1로 해서 각 값들의 비율을 구한다.
    yData = (y - ymin)./yr; % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.

    % yback = ynorm * yrate + ymin
    % xback = xnorm * xrate + xmin
end    