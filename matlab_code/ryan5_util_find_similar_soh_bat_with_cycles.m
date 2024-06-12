function [return_batNum,return_start_cycle,return_batNum_nth,return_start_cycle_nth] = ...
    ryan5_util_find_similar_soh_bat_with_cycles( bat_soh_data, start_cycle, window, nth ) 

% https://kr.mathworks.com/matlabcentral/answers/420960-how-to-use-global-variables-inside-a-function
global ryan5_battery_dataset  ;
global RUL SOH Y_trainValid_RUL Y_test_RUL Y_trainValid_SOH Y_test_SOH ;
global idxTrain idxValid idxTest idxTrainValid idxTrainSort idxValidSort idxTranValidSort idxTestSort ;
global idxAll idxTestAll_batIndex ;

idxAll;
idxTestSort;
%bat_soh_data = idxTestSort(bat_index1)

%{
idxFindAll = find(idxTestAll_batIndex == bat_soh_data);
idxFindAll;
size(Y_test_RUL);
size(Y_test_SOH);
Y_test_RUL_ref = Y_test_RUL(idxFindAll);
Y_test_SOH_ref = Y_test_SOH(idxFindAll);
% Yfit_test_Y_test_RUL1 = Yfit_test_RUL(idxFindAll);
%}

compareStart = bat_soh_data(start_cycle);
compareEnd = bat_soh_data(start_cycle+window-1);
soh_gap = compareStart - compareEnd ;


% find most similar data
% idxTrainValid = [idxTrain idxValid]

count = length(idxTrain) + length(idxValid);


idxSel_start = 1;
idxSel_end = 1;
diff_start_save = 1000;
diff_end_save = 1000;
result_gap = zeros(count,1);
result_batNum = zeros(count,1);
result_startInx = zeros(count,1);
cycle_number = 1;

for i=1:count 
    diff_start_save = 1000;
    bat_index = idxTrainValid(i);
    endIdx = ryan5_battery_dataset(bat_index).cycle_life - (window - 1);
    for j=1 : endIdx
        diff_start = ryan5_battery_dataset(bat_index).QDischargeSmooth(j) - compareStart ;
        diff_start = abs(diff_start);
        if diff_start < diff_start_save
            idxSel_start = bat_index;
            cycle_number = j;
            diff_start_save = diff_start;
        end
    end
    result_startInx(i,:) = cycle_number;
    result_batNum(i,:) = idxSel_start;
    if cycle_number  + (window - 1) > endIdx 
        err_here = 0 ;
    end
    gap_temp = ryan5_battery_dataset(bat_index).QDischargeSmooth(cycle_number) ...
        - ryan5_battery_dataset(bat_index).QDischargeSmooth(cycle_number  + (window - 1));
    gap_temp = abs(gap_temp);
    result_gap(i,:) = abs(soh_gap - gap_temp); 
end

[min_value, min_bat_idx ] = min(result_gap);
return_batNum = result_batNum(min_bat_idx);
return_start_cycle = result_startInx(min_bat_idx);

% find 5th min

[sortedVals,indexes] = sort(result_gap);
return_batNum_nth = result_batNum(indexes(nth));
return_start_cycle_nth = result_startInx(indexes(nth));

end