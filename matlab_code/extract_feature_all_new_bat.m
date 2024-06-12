function [info_str, cycle_index, summary,VITcharge, VITdischarge,VIT_leng ] = extract_feature_all_new_bat(batchNum,batNum,B)

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
    policy = B.policy ;
    policy_readable = B.policy_readable ;
    channel_id = B.channel_id;
    cycle_life = B.cycle_life;
    key = "b" +  num2str(batchNum) + "c" + num2str(batNum) ;
    
    info_str = [ key, channel_id ,policy, policy_readable ];
    % ( cycle_life - 1) * 1
    chargetime = B.summary.chargetime;
    cycle = B.summary.cycle;
    IR = B.summary.IR;
    QCharge = B.summary.QCharge;
    QDischarge = B.summary.QDischarge;
    Tavg = B.summary.Tavg;
    Tmin = B.summary.Tmin;
    Tmax = B.summary.Tmax;

    cycle = cycle-1;
    summary = horzcat( cycle,  QDischarge, IR , Tavg, Tmin, Tmax, chargetime, QCharge);
    
    % https://kr.mathworks.com/matlabcentral/answers/69551-how-can-i-delete-a-certain-number-of-rows-in-a-vector?s_tid=ta_ans_results
    
    % delete first row which contains null values
    summary(1,:) = [];
    
    % 10000 * 1
    Vdlin = B.Vdlin;
    
    % 1 * ( cycle_life - 1)
    %cycles = B.cycles
    cycle_index = 1;   
    
    %{
    for cycleNum = 2: cycle_life-1  
             %% V I T
 
             % 789 % 10 = 9
            le = mod(length(B.cycles(cycleNum).V), 10);
            vTemp = B.cycles(cycleNum).V(1:end-le,:)'; % end - le = 789 - 9 = 780 %끝을 자른다.
            vTemp = reshape(vTemp, length(vTemp)/10, []); % 열개의 row로 만든다. fill the first column and then fill the next column
            vTemp = mean(vTemp); % column 각 항목의 평균값을 구한다. 시리즈의 첫번째 블럭의 평
            vTemp_leng = length(vTemp);
            
            iTemp = B.cycles(cycleNum).I(1:end-le,:)';
            iTemp = reshape(iTemp, length(iTemp)/10, []);
            iTemp = mean(iTemp);
            iTemp_leng = length(iTemp);

            tTemp = B.cycles(cycleNum).T(1:end-le,:)';
            tTemp = reshape(tTemp, length(tTemp)/10, []);
            tTemp = mean(tTemp);
            tTemp_leng = length(tTemp);

            VITdischarge(cycle_index, :) = [vTemp, iTemp, tTemp];   
            VITdischargeIndex(cycle_index, :) = [vTemp_leng,iTemp_leng,tTemp_leng];
            cycle_index = cycle_index+1;
    end    
    %}
      VIT_leng = 0;
      break_pioint = 0;
      xq_new = linspace(0.0,1.1,100);

     for cycleNum = 2: cycle_life-1  
             %% V I T
 
             %% charge
            [xq, index] = unique(B.cycles(cycleNum).Qc,"last");

            yV = B.cycles(cycleNum).V(index);
            yI = B.cycles(cycleNum).I(index);
            yT = B.cycles(cycleNum).T(index);
            
            yV = interp1(xq,yV,xq_new,'linear');
            yI = interp1(xq,yI,xq_new,'linear');
            yT = interp1(xq,yT,xq_new,'linear');
            
            if cycleNum == 2
                VIT_leng = length(xq_new);
            end
            
            try
                yV = fillmissing(yV,'nearest');
                yI(isnan(yI)) = 0;
                %yT = fillmissing(yT,'movmean', 50) ; 
                yT = fillmissing(yT,'nearest');
                   
                
%                 [yV,tfV] = fillmissing(yV,'linear','SamplePoints',xq_new);
%                 yI(isnan(yI)) = 0;
%                 [yT,tfT] = fillmissing(yT,'linear','SamplePoints',xq_new);

                
                
%                 % fill nan by last value
%                 idxV = (~isnan(yV )); % find index of not nan
%                 yV = yV(idxV);
%                 yV = yV(cumsum(idxV)); % fill nana by last value
% 
%                 % fill nan by zero
%                 yI(isnan(yI)) = 0;
% 
%                 idxT = (~isnan(yT )); % find index of not nan
%                 yT = yT(idxT);
%                 yT = yT(cumsum(idxT)); % fill nana by last value

            catch
                break_pioint = 1
            end 
 
            VITcharge(cycle_index, :) = [yV, yI, yT];   
            
            
            %% discarge
            [xq, index] = unique(B.cycles(cycleNum).Qd,"last");
              
            yV = B.cycles(cycleNum).V(index);
            yI = B.cycles(cycleNum).I(index);
            yT = B.cycles(cycleNum).T(index);
            
            yV = interp1(xq,yV,xq_new,'linear');
            yI = interp1(xq,yI,xq_new,'linear');
            yT = interp1(xq,yT,xq_new,'linear');
            
            
            try
                
                
                yV = fillmissing(yV,'nearest');
                yI(isnan(yI)) = 0;
               % yT = fillmissing(yT,'linear','SamplePoints',xq_new);
                yT = fillmissing(yT,'nearest');
                
%                 [yV,tfV] = fillmissing(yV,'linear','SamplePoints',xq_new);
%                 yI(isnan(yI)) = 0;
%                 [yT,tfT] = fillmissing(yT,'linear','SamplePoints',xq_new);

%                 % fill nan by last value
%                 idxV = (~isnan(yV )); % find index of not nan
%                 yV = yV(idxV);
%                 yV = yV(cumsum(idxV)); % fill nana by last value
% 
%                 % fill nan by zero
%                 yI(isnan(yI)) = 0;
% 
%                 idxT = (~isnan(yT )); % find index of not nan
%                 yT = yT(idxT);
%                 yT = yT(cumsum(idxT)); % fill nana by last value

            catch
                break_pioint = 1
            end 
            
            VITdischarge(cycle_index, :) = [yV, yI, yT];   
   
            %%%%%%%%%%%%%%%%%%%%%%
            %% time based - 방전시간이 각각 달라서 적용하기 어렵다.
            
            %%%%%%%%%%%%%%%%%%%
            %% finally 
            cycle_index = cycle_index+1;
     end   
    
 %{   
    
    for cycleNum = 2: cycle_life  
    %    I = B.cycles.I
        cycleNum
        i = cycleNum -1 ;
        cycles(i) = horzcat( ...
            B.cycles(cycleNum).t ...
            , B.cycles(cycleNum).I ...
            , B.cycles(cycleNum).V ...
            , B.cycles(cycleNum).T ...
            , B.cycles(cycleNum).Qc ...
            , B.cycles(cycleNum).Qd ...
        )

       cycles_lin(i) = horzcat( ...
          B.cycles(cycleNum).Qdlin ...
          , B.cycles(cycleNum).Tdlin ...
          , B.cycles(cycleNum).discharge_dQdV ...
          ); 
      
    end
   %}

     cycle_index = cycle_life -2 ;

%charInput(~any(charInput, 2), :) = [];% 빈 열 삭제 - discharge / measure 항목 삭제

end % end function


