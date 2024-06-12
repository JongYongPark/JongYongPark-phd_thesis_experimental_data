function [idxSel_upper,matchedRUL_upper,idxSel_lower,matchedRUL_lower,bestIndex] = ryan5_util_find_similar_rul_bat_with_full_cycle( bat_num ) 

% https://kr.mathworks.com/matlabcentral/answers/420960-how-to-use-global-variables-inside-a-function
global ryan5_battery_dataset  ;
global RUL SOH Y_trainValid_RUL Y_test_RUL Y_trainValid_SOH Y_test_SOH ;
global idxTrain idxValid idxTest idxTrainValid idxTrainSort idxValidSort idxTranValidSort idxTestSort ;
global idxAll idxTestAll_batIndex ;

idxAll;
idxTestSort;
%bat_num = idxTestSort(bat_index1)

%{
idxFindAll = find(idxTestAll_batIndex == bat_num);
idxFindAll;
size(Y_test_RUL);
size(Y_test_SOH);
Y_test_RUL_ref = Y_test_RUL(idxFindAll);
Y_test_SOH_ref = Y_test_SOH(idxFindAll);
% Yfit_test_Y_test_RUL1 = Yfit_test_RUL(idxFindAll);
%}

compareTo = ryan5_battery_dataset(bat_num).cycle_life;

% find most similar data
% idxTrainValid = [idxTrain idxValid]

count = length(idxTrain) + length(idxValid);

idxSelIsBigger = false;

idxSel_upper = 0;
idxSel_lower = 0;
diff_upper = 1000;
diff_lower = -1000;
for i=1:count 
    diff = ryan5_battery_dataset(idxTrainValid(i)).cycle_life - compareTo ;
    %ref_is_bigger = ( ttt  > 0 );
    if diff > 0
        if diff < diff_upper
            idxSel_upper = idxTrainValid(i);
            diff_upper = diff;
        end
    else
        if diff > diff_lower
            %idxSel_3rd =  idxSel_lower;
            idxSel_lower = idxTrainValid(i);
            diff_lower = diff;
        end
    end
end

% just trick
%idxSel_lower = idxSel_3rd; 
if diff_upper == 1000
    kkk = 0;
end

if diff_lower == -1000
    kkk = 1;
end

matchedRUL_upper = ryan5_battery_dataset(idxSel_upper).cycle_life;
inTrain_upper = any(idxTrain==idxSel_upper);
inValid_upper = any(idxValid==idxSel_upper);
matchedRUL_lower = ryan5_battery_dataset(idxSel_lower).cycle_life;
inTrain_lower = any(idxTrain==idxSel_lower);
inValid_lower = any(idxValid==idxSel_lower);


if abs(diff_upper) < abs(diff_lower)
    bestIndex = 1;
else
    bestIndex = 2;
end
% 
% if inTrain_upper
%     idxFindSel = idxTest(find(idxTest == idxTestSort(idxSearch)));
%     idxFindAllSel = find(idxTestAll_batIndex == idxFindSel);
%     y_test_RUL_Sel1 = y_test_RUL(idxFindAllSel);
%     Y_test_RUL_Sel1 = Y_test_RUL(idxFindAllSel);
%     Y_test_SOH_Sel1 = Y_test_SOH(idxFindAllSel); 
% else
%     idxFindSel = idxTest(find(idxValid == idxValidSort(idxSearch)));
%     idxFindAllSel = find(idxValidAll_batIndex == idxFindSel);
%     y_test_RUL_Sel1 = y_test_RUL(idxFindAllSel);
%     Y_test_RUL_Sel1 = Y_test_RUL(idxFindAllSel);
%     Y_test_SOH_Sel1 = Y_test_SOH(idxFindAllSel); 
% end 
% 
% 
% ytrainSim = y_test_RUL_Sel1;

end