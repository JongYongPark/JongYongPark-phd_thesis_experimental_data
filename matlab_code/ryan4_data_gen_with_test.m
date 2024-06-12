%% 
% <https://github.com/Mamtapriya/Linear-Regression-of-data-driven-battery https://github.com/Mamtapriya/Linear-Regression-of-data-driven-battery>
% 
% 
% 
% <https://github.com/Ronakj2904/BatteryManagementSystem_Algorithm_usingMatlab/tree/master/State_Of_Charge 
% https://github.com/Ronakj2904/BatteryManagementSystem_Algorithm_usingMatlab/tree/master/State_Of_Charge>
% 
% <https://github.com/jollylst/MoBike_LifeCyclePrediction/blob/master/MoBike%20V1.0.ipynb 
% https://github.com/jollylst/MoBike_LifeCyclePrediction/blob/master/MoBike%20V1.0.ipynb>
% 
% <https://github.com/er-sourav99/Forest_Fires_Dataset_Analysis_and_prediction/blob/master/Forest_Fires_Prediction.ipynb 
% https://github.com/er-sourav99/Forest_Fires_Dataset_Analysis_and_prediction/blob/master/Forest_Fires_Prediction.ipynb>
% 
% <https://github.com/jhagyanesh/Telecom-Churn-Prediction/blob/master/Gyanesh_Jha_Telecom-Churn.ipynb 
% https://github.com/jhagyanesh/Telecom-Churn-Prediction/blob/master/Gyanesh_Jha_Telecom-Churn.ipynb>
% 
% <https://github.com/Mamtapriya/Linear-Regression-of-data-driven-battery https://github.com/Mamtapriya/Linear-Regression-of-data-driven-battery>
% 
% <https://github.com/Mamtapriya/Linear-Regression-of-data-driven-battery/blob/main/Batch1_Linear_Regression.ipynb 
% https://github.com/Mamtapriya/Linear-Regression-of-data-driven-battery/blob/main/Batch1_Linear_Regression.ipynb>
% 
% 
% 
% 
% 
% <https://github.com/Mamtapriya/Linear-Regression-of-data-driven-battery/blob/main/Load_Data_Linear_Regression.ipynb 
% https://github.com/Mamtapriya/Linear-Regression-of-data-driven-battery/blob/main/Load_Data_Linear_Regression.ipynb>
% 
% <https://github.com/lanmei1211/Battery_Cycle_Life_Prediction_Pytorch/blob/a5c4705111feb14a8739595c50be4cac0eca3157/data_preprocessing.py#L112 
% https://github.com/lanmei1211/Battery_Cycle_Life_Prediction_Pytorch/blob/a5c4705111feb14a8739595c50be4cac0eca3157/data_preprocessing.py#L112>
% 
% 
% 
% 
% 
% 
% 
% 
% 
% 
% 
% 
%% 
%% 데이타 읽어 들이기.

%['ap:/nobackup/_phd_work/_battery_soh/_dataset/data.matr.io/2017-05-12_batchdata_updated_struct_errorcorrect.mat',
%           'C:/nobackup/_phd_work/_battery_soh/_dataset/data.matr.io/2017-06-30_batchdata_updated_struct_errorcorrect.mat',
%           'C:/nobackup/_phd_work/_battery_soh/_dataset/data.matr.io/2018-04-12_batchdata_updated_struct_errorcorrect.mat']

% do not run this.
error aahalha 

clear ;
close all;

batchNum = 1;
load C:\nobackup\_phd_work\_battery_soh\_dataset\data.matr.io\2017-05-12_batchdata_updated_struct_errorcorrect.mat
trainData = batch;
clear batch
clear batch_date

load C:\nobackup\_phd_work\_battery_soh\_dataset\data.matr.io\2017-06-30_batchdata_updated_struct_errorcorrect.mat
trainData2 = batch;
clear batch
clear batch_date

load C:\nobackup\_phd_work\_battery_soh\_dataset\data.matr.io\2018-04-12_batchdata_updated_struct_errorcorrect.mat
trainData3 = batch;
clear batch
clear batch_date

ryan4_battery_dataset_raw_org_sample1 = trainData(1);
ryan4_battery_dataset_raw_org_sample2 = trainData(2);
ryan4_battery_dataset_raw_org_sample3 = trainData(3);

save('ryan4_battery_dataset_raw_org_sample1.mat','ryan4_battery_dataset_raw_org_sample1' )
save('ryan4_battery_dataset_raw_org_sample2.mat','ryan4_battery_dataset_raw_org_sample2' )
save('ryan4_battery_dataset_raw_org_sample3.mat','ryan4_battery_dataset_raw_org_sample3' )

%% ryan4_extract_feature test

% function structData  = ryan4_extract_feature(batchNum,batNum,B)
batchNum = 1;
batNum = 2;
B = trainData(2);

% ignore all cycle which dose not compose charge-dischage pair. some cycles
% have duplicated same cycles.
% delete regenratoin cycle is done in outside of this function
% v3 - add Voltage/Current/temp

