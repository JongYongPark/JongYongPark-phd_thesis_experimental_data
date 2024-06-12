function [Ah_ds Ah SOC SOH] = ryan4_calc_SOC(I,t,isDischarge,Q)
  
    % C:\nobackup\_phd_work\_battery_soh\_작성문서_battery\346501527888d799d94279cfe74049fde53ca2d5a1275d083d28f925253cf657.pdf
    % A123 Systems, model APR18650M1A, 1.1 Ah nominal capacity)
    Ah_rated = 1.1;
    % 1.1004, 0.3292
    offset_rate_c = 1.0969; %1.0283;
    offset_c = 0;

    offset_rate_d =  0.9075; %0.3292; %1.1;
    offset_d = 0;    
    
    t_diff = diff(t);
    
    %t_diff = [ t_diff t_diff(end)] ;
    t_diff = [ t(1) t_diff ] ;

    if isDischarge
        Ah_ds = -I .* t_diff .* offset_rate_d + offset_d ; % minute
    else
        Ah_ds = I .* t_diff .* offset_rate_c + offset_c ; % minute        
    end
    Ah_ds = Ah_ds  / 60 ;
    Ah = cumsum(Ah_ds) ;
    SOC = Ah/ Q;
    SOH = Ah(end)/Ah_rated;


end % end function


