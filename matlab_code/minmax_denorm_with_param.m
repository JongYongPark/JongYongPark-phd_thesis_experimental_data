function [yData] = minmax_denorm_with_param(y, ymin, yrate)
    yData = y * yrate + ymin ;
end    