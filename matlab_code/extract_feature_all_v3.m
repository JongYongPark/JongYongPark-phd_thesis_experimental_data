function [result] = extract_feature_all_v3(B,cycleCountToIgnoreFromFirst,refCap)

% ignore all cycle which dose not compose charge-dischage pair. some cycles
% have duplicated same cycles.
% delete regenratoin cycle is done in outside of this function
% v3 - add Voltage/Current/temp

%% all
%cap,cTempMax,cTempMaxDtSec,cTempMaxDtAdj,ohm,re_c,re_d,dTempMax,dTempMaxDt,dTempMaxDtAdj
% cap 에서 하나의 index 가 빠진다. 하지만 일단 무시해도 된다.

    % cycle pattern
    % charge ( impenedace ) discarge ( impedance )
    bcycle = B.cycle;
    cycle_index = 1;
    cap_prev = 100;
    last_charge_reverse_index = 3;
    
    %  temp
    prevTemp = 0;
    cTempMaxIndex_prev = 1;

    % restTimeOption 
    %restTimeOption = 0; % charge high temp ~ start discharge
    restTimeOption = 1; % last discharge staring time ~ current dischage starting time
    
    %  ohm
    deltaVoltages = [];
    %ohm = [];
    Ifirst3 = 2; % 2A CC load
    Vfirst3 = 4.2;
    indexV = []; 
    re_c =[];
    re_d =[];
    ohm_start_index = 1;
    ohm_measure_index = 5;
    imp_d_index = 1;
    max_cycle_org = length(bcycle);
    
    total_discharge_cycle = 0;
    for j = max_cycle_org:-1:2
        if isequal(bcycle(j).type,'discharge' )
            total_discharge_cycle = total_discharge_cycle +1;
        end
        if isequal(bcycle(j).type, bcycle(j-1).type) 
            if isequal(bcycle(j).type,'discharge' )
                sprintf("break here")
            end
            bcycle(j)=[];
        end
    end 
    
    cCC_end_current = 1.4 ; % 1.5 A - 0.1 V margin
    dCC_end_current = -0.5;
    max_cycle = length(bcycle);
    for i = 1:max_cycle
        % start from charge [impedance] discharge [impedance]
        if isequal(bcycle(i).type, 'charge') && ( i <=  max_cycle - last_charge_reverse_index  ) ...
                && ((isequal(bcycle(i+1).type, 'discharge') || isequal(bcycle(i+2).type, 'discharge')) )
                
            %% CC end
            cCC_end_current_ignore_first_datas = 20;
            cCC_end_current_skip = false;
            for ii = 1:length(bcycle(i).data.Current_measured)
                if  ii > cCC_end_current_ignore_first_datas && bcycle(i).data.Current_measured(ii) < cCC_end_current 
                    cCC_end_current_skip = true;
                    break % end for 
                end
            end
            
            if cCC_end_current_skip == false 
                sprintf("error in finding charge CC end time - %d",cycle_index)
                cCcEndIndex(cycle_index) = 1;
                cCcEndTimeSec(cycle_index) = 1; 
                cTempMax(cycle_index) = max(bcycle(i).data.Temperature_measured);
            else
                cCcEndIndex(cycle_index) = ii;
                cCcEndTimeSec(cycle_index) = bcycle(i).data.Time(ii) ; 
                cTempMax(cycle_index) = bcycle(i).data.Temperature_measured(ii) ;  
            end
            
            pattern_dVolt(cycle_index) = 0 ; 
            pattern_temp(cycle_index) = 0 ; 
            pattern_CC_amps(cycle_index) = 0 ; 
            
            %% V I T
            % 789 % 10 = 9
            le = mod(length(bcycle(i).data.Voltage_measured), 10);
            vTemp = bcycle(i).data.Voltage_measured(:, 1:end-le); % end - le = 789 - 9 = 780 %끝을 자른다.
            vTemp = reshape(vTemp, length(vTemp)/10, []); % 열개의 row로 만든다. fill the first column and then fill the next column
            vTemp = mean(vTemp); % column 각 항목의 평균값을 구한다. 시리즈의 첫번째 블럭의 평

            iTemp = bcycle(i).data.Current_measured(:, 1:end-le);
            iTemp = reshape(iTemp, length(iTemp)/10, []);
            iTemp = mean(iTemp);

            tTemp = bcycle(i).data.Temperature_measured(:, 1:end-le);
            tTemp = reshape(tTemp, length(tTemp)/10, []);
            tTemp = mean(tTemp);

            charInput(cycle_index, :) = [vTemp, iTemp, tTemp];
            
            %% Cycle index  
               
            if isequal(bcycle(i+1).type, 'discharge')
                discharge_index = i+1;

                imp_c_index = -1;         
                if isequal(bcycle(i+2).type, 'impedance')
                    imp_d_index = i+2;
                else 
                    imp_d_index = -1;
                end 
            elseif isequal(bcycle(i+2).type, 'discharge')
                discharge_index = i+2;

                if isequal(bcycle(i+1).type, 'impedance')
                    imp_c_index = i+1;
                else   
                    imp_c_index = -1;
                end

                if (i+last_charge_reverse_index <= max_cycle)  &&  (isequal(bcycle(i+3).type, 'impedance'))
                    imp_d_index = i+3;
                else   
                    imp_d_index = -1;
                end
            else
                sprintf("error ")
            end        
            %% Capacity
            
            % ignore rest regeneratoin.
            cap_value = bcycle(discharge_index).data.Capacity;
            cap(cycle_index) = cap_value;
            
            %i;
            %discharge_index
            
            
            if cap_value ~= refCap(cycle_index)
                %cap_value
                %cycle_index
                %refCap(cycle_index)
                %sprintf("error ")
            end
            
            %% Check Rest Cycle
            if cap_prev <= cap_value
                isRestCycle = true;
                restCycle(cycle_index) = true;
            else
                isRestCycle = false;
                restCycle(cycle_index) = false;
                cap_prev = cap_value;
            end 
            

            %% discharge CC end time
            dCC_end_current_ignore_first_datas = 20;
            dCC_end_current_skip = false;
            for ii = 1:length(bcycle(discharge_index).data.Current_measured)
                if  ii > cCC_end_current_ignore_first_datas &&  bcycle(discharge_index).data.Current_measured(ii) > dCC_end_current 
                    dCC_end_current_skip = true;
                    break % end for 
                end
            end
            
            % some data never finish the CC dischange and no self-recharge cycle so it never return to 0 .
            if dCC_end_current_skip == false && ii == length(bcycle(discharge_index).data.Current_measured)
                dCC_end_current_skip = true;
            end
            
            if dCC_end_current_skip == false
                
                sprintf("error in finding discharge CC end time - %d",cycle_index)
                dCcEndIndex(cycle_index) = 1;
                dCcEndTimeSec(cycle_index) = 1; 
                dTempMax(cycle_index) = max(bcycle(discharge_index).data.Temperature_measured);
            else
                dCcEndIndex(cycle_index) = ii;
                dCcEndTimeSec(cycle_index) = bcycle(discharge_index).data.Time(ii) ; 
                dTempMax(cycle_index) = bcycle(discharge_index).data.Temperature_measured(ii) ;  
                
            end            
            
          
           %% Time Index
           curDischargeTime = datetime(bcycle(discharge_index).time);
           % 현재 사이클에서 충전 시작시간에서 방전시작시간까지 
           restTimeDuration = (datetime(bcycle(discharge_index).time) - datetime(bcycle(i).time)) ;           
           
           % 이전 방전 시작시간 부터 현재 방전 시작시간까지. 방전시간을 기준으로 잡는다.
           if cycle_index == 1 
               initialDischareTime = datetime(curDischargeTime);
               cycleTimeHour(1) = hours(restTimeDuration);
               
           else    
               cycleTimeHour(cycle_index) =  hours(curDischargeTime - initialDischareTime);
           end
           
           %% rest time 
           
           %{
           % from staring time of charge to starting time of discharge
           % 배터리 5,6,7 이 모두 같아서 그래프가 하나로 나온다.
           restTimeDuration = (datetime(bcycle(discharge_index).time) - datetime(bcycle(i).time)) ;
           %restTimeHour = minutes(restTimeDuration,'seconds');
           restTimeHour(cycle_index) = minutes(restTimeDuration);
           %}
           
           
           % 디버그 
          
           % from ending time of charge to starting time of discharge
           
           %bcycle(discharge_index).time
           %bcycle(i).time
           %cTempMaxDtSec(cycle_index)
           
           if restTimeOption == 0 
               % 충전시작시간에서 CC 가 끝나는 시점, 이것은 최고 온도로 확인 
               restTimeDurationSec = seconds(restTimeDuration) - cTempMaxDtSec(cycle_index);
               %restTimeHour(cycle_index) = restTimeDurationSec / 60; % minute
               restTimeHour(cycle_index) = restTimeDurationSec / 60 / 60; % hours 
           elseif restTimeOption == 1
               if cycle_index == 1 
                   restTimeHour(cycle_index) =  cycleTimeHour(1);
               else
               restTimeHour(cycle_index) = cycleTimeHour(cycle_index) - cycleTimeHour(cycle_index-1) ;     
               end 
           end
           
           
           %% Internal Register - measure on discharge status

            deltaV = bcycle(discharge_index).data.Voltage_measured(ohm_start_index) -  bcycle(discharge_index).data.Voltage_measured(ohm_measure_index);
            deltaT = bcycle(discharge_index).data.Time(ohm_measure_index) - bcycle(discharge_index).data.Time(ohm_start_index);

            % deltaV = Vfirst3 -  BAT1.cycle(i).data.Voltage_measured(measure_index);
            % deltaT = BAT1.cycle(i).data.Time(measure_index) ;

            %BAT1.cycle(i).data.Voltage_measured(1)
            deltaVoltages(cycle_index) =  deltaV;
            ohm(cycle_index) = deltaV / (deltaT * Ifirst3 );

            %% Impedance - only use re. do not use rct and others
            if(imp_c_index == -1) 
                re_c(cycle_index) = NaN;
                cycleNoChargeRe(cycle_index) = 1;
            else
                re_c(cycle_index) = bcycle(imp_c_index).data.Re;
                cycleNoChargeRe(cycle_index) = 0;
            end

            if(imp_d_index == -1) 
                re_d(cycle_index) = NaN;
                cycleNoDischargeRe(cycle_index) = 1;
            else
                cycleNoDischargeRe(cycle_index) = 0;
                try
                    re_d(cycle_index) = bcycle(imp_d_index).data.Re;
                catch
                    print("error");
                end
                    
            end

            %% Increase Cycle index
            if cycleCountToIgnoreFromFirst > 0
                cycleCountToIgnoreFromFirst = cycleCountToIgnoreFromFirst -1;
            else
                cycle_index = cycle_index +1;
            end
            
            %% ignore double charge cycle 
            if isequal(bcycle(i+1).type, 'charge')  % double charge cycle
                %i = i+1; % ignore later charge cycle  %not work
            end 
            %% end 
            %sprintf("in %d",i)

        else
            %sprintf("out %d",i)
        end

        %i = i+1;

    end % end for

