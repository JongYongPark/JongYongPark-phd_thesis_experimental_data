
function [yCap,yPattern, xData] = minmax_norm_v2( charInput,capInput,patternInput,step,VIT_V_min,VIT_I_min,VIT_T_min,VIT_V_rate,VIT_I_rate,VIT_T_rate,ym_cap,yr_cap,ym_pattern,yr_pattern )
    VIT_V_idx = [1 : 1 : step ];
    
    startI = length(VIT_V_idx)+1   ;
    endI = startI + 10 -1    ;
    VIT_I_idx = [ startI : 1: endI ]   ;
    
    startT = length(VIT_V_idx) + length(VIT_I_idx)+1   ;
    endT = startT + 10 -1   ;
    VIT_T_idx = [ startT : 1: endT ]   ;
    
    xData_V = (charInput(:,VIT_V_idx) - VIT_V_min)./VIT_V_rate ;
    xData_I = (charInput(:,VIT_I_idx) - VIT_I_min)./VIT_I_rate ;
    xData_T = (charInput(:,VIT_T_idx) - VIT_T_min)./VIT_T_rate ;
    xData = [ xData_V xData_I xData_T ];

    yCap = (capInput - ym_cap)/yr_cap; % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.
    yPattern = (patternInput - ym_pattern)/yr_pattern;
end    
