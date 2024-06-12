function [cap,cTempMax,cTempMaxDt,cTempMaxDtAdj,ohm,re_c,re_d,dTempMax,dTempMaxDt,dTempMaxDtAdj] = extract_feature_v4(B,ignoreCycle)
  
% v4 - delete regenratoin cycle

    % cycle pattern
    % charge ( impenedace ) discarge ( impedance )
    bcycle = B.cycle;
    cycle_index = 1;
    cap_prev = 100;
    last_charge_reverse_index = 3;

    %  temp
    prevTemp = 0;

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

              cTempMaxGuess = islocalmax(bcycle(i).data.Temperature_measured,'MinProminence',2);
              cTempMaxIndex = find(cTempMaxGuess, 1, 'first');

              % https://kr.mathworks.com/matlabcentral/answers/36117-check-edittext-empty-or-not?s_tid=ta_ans_results
              if isempty(cTempMaxIndex)
                  % https://kr.mathworks.com/matlabcentral/answers/232852-how-to-initialize-an-empty-vector-null-vector-in-matlab?s_tid=srchtitle
                  % u_Q1 = []; 

                  % https://kr.mathworks.com/matlabcentral/answers/12912-how-to-create-an-empty-array-of-structs?s_tid=ta_ans_results
                  % create empty struct  

                  % sometime we can not find max value with islocalmax when
                  % noise is large, then use max function
                  cTemp = max(bcycle(i).data.Temperature_measured);
              else
                  cTemp = bcycle(i).data.Temperature_measured(cTempMaxIndex);
              end

              if cTemp == 0 
                  sprintf("temp=0 at index =%d ",i)
              end
              cTempMax(cycle_index) = cTemp; 

              for j=1:length(bcycle(i).data.Temperature_measured)
                  if cTempMax(cycle_index) ==  bcycle(i).data.Temperature_measured(j)
                      cTempMaxDt(cycle_index) = bcycle(i).data.Time(j);
                      break % check scope - exit inner loop
                  end
              end

              if j == length(bcycle(i).data.Temperature_measured)
                  sprintf("error")
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

            end        
            %% Capacity
            
            % ignore rest regeneratoin.
            cap_value = bcycle(discharge_index).data.Capacity;
            cap(cycle_index) = cap_value;
            if cap_prev <= cap_value
                cap_ignore = true;
            else
                cap_ignore = false;
                cap_prev = cap_value;
            end 
            %% discharge temp

             dTempMaxGuess = islocalmax(bcycle(i).data.Temperature_measured,'MinProminence',2);
              dTempMaxIndex = find(dTempMaxGuess, 1, 'first');

              % https://kr.mathworks.com/matlabcentral/answers/36117-check-edittext-empty-or-not?s_tid=ta_ans_results
              if isempty(dTempMaxIndex)
                  dTemp = max(bcycle(i).data.Temperature_measured);
              else
                  dTemp = bcycle(i).data.Temperature_measured(dTempMaxIndex);
              end

              if dTemp == 0 
                  sprintf("temp=0 at index =%d ",i)
              end
              dTempMax(cycle_index) = dTemp; 
              
              for j=1:length(bcycle(i).data.Temperature_measured)
                  if dTempMax(cycle_index) ==  bcycle(i).data.Temperature_measured(j)
                      dTempMaxDt(cycle_index) = bcycle(i).data.Time(j);
                      break % check scope - exit inner loop
                  end
              end

              if j == length(bcycle(i).data.Temperature_measured)
                  sprintf("error")
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
            else
                re_c(cycle_index) = bcycle(imp_c_index).data.Re;
            end

            if(imp_d_index == -1) 
                re_d(cycle_index) = NaN;
            else
                try
                    re_d(cycle_index) = bcycle(imp_d_index).data.Re;
                catch
                    print("error");
                end
                    
            end

            %% Increase Cycle index
            
            if ignoreCycle > 0
                ignoreCycle = ignoreCycle -1;
            elseif cap_ignore 
                
            else
                cycle_index = cycle_index +1;
            end
        
            %sprintf("in %d",i)
        else
            %sprintf("out %d",i)
        end


    end % end for

%print("end");
%maxTimedelta(maxTemp==0) = []; % It can be 0 when first index have high temp
%cap(maxTemp==0) = [];
%abnormal(maxTemp==0) = [];
%maxTemp(maxTemp==0) = [];

tct = datetime(2017,1,1,0,0,0) + hours(0:length(cTempMaxDt)-1);
[cTempMaxDtAdj,TF,U,L,C] = filloutliers(cTempMaxDt,'clip','movmedian',hours(5),'SamplePoints',tct);

tdt = datetime(2017,1,1,0,0,0) + hours(0:length(dTempMaxDt)-1);
[dTempMaxDtAdj,TF,U,L,C] = filloutliers(dTempMaxDt,'clip','movmedian',hours(5),'SamplePoints',tdt);

end % end function


