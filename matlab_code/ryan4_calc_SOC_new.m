function [Ah_ds_h Ah_h SOC SOH] = ryan4_calc_SOC_new(I,t,Q)
  
    % C:\nobackup\_phd_work\_battery_soh\_작성문서_battery\346501527888d799d94279cfe74049fde53ca2d5a1275d083d28f925253cf657.pdf
    % A123 Systems, model APR18650M1A, 1.1 Ah nominal capacity)
    Ah_rated = 1.1;
    % 1.1004, 0.3292
    offset_rate = 1; %1.0283;
    offset = 0;
   
    t_diff = diff(t);
    
    %t_diff = [ t_diff t_diff(end)] ;
    t_diff = [ t(1) t_diff ] ;

    Ah_ds_h = (-I .* t_diff  + offset)  / 60 ;
    Ah_h = cumsum(Ah_ds_h) ;
    Ah_end = Ah_h(end);
    offset_rate = Q / Ah_end;
    
    Ah_ds = -I .* t_diff .*offset_rate + offset ; % minute
    Ah_ds_h = Ah_ds  / 60 ;
    Ah_h = cumsum(Ah_ds_h) ;
    Ah_end = Ah_h(end);
    SOC = Ah_h/ Q;
    SOH = Ah_h(end)/Ah_rated;


end % end function


