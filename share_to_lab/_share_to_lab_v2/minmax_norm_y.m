function [yData, ym, yr] = minmax_norm_y( yData)
    ym = min(yData);
    yr = max(yData) - min(yData);
    yData = (yData - ym)/yr; % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.
    yData = yData';
end    