%% all
%cap,cTempMax,cTempMaxDtSec,cTempMaxDtAdj,ohm,re_c,re_d,dTempMax,dTempMaxDt,dTempMaxDtAdj
% cap 에서 하나의 index 가 빠진다. 하지만 일단 무시해도 된다.

    cycles = zeros();
    cycles_lin = zeros();
    %%%%
    %structData = struct([]);
    structData = struct();
    structData.policy = B.policy ;
    structData.policy_readable = B.policy_readable ;
    structData.channel_id = B.channel_id;
    structData.cycle_life = B.cycle_life;
    structData.key = "b" +  num2str(batchNum) + "c" + num2str(batNum) ;
    structData.batchNum = batchNum;
    structData.batNum = batNum;
    
    % to remove data under EOL
    if batchNum ==  1
        new_cycle_end_idx = B.cycle_life - 1;
        new_cycle_start_idx = 2;
        structData.cycle_life = B.cycle_life -2 ;
    else
        new_cycle_end_idx = B.cycle_life - 1;
        new_cycle_start_idx = 1;
        structData.cycle_life = B.cycle_life - 1 ;
    end

    
    
    % change end to new_cycle_end_idx
    chargetime   = B.summary.chargetime(new_cycle_start_idx:new_cycle_end_idx,:);
    cycle        = B.summary.cycle(new_cycle_start_idx:new_cycle_end_idx,:);
    IR           = B.summary.IR(new_cycle_start_idx:new_cycle_end_idx,:);
    QCharge      = B.summary.QCharge(new_cycle_start_idx:new_cycle_end_idx,:);
    QDischarge   = B.summary.QDischarge(new_cycle_start_idx:new_cycle_end_idx,:);
    Tavg         = B.summary.Tavg(new_cycle_start_idx:new_cycle_end_idx,:);
    Tmin         = B.summary.Tmin(new_cycle_start_idx:new_cycle_end_idx,:);
    Tmax         = B.summary.Tmax(new_cycle_start_idx:new_cycle_end_idx,:);
    cycle        = cycle-1;
    Vdlin        = B.Vdlin(1:10:end);
	
	
	structData.chargetime   = chargetime ;
    structData.cycle        = cycle      ;
    structData.IR           = IR      ;   
    structData.QCharge      = QCharge    ;
    structData.QDischarge   = QDischarge ;
    structData.Tavg         = Tavg       ;
    structData.Tmin         = Tmin       ;
    structData.Tmax         = Tmax       ;
    structData.cycle        = cycle      ;
    structData.Vdlin        = Vdlin      ;
    
    cycleNum = 1;   
    VT_leng = 0;
    break_pioint = 0;
    xq_new = linspace(0.0,1.2,101);
    %xq_new = linspace(0.0,1.2,101); % SOC
    %xq_new = xq_new(2:end);  % remove 0 
    newcycleNum = 1;
    
     for cycleNum = new_cycle_start_idx: new_cycle_end_idx  
             %% V I T
             %% charge
            try
                index_middle = zeros();
                Qc_tmp = B.cycles(cycleNum).Qc;
                Qc_tmp(Qc_tmp<0) = 0;
                [xq, index] = unique(Qc_tmp,"first");
                [xq_last, index_last] = unique(Qc_tmp,"last");
                
                idxCount=1;
                if index(idxCount) ~= index_last(idxCount)
                    index_middle = round((index(idxCount) + index_last(idxCount))/2);
                else
                    index_middle = index(idxCount);
                end

                for idxCount=2 : length(index)
                    if index(idxCount) ~= index_last(idxCount)
                        index_middle = [index_middle round((index(idxCount) + index_last(idxCount))/2)];
                    else
                        index_middle = [index_middle index(idxCount)];
                    end
                end
                index = index_middle;
                
                %yQc = B.cycles(cycleNum).Qc(index);
                yTime_c  =  B.cycles(cycleNum).t(index);
                yV = B.cycles(cycleNum).V(index);
                yI_c = B.cycles(cycleNum).I(index);
                yT = B.cycles(cycleNum).T(index);
                
                %yQc = interp1(xq,yQc,xq_new,'linear');
                yTime_c = interp1(xq,yTime_c,xq_new,'linear');
                yV = interp1(xq,yV,xq_new,'linear');
                yI_c = interp1(xq,yI_c,xq_new,'linear');
                yT = interp1(xq,yT,xq_new,'linear');
            
                %yQc = fillmissing(yQc,'nearest');    
                yTime_c = fillmissing(yTime_c,'nearest');    
                yV = fillmissing(yV,'nearest');
                yI_c(isnan(yI_c)) = 0; % e
                %yT = fillmissing(yT,'movmean', 50) ; 
                yT = fillmissing(yT,'nearest');
                
                yTime_c = yTime_c(2:end);
                yV = yV(2:end);
                yI_c = yI_c(2:end);
                yT = yT(2:end);

            catch
                batchNum
                batNum
                cycleNum
                break_pioint= 1
            end 
             %VTcharge(cycleNum, :) = [yV, yT];   
            
            Vc(newcycleNum, :) = yV';
            Tc(newcycleNum, :) = yT';
            Ic(newcycleNum, :) = yI_c';
            Time_c(newcycleNum, :) = yTime_c';
            %Qc(newcycleNum, :) = yQc';
            
            %% discarge

            
            try
                index_middle = zeros();
                Qd_tmp = B.cycles(cycleNum).Qd;
                Qd_tmp(Qd_tmp<0) = 0;
                [xq, index] = unique(Qd_tmp,"first");
                [xq_last, index_last] = unique(Qd_tmp,"last");
                
                idxCount=1;
                if index(idxCount) ~= index_last(idxCount)
                    index_middle = round((index(idxCount) + index_last(idxCount))/2);
                else
                    index_middle = index(idxCount);
                end

                for idxCount =2: length(index)
                    if index(idxCount) ~= index_last(idxCount)
                        index_middle = [index_middle round((index(idxCount) + index_last(idxCount))/2)];
                    else
                        index_middle = [index_middle index(idxCount)];
                    end
                end
                index = index_middle;

                
                %yQd  =  B.cycles(cycleNum).t(index);
                yTime_d  =  B.cycles(cycleNum).t(index);
                yV = B.cycles(cycleNum).V(index);
                yI_d = B.cycles(cycleNum).I(index);
                yT = B.cycles(cycleNum).T(index);

                %yQd = interp1(xq,yQd,xq_new,'linear');
                yTime_d = interp1(xq,yTime_d,xq_new,'linear');
                yV = interp1(xq,yV,xq_new,'linear');
                yI_d = interp1(xq,yI_d,xq_new,'linear');
                yT = interp1(xq,yT,xq_new,'linear');

                %yQd = fillmissing(yQd,'nearest');
                yTime_d = fillmissing(yTime_d,'nearest');
                yV = fillmissing(yV,'nearest');
                yI_d(isnan(yI_d)) = 0;
                % yT = fillmissing(yT,'linear','SamplePoints',xq_new);
                yT = fillmissing(yT,'nearest');
                %yT = yT(cumsum(idxT)); % fill nana by last value
                deltaT = yTime_d(7) - yTime_d(6);
                %deltaT2 = deltaT+ deltaT;
                endVal = yTime_d(end) - yTime_d(6) + deltaT;
                
                %aaa = [ yTime_d(6:end)-yTime_d(6)+deltaT , endVal+deltaT , v+deltaT*2 ,endVal+deltaT*3 ,endVal+deltaT*4] ;
                aaa =  yTime_d(6:end)-yTime_d(6)+deltaT;
                bbb = [ endVal+deltaT , endVal+deltaT*2 ,endVal+deltaT*3 ,endVal+deltaT*4] ;
                yTime_d1 = [ aaa bbb ];
                yTime_d = yTime_d(2:end);
                yV = yV(2:end);
                yI_d = yI_d(2:end);
                yT = yT(2:end);
                
            catch
                batchNum
                batNum
                cycleNum
                break_pioint = 2
            end 
            
            Vd(newcycleNum, :) = yV';
            Td(newcycleNum, :) = yT';
            Id(newcycleNum, :) = yI_d';
            Time_d(newcycleNum, :) = yTime_d';
            Time_d1(newcycleNum, :) = yTime_d1';
            %Qd(newcycleNum, :) = yQd';
            

   
            if cycleNum == 2
                VT_leng = length(xq_new);
                %chargeI = yI_c;
                %dischargeI = yI_d;
            end
            
            discharge_dQdV(newcycleNum, :) = B.cycles(cycleNum).discharge_dQdV(1:10:end)';
            Qdlin(newcycleNum, :) = B.cycles(cycleNum).Qdlin(1:10:end)';
            Tdlin(newcycleNum, :) = B.cycles(cycleNum).Tdlin(1:10:end)';

            %%%%%%%%%%%%%%%%%%%%%%
            %% time based - 방전시간이 각각 달라서 적용하기 어렵다.
            
            %%%%%%%%%%%%%%%%%%%
            %% finally 
            cycleNum = cycleNum+1;
            newcycleNum = newcycleNum +1;
     end   
    
    %structData.cycle_life = structData.cycle_life -2 ;
    structData.Vc = Vc;
    structData.Tc = Tc;    
    structData.Vd = Vd;
    structData.Td = Td;
    structData.VT_leng = VT_leng;
    structData.Ic = Ic; %chargeI;
    structData.Id = Id; %dischargeI;
    %structData.total_cycle = cycleNum;
    structData.Time_c = Time_c;
    structData.Time_d = Time_d;
    structData.Time_d1 = Time_d1;
    structData.discharge_dQdV = discharge_dQdV;
    structData.Qdlin = Qdlin;
    structData.Tdlin = Tdlin;
    
    QChargeSmooth = smooth(structData.cycle, structData.QCharge ,0.1,'rloess');
    QDischargeSmooth = smooth(structData.cycle, structData.QDischarge ,0.1,'rloess');
    QDischargePolyMdl = polyfit(structData.cycle, QDischargeSmooth,4);
    QDischargePolyfit = polyval(QDischargePolyMdl,structData.cycle')';
    
	structData.QChargeSmooth     = QChargeSmooth    ; 
    structData.QDischargeSmooth  = QDischargeSmooth  ;
    structData.QDischargePolyMdl = QDischargePolyMdl ;
    structData.QDischargePolyfit = QDischargePolyfit  ;    
    
    Time_dT = Time_d';
    
%%
    figure
    plot(Vc')
    
    
    Vc_start = Vc(1,:);
    Vc_end = Vc(end,:);
    figure, hold on 
    plot(Vc_start)
    plot(Vc_end,'--')
    hold off
    figure
    plot(Vd')

    Vd_start = Vd(1,:);
    Vd_end = Vd(end,:);
    
    figure, hold on 
    plot(Vd_start)
    plot(Vd_end,'--')
    hold off
    
    
    figure
    plot(Ic')
    
    
    Ic_start = Ic(1,:);
    Ic_end = Ic(end,:);
    figure, hold on 
    plot(Ic_start)
    plot(Ic_end,'--')
    hold off
    figure
    plot(Id')

    Id_start = Id(1,:);
    Id_end = Id(end,:);
    
    figure, hold on 
    plot(Id_start)
    plot(Id_end,'--')
    hold off
	
    figure
    plot(Tc')
    
    
    Tc_start = Tc(1,:);
    Tc_end = Tc(end,:);
    figure, hold on 
    plot(Tc_start)
    plot(Tc_end,'--')
    hold off
    figure
    plot(Td')

    Td_start = Td(1,:);
    Td_end = Td(end,:);
    
    figure, hold on 
    plot(Td_start)
    plot(Td_end,'--')
    hold off
    
%%
    
	figure
    plot(Time_c')
    
    
    Time_c_start = Time_c(1,:);
    Time_c_end = Time_c(end,:);
    figure, hold on 
    plot(Time_c_start)
    plot(Time_c_end,'--')
    hold off
	
    figure
    plot(Time_d')

    Time_d_start = Time_d(1,:);
    Time_d_end = Time_d(end,:);
    
    figure, hold on 
    plot(Time_d_start)
    plot(Time_d_end,'--')
    hold off
    
%%
figure
plot(Time_d1')

Time_d1_start = Time_d1(1,:);
Time_d1_end = Time_d1(end,:);

figure, hold on 
plot(Time_d1_start)
plot(Time_d1_end,'--')
hold off
%%
new_index = 1;
ryan4_battery_dataset_raw = zeros();
% 이 코드가 중요함. ryan4_battery_dataset_raw 이 structure를 가짐을 알려주어야 함.
ryan4_battery_dataset_raw = ryan4_extract_feature(1,1,trainData(1));
%%

plot_Vc = ryan4_battery_dataset_raw.Vc(1,:)
plot_Vd = ryan4_battery_dataset_raw.Vd(1,:)
plot_Ic = ryan4_battery_dataset_raw.Ic(1,:)
plot_Id = ryan4_battery_dataset_raw.Id(1,:)
plot_Tc = ryan4_battery_dataset_raw.Tc(1,:)
plot_Td = ryan4_battery_dataset_raw.Td(1,:)
plot_Time_c = ryan4_battery_dataset_raw.Time_c(1,:)
plot_Time_d = ryan4_battery_dataset_raw.Time_d(1,:)
plot_Time_d1 = ryan4_battery_dataset_raw.Time_d1(1,:)
plot_discharge_dQdV = ryan4_battery_dataset_raw.discharge_dQdV(1,:)
plot_Qdlin = ryan4_battery_dataset_raw.Qdlin(1,:)
plot_Tdlin = ryan4_battery_dataset_raw.Tdlin(1,:)
plot_Vdlin = ryan4_battery_dataset_raw.Vdlin
%% SOC 측정 함수 테스트 = Ah = Current * Time   
%% SOC = cumsum () 
%% SOCmax = sum(SOC) 
% 


% Ah측정
%ryan4_battery_dataset_raw = ryan4_battery_dataset_raw;
figure, hold on
%for i=1:length(ryan4_battery_dataset_raw.cycle_life)
plot(ryan4_battery_dataset_raw.QDischargeSmooth)
%end
hold off
ryan4_battery_dataset_raw.Time_c(1,1)
ryan4_battery_dataset_raw.Time_c(1,end)
ryan4_battery_dataset_raw.Time_c(2,1)
ryan4_battery_dataset_raw.Time_c(2,end)
ryan4_battery_dataset_raw.Time_c(3,end) 

ryan4_battery_dataset_raw.Time_c(1,end) + ryan4_battery_dataset_raw.Time_c(2,end)

ryan4_battery_dataset_raw.Time_c(1,end) + ryan4_battery_dataset_raw.Time_c(2,end)

ryan4_battery_dataset_raw.Time_c(1,end) + ryan4_battery_dataset_raw.Time_c(2,end) + ryan4_battery_dataset_raw.Time_c(3,end)
ryan4_battery_dataset_raw.Time_c(:,end)

Time_c_end = cumsum(ryan4_battery_dataset_raw.Time_c(:,end))
Time_c_start = cumsum(ryan4_battery_dataset_raw.Time_c(:,end)) - ryan4_battery_dataset_raw.Time_c(1,end)

index = 1
cycle1_time = ryan4_battery_dataset_raw.Time_c(index,:)
cycle1_time_diff = diff(cycle1_time);
%cycle1_time_diff = [0  cycle1_time_diff]
cycle1_time_diff = [ cycle1_time_diff cycle1_time_diff(end)]
offset = 1.0283
calcAh = ryan4_battery_dataset_raw.Ic(index,:) .* cycle1_time_diff .*offset

calcAhSum = sum(calcAh) + calcAh(end) % minute
calcAhSumHour = calcAhSum / 60
ryan4_battery_dataset_raw.QCharge(index)

[SOC_c, soc_max_c] = ryan4_calc_SOC_cali(ryan4_battery_dataset_raw.Ic(index,:), ryan4_battery_dataset_raw.Time_c(index,:), false)
ryan4_battery_dataset_raw.QCharge(index)
ryan4_battery_dataset_raw.QCharge(index) - soc_max_c
ryan4_battery_dataset_raw.QCharge(index) / soc_max_c


[SOC_d, soc_max_d] = ryan4_calc_SOC_cali(ryan4_battery_dataset_raw.Id(index,:), ryan4_battery_dataset_raw.Time_d(index,:), true)
ryan4_battery_dataset_raw.QDischarge(index)
ryan4_battery_dataset_raw.QDischarge(index) - soc_max_d
ryan4_battery_dataset_raw.QDischarge(index) / soc_max_d
[SOC_c, soc_max_c] = ryan4_calc_SOC_with_offset(ryan4_battery_dataset_raw.Ic(index,:), ryan4_battery_dataset_raw.Time_c(index,:), false, 1.1004, 0.3292)
[SOC_d, soc_max_d] = ryan4_calc_SOC_with_offset(ryan4_battery_dataset_raw.Id(index,:), ryan4_battery_dataset_raw.Time_d(index,:), true, 1.1004, 0.3292)
%%%%%%%%%%%%%%%%%%%%%%%
%%

%%%%%%%%%%%%%%%%%%%%%%%
modeDischarge = false;
modeCharge = true;

[Ah_ds_c, Ah_c, SOC_c, SOH_c] = ryan4_calc_SOC_new(ryan4_battery_dataset_raw.Ic(index,:), ryan4_battery_dataset_raw.Time_c(index,:), ryan4_battery_dataset_raw.QChargeSmooth(index))
Ah_c(end) 
SOC_c(end)

[Ah_ds_d, Ah_d, SOC_d, SOH_d] = ryan4_calc_SOC_new(ryan4_battery_dataset_raw.Id(index,:), ryan4_battery_dataset_raw.Time_d(index,:), ryan4_battery_dataset_raw.QDischargeSmooth(index))
Ah_d(end)
SOC_d(end)
%%





x_axis_ah = linspace(0,1.2,102)
x_axis_ah = x_axis_ah(2:end-1)

x_axis_vdlin = linspace(2,3.5,100)

%% 기본 데이타 분석

i=3 
policy = trainData(i).policy 
policy_readable = trainData(i).policy_readable 
channel_id = trainData(i).channel_id
cycle_life = trainData(i).cycle_life
chargetime = trainData(i).summary.chargetime
cycle = trainData(i).summary.cycle
IR = trainData(i).summary.IR
QCharge = trainData(i).summary.QCharge
QDischarge = trainData(i).summary.QDischarge
Vdlin = trainData(i).Vdlin
trainData(i).Vdlin
%% 
% 

cycleNum = 2
cycleNum1 = 100
size ( trainData(3).cycles(2).t )
trainData(3).cycles(2).t 
% trainData(3).cycles(1).t(2:3,:)
 
trainData(3).cycles(cycleNum).t 
%% 그래프로 확인
%% 전체 전류 ( 충/방전 )
% 테스트 환경 설정

test_bat = 6 ;
cycle_div = 500;
%% 측정 포인트 대비 시간 - 1:1 이 아니다.

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).t)
    end
end
hold off , xlabel 'Measure Point' , ylabel 'Time (Min)' , title 'time / point'
% Charge Q / Meature Point


figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qc,'x')
    end
end
hold off , xlabel 'Measure Point' , ylabel 'A' , title 'Charge Q'
% Charge Q / Time

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).Qc,'x')
    end
end
hold off , xlabel 'Time (Min)' , ylabel 'A' , title 'Chager Q'
figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qd,'x')
    end
end
hold off , xlabel 'Measure Point' , ylabel 'A' , title 'Discharge Q'

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).Qd,'x')
    end
end
hold off , xlabel 'Time (Min)' , ylabel 'A' , title 'Discharge Q'
% Qc 와 Qd 를 보면 이를 통해 충전 사이클과 방전 사이클을 확인할 수 있다.

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qc)
        plot(trainData(test_bat).cycles(i).Qd,'-')
    end
end
hold off , xlabel 'Measure Point' , ylabel 'A' , title 'Charge / Discharge Q'
%% 충전 전류 분석
% I는 충방전 전체 사이클에 대한 정보이다.
% 충전시와 방전시로 분리하자.
% 
% Measure Point 는 Cycle 이 증가할 수로 줄어든다.
% Measure Time 는 Cycle 이 증가할 수로 줄어든다.
% x 축의 마지막 값이 cycle 에 따라 달라지면 이를 이용하기 힘들다.
% 
% 
% 

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).I)
        plot(trainData(test_bat).cycles(i).Qc,'x')
        plot(trainData(test_bat).cycles(i).Qd,'+')
    end
end
hold off , xlabel 'Measure Point' , ylabel 'A' , title 'Charge Current'
figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).I)
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).Qc,'x')
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).Qd,'+')        
    end
