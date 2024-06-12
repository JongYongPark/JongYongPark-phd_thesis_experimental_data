function [idxSel,matchedRUL,idxCrossSel,idxSel_2nd,matchedRUL_2nd,idxCrossSel_2nd] = ...
    ryan4_util_find_similar_bat_with_rul_after_change( rul_data,idx_after_change,cap_after_change ) 

% https://kr.mathworks.com/matlabcentral/answers/420960-how-to-use-global-variables-inside-a-function
global ryan4_battery_dataset  ;
global RUL SOH Y_trainValid_RUL Y_test_RUL Y_trainValid_SOH Y_test_SOH ;
global idxTrain idxValid idxTest idxTrainValid idxTrainSort idxValidSort idxTranValidSort idxTestSort ;
global idxAll idxTestAll_batIndex ;

idxAll;
idxTestSort;
% bat_num = idxTestSort(bat_index1)
% 
% idxFindAll = find(idxTestAll_batIndex == bat_num);
% idxFindAll;
% size(Y_test_RUL);
% size(Y_test_SOH);
% Y_test_RUL_ref = Y_test_RUL(idxFindAll);
% Y_test_SOH_ref = Y_test_SOH(idxFindAll);
% % Yfit_test_Y_test_RUL1 = Yfit_test_RUL(idxFindAll);

compareTo = rul_data(idx_after_change); %Y_test_RUL_ref(idx_after_change);

% find most similar data
% idxTrainValid = [idxTrain idxValid]

count = length(idxTrain) + length(idxValid);
idxSel = 0;
idxSel_2nd = 0;
idxCrossSel = 0;
diff_upper = 1000;
diff_lower = -1000;
for i=1:count 
    [val,idxCross] = min(abs(ryan4_battery_dataset(idxTrainValid(i)).QDischarge -  cap_after_change ));
    rul_remained =  ryan4_battery_dataset(idxTrainValid(i)).cycle_life - idxCross ;
    diff_new =  rul_remained - compareTo ;
    if(diff_new > 0 )
        if diff_new < diff_upper 
            idxSel = idxTrainValid(i);
            diff_upper = diff_new;
            idxCrossSel = idxCross;
        end
    else
        if diff_new > diff_lower 
            idxSel_2nd = idxTrainValid(i);
            diff_lower = diff_new;
            idxCrossSel_2nd = idxCross;
        end
    end
end

matchedRUL = ryan4_battery_dataset(idxSel).cycle_life - idxCrossSel;
inTrain = any(idxTrain==idxSel);
inValid = any(idxValid==idxSel);
matchedRUL_2nd = ryan4_battery_dataset(idxSel_2nd).cycle_life - idxCrossSel_2nd;
inTrain_2nd = any(idxTrain==idxSel_2nd);
inValid_2nd = any(idxValid==idxSel_2nd);

% 
% if inTrain
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