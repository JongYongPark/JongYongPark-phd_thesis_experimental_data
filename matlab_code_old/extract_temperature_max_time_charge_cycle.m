function [cap,maxTemp,maxTimedelta,abnormal] = extract_temperature_max_time_charge_cycle(B)
bcycle = B.cycle;
prevTemp = 0;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'charge') && ( i <=  length(bcycle) -2  )
          % save max temp
          %{
          if i <= 40
              maxTemp(i) = max(bcycle(i).data.Temperature_measured(300:end)); % to ignaore max temp is high at start
          else
              maxTemp(i) = max(bcycle(i).data.Temperature_measured);
          end
          %}
          
          boolVector = islocalmax(bcycle(i).data.Temperature_measured,'MinProminence',2);
          index = find(boolVector, 1, 'first');
          
          % https://kr.mathworks.com/matlabcentral/answers/36117-check-edittext-empty-or-not?s_tid=ta_ans_results
          if isempty(index)
              % https://kr.mathworks.com/matlabcentral/answers/232852-how-to-initialize-an-empty-vector-null-vector-in-matlab?s_tid=srchtitle
              % u_Q1 = []; 
              
              % https://kr.mathworks.com/matlabcentral/answers/12912-how-to-create-an-empty-array-of-structs?s_tid=ta_ans_results
              % create empty struct  
              
              % sometime we can not find max value with islocalmax when
              % noise is large, then use max function
              temp = max(bcycle(i).data.Temperature_measured);
          else
              temp = bcycle(i).data.Temperature_measured(index);
          end
          
          maxTemp(i) = temp; 
          

          
          for j=1:length(bcycle(i).data.Temperature_measured)
              if maxTemp(i) ==  bcycle(i).data.Temperature_measured(j)
                  maxTimedelta(i) = bcycle(i).data.Time(j);
                  break % check scope - exit inner loop
              end
          end
          
          % for abnormal cases - debug here
          if  maxTemp(i) <  28.0 
              abnormalTemp = bcycle(i).data.Temperature_measured;
              abnormalTime = bcycle(i).data.Time;
              timeDelta = bcycle(i).data.Time(j);
              abnormal(i) = 1;
          else
              abnormal(i) = 0;
          end
          prevTemp = maxTemp(i);
          
          
          if j == length(bcycle(i).data.Temperature_measured)
              print("error")
          end
         
        if isequal(bcycle(i+1).type, 'discharge')
            cap(i) = bcycle(i+1).data.Capacity;
        elseif isequal(bcycle(i+2).type, 'discharge')
            cap(i) = bcycle(i+2).data.Capacity;
        else
            maxTemp(i) = [];
            maxTimedelta(i) = [];
        end
    
    end
    

        
end
maxTimedelta(maxTemp==0) = []; % It can be 0 when first index have high temp
cap(maxTemp==0) = [];
abnormal(maxTemp==0) = [];
maxTemp(maxTemp==0) = [];