end
hold off , xlabel 'Time (Min)' , ylabel 'A' , title 'Charge Current'

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qc,trainData(test_bat).cycles(i).I)     
    end
end
hold off , xlabel 'Qc' , ylabel 'A' , title 'Charge Current'
% 아래 그래프에서 이상치가 있어 smooth함수를 사용했지만 큰 개선은 없다.

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qc,smooth(trainData(test_bat).cycles(i).I))     
    end
end
hold off , xlabel 'Qc' , ylabel 'A' , title 'Charge Current - smoothed'
% x축의 단위를 용량기준으로 0 부터 1.2까지의 100개의 포인트로 전환하자. 
% 변환에서 중요한 것은 Qc에 해당하는 I를 구하는 것이다.   
% uniq함수에서  first 인자를 사용하면 동일한 용량값 여려개 있을때 첫번째를 선정하고
% last 인자를 사용하면 동일한 용량값 여러개 있을대 제일 마지막 것을 선정한다.
% 아래 그림에서 Ic를 얻기 위해서는 동일 Qc 의 첫번째 것을 선택해야 하고
% Id를 얻기위해서는 Qd의 마지막 것을 선택해야 한다.
% 그러나 실험결과 first 든 last 든 큰 차이가 없다.
% .

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qc)
        plot(trainData(test_bat).cycles(i).Qd,'-')
    end
end
hold off , xlabel 'Measure Point' , ylabel 'A' , title 'Charge / Discharge Q'
%% 
% 


figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
    [x_c, index] = unique(trainData(test_bat).cycles(i).Qc,"first");
    %[x_c, index] = unique(trainData(test_bat).cycles(cycleNum).Qc)
    y_c = trainData(test_bat).cycles(i).I(index);
    new_x_c = linspace(0,1.2,100);
    new_y_c = interp1(x_c,y_c,new_x_c,'linear');
    new_y_c = fillmissing(new_y_c,'nearest');
    plot(new_x_c,new_y_c);  
    end
end
hold off , xlabel 'Qc' , ylabel 'A' , title 'Charge Current'

length(new_x_c)
index_first = index
figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
    [x_c_first, index_first] = unique(trainData(test_bat).cycles(i).Qc,"first");
    [x_c_last, index_last] = unique(trainData(test_bat).cycles(i).Qc,"last");
    plot(trainData(test_bat).cycles(i).Qc)
    plot(index_first,x_c_first,'_')
    plot(index_last,x_c_last,'|')
    end
end
hold off

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
    [x_c, index] = unique(trainData(test_bat).cycles(i).Qc,"last");
    %[x_c, index] = unique(trainData(test_bat).cycles(cycleNum).Qc)
    y_c = trainData(test_bat).cycles(i).I(index);
    new_x_c = linspace(0,1.2,100);
    new_y_c = interp1(x_c,y_c,new_x_c,'linear');
    new_y_c = fillmissing(new_y_c,'nearest');
    plot(new_x_c,new_y_c);  
    end
end
hold off , xlabel 'Qc' , ylabel 'A' , title 'Charge Current'
length(new_x_c)
index_last = index

indexs = [index_first index_last]
indexs_gap = index_last - index_first
%%

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qd,trainData(test_bat).cycles(i).I)     
    end
end
hold off , xlabel 'Qd' , ylabel 'A' , title 'Discharge Current'

%% 테스트 한것들 


[x_c, index] = unique(trainData(test_bat).cycles(cycleNum).Qc,"last");
%[x_c, index] = unique(trainData(test_bat).cycles(cycleNum).Qc)
y_c = trainData(test_bat).cycles(cycleNum).I(index);
new_x_c = linspace(0,1.2,100);
new_y_c = interp1(x_c,y_c,new_x_c,'linear');
plot(new_x_c,new_y_c);
xlabel("Qc / Ah")
% https://kr.mathworks.com/matlabcentral/answers/88808-fill-nans-in-array-with-last-value?s_tid=ta_ans_results
idx = (~isnan(new_y_c ))
idxNon = isnan(new_y_c )
vr = new_y_c(idx); %v non nan
new_y_c_fix = vr(cumsum(idx)) %use cumsum to build index into vr
plot(new_y_c_fix)
% https://kr.mathworks.com/matlabcentral/answers/6038-convert-zeros-to-nan
% https://kr.mathworks.com/matlabcentral/answers/85568-how-to-convert-nan-to-zero?s_tid=ta_ans_results

new_y_c_fix_fill_zero = new_y_c;
%% not work
%new_y_c_fix_fill_zero(new_y_c_fix_fill_zero==NaN)=0;
%new_y_c_fix_fill_zeroA(find(new_y_c_fix_fill_zero==NaN)) = 0;

%% work
new_y_c_fix_fill_zero(isnan(new_y_c_fix_fill_zero)) = 0;
plot(new_y_c_fix_fill_zero)
%[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd);
[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd,"last");

y_d = trainData(test_bat).cycles(cycleNum).I(index);
new_x_d = linspace(0,1.2,100);
new_y_d = interp1(x_d,y_d,new_x_d,'linear'); 
new_y_d(isnan(new_y_d)) = 0;
plot(new_x_d,new_y_d);
[x_c, index] = unique(trainData(test_bat).cycles(cycleNum).Qc,"last");
%[x_c, index] = unique(trainData(test_bat).cycles(cycleNum).Qc)
y_c = trainData(test_bat).cycles(cycleNum).T(index);
new_x_c = linspace(0,1.2,100);
new_y_c = interp1(x_c,y_c,new_x_c,'linear');
plot(new_x_c,new_y_c);
xlabel("Qc / Ah")
% https://kr.mathworks.com/matlabcentral/answers/88808-fill-nans-in-array-with-last-value?s_tid=ta_ans_results
idx = (~isnan(new_y_c ))
vr = new_y_c(idx); %v non nan
new_y_c_fix = vr(cumsum(idx)) %use cumsum to build index into vr
plot(new_y_c_fix)
% https://kr.mathworks.com/matlabcentral/answers/6038-convert-zeros-to-nan
% https://kr.mathworks.com/matlabcentral/answers/85568-how-to-convert-nan-to-zero?s_tid=ta_ans_results

new_y_c_fix_fill_zero = new_y_c;
%% not work
%new_y_c_fix_fill_zero(new_y_c_fix_fill_zero==NaN)=0;
%new_y_c_fix_fill_zeroA(find(new_y_c_fix_fill_zero==NaN)) = 0;

%% work
new_y_c_fix_fill_zero(isnan(new_y_c_fix_fill_zero)) = 0;
plot(new_y_c_fix_fill_zero)
%[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd);
[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd,"last");

y_d = trainData(test_bat).cycles(cycleNum).T(index);
new_x_d = linspace(0,1.2,100);
new_y_d = interp1(x_d,y_d,new_x_d,'linear'); 
new_y_d(isnan(new_y_d)) = 0;
plot(new_x_d,new_y_d);
[x_c, index] = unique(trainData(test_bat).cycles(cycleNum).Qc,"last");
%[x_c, index] = unique(trainData(test_bat).cycles(cycleNum).Qc)
y_c = trainData(test_bat).cycles(cycleNum).V(index);
new_x_c = linspace(0,1.2,100);
new_y_c = interp1(x_c,y_c,new_x_c,'linear');
plot(new_x_c,new_y_c);
xlabel("Qc / Ah")
% https://kr.mathworks.com/matlabcentral/answers/88808-fill-nans-in-array-with-last-value?s_tid=ta_ans_results
% https://kr.mathworks.com/matlabcentral/answers/29481-last-non-nan-observation
idx = (~isnan(new_y_c ))
vr = new_y_c(idx); %v non nan
new_y_c_fix = vr(cumsum(idx)) %use cumsum to build index into vr
plot(new_y_c_fix)

% https://kr.mathworks.com/matlabcentral/answers/6038-convert-zeros-to-nan
% https://kr.mathworks.com/matlabcentral/answers/85568-how-to-convert-nan-to-zero?s_tid=ta_ans_results

new_y_c_fix_fill_zero = new_y_c;
%% not work
%new_y_c_fix_fill_zero(new_y_c_fix_fill_zero==NaN)=0;
%new_y_c_fix_fill_zeroA(find(new_y_c_fix_fill_zero==NaN)) = 0;

%% work
new_y_c_fix_fill_zero(isnan(new_y_c_fix_fill_zero)) = 0;
plot(new_y_c_fix_fill_zero)
figure
hold on
for i=1:trainData(test_bat).cycle_life-3
    if rem(i,100) == 0
        plot(trainData(test_bat).cycles(i).Qd)
    end
end 
hold off 
figure
hold on
for i=1:trainData(test_bat).cycle_life-3
    if rem(i,100) == 0
    plot(trainData(test_bat).cycles(i).V')
    end
end 
hold off 
%% 

figure
hold on

for i=3:trainData(test_bat).cycle_life-3
    if rem(i,100) == 0
    %[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd);
    [x_d, index] = unique(trainData(test_bat).cycles(i).Qd,"last");
    
    y_d = trainData(test_bat).cycles(i).V(index);
    new_x_d = linspace(0,1.2,100);
    new_y_d = interp1(x_d,y_d,new_x_d,'linear'); 
    new_y_d(isnan(new_y_d)) = 0;
    plot(new_x_d,new_y_d);
    end
end 
hold off
figure
hold on

for i=3:trainData(test_bat).cycle_life-3
    if rem(i,100) == 0
    Qd_tmp = trainData(test_bat).cycles(i).Qd;
    Qd_tmp(Qd_tmp<0) = 0;
    %[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd);
    [xq, index] = unique(Qd_tmp,"first");
    
    yV = trainData(test_bat).cycles(i).V(index);
    xq_new = linspace(0,1.5,100);
    yV = interp1(xq,yV,xq_new,'linear'); 
    yV = fillmissing(yV,'nearest');
    %new_y_d(isnan(new_y_d)) = 0;
    plot(xq_new,yV);
    end
end 
hold off
figure
hold on

for i=3:trainData(test_bat).cycle_life-3
    if rem(i,100) == 0
    Qd_tmp = trainData(test_bat).cycles(i).Qd;
    Qd_tmp(Qd_tmp<0) = 0;
    %[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd);
    [xq, index] = unique(Qd_tmp,"first");
    
    yV = trainData(test_bat).cycles(i).V(index);
    xq_new = linspace(0,1.0,100);
    yV = interp1(xq,yV,xq_new,'linear'); 
    yV = fillmissing(yV,'nearest');
    %new_y_d(isnan(new_y_d)) = 0;
    plot(xq_new,yV);
    end
end 
hold off

%[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd);
[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd,"last");

y_d = trainData(test_bat).cycles(cycleNum).V(index);
new_x_d = linspace(0,1.2,100);
new_y_d = interp1(x_d,y_d,new_x_d,'linear'); 
new_y_d(isnan(new_y_d)) = 0;
plot(new_x_d,new_y_d);
%{
x_indexs = find(trainData(test_bat).cycles(2).Qd')
x_index = x_indexs(1)
x = trainData(test_bat).cycles(2).Qd';
x = x(x_index : end)
y = trainData(test_bat).cycles(2).V';
y = y(x_index : end)
new_x = linspace(0,1.2,100);
new_y = interp1(x,y,new_x,'linear'); 
plot(new_y)
%}   
%% 다시 실험 시작 - 전류는 했으니 전압과 온도에 대해서 하자.

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).V)
        plot(trainData(test_bat).cycles(i).Qc,'x')
        plot(trainData(test_bat).cycles(i).Qd,'+')
    end
end
hold off , xlabel 'Measure Point' , ylabel 'A' , title 'Charge Voltage'
figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).V)
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).Qc,'x')
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).Qd,'+')        
    end
end
hold off , xlabel 'Time (Min)' , ylabel 'A' , title 'Charge Voltage'

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qc,trainData(test_bat).cycles(i).V)     
    end
end
hold off , xlabel 'Qc' , ylabel 'A' , title 'Charge Voltage'

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qd,trainData(test_bat).cycles(i).V)     
    end
end
hold off , xlabel 'Qd' , ylabel 'A' , title 'Discharge Voltage'
%%
figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).T)
        plot(trainData(test_bat).cycles(i).Qc,'x')
        plot(trainData(test_bat).cycles(i).Qd,'+')
    end
end
hold off , xlabel 'Measure Point' , ylabel 'A' , title 'Charge Temperature'
figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).T)
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).Qc,'x')
        plot(trainData(test_bat).cycles(i).t,trainData(test_bat).cycles(i).Qd,'+')        
    end
end
hold off , xlabel 'Time (Min)' , ylabel 'A' , title 'Charge Temperature'

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qc,trainData(test_bat).cycles(i).T)     
    end
end
hold off , xlabel 'Qc' , ylabel 'A' , title 'Charge Temperature'

figure , hold on
for i=1:trainData(test_bat).cycle_life
    if rem(i,cycle_div) == 0
        plot(trainData(test_bat).cycles(i).Qd,trainData(test_bat).cycles(i).T)     
    end
