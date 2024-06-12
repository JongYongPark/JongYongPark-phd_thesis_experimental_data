function structData  = ryan4_extract_feature(batchNum,batNum,B)

% ignore all cycle which dose not compose charge-dischage pair. some cycles
% have duplicated same cycles.
% delete regenratoin cycle is done in outside of this function
% v3 - add Voltage/Current/temp

%% all
%cap,cTempMax,cTempMaxDtSec,cTempMaxDtAdj,ohm,re_c,re_d,dTempMax,dTempMaxDt,dTempMaxDtAdj
% cap 에서 하나의 index 가 빠진다. 하지만 일단 무시해도 된다.
    rated_ah=1.1;
    
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
    structData.chargetime = B.summary.chargetime(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.cycle = B.summary.cycle(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.IR = B.summary.IR(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.QCharge = B.summary.QCharge(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.QDischarge = B.summary.QDischarge(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.Tavg = B.summary.Tavg(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.Tmin = B.summary.Tmin(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.Tmax = B.summary.Tmax(new_cycle_start_idx:new_cycle_end_idx,:);
    
    structData.cycle = structData.cycle-1;
    structData.Vdlin = B.Vdlin(1:10:end);;
    
    cycleNum = 1;   
    VT_leng = 0;
    break_pioint = 0;
    xq_new = linspace(0.0,1.2,102);
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
                
                yTime_c = yTime_c(2:end-1);
                yV = yV(2:end-1);
                yI_c = yI_c(2:end-1);
                yT = yT(2:end-1);
                
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
                %index = index_last;
                
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
                bbb = [ endVal , endVal ,endVal ] ;
                yTime_d1 = [ aaa bbb ];

                yTime_d = yTime_d(2:end-1);
                yV = yV(2:end-1);
                yI_d = yI_d(2:end-1);
                yT = yT(2:end-1);
                
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
    
    structData.QChargeSmooth = smooth(structData.cycle, structData.QCharge ,0.1,'rloess');
    structData.QDischargeSmooth = smooth(structData.cycle, structData.QDischarge ,0.1,'rloess');
    structData.QDischargePolyMdl = polyfit(structData.cycle, structData.QDischargeSmooth,4);
    structData.QDischargePolyfit = polyval(structData.QDischargePolyMdl,structData.cycle')';
    structData.SOH_c = structData.QChargeSmooth/rated_ah; 
    structData.SOH_d = structData.QDischargeSmooth/rated_ah; 
       
%charInput(~any(charInput, 2), :) = [];% 빈 열 삭제 - discharge / measure 항목 삭제

end % end function


