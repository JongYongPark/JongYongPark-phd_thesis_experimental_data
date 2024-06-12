function [SOC soc_max] = ryan4_calc_SOC_with_offset(I,t,isDischarge,offset_rate_c,offset_rate_d)

    %offset_rate_c = 1; %1.0283;
    offset_c = 0;

    %offset_rate_d = 1; %1.1;
    offset_d = 0;    
    
    t_diff = diff(t);
    
    %t_diff = [ t_diff t_diff(end)] ;
    t_diff = [ t(1) t_diff ] ;

    if isDischarge
        SOC_minute = -I .* t_diff .* offset_rate_d + offset_d ; % minute
    else
        SOC_minute = I .* t_diff .* offset_rate_c + offset_c ; % minute        
    end
    SOC = SOC_minute  / 60 ;
    soc_max = sum(SOC) ;

end % end function