%print("end");
%maxTimedelta(maxTemp==0) = []; % It can be 0 when first index have high temp
%cap(maxTemp==0) = [];
%abnormal(maxTemp==0) = [];
%maxTemp(maxTemp==0) = [];

%{
% v0
tct = datetime(2017,1,1,0,0,0) + hours(0:length(cTempMaxDtSec)-1);
[cTempMaxDtAdj,TF,U,L,C] = filloutliers(cTempMaxDtSec,'clip','movmedian',hours(5),'SamplePoints',tct);

tdt = datetime(2017,1,1,0,0,0) + hours(0:length(dTempMaxDt)-1);
[dTempMaxDtAdj,TF,U,L,C] = filloutliers(dTempMaxDt,'clip','movmedian',hours(5),'SamplePoints',tdt);
%}

%slidingWindowsSize = 5; % not work for b7 b11

%{
slidingWindowsSize = 11;
try
    [cTempMaxDtAdj,TF,U,L,C] = filloutliers(cTempMaxDtSec,'clip','movmedian',slidingWindowsSize,'SamplePoints',1:length(cTempMaxDtSec));
    [dTempMaxDtAdj,TF,U,L,C] = filloutliers(dTempMaxDt,'clip','movmedian',slidingWindowsSize,'SamplePoints',1:length(dTempMaxDt));
catch
    print("error in applying filloutliers ") 
end
%}                

 
%charInput(~any(charInput, 2), :) = [];% 빈 열 삭제 - discharge / measure 항목 삭제
result = [cap',cycleTimeHour',restTimeHour',restCycle',cTempMax',cCcEndTimeSec',dTempMax',dCcEndTimeSec',ohm',re_c',re_d',cycleNoChargeRe',cycleNoDischargeRe',pattern_dVolt',pattern_temp',pattern_CC_amps',charInput ];

end % end function


