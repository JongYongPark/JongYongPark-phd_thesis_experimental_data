load cap_05             
load cap_06             
load cap_07             
load cap_0506           
load cap_0605           
load cap_05plus06       
load cap_05plus07       
load cap_06plus07       
load cap_05plus06plus07 


load charVIT_05
load charVIT_06
load charVIT_07
load charVIT_0506              
load charVIT_0605              
load charVIT_05plus06          
load charVIT_05plus07          
load charVIT_06plus07          
load charVIT_05plus06plus07    

load InitC_05 				
load InitC_06 				
load InitC_07 				
load InitC_0506 			
load InitC_0605 			
load InitC_05plus06 		
load InitC_05plus07 		
load InitC_06plus07 		
load InitC_05plus06plus07 	

load charVIT_input_size                  
load charVIT_05plus06_input_size         
load charVIT_05plus07_input_size         
load charVIT_06plus07_input_size         
load charVIT_05plus06plus07_input_size  

data_0506_patten_change = [27 32];  % 1.6849 -> 1.6821
data_0605_patten_change = [31 27];  % 1.6976 -> 1.6849


%%

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

%%

[xB_05, yB_05, ym_05, yr_05] = minmax_norm(charVIT_05, InitC_05, cap_05);
[xB_06, yB_06, ym_06, yr_06] = minmax_norm(charVIT_06, InitC_06, cap_06);
[xB_07, yB_07, ym_07, yr_07] = minmax_norm(charVIT_07, InitC_07, cap_07);
[xB_0506, yB_0506, ym_0506, yr_0506] = minmax_norm(charVIT_0506, InitC_05, cap_0506);
[xB_0605, yB_0605, ym_0605, yr_0605] = minmax_norm(charVIT_0605, InitC_06, cap_0605);
[xB_05plus06, yB_05plus06, ym_05plus06, yr_05plus06] = minmax_norm(charVIT_05plus06, InitC_05, cap_05plus06);
[xB_05plus07, yB_05plus07, ym_05plus07, yr_05plus07] = minmax_norm(charVIT_05plus07, InitC_05, cap_05plus07);
[xB_06plus07, yB_06plus07, ym_06plus07, yr_06plus07] = minmax_norm(charVIT_06plus07, InitC_06, cap_06plus07);
[xB_05plus06plus07, yB_05plus06plus07, ym_05plus06plus07, yr_05plus06plus07] = minmax_norm(charVIT_05plus06plus07, InitC_05, cap_05plus06plus07);
    

idx_0506           = data_0506_patten_change(1)+1;
xB_0506_ptn        = xB_0506(idx_0506:end,:);
yB_0506_ptn        = yB_0506(idx_0506:end);
yB_0506_ptn_pre    = nan(1,idx_0506-1);

idx_0605           = data_0605_patten_change(1)+1;
xB_0605_ptn        = xB_0605(idx_0605:end,:);
yB_0605_ptn        = yB_0605(idx_0605:end);
yB_0605_ptn_pre    = nan(1,idx_0605-1);


%%
% de normalize  - y - 동일 
y_05 = yB_05 * yr_05 + ym_05;
figure ; hold on  ; plot(cap_05),plot(y_05+0.1);hold off; 

% 칼럼별로 연산
max(charVIT_05)
max(charVIT_05(:,1))
max(charVIT_05(:,2))
min(charVIT_05)
min(charVIT_05(:,1))
min(charVIT_05(:,2))
max(charVIT_05) - min(charVIT_05)
max(charVIT_05(:,1)) - min(charVIT_05(:,1))
max(charVIT_05(:,2)) - min(charVIT_05(:,2))

size(cap_05)
length(cap_05)
size(charVIT_05)
length(charVIT_05)

ones(5, 1)
ones(0, 1)
ones(-1, 1)



