clear % 이전 그래프는 지우지 않는다.
clear all 
close all %  이전 그래프는 지운다.
load B0005.mat
load B0006.mat
load B0007.mat
load B0018.mat


cap5 = extract_discharge(B0005);
cap6 = extract_discharge(B0006);
cap7 = extract_discharge(B0007);
cap18 = extract_discharge(B0018);

% A set of four Li-ion batteries (# 5, 6, 7 and 18) 
% were run through 3 different operational profiles (charge, discharge and impedance) at room temperature. 
% Charging was carried out in a constant current (CC) mode at 1.5A until the battery voltage reached 4.2V 
% and then continued in a constant voltage (CV) mode until the charge current dropped to 20mA. 
% Discharge was carried out at a constant current (CC) level of 2A 
% until the battery voltage fell to 2.7V, 2.5V, 2.2V and 2.5V for batteries 5 6 7 and 18 respectively. 
% Impedance measurement was carried out through an electrochemical impedance spectroscopy (EIS) frequency sweep from 0.1Hz to 5kHz. Repeated charge and discharge cycles result in accelerated aging of the batteries while impedance measurements provide insight into the internal battery parameters that change as aging progresses. The experiments were stopped when the batteries reached end-of-life (EOL) criteria, which was a 30% fade in rated capacity (from 2Ahr to 1.4Ahr). This dataset can be used for the prediction of both remaining charge (for a given discharge cycle) and remaining useful life (RUL).

pattern_CRate = 1;
pattern_restTime = 1; % dynamic 

pattern_dVolt_const5 = 4.2-2.7; % driving range
pattern_CRate5 = 1;
pattern_restTime5 = 1; % dynamic 

pattern_dVolt_const6 = 4.2-2.5; % driving range
pattern_CRate6 = 1;
pattern_restTime6 = 1; % dynamic 

pattern_dVolt_const7 = 4.2-2.2; % driving range
pattern_CRate7 = 1;
pattern_restTime7 = 1; % dynamic 

pattern_dVolt_const18 = 4.2-2.5; % driving range
pattern_CRate18 = 1;
pattern_restTime18 = 1; % dynamic 


%result = [cap',cycleTime',restTime',restCycle',cTempMax',cTempMaxDt',cTempMaxDtAdj',ohm',re_c',re_d',cycleNoChargeRe',cycleNoDischargeRe',dTempMax',dTempMaxDt',dTempMaxDtAdj' ];
i=1;
capacityIdx = i; i=i+1;
cycleTimeIdx = i; i=i+1;
restTimeIdx = i; i=i+1;
restCycleIdx = i; i=i+1;
cTempMaxIdx = i; i=i+1;
cTempMaxDtIdx = i; i=i+1;
cTempMaxDtAdjIdx = i; i=i+1;
ohmIdx = i; i=i+1;
re_cIdx = i; i=i+1;
re_dIdx = i; i=i+1;
cycleNoChageReIdx = i; i=i+1;
cycleNoDischageReIdx = i; i=i+1;
dTempMaxIdx = i; i=i+1;
dTempMaxDtIdx = i; i=i+1;
dTempMaxDtAdjIdx = i; i=i+1;
pattern_dVoltIdx = i; i=i+1;

result5_ = extract_feature_all(B0005,0,cap5);
% https://kr.mathworks.com/matlabcentral/answers/269056-how-to-initialize-a-row-vector-with-value-zero-of-size-1xn
pattern_dVolt5_vector = ones(length(result5_),1) * pattern_dVolt_const5; 
result5 = [result5_ pattern_dVolt5_vector];

i = 1;
capacity5 = result5(:,i)'; i=i+1;
cycleTime5 = result5(:,i)'; i=i+1;
restTime5 = result5(:,i)'; i=i+1;
restCycle5 = result5(:,i)'; i=i+1;
cTempMax5 = result5(:,i)'; i=i+1;
cTempMaxDt5 = result5(:,i)'; i=i+1;
cTempMaxDtAdj5 = result5(:,i)'; i=i+1;
ohm5  = result5(:,i)'; i=i+1;
re_c5 =  result5(:,i)'; i=i+1;
re_d5 = result5(:,i)'; i=i+1;
cycleNoChageRe5 = result5(:,i)'; i=i+1;
cycleNoDischageRe5 = result5(:,i)'; i=i+1;
dTempMax5 = result5(:,i)'; i=i+1;
dTempMaxDt5 = result5(:,i)'; i=i+1;
dTempMaxDtAdj5 = result5(:,i)'; i=i+1;
pattern_dVolt5 = result5(:,i)'; i=i+1;

%%
result6_ = extract_feature_all(B0006,0,cap6);
pattern_dVolt6_vector = ones(length(result6_),1) * pattern_dVolt_const6; 
result6 = [result6_ pattern_dVolt6_vector];

i = 1;
capacity6 = result6(:,i)'; i=i+1;
cycleTime6 = result6(:,i)'; i=i+1;
restTime6 = result6(:,i)'; i=i+1;
restCycle6 = result6(:,i)'; i=i+1;
cTempMax6 = result6(:,i)'; i=i+1;
cTempMaxDt6 = result6(:,i)'; i=i+1;
cTempMaxDtAdj6 = result6(:,i)'; i=i+1;
ohm6  = result6(:,i)'; i=i+1;
re_c6 =  result6(:,i)'; i=i+1;
re_d6 = result6(:,i)'; i=i+1;
cycleNoChageRe6 = result6(:,i)'; i=i+1;
cycleNoDischageRe6 = result6(:,i)'; i=i+1;
dTempMax6 = result6(:,i)'; i=i+1;
dTempMaxDt6 = result6(:,i)'; i=i+1;
dTempMaxDtAdj6 = result6(:,i)'; i=i+1;
pattern_dVolt6 = result6(:,i)'; i=i+1;

%%
result7_ = extract_feature_all(B0007,0,cap7);
pattern_dVolt7_vector = ones(length(result7_),1) * pattern_dVolt_const7; 
result7 = [result7_ pattern_dVolt7_vector];

i = 1;
capacity7 = result7(:,i)'; i=i+1;
cycleTime7 = result7(:,i)'; i=i+1;
restTime7 = result7(:,i)'; i=i+1;
restCycle7 = result7(:,i)'; i=i+1;
cTempMax7 = result7(:,i)'; i=i+1;
cTempMaxDt7 = result7(:,i)'; i=i+1;
cTempMaxDtAdj7 = result7(:,i)'; i=i+1;
ohm7  = result7(:,i)'; i=i+1;
re_c7 =  result7(:,i)'; i=i+1;
re_d7 = result7(:,i)'; i=i+1;
cycleNoChageRe7 = result7(:,i)'; i=i+1;
cycleNoDischageRe7 = result7(:,i)'; i=i+1;
dTempMax7 = result7(:,i)'; i=i+1;
dTempMaxDt7 = result7(:,i)'; i=i+1;
dTempMaxDtAdj7 = result7(:,i)'; i=i+1;
pattern_dVolt7 = result7(:,i)'; i=i+1;

%%
result18_ = extract_feature_all(B0018,0,cap18);
pattern_dVolt18_vector = ones(length(result18_),1) * pattern_dVolt_const18; 
result18 = [result18_ pattern_dVolt18_vector];
i = 1;
capacity18 = result18(:,i)'; i=i+1;
cycleTime18 = result18(:,i)'; i=i+1;
restTime18 = result18(:,i)'; i=i+1;
restCycle18 = result18(:,i)'; i=i+1;
cTempMax18 = result18(:,i)'; i=i+1;
cTempMaxDt18 = result18(:,i)'; i=i+1;
cTempMaxDtAdj18 = result18(:,i)'; i=i+1;
ohm18  = result18(:,i)'; i=i+1;
re_c18 =  result18(:,i)'; i=i+1;
re_d18 = result18(:,i)'; i=i+1;
cycleNoChageRe18 = result18(:,i)'; i=i+1;
cycleNoDischageRe18 = result18(:,i)'; i=i+1;
dTempMax18 = result18(:,i)'; i=i+1;
dTempMaxDt18 = result18(:,i)'; i=i+1;
dTempMaxDtAdj18 = result18(:,i)'; i=i+1;
pattern_dVolt18 = result18(:,i)'; i=i+1;

%% org graph - cycle
cycle_number = length(capacity5);

figure
plot(capacity5), hold on, plot(capacity6), plot(capacity7), plot(capacity18)
plot(1:cycle_number, 1.4*ones(1, cycle_number),'k--','LineWidth', 2)
hold off, grid on
xlabel Cycle, ylabel Capacity(Ah)
legend('Battery #5', 'Battery #6', 'Battery #7', 'Battery #18','Failure Threshold')
title('Capacity Degradations in Cycle')

%% org graph -  time 
figure
plot(cycleTime5,capacity5), hold on, plot(cycleTime6,capacity6), plot(cycleTime7,capacity7), plot(cycleTime18,capacity18)
plot(1:cycle_number, 1.4*ones(1, cycle_number),'k--','LineWidth', 2)
hold off, grid on
xlabel Hours, ylabel Capacity(Ah)
legend('Battery #5', 'Battery #6', 'Battery #7', 'Battery #18','Failure Threshold')
title('Capacity Degradations in Hours')

%% new graph using my function - cycle
figure
plot(capacity5), hold on, plot(capacity6), plot(capacity7), plot(capacity18)
plot(1:cycle_number, 1.4*ones(1, cycle_number),'k--','LineWidth', 2)
hold off, grid on
xlabel Cycle, ylabel Capacity(Ah)
legend('Battery #5', 'Battery #6', 'Battery #7', 'Battery #18','Failure Threshold')
title('Capacity Degradations in Cycle - extract feature')

%% new graph using my function - time
figure
plot(cycleTime5,capacity5), hold on, plot(cycleTime6,capacity6), plot(cycleTime7,capacity7), plot(cycleTime18,capacity18)
hold off, grid on
xlabel Hours, ylabel Capacity(Ah)
legend('Battery #5', 'Battery #6', 'Battery #7', 'Battery #18')
title('Capacity Degradations in Hours ')


%% rest time   - cycle
use_plot = true; %false;
% battery 18번이 한번 큰 rest time을 가져서 그래프로 보기 힘들다.
figure
if use_plot
    %plot(restTime5), hold on, plot(restTime6), plot(restTime7)
    % plot(1:cycle_number, 1.4*ones(1, cycle_number),'k--','LineWidth', 2)
    plot(restTime5), hold on, plot(restTime6), plot(restTime7),plot(restTime18)
else
    bar(restTime5), hold on, bar(restTime6), bar(restTime7),bar(restTime18)
end
hold off, grid on
xlabel Cycle, ylabel restTime(hours)
%legend('Battery #5', 'Battery #6', 'Battery #7')
legend('Battery #5', 'Battery #6', 'Battery #7','Battery #18')
title('Rest Time in Cycle ')

%% rest time   - time
figure
if use_plot
    %plot(cycleTime5,restTime5), hold on, plot(cycleTime6,restTime6), plot(cycleTime7,restTime7)
    % plot(1:cycle_number, 1.4*ones(1, cycle_number),'k--','LineWidth', 2)
    plot(cycleTime5,restTime5), hold on, plot(cycleTime6,restTime6), plot(cycleTime7,restTime7),plot(cycleTime18,restTime18)
else
    bar(cycleTime5,restTime5), hold on, bar(cycleTime6,restTime6), bar(cycleTime7,restTime7),bar(cycleTime18,restTime18)
end 
hold off, grid on
xlabel Cycle, ylabel restTime(hours)
%legend('Battery #5', 'Battery #6', 'Battery #7')
legend('Battery #5', 'Battery #6', 'Battery #7', 'Battery #18')
title('Rest Time in Hours ')


%% remove battery 18 

figure

plot(restTime5), hold on, plot(restTime6), plot(restTime7)
hold off, grid on
xlabel Cycle, ylabel restTime(hours)
legend('Battery #5', 'Battery #6', 'Battery #7')
title('Rest Time in Cycle ')

figure
plot(cycleTime5,restTime5), hold on, plot(cycleTime6,restTime6), plot(cycleTime7,restTime7)
hold off, grid on
xlabel Cycle, ylabel restTime(hours)
legend('Battery #5', 'Battery #6', 'Battery #7')
title('Rest Time in Hours ')

%% index
i=1;
capacityIdx = i; i=i+1;
cycleTimeIdx = i; i=i+1;
restTimeIdx = i; i=i+1;
restCycleIdx = i; i=i+1;
cTempMaxIdx = i; i=i+1;
cTempMaxDtIdx = i; i=i+1;
cTempMaxDtAdjIdx = i; i=i+1;
ohmIdx = i; i=i+1;
re_cIdx = i; i=i+1;
re_dIdx = i; i=i+1;
cycleNoChageReIdx = i; i=i+1;
cycleNoDischageReIdx = i; i=i+1;
dTempMaxIdx = i; i=i+1;
dTempMaxDtIdx = i; i=i+1;idxResult = i; i=i+1;
dTempMaxDtAdjIdx = i; i=i+1;

%% create vector / table
    
regression_vector5 = [ ...
    result5(:, restTimeIdx ) ... 
    result5(:, cTempMaxDtAdjIdx ) ...
    result5(:, ohmIdx ) ...
    result5(:, pattern_dVoltIdx ) ...
    result5(:, capacityIdx ) ] ;

regression_vector6 = [ ...
    result6(:, restTimeIdx ) ... 
    result6(:, cTempMaxDtAdjIdx ) ...
    result6(:, ohmIdx ) ...
    result6(:, pattern_dVoltIdx ) ...
    result6(:, capacityIdx ) ] ;

regression_vector7 = [ ...
    result7(:, restTimeIdx ) ... 
    result7(:, cTempMaxDtAdjIdx ) ...
    result7(:, ohmIdx ) ...
    result7(:, pattern_dVoltIdx ) ...
    result7(:, capacityIdx ) ] ;

regression_vector18 = [ ...
    result18(:, restTimeIdx ) ... 
    result18(:, cTempMaxDtAdjIdx ) ...
    result18(:, ohmIdx ) ...
    result18(:, pattern_dVoltIdx ) ...
    result18(:, capacityIdx ) ] ;

% works
regression_table5 = array2table(regression_vector5,...
    'VariableNames',{'restTime','cTempMaxDtAdj','ohm','pattern_dVolt','capacity'});

regression_table6 = array2table(regression_vector6,...
    'VariableNames',{'restTime','cTempMaxDtAdj','ohm','pattern_dVolt','capacity'});

regression_table7 = array2table(regression_vector7,...
    'VariableNames',{'restTime','cTempMaxDtAdj','ohm','pattern_dVolt','capacity'});

regression_table18 = array2table(regression_vector18,...
    'VariableNames',{'restTime','cTempMaxDtAdj','ohm','pattern_dVolt','capacity'});

    
% https://kr.mathworks.com/help/matlab/ref/cell2table.html    
% works
%{
regression_table_5 = array2table(regression_vector5,...
    'VariableNames',{'restTime','cTempMaxDtAdj','ohm','capacity'});

regression_table_6 = array2table(regression_vector6,...
    'VariableNames',{'restTime','cTempMaxDtAdj','ohm','capacity'});
%}

%% correlation

figure
[R5,PValue5] = corrplot(regression_vector5,'type','Pearson','testR','on','varNames',{'restTime','cTempMaxDtAdj','ohm','pattern_dVolt','capacity'})
figure
[R6,PValue6] = corrplot(regression_vector6,'type','Pearson','testR','on','varNames',{'restTime','cTempMaxDtAdj','ohm','pattern_dVolt','capacity'})

%% linear regression

% https://kr.mathworks.com/help/stats/fitlm.html
modelspec = ' capacity ~ restTime + cTempMaxDtAdj + ohm + pattern_dVolt '
modelspecSingleX = ' capacity ~  cTempMaxDtAdj + pattern_dVolt '

mdl5 = fitlm(regression_table5,modelspec )
mdlSingleX5 = fitlm(regression_table5,modelspecSingleX )



%% culcurate hat 
% https://kr.mathworks.com/help/matlab/matlab_prog/access-data-in-a-table.html
capacitySingleXHat5_ = table2array(mdlSingleX5.Coefficients(1,1)) ...
    + table2array(mdlSingleX5.Coefficients(2,1))*table2array(regression_table5(:,{'cTempMaxDtAdj'}))  ... 
    + table2array(mdlSingleX5.Coefficients(3,1))*table2array(regression_table5(:,{'pattern_dVolt'})) 

capacitySingleXHat5 = capacitySingleXHat5_' ;

capacityHat5_ = table2array(mdl5.Coefficients(1,1)) ...
    + table2array(mdl5.Coefficients(2,1))*table2array(regression_table5(:,{'restTime'})) ...
    + table2array(mdl5.Coefficients(3,1))*table2array(regression_table5(:,{'cTempMaxDtAdj'}))  ...
    + table2array(mdl5.Coefficients(4,1))*table2array(regression_table5(:,{'ohm'})) ... 
    + table2array(mdl5.Coefficients(5,1))*table2array(regression_table5(:,{'pattern_dVolt'})) ;
    
capacityHat5 = capacityHat5_' ;



%% plot - model
figure
plot(mdl5)
hold on 
plot(mdlSingleX5)
hold off
legend('{MultiVar,SigleVar} + pattern_dVolt ')


%% plot - residuals 
plotResiduals(mdl5)
legend('MultiVar  + pattern_dVolt')
figure
plotResiduals(mdlSingleX5)
legend('SigleVar  + pattern_dVolt')
figure


%% plot - hat 
figure
plot(capacity5), hold on, plot(capacityHat5),plot(capacitySingleXHat5)
plot(0:180, 1.4*ones(1, 181),'k--','LineWidth', 2)
hold off, grid on
xlabel Cycle, ylabel Capacity(Ah)
legend('Battery #5 measure', 'Battery #5 predict', 'Battery #5 predict SingleX','Failure Threshold')
title('Capacity Degradations in Cycle - measure and predict')

%%

% https://kr.mathworks.com/matlabcentral/answers/4064-rmse-root-mean-square-error
% https://kr.mathworks.com/matlabcentral/answers/234047-plot-mean-square-error

%%
% https://kr.mathworks.com/matlabcentral/answers/26944-plotting-rmse
% not works
%{
dt = 0.1;
k = length(capacity5);
capacityT5 = capacity5';
capacitySingleXHatT5 = capacitySingleXHat5';
err(k)=sqrt(sum(capacityT5(1:k,1)-capacitySingleXHatT5(1:k,1))^2/k);
t(k) = dt*k;  %simulation time, where dt is time for one increment of loop
%outside of loop:
figure
plot(err,t)
title('RMSE of Battery #5 with Single X variable ')
%}


%%
N = length(capacity5);
for i = 1:N-1
    mse_var(i) = mean((capacity5(i)-capacitySingleXHat5(i)).^2);
end
figure
plot(abs(mse_var));
title('MSE of Battery #5 with Single X variable ')

%% summary
% https://kr.mathworks.com/help/stats/linearmodel.html
anova(mdl5,'summary')
anova(mdlSingleX5,'summary')


mdl5.RMSE % 0.0131
mdl5.SSE



%% model from battery 5 - predict other battery
pred6_by5 = predict(mdlSingleX5,regression_table6(:,{'cTempMaxDtAdj'}));
pred7_by5 = predict(mdlSingleX5,regression_table7(:,{'cTempMaxDtAdj'}));
pred18_by5 = predict(mdlSingleX5,regression_table18(:,{'cTempMaxDtAdj'}));

%% plot
cycle_number = length(capacity5);

figure
plot(capacity5,'r'), hold on, plot(capacity6,'g'), plot(capacity7,'b'), plot(capacity18,'c')
plot(capacitySingleXHat5,'r--'), hold on, plot(pred6_by5,'g--'), plot(pred7_by5,'b--'), plot(pred18_by5,'c--')
plot(1:cycle_number, 1.4*ones(1, cycle_number),'k--','LineWidth', 2)
hold off, grid on
xlabel Cycle, ylabel Capacity(Ah)
legend('#5', '#6', '#7', '#18','#5 pred', '#6 pred', '#7 pred', '#18 pred','Failure Threshold')
title('Capacity Degradations by model for #5 - signle X var in Cycle')

% 18 번 6번은 잘 적용이 안되고 특히 18번은 오류가 많다.
% 아무래도 cTempMaxDtAdj 값이 해당 배터리에서 적용이 잘 안되는 것 같다.

%% ARIMA 
% https://www.kaggle.com/sumi25/understand-arima-and-tune-p-d-q
% https://machinelearningmastery.com/arima-for-time-series-forecasting-with-python/


%%