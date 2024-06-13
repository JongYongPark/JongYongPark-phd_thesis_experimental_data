function [yData, ym, yr] = minmax_norm_v1( charInput, maxCharInput, minyData,ym,yr)
    yData = (yData - ym)/yr; % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.
    yData = yData';
end    

%{
function [xData, yData, ym, yr] = minmax_norm(charInput, InitC, cap)
    r = max(charInput) - min(charInput); % 각 column의 max, min 값을 구한다 => 결국 열 한개로 변환
    xData = (charInput - min(charInput))./r; % 최대 1로 해서 각 값들의 비율을 구한다.
    comp = length(charInput) - length(cap); % langth는 row 갯수의 차이를 리턴한다.
    yData = [InitC*ones(comp, 1); cap']; % 갯수 차이만큼 초기값을 넣어준다.
    ym = min(yData);
    yr = max(yData) - min(yData);
    yData = (yData - ym)/yr; % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.
end 
%}