r = max(charVIT_05) - min(charVIT_05) % 각 column의 max, min 값을 구한다 => 결국 열 한개로 변환
xData = (charVIT_05 - min(charVIT_05))./r % 최대 1로 해서 각 값들의 비율을 구한다.
comp = length(charVIT_05) - length(cap_05) % langth는 row 갯수의 차이를 리턴한다.
yData = [InitC_05*ones(comp, 1); cap_05'] % 갯수 차이만큼 초기값을 넣어준다.

size(yData)
length(yData)
yData
max(yData)
min(yData)

ym = min(yData)
yr = max(yData) - min(yData)
yData = (yData - ym)/yr % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.

%%

% de normalize  - y - 동일 
y_05plus06plus07 = yB_05plus06plus07 * yr_05plus06plus07 + ym_05plus06plus07;
figure ; hold on  ; plot(cap_05plus06plus07),plot(y_05plus06plus07+0.1);hold off; 

size(charVIT_05plus06plus07)
length(charVIT_05plus06plus07)

% 칼럼별로 연산
VIT_V_idx = [1:10]
VIT_I_idx = [11:20]
VIT_T_idx = [21:30]

max(charVIT_05plus06plus07)
max(charVIT_05plus06plus07(:,1))
max(charVIT_05plus06plus07(:,2))

charVIT_05plus06plus07(:,VIT_V_idx)
max(charVIT_05plus06plus07(:,VIT_V_idx))
min(charVIT_05plus06plus07(:,VIT_V_idx))
VIT_V_max  = max(max(charVIT_05plus06plus07(:,VIT_V_idx)))
VIT_V_min  = min(min(charVIT_05plus06plus07(:,VIT_V_idx)))
VIT_V_rate = max(max(charVIT_05plus06plus07(:,VIT_V_idx))) - min(min(charVIT_05plus06plus07(:,VIT_V_idx)))

charVIT_05plus06plus07(:,VIT_I_idx)
max(charVIT_05plus06plus07(:,VIT_I_idx))
min(charVIT_05plus06plus07(:,VIT_I_idx))
VIT_I_max  = max(max(charVIT_05plus06plus07(:,VIT_I_idx)))
VIT_I_min  = min(min(charVIT_05plus06plus07(:,VIT_I_idx)))
VIT_I_rate = max(max(charVIT_05plus06plus07(:,VIT_I_idx))) - min(min(charVIT_05plus06plus07(:,VIT_I_idx)))

charVIT_05plus06plus07(:,VIT_T_idx)
max(charVIT_05plus06plus07(:,VIT_T_idx))
min(charVIT_05plus06plus07(:,VIT_T_idx))
VIT_T_max  = max(max(charVIT_05plus06plus07(:,VIT_T_idx)))
VIT_T_min  = min(min(charVIT_05plus06plus07(:,VIT_T_idx)))
VIT_T_rate = max(max(charVIT_05plus06plus07(:,VIT_T_idx))) - min(min(charVIT_05plus06plus07(:,VIT_T_idx)))


xData_V = (charVIT_05(:,VIT_V_idx) - VIT_V_min)./VIT_V_rate 
xData_I = (charVIT_05(:,VIT_I_idx) - VIT_I_min)./VIT_I_rate 
xData_T = (charVIT_05(:,VIT_T_idx) - VIT_T_min)./VIT_T_rate 
xData = [ xData_V xData_I xData_T ]

yCap = cap_05plus06plus07
size(yCap)
length(yCap)
cap_all = yCap
cap_all_max = max(yCap)
cap_all_min = min(yCap)
cap_all_rate = cap_all_max / cap_all_min
yCap_result = ( yCap - cap_all_min ) / cap_all_rate
% recover 

% de normalize  - y - 동일 
y_05plus06plus07 = yB_05plus06plus07 * cap_all_rate + cap_all_min;
figure ; hold on  ; plot(cap_05plus06plus07),plot(y_05plus06plus07+0.1);hold off; 

yPattern = data_05plus06plus07(:,pattern_dVoltIdx)
size(yPattern)
length(yPattern)
pattern_all = yPattern
pattern_all_max = max(yPattern)
pattern_all_min = min(yPattern)
pattern_all_rate = pattern_all_max / pattern_all_min
yPattern_result = ( yPattern - pattern_all_min ) / pattern_all_rate

%
yData = cap_05
size(yData)
length(yData)
cap_all = yData
cap_all_max = max(yData)
cap_all_min = min(yData)
cap_all_rate = cap_all_max / cap_all_min
yB_05 = ( yData - cap_all_min ) / cap_all_rate

y_05 = yB_05 * cap_all_rate + cap_all_min;
figure ; hold on  ; plot(cap_05),plot(y_05+0.1);hold off; 

% function [yCap,yPattern, xData] = minmax_norm_v2( charInput,capInput,patternInput,VIT_V_idx,VIT_I_idx,VIT_I_idx,VIT_V_min,VIT_I_min,VIT_T_min,VIT_V_rate,VIT_I_rate,VIT_T_rate,ym_cap,yr_cap,ym_pattern,yr_pattern )

[yCap_05, yPattern_05, x_05] = minmax_norm_v2(charVIT_05,cap_05,patternInput,VIT_V_idx,VIT_I_idx,VIT_I_idx,VIT_V_min,VIT_I_min,VIT_T_min,VIT_V_rate,VIT_I_rate,VIT_T_rate,ym_cap,yr_cap,ym_pattern,yr_pattern )

[x_06, yB_06, ym_06, yr_06] = minmax_norm(charVIT_06, InitC_06, cap_06);
[x_07, yB_07, ym_07, yr_07] = minmax_norm(charVIT_07, InitC_07, cap_07);
[x_0506, yB_0506, ym_0506, yr_0506] = minmax_norm(charVIT_0506, InitC_05, cap_0506);
[xB_0605, yB_0605, ym_0605, yr_0605] = minmax_norm(charVIT_0605, InitC_06, cap_0605);
[xB_05plus06, yB_05plus06, ym_05plus06, yr_05plus06] = minmax_norm(charVIT_05plus06, InitC_05, cap_05plus06);
[xB_05plus07, yB_05plus07, ym_05plus07, yr_05plus07] = minmax_norm(charVIT_05plus07, InitC_05, cap_05plus07);
[xB_06plus07, yB_06plus07, ym_06plus07, yr_06plus07] = minmax_norm(charVIT_06plus07, InitC_06, cap_06plus07);
[xB_05plus06plus07, yB_05plus06plus07, ym_05plus06plus07, yr_05plus06plus07] = minmax_norm(charVIT_05plus06plus07, InitC_05, cap_05plus06plus07);


%%
% pattern

%{
function [yData, ym, yr] = minmax_norm_y( yData)
    ym = min(yData);
    yr = max(yData) - min(yData);
    yData = (yData - ym)/yr; % 출력값도 최대 1로 해서 각 값들의 비율을 구한다.
    yData = yData';
end    
%}

pattern_dVolt_consts = [ pattern_dVolt_05_const pattern_dVolt_06_const pattern_dVolt_07_const ];
[yB_05plus06plus07_pattern, ym_05plus06plus07_pattern, yr_05plus06plus07_pattern] = minmax_norm_y(data_05plus06plus07(:,pattern_dVoltIdx));
[yB_0506_pattern, ym_0506_pattern, yr_0506_pattern] = minmax_norm_y(data_0506(:,pattern_dVoltIdx));
[yB_0605_pattern, ym_0605_pattern, yr_0605_pattern] = minmax_norm_y(data_0605(:,pattern_dVoltIdx));

ym_0506_pattern = ym_05plus06plus07_pattern;
ym_0605_pattern = ym_05plus06plus07_pattern;
yr_0506_pattern = yr_05plus06plus07_pattern;
yr_0605_pattern = yr_05plus06plus07_pattern;  

yRef = data_05plus06plus07(:,pattern_dVoltIdx);
ym = min(yRef);
yr = max(yRef) - min(yRef);

yData = data_0506(:,pattern_dVoltIdx);
yB_0506_pattern = (yData - ym)/yr; 
yData = data_0605(:,pattern_dVoltIdx);
yB_0605_pattern = (yData - ym)/yr; 

%%