end
hold off , xlabel 'Qd' , ylabel 'A' , title 'Discharge Temperature'


%%



%%

%% 
% 데이타중 첫번째 batch에서 하나를 선택해서 데이타 확인



%batch2_keys = ["b2c8", "b2c9", "b2c10", "b2c16", "b2c17"]
%batch1_keys = ["b1c1","b1c2","b1c3","b1c4","b1c5"]
% src = trainData(1); % src has invaild item on index 1
% dest = trainData2(8); % dest has vaild item on index 1
% merge = merge_struct(trainData(1),trainData2(8));

src = trainData(1); % src has invaild item on index 1
dest = trainData2(8); % dest has vaild item on index 1
%% 
% 특정데이타는 다른 batch에 나눠져 있는 경우가 있어서 이를 합쳐야 한다.

merge = merge_struct(trainData(1),trainData2(8));

% verify
src.cycle_life
dest.cycle_life
src.cycle_life + dest.cycle_life - 1
merge.cycle_life
length(src.summary.QDischarge)
length(dest.summary.QDischarge)
length(merge.summary.QDischarge)
%%%%%%%%%%%
src.summary.QDischarge(1)
src.summary.QDischarge(2)
src.summary.QDischarge(end-1)
src.summary.QDischarge(end)
%%%%
dest.summary.QDischarge(1)
dest.summary.QDischarge(2)
dest.summary.QDischarge(end-1)
dest.summary.QDischarge(end)
%%%%
merge.summary.QDischarge(1)
merge.summary.QDischarge(2)
merge.summary.QDischarge(length(src.summary.QDischarge)-1)
merge.summary.QDischarge(length(src.summary.QDischarge))
merge.summary.QDischarge(length(src.summary.QDischarge)+1)
merge.summary.QDischarge(length(src.summary.QDischarge)+2)
merge.summary.QDischarge(end-1)
merge.summary.QDischarge(end)
test = zeros();
test = ryan4_extract_feature(1,1,merge);

%% 
% #batch1 = pickle.load(open(r'.\Data\batch1.pkl', 'rb'))
% 
% batch1 = pickle.load(open(r'.\batch1.pkl', 'rb'))
% 
% #remove batteries that do not reach 80% capacity
% 
% del batch1['b1c8']
% 
% del batch1['b1c10']
% 
% del batch1['b1c12']
% 
% del batch1['b1c13']
% 
% del batch1['b1c22']
% 
% ///////////
% 
% # There are four cells from batch1 that carried into batch2, we'll remove 
% the data from batch2
% 
% # and put it with the correct cell from batch1
% 
% batch2_keys = ['b2c7', 'b2c8', 'b2c9', 'b2c15', 'b2c16']
% 
% batch1_keys = ['b1c0', 'b1c1', 'b1c2', 'b1c3', 'b1c4']
% 
% add_len = [662, 981, 1060, 208, 482];
% 
% for i, bk in enumerate(batch1_keys):
% 
% batch1[bk]['cycle_life'] = batch1[bk]['cycle_life'] + add_len[i]
% 
% for j in batch1[bk]['summary'].keys():
% 
% if j == 'cycle':
% 
% batch1[bk]['summary'][j] = np.hstack((batch1[bk]['summary'][j], batch2[batch2_keys[i]]['summary'][j] 
% + len(batch1[bk]['summary'][j])))
% 
% else:
% 
% batch1[bk]['summary'][j] = np.hstack((batch1[bk]['summary'][j], batch2[batch2_keys[i]]['summary'][j]))
% 
% last_cycle = len(batch1[bk]['cycles'].keys())
% 
% for j, jk in enumerate(batch2[batch2_keys[i]]['cycles'].keys()):
% 
% batch1[bk]['cycles'][str(last_cycle + j)] = batch2[batch2_keys[i]]['cycles'][jk]
% 
% del batch2['b2c7']
% 
% del batch2['b2c8']
% 
% del batch2['b2c9']
% 
% del batch2['b2c15']
% 
% del batch2['b2c16']
%% 
% 


%%

%%

figure, hold on
plot(x_axis_ah,SOC_c)
plot(x_axis_ah,cumsum(SOC_c))
hold off 
index = 1;
figure, hold on
plot(ryan4_battery_dataset_raw.Ic(index,:))
plot([ 0 diff(ryan4_battery_dataset_raw.Time_c(index,:))])
hold off



figure, hold on
plot(x_axis_ah,SOC_d)
plot(x_axis_ah,cumsum(SOC_d))
hold off 

figure, hold on
plot(ryan4_battery_dataset_raw.Id(index,:))
plot([ 0 diff(ryan4_battery_dataset_raw.Time_d(index,:))])
hold off
%%

%%
figure
plot(trainData(1).cycles(2).Qd)
figure
plot(trainData(1).cycles(2).t, trainData(1).cycles(2).Qd)

figure
plot(trainData(1).Vdlin)
figure
plot(trainData(1).cycles(2).V)
figure
plot(trainData(1).cycles(2).Qd, trainData(1).cycles(2).V)


figure
plot(trainData(1).cycles(2).Qd, trainData(1).cycles(2).Qd)
% https://github.com/lanmei1211/Battery_Cycle_Life_Prediction_Pytorch/blob/a5c4705111feb14a8739595c50be4cac0eca3157/data_preprocessing.py#L121

%{
figure
base = trainData(1).Vdlin';
base(base<0) = 0;
%[x_d, index] = unique(trainData(test_bat).cycles(cycleNum).Qd);
[xq, index] = unique(base,"first");

yQd = trainData(1).cycles(2).Qd(index);
xq_new = linspace(0,999,1000);
yQd = interp1(xq,yQd,xq_new,'linear'); 
yQd = fillmissing(yQd,'nearest');
%new_y_d(isnan(new_y_d)) = 0;
plot(xq_new,yQd);
%}
%%

figure
hold on
plot((trainData2(1).cycles(100).Qdlin - trainData2(1).cycles(2).Qdlin), trainData2(1).Vdlin )
plot((trainData2(2).cycles(100).Qdlin - trainData2(2).cycles(2).Qdlin), trainData2(2).Vdlin )
hold off

%%

figure
plot(trainData(1).cycles(2).Qdlin)

figure
plot(trainData(1).cycles(2).T)
figure 
plot(trainData(1).cycles(2).t, trainData(1).cycles(2).T)

figure 
plot(trainData(1).cycles(2).Qd, trainData(1).cycles(2).T)

figure
plot(trainData(1).cycles(2).Tdlin)


