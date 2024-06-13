function [yPattern, ym, yr] = minmax_norm_pattern( patterns)
    ym = min(patterns);
    yr = max(patterns) - min(patterns);
    yPattern = (patterns - ym)/yr; % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.
end    