function structData  = extract_feature_all_new_bat_v3(batchNum,batNum,B)

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
    structData.chargetime = B.summary.chargetime(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.cycle = B.summary.cycle(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.IR = B.summary.IR(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.QCharge = B.summary.QCharge(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.QDischarge = B.summary.QDischarge(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.Tavg = B.summary.Tavg(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.Tmin = B.summary.Tmin(new_cycle_start_idx:new_cycle_end_idx,:);
    structData.Tmax = B.summary.Tmax(new_cycle_start_idx:new_cycle_end_idx,:);

    structData.cycle = structData.cycle-1;
    structData.Vdlin = B.Vdlin;
    
    cycleNum = 1;   
    VT_leng = 0;
    break_pioint = 0;
    xq_new = linspace(0.0,1.0,100); % SOC
    newcycleNum = 1;
     for cycleNum = new_cycle_start_idx: new_cycle_end_idx  
             %% V I T
 
             %% charge

            try
                Qc_tmp = B.cycles(cycleNum).Qc;
                Qc_tmp(Qc_tmp<0) = 0;
               [xq, index] = unique(Qc_tmp,"first");

                yV = B.cycles(cycleNum).V(index);
                yI_c = B.cycles(cycleNum).I(index);
                yT = B.cycles(cycleNum).T(index);

                yV = interp1(xq,yV,xq_new,'linear');
                yI_c = interp1(xq,yI_c,xq_new,'linear');
                yT = interp1(xq,yT,xq_new,'linear');
            
                yV = fillmissing(yV,'nearest');
                yI_c(isnan(yI_c)) = 0;
                %yT = fillmissing(yT,'movmean', 50) ; 
                yT = fillmissing(yT,'nearest');
            catch
                batchNum
                batNum
                cycleNum
                break_pioint= 1
            end 
             %VTcharge(cycleNum, :) = [yV, yT];   
            
            Vc(newcycleNum, :) = yV';
            Tc(newcycleNum, :) = yT';
         
            
            %% discarge

            
            try
                Qd_tmp = B.cycles(cycleNum).Qd;
                Qd_tmp(Qd_tmp<0) = 0;
                [xq, index] = unique(Qd_tmp,"first");

                yV = B.cycles(cycleNum).V(index);
                yI_d = B.cycles(cycleNum).I(index);
                yT = B.cycles(cycleNum).T(index);

                yV = interp1(xq,yV,xq_new,'linear');
                yI_d = interp1(xq,yI_d,xq_new,'linear');
                yT = interp1(xq,yT,xq_new,'linear');

            
                yV = fillmissing(yV,'nearest');
                yI_d(isnan(yI_d)) = 0;
                % yT = fillmissing(yT,'linear','SamplePoints',xq_new);
                yT = fillmissing(yT,'nearest');
                %yT = yT(cumsum(idxT)); % fill nana by last value
            catch
                batchNum
                batNum
                cycleNum
                break_pioint = 2
            end 
            
            Vd(newcycleNum, :) = yV';
            Td(newcycleNum, :) = yT';
            

   
            if cycleNum == 2
                VT_leng = length(xq_new);
                chargeI = yI_c;
                dischargeI = yI_d;
            end
            

            
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
    structData.Ic = chargeI;
    structData.Id = dischargeI;
    %structData.total_cycle = cycleNum;
    
    structData.QDischargeSmooth = smooth(structData.cycle, structData.QDischarge ,0.1,'rloess');
    structData.QDischargePolyMdl = polyfit(structData.cycle, structData.QDischargeSmooth,4);
    structData.QDischargePolyfit = polyval(structData.QDischargePolyMdl,structData.cycle')';
      
       
%charInput(~any(charInput, 2), :) = [];% 빈 열 삭제 - discharge / measure 항목 삭제

end % end function


