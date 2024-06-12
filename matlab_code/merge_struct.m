function structData  = merge_struct(src,dest)

    structData = src;

    structData.cycle_life = src.cycle_life + dest.cycle_life -1 ;
    %structData.Vdlin
  
    structData.summary.chargetime = vertcat(src.summary.chargetime(:),dest.summary.chargetime);
    total_cycle = length(src.summary.cycle) + length(dest.summary.cycle) ;
    structData.summary.cycle = linspace(1,total_cycle,total_cycle)';
    structData.summary.IR = vertcat(src.summary.IR(:),dest.summary.IR);
    structData.summary.QCharge = vertcat(src.summary.QCharge(:),dest.summary.QCharge);
    structData.summary.QDischarge = vertcat(src.summary.QDischarge(:),dest.summary.QDischarge);
    structData.summary.Tavg = vertcat(src.summary.Tavg(:),dest.summary.Tavg);
    structData.summary.Tmin = vertcat(src.summary.Tmin(:),dest.summary.Tmin);
    structData.summary.Tmax = vertcat(src.summary.Tmax(:),dest.summary.Tmax);
    structData.summary.chargetime = vertcat(src.summary.chargetime(:),dest.summary.chargetime);
    
    src_count = length(src.summary.cycle);
    dest_count = length(dest.summary.cycle);
    i = src_count+1;
    j = 1;
    for ii = 1: dest_count 
        %i
        %j
        structData.cycles(i).discharge_dQdV = dest.cycles(j).discharge_dQdV;
        structData.cycles(i).t = dest.cycles(j).t;
        structData.cycles(i).Qc = dest.cycles(j).Qc;
        structData.cycles(i).I = dest.cycles(j).I;
        structData.cycles(i).V = dest.cycles(j).V;
        structData.cycles(i).T = dest.cycles(j).T;
        structData.cycles(i).Qd = dest.cycles(j).Qd;
        structData.cycles(i).Qdlin = dest.cycles(j).Qdlin;
        structData.cycles(i).Tdlin = dest.cycles(j).Tdlin;
        i = i + 1;
        j = j + 1;
    end
end % end function


