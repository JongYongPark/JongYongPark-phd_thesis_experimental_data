function [result] = extract_feature_all(B,cycleCountToIgnoreFromFirst,refCap)

% v4 - delete regenratoin cycle

%% all
%cap,cTempMax,cTempMaxDt,cTempMaxDtAdj,ohm,re_c,re_d,dTempMax,dTempMaxDt,dTempMaxDtAdj
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
    
    
    max_cycle = length(bcycle);
    for i = 1:max_cycle
        % start from charge [impedance] discharge [impedance]
        if isequal(bcycle(i).type, 'charge') && ( i <=  max_cycle - last_charge_reverse_index  ) ...
                && ((isequal(bcycle(i+1).type, 'discharge') || isequal(bcycle(i+2).type, 'discharge')) )
                
            %% Temperature
              % save max temp
              %{
              if i <= 40
                  maxTemp(i) = max(bcycle(i).data.Temperature_measured(300:end)); % to ignaore max temp is high at start
              else
                  maxTemp(i) = max(bcycle(i).data.Temperature_measured);
              end
              %}
              
                temp = bcycle(i).data.Temperature_measured;
                
              %{
              cTempMaxGuess = islocalmax(,'MinProminence',2);
              cTempMaxIndex = find(cTempMaxGuess, 1, 'first');
              %}

            
            cTempMaxGuess = islocalmax(temp,'MinProminence',2);
            if sum(cTempMaxGuess(:) == 1 ) == 0 
               cTempMaxGuess = islocalmax(temp,'MinProminence',1);
            end
            
            if sum(cTempMaxGuess(:) == 1 ) == 0 
                smoothed = smoothdata(temp);
                cTempMaxGuess = islocalmax(smoothed,'MinProminence',2);
                if sum(cTempMaxGuess(:) == 1 ) == 0 
                   cTempMaxGuess = islocalmax(smoothed,'MinProminence',1);
                end
            end

            %{
            if sum(cTempMaxGuess(:) == 1 ) == 0 
                if cycle_index == 1
                    cTempMaxIndex = round(length(temp)*1/3); % 1/3 쯤 될거라고 가정
                else
                    %cTempMaxIndex = cTempMaxIndex_prev; % 이전 인텍스를 가져온다. 이것은 index 에러 발생시킴
                    cTempMaxIndex = round(length(temp)*1/3); % 1/3 쯤 될거라고 가정
                end 
            else 
                
            end
            %}
            cTempMaxIndex = find(cTempMaxGuess, 1, 'first');  
            
            cTempMaxIndex_prev =  cTempMaxIndex;
              try 
                  % https://kr.mathworks.com/matlabcentral/answers/36117-check-edittext-empty-or-not?s_tid=ta_ans_results
                  if isempty(cTempMaxIndex)
                      % https://kr.mathworks.com/matlabcentral/answers/232852-how-to-initialize-an-empty-vector-null-vector-in-matlab?s_tid=srchtitle
                      % u_Q1 = []; 

                      % https://kr.mathworks.com/matlabcentral/answers/12912-how-to-create-an-empty-array-of-structs?s_tid=ta_ans_results
                      % create empty struct  

                      % sometime we can not find max value with islocalmax when
                      % noise is large, then use max function
                      
                      cTemp = max(bcycle(i).data.Temperature_measured);
                      cTemp = cTemp_prev ;
                  else
                      cTemp = bcycle(i).data.Temperature_measured(cTempMaxIndex);
                  end
                  cTemp_prev = cTemp;

                  if cTemp == 0 
                      sprintf("temp=0 at index =%d ",i)
                  end

                    cTempMax(cycle_index) = cTemp; 
                    
                  %{
                  for j=1:length(bcycle(i).data.Temperature_measured)
                      if cTempMax(cycle_index) ==  bcycle(i).data.Temperature_measured(j)
                          cTempMaxDt(cycle_index) = bcycle(i).data.Time(j);
                          break % check scope - exit inner loop
                      end
                  end
                    
                  if j == length(bcycle(i).data.Temperature_measured)
                      sprintf("error")
                  end
                  %}

                  if isempty(cTempMaxIndex)
                      cTempMaxDt(cycle_index) = cTempMaxDt_prev;
                  else
                      cTempMaxDt(cycle_index) = bcycle(i).data.Time(cTempMaxIndex);
                  end 
                  cTempMaxDt_prev = cTempMaxDt(cycle_index);
                  
              catch
                    sprintf("error - cTempMaxDt");
              end

              
              



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
                restCycle(cycle_index) = 1;
            else
                isRestCycle = false;
                restCycle(cycle_index) = 0;
                cap_prev = cap_value;
            end 
            

            
            
            %% discharge temp

             dTempMaxGuess = islocalmax(bcycle(discharge_index).data.Temperature_measured,'MinProminence',2);
              dTempMaxIndex = find(dTempMaxGuess, 1, 'first');

              % https://kr.mathworks.com/matlabcentral/answers/36117-check-edittext-empty-or-not?s_tid=ta_ans_results
              if isempty(dTempMaxIndex)
                  dTemp = max(bcycle(discharge_index).data.Temperature_measured);
              else
                  dTemp = bcycle(discharge_index).data.Temperature_measured(dTempMaxIndex);
              end

              if dTemp == 0 
                  sprintf("temp=0 at index =%d ",discharge_index)
              end
              dTempMax(cycle_index) = dTemp; 
              
              for j=1:length(bcycle(discharge_index).data.Temperature_measured)
                  if dTempMax(cycle_index) ==  bcycle(discharge_index).data.Temperature_measured(j)
                      dTempMaxDt(cycle_index) = bcycle(discharge_index).data.Time(j);
                      break % check scope - exit inner loop
                  end
              end

              if j == length(bcycle(discharge_index).data.Temperature_measured)
                  sprintf("error")
              end
              
        
           
           %% Time Index
           curDischargeTime = datetime(bcycle(discharge_index).time);
           % 현재 사이클에서 충전 시작시간에서 방전시작시간까지 
           restTimeDuration = (datetime(bcycle(discharge_index).time) - datetime(bcycle(i).time)) ;           
           
           % 이전 방전 시작시간 부터 현재 방전 시작시간까지. 방전시간을 기준으로 잡는다.
           if cycle_index == 1 
               initialDischareTime = datetime(curDischargeTime);
               cycleTime(1) = hours(restTimeDuration);
               
           else    
               cycleTime(cycle_index) =  hours(curDischargeTime - initialDischareTime);
           end
           
           %% rest time 
           
           %{
           % from staring time of charge to starting time of discharge
           % 배터리 5,6,7 이 모두 같아서 그래프가 하나로 나온다.
           restTimeDuration = (datetime(bcycle(discharge_index).time) - datetime(bcycle(i).time)) ;
           %restTime = minutes(restTimeDuration,'seconds');
           restTime(cycle_index) = minutes(restTimeDuration);
           %}
           
           
           % 디버그 
          
           % from ending time of charge to starting time of discharge
           
           %bcycle(discharge_index).time
           %bcycle(i).time
           %cTempMaxDt(cycle_index)
           
           if restTimeOption == 0 
               % 충전시작시간에서 CC 가 끝나는 시점, 이것은 최고 온도로 확인 
               restTimeDuration_sec = seconds(restTimeDuration) - cTempMaxDt(cycle_index);
               %restTime(cycle_index) = restTimeDuration_sec / 60; % minute
               restTime(cycle_index) = restTimeDuration_sec / 60 / 60; % hours 
           elseif restTimeOption == 1
               if cycle_index == 1 
                   restTime(cycle_index) =  cycleTime(1);
               else
               restTime(cycle_index) = cycleTime(cycle_index) - cycleTime(cycle_index-1) ;     
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
tct = datetime(2017,1,1,0,0,0) + hours(0:length(cTempMaxDt)-1);
[cTempMaxDtAdj,TF,U,L,C] = filloutliers(cTempMaxDt,'clip','movmedian',hours(5),'SamplePoints',tct);

tdt = datetime(2017,1,1,0,0,0) + hours(0:length(dTempMaxDt)-1);
[dTempMaxDtAdj,TF,U,L,C] = filloutliers(dTempMaxDt,'clip','movmedian',hours(5),'SamplePoints',tdt);
%}

%slidingWindowsSize = 5; % not work for b7 b11
slidingWindowsSize = 11;
[cTempMaxDtAdj,TF,U,L,C] = filloutliers(cTempMaxDt,'clip','movmedian',slidingWindowsSize,'SamplePoints',1:length(cTempMaxDt));
[dTempMaxDtAdj,TF,U,L,C] = filloutliers(dTempMaxDt,'clip','movmedian',slidingWindowsSize,'SamplePoints',1:length(dTempMaxDt));

result = [cap',cycleTime',restTime',restCycle',cTempMax',cTempMaxDt',cTempMaxDtAdj',ohm',re_c',re_d',cycleNoChargeRe',cycleNoDischargeRe',dTempMax',dTempMaxDt',dTempMaxDtAdj' ];

end % end function


