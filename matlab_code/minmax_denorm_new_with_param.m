function [yData,  xData, ] = minmax_denorm_new_with_param(y,x, ymin, yr, xmin, xr)
    yData = y * yrate + ymin
    xData = x * xrate + xmin
end    