function [ryan5_battery_dataset,data_conversion_param]  = ryan5_util_remove_data_over_specific_soh(soh_ref)

global ryan5_battery_dataset_raw 
new_index = 1;

idxAll = (1:length(ryan5_battery_dataset_raw));
for i = 1:length(idxAll)
    %j = idx(i);
    initC = ryan5_battery_dataset_raw(i).QDischargeSmooth(1) ;

    for ii = 1:ryan5_battery_dataset_raw(i).cycle_life
        if ryan5_battery_dataset_raw(i).QDischargeSmooth(ii) <= soh_ref  %1.048
            % skip count 
            break
        end
        if ii == ryan5_battery_dataset_raw(i).cycle_life
            error_is = true;
        end
    end
    %              bat_num        new_start_index  
    
    ryan5_battery_dataset(i) = ryan5_battery_dataset_raw(i);
    ryan5_battery_dataset(i).cycle_life = ryan5_battery_dataset_raw(i).cycle_life - ii;
    %ryan5_battery_dataset_raw(i).cycle_life
    %ryan5_battery_dataset(i).cycle_life
    ryan5_battery_dataset(i).chargetime([1:ii],:) = [] ;

    data_conversion_param(i,:) = [ i      initC  ii   ryan5_battery_dataset_raw(i).QDischargeSmooth(ii)   ryan5_battery_dataset_raw(i).cycle_life ryan5_battery_dataset(i).cycle_life    ];
    
    %size(ryan5_battery_dataset_raw(i).chargetime)
    %size(ryan5_battery_dataset(i).chargetime)
    ryan5_battery_dataset(i).cycle = [] ;
    ryan5_battery_dataset(i).cycle = ryan5_battery_dataset_raw(i).cycle(1:end-ii,:);
    ryan5_battery_dataset(i).RUL([1:ii],:) = [] ;
    ryan5_battery_dataset(i).IR([1:ii],:) = [] ;
    ryan5_battery_dataset(i).QCharge([1:ii],:) = [] ;
    ryan5_battery_dataset(i).QDischarge([1:ii],:) = [] ;
    ryan5_battery_dataset(i).SOH_c([1:ii],:) = [] ;
    ryan5_battery_dataset(i).SOH_d([1:ii],:) = [] ;  
    ryan5_battery_dataset(i).Time_c([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Time_d([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Time_d1([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Tavg([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Tmin([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Tmax([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Vc([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Vd([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Ic([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Id([1:ii],:) = [] ;    
    ryan5_battery_dataset(i).Tc([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Td([1:ii],:) = [] ;

    
    ryan5_battery_dataset(i).discharge_dQdV([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Qdlin([1:ii],:) = [] ;
    ryan5_battery_dataset(i).Tdlin([1:ii],:) = [] ;

    ryan5_battery_dataset(i).QChargeSmooth([1:ii],:) = [] ;    
    ryan5_battery_dataset(i).QDischargeSmooth([1:ii],:) = [] ;
    ryan5_battery_dataset(i).QDischargePolyMdl = [];
    ryan5_battery_dataset(i).QDischargePolyMdl = polyfit(ryan5_battery_dataset(i).cycle, ryan5_battery_dataset(i).QDischargeSmooth,4);
    ryan5_battery_dataset(i).QDischargePolyfit = [];
    ryan5_battery_dataset(i).QDischargePolyfit = polyval(ryan5_battery_dataset(i).QDischargePolyMdl,ryan5_battery_dataset(i).cycle')';

end % for
end % end function