%%
%{
new_time = 0.0;
for i=2:length(ryan4_battery_dataset_raw.cycle_life) 
    time = ryan4_battery_dataset_raw.Time_c(i,end)  
    new_time = [ new_time 
end
%}
%%
ryan4_battery_dataset_raw = zeros();
% 이 코드가 중요함. ryan4_battery_dataset_raw 이 structure를 가짐을 알려주어야 함.
ryan4_battery_dataset_raw = ryan4_extract_feature(1,1,trainData(1));

% 1.1 * 0.8 = 0.88 Ah = EOL
% batch 2 = get data under 0.88 Ah - to remove this data under EOL
test2 = ryan4_extract_feature(2,1,trainData2(1));
test1 = ryan4_extract_feature(1,1,trainData(1));
test3 = ryan4_extract_feature(3,1,trainData3(1));
skip_bat1 = [8 10 12 13 22 ]; % base 0 index
skip_bat1 = skip_bat1 +1; % to 1 index

% # There are four cells from batch1 that carried into batch2, we'll remove the data from batch2
% # and put it with the correct cell from batch1
% batch2_keys = ['b2c7', 'b2c8', 'b2c9', 'b2c15', 'b2c16']
% batch1_keys = ['b1c0', 'b1c1', 'b1c2', 'b1c3', 'b1c4']
% add_len = [662, 981, 1060, 208, 482];

skip_bat2 = [7 8 9 15 16 ]; % base 0 index
skip_bat2 = skip_bat2 +1; % to 1 index

batch2_keys = ["b2c8", "b2c9", "b2c10", "b2c16", "b2c17"];
batch2_fix = [8 9 10 16 17];
batch1_keys = ["b1c1","b1c2","b1c3","b1c4","b1c5"];
batch1_fix = [1 2 3 4 5];

batchNum =1;
for batNum = 1:size(trainData,2)
    if numel(trainData(batNum).summary.cycle) == numel(unique(trainData(batNum).summary.cycle))
        if ismember(batNum,skip_bat1) 
            batNum;
        elseif ismember(batNum,batch1_fix) 
            %ismember(batNum,batch1_fix) % true or fale
            idx = find(batch1_fix==batNum);
            % find(strcmp
%             batch1_fix(idx)
%             batch2_fix(idx)
            src = trainData(batch1_fix(idx));
            dest = trainData2(batch2_fix(idx));
            merge = merge_struct(trainData(batch1_fix(idx)),trainData2(batch2_fix(idx)));
            ryan4_battery_dataset_raw(new_index) = ryan4_extract_feature(batchNum,batNum,merge);
            batNum;      
        else
            ryan4_battery_dataset_raw(new_index) = ryan4_extract_feature(batchNum,batNum,trainData(batNum));
            new_index = new_index + 1;
            batNum;            
        end
    else
        batchNum
        batNum
    end
end
%%%%%%%%%%%%%
batchNum = 2;
for batNum = 1:size(trainData2,2)
    if numel(trainData2(batNum).summary.cycle) == numel(unique(trainData2(batNum).summary.cycle))
        if ismember(batNum,batch2_fix) 
            batNum;
        else
            ryan4_battery_dataset_raw(new_index) = ryan4_extract_feature(batchNum,batNum,trainData2(batNum));
            new_index = new_index + 1;
            batNum;            
        end
    else
        batchNum
        batNum
    end
end


%%%%%%%%%%%%%%%
batchNum = 3;
skip_bat3 = [37 2 23 32 42 43 ]; % base 0 index
skip_bat3 = skip_bat3 +1; % to 1 index

% # remove noisy channels from batch3
% del batch3['b3c37']
% del batch3['b3c2']
% del batch3['b3c23']
% del batch3['b3c32']
% del batch3['b3c42']
% del batch3['b3c43']

for batNum = 1:size(trainData3,2)
    if numel(trainData3(batNum).summary.cycle) == numel(unique(trainData3(batNum).summary.cycle))
        if ismember(batNum,skip_bat3) 
            batNum;
        else
            ryan4_battery_dataset_raw(new_index) = ryan4_extract_feature(batchNum,batNum,trainData3(batNum));
            new_index = new_index + 1;
            batNum;            
        end
    else
        batchNum
        batNum
    end
end

%% 첫번째 정제된 데이타

ryan4_gen_data_raw_org_desc = 'ryan4_gen_data_raw_org_desc';
%save('ryan4_data_raw_org.mat','ryan4_gen_data_raw_org_desc');
save('ryan4_data_raw_org.mat','ryan4_battery_dataset_raw' ,'-append')

ryan4_battery_dataset_raw_sample1 = ryan4_battery_dataset_raw(1);
ryan4_battery_dataset_raw_sample2 = ryan4_battery_dataset_raw(2);
ryan4_battery_dataset_raw_sample3 = ryan4_battery_dataset_raw(3);
%%

save('ryan4_battery_dataset_raw_sample1.mat','ryan4_battery_dataset_raw_sample1' )
save('ryan4_battery_dataset_raw_sample2.mat','ryan4_battery_dataset_raw_sample2' )
save('ryan4_battery_dataset_raw_sample3.mat','ryan4_battery_dataset_raw_sample3' )


%%


%%

%{
clear trainData
clear trainData2
clear trainData3
clear merge
clear src
clear dest


save('ryan4_data_raw_org.mat', 'plot_Vc'                             ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Vd'                             ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Ic'                             ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Id'                             ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Tc'                             ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Td'                             ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Time_c'                         ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Time_d'                        ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_discharge_dQdV'                 ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Qdlin'                          ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Tdlin'                          ,'-append')'
save('ryan4_data_raw_org.mat', 'plot_Vdlin'                          ,'-append')'
%}
%% 시작  Ah을 고정하자. 이보다 큰 데이타는 모두 지우자.
%% 먼저 데이타 하나로 테스트

data_conversion_param = zeros();
data_conversion_param = [0 0 0 0 0 0];

idxAll = (1:length(ryan4_battery_dataset_raw))
idx = idxAll
i=1 
j = idx(i)
ryan4_battery_dataset_raw(i).QDischargeSmooth(1) 


ryan4_battery_dataset = zeros()
ryan4_battery_dataset = ryan4_battery_dataset_raw(1)
i=1;
for ii = 1:1000
    if ryan4_battery_dataset_raw(i).QDischargeSmooth(ii) <= 1.048
        % skip count 
        break
    end
end
ii
ryan4_battery_dataset(i) = ryan4_battery_dataset_raw(i);
ryan4_battery_dataset(i).cycle_life = ryan4_battery_dataset_raw(i).cycle_life - ii;
ryan4_battery_dataset_raw(i).cycle_life
ryan4_battery_dataset(i).cycle_life
ryan4_battery_dataset(i).chargetime([1:ii],:) = [] ;

size(ryan4_battery_dataset_raw(i).chargetime)
size(ryan4_battery_dataset(i).chargetime)
ryan4_battery_dataset(i).cycle = [] ;
ryan4_battery_dataset(i).cycle = ryan4_battery_dataset_raw(i).cycle(1:end-ii,:);
ryan4_battery_dataset(i).IR([1:ii],:) = [] ;
ryan4_battery_dataset(i).QCharge([1:ii],:) = [] ;
ryan4_battery_dataset(i).QDischarge([1:ii],:) = [] ;
ryan4_battery_dataset(i).SOH_c([1:ii],:) = [] ;
ryan4_battery_dataset(i).SOH_d([1:ii],:) = [] ;
ryan4_battery_dataset(i).Time_c([1:ii],:) = [] ;
ryan4_battery_dataset(i).Time_d([1:ii],:) = [] ;
ryan4_battery_dataset(i).Time_d1([1:ii],:) = [] ;
ryan4_battery_dataset(i).Tavg([1:ii],:) = [] ;
ryan4_battery_dataset(i).Tmin([1:ii],:) = [] ;
ryan4_battery_dataset(i).Tmax([1:ii],:) = [] ;
ryan4_battery_dataset(i).Vc([1:ii],:) = [] ;
ryan4_battery_dataset(i).Vd([1:ii],:) = [] ;
ryan4_battery_dataset(i).Tc([1:ii],:) = [] ;
ryan4_battery_dataset(i).Td([1:ii],:) = [] ;
ryan4_battery_dataset(i).Ic([1:ii],:) = [] ;
ryan4_battery_dataset(i).Id([1:ii],:) = [] ;

ryan4_battery_dataset(i).discharge_dQdV([1:ii],:) = [] ;
ryan4_battery_dataset(i).Qdlin([1:ii],:) = [] ;
ryan4_battery_dataset(i).Tdlin([1:ii],:) = [] ;

ryan4_battery_dataset(i).QChargeSmooth([1:ii],:) = [] ;
ryan4_battery_dataset(i).QDischargeSmooth([1:ii],:) = [] ;
ryan4_battery_dataset(i).QDischargePolyMdl = [];
ryan4_battery_dataset(i).QDischargePolyMdl = polyfit(ryan4_battery_dataset(i).cycle, ryan4_battery_dataset(i).QDischargeSmooth,4);
ryan4_battery_dataset(i).QDischargePolyfit = [];
ryan4_battery_dataset(i).QDischargePolyfit = polyval(ryan4_battery_dataset.QDischargePolyMdl,ryan4_battery_dataset.cycle')';
%% 전체 데이타에 대해 특정 Ah보다 큰 것은 모두 지우자 

%%%%%%%%%%%%%%%%%%
% get first capacity
for i = 1:length(idxAll)
    %j = idx(i);
    initC = ryan4_battery_dataset_raw(i).QDischargeSmooth(1) ;

    for ii = 1:ryan4_battery_dataset_raw(i).cycle_life
        if ryan4_battery_dataset_raw(i).QDischargeSmooth(ii) <= 1.048
            % skip count 
            break
        end
        if ii == ryan4_battery_dataset_raw(i).cycle_life
            error_is = true;
        end
    end
    %              bat_num        new_start_index  
    
    ryan4_battery_dataset(i) = ryan4_battery_dataset_raw(i);
    ryan4_battery_dataset(i).cycle_life = ryan4_battery_dataset_raw(i).cycle_life - ii;
    %ryan4_battery_dataset_raw(i).cycle_life
    %ryan4_battery_dataset(i).cycle_life
    ryan4_battery_dataset(i).chargetime([1:ii],:) = [] ;

    data_conversion_param(i,:) = [ i      initC  ii   ryan4_battery_dataset_raw(i).QDischargeSmooth(ii)   ryan4_battery_dataset_raw(i).cycle_life ryan4_battery_dataset(i).cycle_life    ];
    
    %size(ryan4_battery_dataset_raw(i).chargetime)
    %size(ryan4_battery_dataset(i).chargetime)
    ryan4_battery_dataset(i).cycle = [] ;
    ryan4_battery_dataset(i).cycle = ryan4_battery_dataset_raw(i).cycle(1:end-ii,:);
    ryan4_battery_dataset(i).IR([1:ii],:) = [] ;
    ryan4_battery_dataset(i).QCharge([1:ii],:) = [] ;
    ryan4_battery_dataset(i).QDischarge([1:ii],:) = [] ;
    ryan4_battery_dataset(i).SOH_c([1:ii],:) = [] ;
    ryan4_battery_dataset(i).SOH_d([1:ii],:) = [] ;  
    ryan4_battery_dataset(i).Time_c([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Time_d([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Time_d1([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Tavg([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Tmin([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Tmax([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Vc([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Vd([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Ic([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Id([1:ii],:) = [] ;    
    ryan4_battery_dataset(i).Tc([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Td([1:ii],:) = [] ;

    
    ryan4_battery_dataset(i).discharge_dQdV([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Qdlin([1:ii],:) = [] ;
    ryan4_battery_dataset(i).Tdlin([1:ii],:) = [] ;

    ryan4_battery_dataset(i).QChargeSmooth([1:ii],:) = [] ;    
    ryan4_battery_dataset(i).QDischargeSmooth([1:ii],:) = [] ;
    ryan4_battery_dataset(i).QDischargePolyMdl = [];
    ryan4_battery_dataset(i).QDischargePolyMdl = polyfit(ryan4_battery_dataset(i).cycle, ryan4_battery_dataset(i).QDischargeSmooth,4);
    ryan4_battery_dataset(i).QDischargePolyfit = [];
    ryan4_battery_dataset(i).QDischargePolyfit = polyval(ryan4_battery_dataset(i).QDischargePolyMdl,ryan4_battery_dataset(i).cycle')';


end
data_conversion_param 
max(data_conversion_param(:,2))
min(data_conversion_param(:,2))
%%
length(ryan4_battery_dataset)
size(ryan4_battery_dataset)
[ryan4_battery_dataset.key]
{[ryan4_battery_dataset.key]}
contains([ryan4_battery_dataset.key],'b1','IgnoreCase',true)
contains([ryan4_battery_dataset.key],'b2','IgnoreCase',true)
contains([ryan4_battery_dataset.key],'b3','IgnoreCase',true)
idx1 = find(contains([ryan4_battery_dataset.key],'b1','IgnoreCase',true))
idx2 = find(contains([ryan4_battery_dataset.key],'b2','IgnoreCase',true))
idx3 = find(contains([ryan4_battery_dataset.key],'b3','IgnoreCase',true))
idx12 = [idx1 idx2]
idx13 = [idx1 idx3]
idx23 = [idx2 idx3]
idxAll = (1:length(ryan4_battery_dataset))
idx123 = [idx1 idx2 idx3]

key1 = [ryan4_battery_dataset(idx1).key]'
key2 = [ryan4_battery_dataset(idx2).key]'
key3 = [ryan4_battery_dataset(idx3).key]'
%%
cycle_life = [ryan4_battery_dataset(idxAll).cycle_life]'
bat_index = [1:length(idxAll)]'
index_cyclelife = [ bat_index, cycle_life]
% https://kr.mathworks.com/help/matlab/ref/double.sortrows.html#bt8bz9j-3
index_cyclelife_table = table(bat_index,cycle_life)
[index_cyclelife_table_sort,index] = sortrows(index_cyclelife_table,{'cycle_life'},{'ascend'})

%%%%%%%%%%%%%%%%
total_index = length(idxAll)
	
index_cyclelife_table_sort.Variables
index_cyclelife_table_sort.Properties
[~, maxrow] = max(index_cyclelife_table_sort.bat_index)
%maxrowname = index_cyclelife_table_sort.Properties.RowNames(1:maxrow-1)
%index_cyclelife_table_sort.Properties.RowNames

index_vec = [1:total_index]
idxVal_ = index_vec(5:10:end)
idxTest_ = index_vec(6:10:end)
idxTrain_ = setdiff(index_vec,idxVal_);
idxTrain_ = setdiff(idxTrain_,idxTest_)
idxTestTable = index_cyclelife_table_sort(idxTest_,{'bat_index'})
idxTrainTable = index_cyclelife_table_sort(idxTrain_,{'bat_index'})
idxValTable = index_cyclelife_table_sort(idxVal_,{'bat_index'})
idxTest = idxTestTable.Variables'
idxValid = idxValTable.Variables'
idxTrain = idxTrainTable.Variables'
idxAll
idxTrainSort = sort(idxTrain)
idxValidSort = sort(idxValid)
idxTestSort = sort(idxTest)

%https://kr.mathworks.com/matlabcentral/answers/101996-how-can-i-sort-a-vector-in-a-random-manner-in-matlab

idxTestRand =  idxTest(randperm(length(idxTest)))
idxTrainRand =  idxTrain(randperm(length(idxTrain)))
idxValidRand =  idxValid(randperm(length(idxValid)))

%sortrows(idxValTable,{'cycle_life'},{'ascend'})
input_size = 100;

%% 
%% 시작 Ah 를 동일하게 맞춘 데이타 

ryan4_gen_data_raw_desc = 'ryan4_gen_data_raw_desc';
%save('ryan4_data_raw.mat','ryan4_gen_data_raw_desc');
save('ryan4_data_raw.mat','ryan4_battery_dataset' ,'-append')
%% 

cycle_life_list = zeros();
cycle_life_list =  [ 1 1 1 ] ;
%%


%%
a = ryan4_battery_dataset(idxTest(1)).QDischargeSmooth;
b = ryan4_battery_dataset(idxTest(end)).QDischargeSmooth;
a1 = ryan4_battery_dataset(idxTest(2)).QDischargeSmooth;
b1 = ryan4_battery_dataset(idxTest(end-1)).QDischargeSmooth;

%https://kr.mathworks.com/matlabcentral/answers/146685-find-index-where-value-exceeds-threshold
[idxFirst] = find(a >= 1,1,'last')
[idxLast] = find(b >= 1,1,'last' )
idxLast = idxLast + 1
a(idxFirst-1)
a(idxFirst)
a(idxFirst+1)

b(idxLast-1)
b(idxLast)
b(idxLast+1)
[idxFirst] = find(a1 >= 1,1,'last')
[idxLast] = find(b1 >= 1,1,'last' )
idxLast = idxLast + 1
a1(idxFirst-1)
a1(idxFirst)
a1(idxFirst+1)

b1(idxLast-1)
b1(idxLast)
b1(idxLast+1)



%%
idxTestCount = length(idxTest)

nLines = length(idxTest);
legend_str = cell(nLines,1);

figure
hold on 
for j = 1 : idxTestCount
    i = idxTest(j);
    plot(ryan4_battery_dataset(i).cycle,ryan4_battery_dataset(i).QDischargeSmooth)
    cycle_life_list(j,:) = [j i ryan4_battery_dataset(i).cycle_life];
    legend_str{j} = num2str(i);
end
hold off
title 'Test Y dataset'
legend(legend_str)
cycle_life_list
%%
battery_testset_org = zeros();
battery_testset_org = ryan4_battery_dataset(idxTest(1));
idxTestCount = length(idxTest)
idxTestStopCount = idxTestCount / 2 
idxTestReverse = idxTestCount
k = 1;
kk = idxTestCount;
for j = 1 : idxTestStopCount
    pre = idxTest(j);
    post = idxTest(idxTestReverse);
    idxTestReverse = idxTestReverse - 1;
    battery_testset_org(k,:) = ryan4_battery_dataset(pre);
    k=k+1;
    battery_testset_org(k,:) = ryan4_battery_dataset(post);
    k=k+1;
end

cycle_life_list = zeros();
cycle_life_list =  [ 1 1 1 ] ;

nLines = size(battery_testset_org,1);
legend_str = cell(nLines,1);
figure
hold on 
for i = 1 : nLines
    %plot(battery_testset(i).cycle,battery_testset(i).QDischargeSmooth)
    plot(battery_testset_org(i).QDischargeSmooth)
    cycle_life_list(i,:) = [i i battery_testset_org(i).cycle_life];
    legend_str{i} = num2str(i);
end

hold off
title 'Test Y dataset'
legend(legend_str)
cycle_life_list_org = cycle_life_list
%%
battery_testset = zeros();
battery_testset = ryan4_battery_dataset(idxTest(1));
%bat_pre = ryan4_battery_dataset(idxTest(1))
%bat_post = ryan4_battery_dataset(idxTest(12))
%battery_testset = bat_pre

idxTestCount = length(idxTest)
idxTestStopCount = idxTestCount / 2 
idxTestReverse = idxTestCount
k = 1;
kk = idxTestCount;
for j = 1 : idxTestStopCount
    pre = idxTest(j);
    post = idxTest(idxTestReverse);
    idxTestReverse = idxTestReverse - 1;
    
    %ryan4_battery_dataset(pre).QDischargeSmooth
    %cycle_life_list(j,:) = [j pre ryan4_battery_dataset(pre).cycle_life];
    %legend_str{j} = num2str(pre);
    
    [idxPre] = find(ryan4_battery_dataset(pre).QDischargeSmooth >= 1,1,'last');
    [idxPost] = find(ryan4_battery_dataset(post).QDischargeSmooth >= 1,1,'last' );
    idxPost = idxPost + 1;
    idxPreAfter = idxPre + 1;
    idxPreBefore = idxPre ;
    idxPostBefore = idxPost -1;
    idxPostAfter = idxPost ;
    
    battery_testset(k,:) = ryan4_battery_dataset(pre);
    
    battery_testset(k).IR([idxPreAfter:end],:) = [] ;
    battery_testset(k).QCharge([idxPreAfter:end],:) = [] ;
    battery_testset(k).QDischarge([idxPreAfter:end],:) = [] ;
    battery_testset(k).SOH_c([idxPreAfter:end],:) = [] ;
    battery_testset(k).SOH_d([idxPreAfter:end],:) = [] ;
    battery_testset(k).Time_c([idxPreAfter:end],:) = [] ;
    battery_testset(k).Time_d([idxPreAfter:end],:) = [] ;
    battery_testset(k).Time_d1([idxPreAfter:end],:) = [] ;    
    battery_testset(k).Tavg([idxPreAfter:end],:) = [] ;
    battery_testset(k).Tmin([idxPreAfter:end],:) = [] ;
    battery_testset(k).Tmax([idxPreAfter:end],:) = [] ;

    battery_testset(k).Vc([idxPreAfter:end],:) = [] ;
    battery_testset(k).Vd([idxPreAfter:end],:) = [] ;
    battery_testset(k).Tc([idxPreAfter:end],:) = [] ;
    battery_testset(k).Td([idxPreAfter:end],:) = [] ;
    battery_testset(k).Ic([idxPreAfter:end],:) = [] ;
    battery_testset(k).Id([idxPreAfter:end],:) = [] ;
    
    battery_testset(k).discharge_dQdV([idxPreAfter:end],:) = [] ;
    battery_testset(k).Qdlin([idxPreAfter:end],:) = [] ;
    battery_testset(k).Tdlin([idxPreAfter:end],:) = [] ;
    
    battery_testset(k).chargetime([idxPreAfter:end],:) = [] ;
    battery_testset(k).QDischargeSmooth([idxPreAfter:end],:) = [] ;
    
    battery_testset(k).IR = vertcat(battery_testset(k).IR,ryan4_battery_dataset(post).IR([idxPost:end],:)) ;
    battery_testset(k).QCharge = vertcat(battery_testset(k).QCharge,ryan4_battery_dataset(post).QCharge([idxPost:end],:)) ;
    battery_testset(k).QDischarge = vertcat(battery_testset(k).QDischarge,ryan4_battery_dataset(post).QDischarge([idxPost:end],:)) ;
    battery_testset(k).SOH_c = vertcat(battery_testset(k).SOH_c,ryan4_battery_dataset(post).SOH_c([idxPost:end],:)) ;
    battery_testset(k).SOH_d = vertcat(battery_testset(k).SOH_d,ryan4_battery_dataset(post).SOH_d([idxPost:end],:)) ;
    battery_testset(k).Time_c = vertcat(battery_testset(k).Time_c,ryan4_battery_dataset(post).Time_c([idxPost:end],:)) ;
    battery_testset(k).Time_d = vertcat(battery_testset(k).Time_d,ryan4_battery_dataset(post).Time_d([idxPost:end],:)) ;
    battery_testset(k).Time_d1 = vertcat(battery_testset(k).Time_d1,ryan4_battery_dataset(post).Time_d1([idxPost:end],:)) ;
    battery_testset(k).Tavg = vertcat(battery_testset(k).Tavg,ryan4_battery_dataset(post).Tavg([idxPost:end],:)) ;
    battery_testset(k).Tmin = vertcat(battery_testset(k).Tmin,ryan4_battery_dataset(post).Tmin([idxPost:end],:)) ;
    battery_testset(k).Tmax = vertcat(battery_testset(k).Tmax,ryan4_battery_dataset(post).Tmax([idxPost:end],:)) ;
    battery_testset(k).Vc = vertcat(battery_testset(k).Vc,ryan4_battery_dataset(post).Vc([idxPost:end],:)) ;
    battery_testset(k).Vd = vertcat(battery_testset(k).Vd,ryan4_battery_dataset(post).Vd([idxPost:end],:)) ;
    battery_testset(k).Tc = vertcat(battery_testset(k).Tc,ryan4_battery_dataset(post).Tc([idxPost:end],:)) ;
    battery_testset(k).Td = vertcat(battery_testset(k).Td,ryan4_battery_dataset(post).Td([idxPost:end],:)) ;
    battery_testset(k).Ic = vertcat(battery_testset(k).Ic,ryan4_battery_dataset(post).Ic([idxPost:end],:)) ;
    battery_testset(k).Id = vertcat(battery_testset(k).Id,ryan4_battery_dataset(post).Id([idxPost:end],:)) ;
    
    battery_testset(k).discharge_dQdV = vertcat(battery_testset(k).discharge_dQdV,ryan4_battery_dataset(post).discharge_dQdV([idxPost:end],:)) ;
    battery_testset(k).Qdlin = vertcat(battery_testset(k).Qdlin,ryan4_battery_dataset(post).Qdlin([idxPost:end],:)) ;
    battery_testset(k).Tdlin = vertcat(battery_testset(k).Tdlin,ryan4_battery_dataset(post).Tdlin([idxPost:end],:)) ;
    
    battery_testset(k).chargetime = vertcat(battery_testset(k).chargetime,ryan4_battery_dataset(post).chargetime([idxPost:end],:)) ;
    battery_testset(k).QDischargeSmooth = vertcat(battery_testset(k).QDischargeSmooth,ryan4_battery_dataset(post).QDischargeSmooth([idxPost:end],:)) ;
    
    battery_testset(k).cycle_life = idxPre +  (ryan4_battery_dataset(post).cycle_life - idxPost  ) + 1 ;
    battery_testset(k).cycle = [];
    battery_testset(k).cycle = linspace(1,battery_testset(k).cycle_life,battery_testset(k).cycle_life) ;

    battery_testset(k).QDischargePolyMdl = [];
%    battery_testset(k).QDischargePolyMdl = polyfit(battery_testset(k).cycle, battery_testset(k).QDischargeSmooth,4);
    battery_testset(k).QDischargePolyfit = [];
%    battery_testset(k).QDischargePolyfit = polyval(battery_testset.QDischargePolyMdl,battery_testset.cycle')';

%%%%%%%%%%%%%%%
    k = k+1;
    battery_testset(k,:) = ryan4_battery_dataset(post);
    
    battery_testset(k).IR([idxPostAfter:end],:) = [] ;
    battery_testset(k).QCharge([idxPostAfter:end],:) = [] ;
    battery_testset(k).QDischarge([idxPostAfter:end],:) = [] ;
    battery_testset(k).SOH_c([idxPostAfter:end],:) = [] ;
    battery_testset(k).SOH_d([idxPostAfter:end],:) = [] ;
    battery_testset(k).Time_c([idxPostAfter:end],:) = [] ;
    battery_testset(k).Time_d([idxPostAfter:end],:) = [] ;
    battery_testset(k).Time_d1([idxPostAfter:end],:) = [] ;
    battery_testset(k).Tavg([idxPostAfter:end],:) = [] ;
    battery_testset(k).Tavg([idxPostAfter:end],:) = [] ;
    battery_testset(k).Tmin([idxPostAfter:end],:) = [] ;
    battery_testset(k).Tmax([idxPostAfter:end],:) = [] ;
    battery_testset(k).Vc([idxPostAfter:end],:) = [] ;
    battery_testset(k).Vd([idxPostAfter:end],:) = [] ;
    battery_testset(k).Tc([idxPostAfter:end],:) = [] ;
    battery_testset(k).Td([idxPostAfter:end],:) = [] ;
    battery_testset(k).Ic([idxPostAfter:end],:) = [] ;
    battery_testset(k).Id([idxPostAfter:end],:) = [] ;
    
    battery_testset(k).discharge_dQdV([idxPostAfter:end],:) = [] ;
    battery_testset(k).Qdlin([idxPostAfter:end],:) = [] ;
    battery_testset(k).Tdlin([idxPostAfter:end],:) = [] ;
    
    battery_testset(k).chargetime([idxPostAfter:end],:) = [] ;
    battery_testset(k).QDischargeSmooth([idxPostAfter:end],:) = [] ;
    
    battery_testset(k).IR = vertcat(battery_testset(k).IR,ryan4_battery_dataset(pre).IR([idxPreAfter:end],:)) ;
    battery_testset(k).QCharge = vertcat(battery_testset(k).QCharge,ryan4_battery_dataset(pre).QCharge([idxPreAfter:end],:)) ;
    battery_testset(k).QDischarge = vertcat(battery_testset(k).QDischarge,ryan4_battery_dataset(pre).QDischarge([idxPreAfter:end],:)) ;
    battery_testset(k).SOH_c = vertcat(battery_testset(k).SOH_c,ryan4_battery_dataset(pre).SOH_c([idxPreAfter:end],:)) ;
    battery_testset(k).SOH_d = vertcat(battery_testset(k).SOH_d,ryan4_battery_dataset(pre).SOH_d([idxPreAfter:end],:)) ;
    battery_testset(k).Time_c = vertcat(battery_testset(k).Time_c,ryan4_battery_dataset(pre).Time_c([idxPreAfter:end],:)) ;
    battery_testset(k).Time_d = vertcat(battery_testset(k).Time_d,ryan4_battery_dataset(pre).Time_d([idxPreAfter:end],:)) ;
    battery_testset(k).Time_d1 = vertcat(battery_testset(k).Time_d1,ryan4_battery_dataset(pre).Time_d1([idxPreAfter:end],:)) ;
    battery_testset(k).Tavg = vertcat(battery_testset(k).Tavg,ryan4_battery_dataset(pre).Tavg([idxPreAfter:end],:)) ;
    battery_testset(k).Tmin = vertcat(battery_testset(k).Tmin,ryan4_battery_dataset(pre).Tmin([idxPreAfter:end],:)) ;
    battery_testset(k).Tmax = vertcat(battery_testset(k).Tmax,ryan4_battery_dataset(pre).Tmax([idxPreAfter:end],:)) ;
    battery_testset(k).Vc = vertcat(battery_testset(k).Vc,ryan4_battery_dataset(pre).Vc([idxPreAfter:end],:)) ;
    battery_testset(k).Vd = vertcat(battery_testset(k).Vd,ryan4_battery_dataset(pre).Vd([idxPreAfter:end],:)) ;
    battery_testset(k).Tc = vertcat(battery_testset(k).Tc,ryan4_battery_dataset(pre).Tc([idxPreAfter:end],:)) ;
    battery_testset(k).Td = vertcat(battery_testset(k).Td,ryan4_battery_dataset(pre).Td([idxPreAfter:end],:)) ;
    battery_testset(k).Ic = vertcat(battery_testset(k).Ic,ryan4_battery_dataset(pre).Ic([idxPreAfter:end],:)) ;
    battery_testset(k).Id = vertcat(battery_testset(k).Id,ryan4_battery_dataset(pre).Id([idxPreAfter:end],:)) ;
    
    battery_testset(k).discharge_dQdV = vertcat(battery_testset(k).discharge_dQdV,ryan4_battery_dataset(pre).discharge_dQdV([idxPreAfter:end],:)) ;
    battery_testset(k).Qdlin = vertcat(battery_testset(k).Qdlin,ryan4_battery_dataset(pre).Qdlin([idxPreAfter:end],:)) ;
    battery_testset(k).Tdlin = vertcat(battery_testset(k).Tdlin,ryan4_battery_dataset(pre).Tdlin([idxPreAfter:end],:)) ;   
     
    battery_testset(k).chargetime = vertcat(battery_testset(k).chargetime,ryan4_battery_dataset(pre).chargetime([idxPreAfter:end],:)) ;
    battery_testset(k).QDischargeSmooth = vertcat(battery_testset(k).QDischargeSmooth,ryan4_battery_dataset(pre).QDischargeSmooth([idxPreAfter:end],:)) ;
    
    battery_testset(k).cycle_life = idxPost +  (ryan4_battery_dataset(pre).cycle_life - idxPre  ) + 1 ;
    battery_testset(k).cycle = [];
    battery_testset(k).cycle = linspace(1,battery_testset(k).cycle_life,battery_testset(k).cycle_life) ;

    battery_testset(k).QDischargePolyMdl = [];
%    battery_testset(k).QDischargePolyMdl = polyfit(battery_testset(k).cycle, battery_testset(k).QDischargeSmooth,4);
    battery_testset(k).QDischargePolyfit = [];
%    battery_testset(k).QDischargePolyfit = polyval(battery_testset.QDischargePolyMdl,battery_testset.cycle')';
    k = k +1;
end
%battery_testset


%%

cycle_life_list = zeros();
cycle_life_list =  [ 1 1 1 ] ;

nLines = size(battery_testset,1);
legend_str = cell(nLines,1);
figure
hold on 
for i = 1 : nLines
    %plot(battery_testset(i).cycle,battery_testset(i).QDischargeSmooth)
    plot(battery_testset(i).QDischargeSmooth)
    cycle_life_list(i,:) = [i i battery_testset(i).cycle_life];
    legend_str{i} = num2str(i);
end

hold off
title 'Test Y dataset'
legend(legend_str)
cycle_life_list_change = cycle_life_list

%%
%{
cycle_life_list = zeros();
cycle_life_list =  [ 1 1 1 ] ;

nLines = length(idxTestSort);
legend_str = cell(nLines,1);
figure
hold on 
for j = 1 : length(idxTestSort)
    i = idxTestSort(j);
    plot(ryan4_battery_dataset(i).cycle,ryan4_battery_dataset(i).QDischargeSmooth)
    cycle_life_list(j,:) = [j i ryan4_battery_dataset(i).cycle_life];
    legend_str{j} = num2str(i);
end

hold off
title 'Test Y dataset'
legend(legend_str)
cycle_life_list
%}
%%

save('ryan4_data.mat','battery_testset' )
save('ryan4_data.mat','battery_testset_org' ,'-append')
%%
% load ryan4_gen_data.mat
%% 
% 첫번째 cycle의 충전전류를 얻는다.

idx = 1; % idxAll; 

ryan4_battery_dataset(idx).Ic
ryan4_battery_dataset(idx).Ic(1,:)
% 열벡터로 바꾼다.
Ic1 = ryan4_battery_dataset(idx).Ic(1,:)'
%%
% 전체 데이타에 대해서 
IcFirstFull = zeros()
IcFirstFull = ryan4_battery_dataset(1).Ic(1,:)

VdFirstFull = zeros()
VdFirstFull = ryan4_battery_dataset(1).Vd(1,:)

%IcFirstFull = ryan4_battery_dataset(2).Ic(1,:)
for i=1:length(ryan4_battery_dataset)
    IcFirstFull(i,:) = ryan4_battery_dataset(i).Ic(1,:);
    VdFirstFull(i,:) = ryan4_battery_dataset(i).Vd(1,:);
end
IcFirstFull
VdFirstFull
%IcFirstFull = IcFirstFull'
RulFirst = [ryan4_battery_dataset(idxAll).cycle_life ]'
blockSize = [1, 5] % 다섯개를 묶어서.
meanFilterFunction = @(theBlockStructure) mean2(theBlockStructure.data(:))
IcFirst = blockproc(IcFirstFull, blockSize, meanFilterFunction)
VdFirst = blockproc(VdFirstFull, blockSize, meanFilterFunction)
%RulFirst = cycleLife;
%clear cycleLife
%%

[ynorm_IcFirst_RUL,ymax_IcFirst_RUL,ymin_IcFirst_RUL,yrate_IcFirst_RUL,xnorm_IcFirstFull_RUL,xmax_IcFirst_RUL,xmin_IcFirst_RUL,xrate_IcFirst_RUL] = ...
minmax_norm_new(RulFirst,IcFirstFull);
[ynorm_IcFirst_RUL1,xnorm_IcFirst_RUL] = minmax_norm_new_with_param(RulFirst,IcFirst,ymin_IcFirst_RUL,yrate_IcFirst_RUL,xmin_IcFirst_RUL,xrate_IcFirst_RUL);
% https://stackoverflow.com/questions/40053450/compare-if-two-vectors-are-the-same
returnsTrue = all(ynorm_IcFirst_RUL == ynorm_IcFirst_RUL1)
%%
[ynorm_VdFirst_RUL,ymax_VdFirst_RUL,ymin_VdFirst_RUL,yrate_VdFirst_RUL,xnorm_VdFirst_RUL,xmax_VdFirst_RUL,xmin_VdFirst_RUL,xrate_VdFirst_RUL] = ...
minmax_norm_new(RulFirst,VdFirst);

all(ynorm_IcFirst_RUL == ynorm_VdFirst_RUL)
all(ymax_IcFirst_RUL == ymax_VdFirst_RUL)
all(ymin_IcFirst_RUL == ymin_VdFirst_RUL)
all(yrate_IcFirst_RUL == yrate_VdFirst_RUL)

ynorm_First_RUL = ynorm_IcFirst_RUL
ymax_First_RUL = ymax_IcFirst_RUL
ymin_First_RUL = ymin_IcFirst_RUL
yrate_First_RUL = yrate_IcFirst_RUL
%%
x_trainValid_IcFirstFull_RUL = xnorm_IcFirstFull_RUL([idxTrain idxValid],:);
x_test_IcFirstFull_RUL = xnorm_IcFirstFull_RUL([idxTest],:);
x_trainValid_IcFirst_RUL = xnorm_IcFirst_RUL([idxTrain idxValid],:);
x_test_IcFirst_RUL = xnorm_IcFirst_RUL([idxTest],:);

y_trainValid_IcFirst_RUL = ynorm_IcFirst_RUL([idxTrain idxValid]);
y_test_IcFirst_RUL = ynorm_IcFirst_RUL([idxTest]);
Y_trainValid_IcFirst_RUL = RulFirst([idxTrain idxValid]);
Y_test_IcFirst_RUL = RulFirst([idxTest]);


x_trainValid_VdFirst_RUL = xnorm_VdFirst_RUL([idxTrain idxValid],:);
x_test_VdFirst_RUL = xnorm_VdFirst_RUL([idxTest],:);

y_trainValid_VdFirst_RUL = ynorm_VdFirst_RUL([idxTrain idxValid]);
y_test_VdFirst_RUL = ynorm_VdFirst_RUL([idxTest]);
Y_trainValid_VdFirst_RUL = RulFirst([idxTrain idxValid]);
Y_test_VdFirst_RUL = RulFirst([idxTest]);

all(y_trainValid_IcFirst_RUL == y_trainValid_VdFirst_RUL)
all(y_test_IcFirst_RUL == y_test_VdFirst_RUL)
all(Y_trainValid_IcFirst_RUL == Y_trainValid_VdFirst_RUL)
all(Y_test_IcFirst_RUL == Y_test_VdFirst_RUL)

y_trainValid_First_RUL = y_trainValid_IcFirst_RUL ;
y_test_First_RUL = y_test_IcFirst_RUL ;
Y_trainValid_First_RUL = Y_trainValid_IcFirst_RUL ;
Y_test_First_RUL = Y_test_IcFirst_RUL ;

%% 변수 추출

Cap = zeros();
%SOH = zeros();
% = zeeros();
VdFull = zeros();
%VdFull = [1:100];
ryan4_battery_dataset(1).QDischargeSmooth
ryan4_battery_dataset(1).Vd
size(ryan4_battery_dataset(1).QDischargeSmooth)
length(ryan4_battery_dataset(1).QDischargeSmooth)

idxAll = (1:length(ryan4_battery_dataset));
idxTrainValid = [ idxTrain idxValid ];
idxTrainAll = []; %zeros();
idxValidAll = []; %zeros();
idxTestAll = []; %zeros();
idxTrainAll_batIndex = []; %zeros();
idxValidAll_batIndex = []; %zeros();
idxTestAll_batIndex = []; %zeros();

j =1;
startIndx = j ;
GenerateFrameList = @(A,S,N) A+S*(0:N-1);

for i = 1: length(idxAll)
        
    cap_temp = ryan4_battery_dataset(i).QDischargeSmooth;
    %SOH_temp = max(cap_temp);
    RUL_temp = linspace(ryan4_battery_dataset(i).cycle_life,1,ryan4_battery_dataset(i).cycle_life)';
    leng = length(cap_temp);
    %startIndx = j ;
    % https://kr.mathworks.com/matlabcentral/answers/478553-how-can-i-have-a-starting-number-a-step-size-then-the-number-of-numbers-i-need-in-a-1d-array
    append_index = GenerateFrameList(startIndx,1,leng);
    
    Vd_temp = ryan4_battery_dataset(i).Vd ;
    Ic_temp = ryan4_battery_dataset(i).Ic ;
    batIndex_temp(1:leng, 1) = i;
    %VdFull = [VdFull ; Vd_temp];
    if  i == 1
        VdFull = Vd_temp;
        Cap = cap_temp; 
        IcFull = Ic_temp;
        RUL = RUL_temp;
        %SOH =
    else
        VdFull = vertcat(VdFull,Vd_temp);
        Cap = vertcat(Cap,cap_temp);
        IcFull = vertcat(IcFull,Ic_temp);
        RUL = vertcat(RUL,RUL_temp);
    end
       
    
    if any(idxTrain(:) == i) 
       % https://kr.mathworks.com/matlabcentral/answers/283821-add-single-element-to-array-or-vector
       idxTrainAll =  [idxTrainAll append_index ] ;
       idxTrainAll_batIndex = [idxTrainAll_batIndex batIndex_temp'];
    end
    if any(idxValid(:) == i) 
       idxValidAll =  [idxValidAll append_index ] ;
       idxValidAll_batIndex = [idxValidAll_batIndex batIndex_temp'];
    end
    if any(idxTest(:) == i) 
       idxTestAll =  [idxTestAll append_index ] ;
       idxTestAll_batIndex = [idxTestAll_batIndex batIndex_temp'];
    end
    %VdFull(i) = Vd_temp;
    
    startIndx = startIndx + leng;
end
%%

idxTrainAll
idxValidAll
idxTestAll
Cap
VdFull
IcFull
% https://kr.mathworks.com/matlabcentral/answers/80480-how-do-i-take-the-average-of-every-n-values-in-a-vector
blockSize = [1, 5] % 다섯개를 묶어서.
meanFilterFunction = @(theBlockStructure) mean2(theBlockStructure.data(:))

Ic = blockproc(IcFull, blockSize, meanFilterFunction)
%clear IcFull  

Vd = blockproc(VdFull, blockSize, meanFilterFunction)
%clear VdFull  
%%


%%

ryan4_gen_data_raw_desc = "ryan4_gen_data_raw_desc";
%save('ryan4_data_raw.mat','ryan4_gen_data_raw_desc');
save('ryan4_data_raw.mat','ryan4_battery_dataset','-append');

%%

% https://stackoverflow.com/questions/39149677/how-to-delete-a-variable-from-mat-file-in-matlab
%rmmatvar('ryan4_gen_data.mat', 'ryan4_battery_dataset');
%%
%clear ryan4_battery_dataset

%%
[ynorm_Ic_RUL,ymax_Ic_RUL,ymin_Ic_RUL,yrate_Ic_RUL,xnorm_Ic_RUL,xmax_Ic_RUL,xmin_Ic_RUL,xrate_Ic_RUL] = minmax_norm_new(RUL,Ic);
[ynorm_Vd_RUL,ymax_Vd_RUL,ymin_Vd_RUL,yrate_Vd_RUL,xnorm_Vd_RUL,xmax_Vd_RUL,xmin_Vd_RUL,xrate_Vd_RUL] = minmax_norm_new(RUL,Vd);

Y_trainValid_Ic_RUL = RUL([idxTrainAll idxValidAll],:);
Y_test_Ic_RUL = RUL([idxTestAll],:);
x_trainValid_Ic_RUL = xnorm_Ic_RUL([idxTrainAll idxValidAll],:)
x_test_Ic_RUL = xnorm_Ic_RUL([idxTestAll],:)
y_trainValid_Ic_RUL = ynorm_Ic_RUL([idxTrainAll idxValidAll])
y_test_Ic_RUL = ynorm_Ic_RUL([idxTestAll])
Y_trainValid_Vd_RUL = RUL([idxTrainAll idxValidAll],:);
Y_test_Vd_RUL = RUL([idxTestAll],:);
x_trainValid_Vd_RUL = xnorm_Vd_RUL([idxTrainAll idxValidAll],:)
x_test_Vd_RUL = xnorm_Vd_RUL([idxTestAll],:)
y_trainValid_Vd_RUL = ynorm_Vd_RUL([idxTrainAll idxValidAll])
y_test_Vd_RUL = ynorm_Vd_RUL([idxTestAll])


all(Y_trainValid_Ic_RUL == Y_trainValid_Vd_RUL)
all(Y_test_Ic_RUL == Y_test_Vd_RUL)
all(y_trainValid_Ic_RUL == y_trainValid_Vd_RUL)
all(y_test_Ic_RUL == y_test_Vd_RUL)
%%

all(ynorm_Ic_RUL == ynorm_Vd_RUL)
ynorm_RUL = ynorm_Ic_RUL ;
ymax_RUL = ymax_Ic_RUL ;
ymin_RUL = ymin_Ic_RUL ;
yrate_RUL = yrate_Ic_RUL ;


Y_trainValid_RUL = Y_trainValid_Vd_RUL ;
Y_test_RUL = Y_test_Vd_RUL ;
y_trainValid_RUL = y_trainValid_Vd_RUL ;
y_test_RUL = y_test_Vd_RUL ;
%%
[ynorm_SOH,ymax_SOH,ymin_SOH,yrate_SOH,xnorm_Ic_SOH,xmax_Ic_SOH,xmin_Ic_SOH,xrate_Ic_SOH] = minmax_norm_new(Cap,Ic);
[ynorm_SOH,ymax_SOH,ymin_SOH,yrate_SOH,xnorm_Vd_SOH,xmax_Vd_SOH,xmin_Vd_SOH,xrate_Vd_SOH] = minmax_norm_new(Cap,Vd);
%%

Y_trainValid_SOH = Cap([idxTrainAll idxValidAll],:)
Y_test_SOH = Cap([idxTestAll],:)
y_trainValid_SOH = ynorm_SOH([idxTrainAll idxValidAll])
y_test_SOH = ynorm_SOH([idxTestAll])

x_trainValid_Ic_SOH = xnorm_Ic_SOH([idxTrainAll idxValidAll],:)
x_test_Ic_SOH = xnorm_Ic_SOH([idxTestAll],:)
x_trainValid_Vd_SOH = xnorm_Vd_SOH([idxTrainAll idxValidAll],:)
x_test_Vd_SOH = xnorm_Vd_SOH([idxTestAll],:)
%%
x_trainValid_IcVd = [x_trainValid_Ic x_trainValid_Vd]; 
x_trainValid_IcVdTd = [x_trainValid_Ic x_trainValid_Vd x_trainValid_Td]; 

x_test_IcVd = [x_test_Ic x_test_Vd]; 
x_test_IcVdTd = [x_test_Ic x_test_Vd x_test_Td]; 

% For FNN
xnorm_IcVd = [xnorm_Ic xnorm_Vd];
xnorm_IcVdTd = [xnorm_Ic xnorm_Vd xnorm_Td];

%% 실제 실험에 사용될 데이타


ryan4_gen_data_desc = 'ryan4_gen_data_desc';
%save('ryan4_data.mat','ryan4_gen_data_desc');
save('ryan4_data.mat','ryan4_battery_dataset' ,'-append')

% ryan4_battery_dataset_raw 는 지워도 된다.
%save('ryan4_data.mat','ryan4_battery_dataset_raw' ,'-append')
save('ryan4_data.mat','data_conversion_param' ,'-append')
save('ryan4_data.mat','idx1' ,'-append')
save('ryan4_data.mat','idx2' ,'-append')
save('ryan4_data.mat','idx3' ,'-append')
save('ryan4_data.mat','idx12' ,'-append')
save('ryan4_data.mat','idx23' ,'-append')
save('ryan4_data.mat','idx13' ,'-append')
save('ryan4_data.mat','idxAll' ,'-append')
save('ryan4_data.mat','idx123' ,'-append')
save('ryan4_data.mat','key1' ,'-append')
save('ryan4_data.mat','key2' ,'-append')
save('ryan4_data.mat','key3' ,'-append')
save('ryan4_data.mat','input_size' ,'-append')

save('ryan4_data.mat','idxTrain' ,'-append')
save('ryan4_data.mat','idxValid' ,'-append')
save('ryan4_data.mat','idxTest' ,'-append')
save('ryan4_data.mat','idxTrainRand' ,'-append')
save('ryan4_data.mat','idxValidRand' ,'-append')
save('ryan4_data.mat','idxTestRand' ,'-append')
save('ryan4_data.mat','idxTrainSort' ,'-append')
save('ryan4_data.mat','idxValidSort' ,'-append')
save('ryan4_data.mat','idxTestSort' ,'-append')

save('ryan4_data.mat','Ic','-append');
save('ryan4_data.mat','Vd','-append');
save('ryan4_data.mat','Cap','-append');
save('ryan4_data.mat','IcFull','-append');
save('ryan4_data.mat','Ic','-append');
save('ryan4_data.mat','VdFull','-append');
save('ryan4_data.mat','Vd','-append');
save('ryan4_data.mat','idxTrainAll','-append');
save('ryan4_data.mat','idxValidAll','-append');
save('ryan4_data.mat','idxTestAll','-append');


save('ryan4_data.mat','idxTrainAll_batIndex','-append');
save('ryan4_data.mat','idxValidAll_batIndex','-append');
save('ryan4_data.mat','idxTestAll_batIndex','-append');



save('ryan4_data.mat','RUL','-append');

%%%%%%%%%  First - common
save('ryan4_data.mat','RulFirst','-append');
save('ryan4_data.mat','IcFirstFull','-append');
save('ryan4_data.mat','IcFirst','-append');
save('ryan4_data.mat','VdFirstFull','-append');
save('ryan4_data.mat','VdFirst','-append');
save('ryan4_data.mat','ynorm_First_RUL','-append');
save('ryan4_data.mat','ymax_First_RUL','-append');
save('ryan4_data.mat','ymin_First_RUL','-append');
save('ryan4_data.mat','yrate_First_RUL','-append');
save('ryan4_data.mat','y_trainValid_First_RUL','-append');
save('ryan4_data.mat','y_test_First_RUL','-append');
save('ryan4_data.mat','Y_trainValid_First_RUL','-append');
save('ryan4_data.mat','Y_test_First_RUL','-append');

%%%%%%%%%%  IcFirst / RUL 
save('ryan4_data.mat','ynorm_IcFirst_RUL','-append');
save('ryan4_data.mat','ymax_IcFirst_RUL','-append');
save('ryan4_data.mat','ymin_IcFirst_RUL','-append');
save('ryan4_data.mat','yrate_IcFirst_RUL','-append');
save('ryan4_data.mat','xnorm_IcFirstFull_RUL','-append');
save('ryan4_data.mat','xmax_IcFirst_RUL','-append');
save('ryan4_data.mat','xmin_IcFirst_RUL','-append');
save('ryan4_data.mat','xrate_IcFirst_RUL','-append');
save('ryan4_data.mat','xnorm_IcFirst_RUL','-append');


save('ryan4_data.mat','x_trainValid_IcFirstFull_RUL','-append');
save('ryan4_data.mat','x_test_IcFirstFull_RUL','-append');
save('ryan4_data.mat','x_trainValid_IcFirst_RUL','-append');
save('ryan4_data.mat','x_test_IcFirst_RUL','-append');
save('ryan4_data.mat','y_trainValid_IcFirst_RUL','-append');
save('ryan4_data.mat','y_test_IcFirst_RUL','-append');
save('ryan4_data.mat','Y_trainValid_IcFirst_RUL','-append');
save('ryan4_data.mat','Y_test_IcFirst_RUL','-append');

%%%%%%% VdFirst / RUL 
save('ryan4_data.mat','ynorm_VdFirst_RUL','-append');
save('ryan4_data.mat','ymax_VdFirst_RUL','-append');
save('ryan4_data.mat','ymin_VdFirst_RUL','-append');
save('ryan4_data.mat','yrate_VdFirst_RUL','-append');
save('ryan4_data.mat','xnorm_IcFirstFull_RUL','-append');
save('ryan4_data.mat','xmax_VdFirst_RUL','-append');
save('ryan4_data.mat','xmin_VdFirst_RUL','-append');
save('ryan4_data.mat','xrate_VdFirst_RUL','-append');
save('ryan4_data.mat','xnorm_VdFirst_RUL','-append');


save('ryan4_data.mat','x_trainValid_IcFirstFull_RUL','-append');
save('ryan4_data.mat','x_test_IcFirstFull_RUL','-append');
save('ryan4_data.mat','x_trainValid_VdFirst_RUL','-append');
save('ryan4_data.mat','x_test_VdFirst_RUL','-append');
save('ryan4_data.mat','y_trainValid_VdFirst_RUL','-append');
save('ryan4_data.mat','y_test_VdFirst_RUL','-append');
save('ryan4_data.mat','Y_trainValid_VdFirst_RUL','-append');
save('ryan4_data.mat','Y_test_VdFirst_RUL','-append');
%%

%%%%%%% Ic Vd RUL common
save('ryan4_data.mat','ynorm_RUL','-append');
save('ryan4_data.mat','ymax_RUL','-append');
save('ryan4_data.mat','ymin_RUL','-append');
save('ryan4_data.mat','yrate_RUL','-append');

%%%%%%%%  Ic / RUL
save('ryan4_data.mat','ynorm_Ic_RUL','-append');
save('ryan4_data.mat','ymax_Ic_RUL','-append');
save('ryan4_data.mat','ymin_Ic_RUL','-append');
save('ryan4_data.mat','yrate_Ic_RUL','-append');
save('ryan4_data.mat','xnorm_Ic_RUL','-append');
save('ryan4_data.mat','xmax_Ic_RUL','-append');
save('ryan4_data.mat','xmin_Ic_RUL','-append');
save('ryan4_data.mat','xrate_Ic_RUL','-append');

save('ryan4_data.mat','x_trainValid_Ic_RUL','-append');
save('ryan4_data.mat','x_test_Ic_RUL','-append');
save('ryan4_data.mat','y_trainValid_Ic_RUL','-append');
save('ryan4_data.mat','y_test_Ic_RUL','-append');
save('ryan4_data.mat','Y_trainValid_Ic_RUL','-append');
save('ryan4_data.mat','Y_test_Ic_RUL','-append');

%%%%%%% Vd / RUL 
save('ryan4_data.mat','ynorm_Vd_RUL','-append');
save('ryan4_data.mat','ymax_Vd_RUL','-append');
save('ryan4_data.mat','ymin_Vd_RUL','-append');
save('ryan4_data.mat','yrate_Vd_RUL','-append');
save('ryan4_data.mat','xnorm_Vd_RUL','-append');
save('ryan4_data.mat','xmax_Vd_RUL','-append');
save('ryan4_data.mat','xmin_Vd_RUL','-append');
save('ryan4_data.mat','xrate_Vd_RUL','-append');

save('ryan4_data.mat','x_trainValid_Vd_RUL','-append');
save('ryan4_data.mat','x_test_Vd_RUL','-append');
save('ryan4_data.mat','y_trainValid_Vd_RUL','-append');
save('ryan4_data.mat','y_test_Vd_RUL','-append');
save('ryan4_data.mat','Y_trainValid_Vd_RUL','-append');
save('ryan4_data.mat','Y_test_Vd_RUL','-append');

%%

%%%%%%% SOH
save('ryan4_data.mat','ynorm_SOH','-append');
save('ryan4_data.mat','ymax_SOH','-append');
save('ryan4_data.mat','ymin_SOH','-append');
save('ryan4_data.mat','yrate_SOH','-append');
save('ryan4_data.mat','y_trainValid_SOH','-append');
save('ryan4_data.mat','y_test_SOH','-append');
save('ryan4_data.mat','Y_trainValid_SOH','-append');
save('ryan4_data.mat','Y_test_SOH','-append');
%%%%%%% Ic / SOH
save('ryan4_data.mat','xnorm_Ic_SOH','-append');
save('ryan4_data.mat','xmax_Ic_SOH','-append');
save('ryan4_data.mat','xmin_Ic_SOH','-append');
save('ryan4_data.mat','xrate_Ic_SOH','-append');
save('ryan4_data.mat','x_trainValid_Ic_SOH','-append');
save('ryan4_data.mat','x_test_Ic_SOH','-append');
%%%%%%% Vd / SOH
save('ryan4_data.mat','xnorm_Vd_SOH','-append');
save('ryan4_data.mat','xmax_Vd_SOH','-append');
save('ryan4_data.mat','xmin_Vd_SOH','-append');
save('ryan4_data.mat','xrate_Vd_SOH','-append');
save('ryan4_data.mat','x_trainValid_Vd_SOH','-append');
save('ryan4_data.mat','x_test_Vd_SOH','-append');


%%
save('ryan4_data.mat','x_trainValid_IcVd','-append')
save('ryan4_data.mat','x_trainValid_IcVdTd','-append')
save('ryan4_data.mat','x_test_IcVd','-append')
save('ryan4_data.mat','x_test_IcVdTd','-append')
save('ryan4_data.mat','xnorm_IcVd','-append')
save('ryan4_data.mat','xnorm_IcVdTd','-append')

%%
Cap_change = (Cap_Rated + Cap_EOL )
save('ryan4_data.mat','Cap_change','-append')