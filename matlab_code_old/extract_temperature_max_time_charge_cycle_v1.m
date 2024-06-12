function [cap,maxTemp,maxTimedelta] = extract_temperature_max_time_charge_cycle_v1(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'charge') && ( i <=  length(bcycle) -2  )
          % save max temp
          if i <= 40
              maxTemp(i) = max(bcycle(i).data.Temperature_measured(300:end)); % to ignaore max temp is high at start
          else
              maxTemp(i) = max(bcycle(i).data.Temperature_measured);
          end
          
          for j=1:length(bcycle(i).data.Temperature_measured)
              if maxTemp(i) ==  bcycle(i).data.Temperature_measured(j)
                  maxTimedelta(i) = bcycle(i).data.Time(j);
                  break % check scope - exit inner loop
              end
          end
          
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
maxTemp(maxTemp==0) = [];

