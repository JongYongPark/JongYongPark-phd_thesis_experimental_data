function [result_mdl_Linear_InputRul,result_mdl_Linear_InputRul_summary] = ...
    ryan4_util_linear( ...
        yfit_trainValid_InputRul, yfit_test_InputRul, ...
        yrate_RUL,ymin_RUL,...
        Y_trainValid_RUL,Y_test_RUL)


    %yfit_trainValid_InputRul'
    %yfit_test_InputRul'
    
    %y_trainValid_RUL'
    %y_test_RUL'
    Yfit_trainValid_InputRul = yfit_trainValid_InputRul * yrate_RUL + ymin_RUL;
    Yfit_test_InputRul = yfit_test_InputRul * yrate_RUL + ymin_RUL;
    
    MAE_InputRul = mean(abs(Yfit_trainValid_InputRul-Y_trainValid_RUL))
    adjMAE_InputRul = MAE_InputRul/range(Y_trainValid_RUL)
    range(Y_trainValid_RUL) % Y_trainValid_RUL = range(X)는 X에 포함된 표본 데이터의 최댓값과 최솟값 간의 차이를 반환합니다.
    
    %(Y_trainValid_RUL - Yfit_trainValid_InputRul)'    % Errors
    %(Y_trainValid_RUL - Yfit_trainValid_InputRul).^2;   % Squared Error
    histogram((Y_trainValid_RUL - Yfit_trainValid_InputRul).^2)
    %mean((Y_trainValid_RUL - Yfit_trainValid_InputRul).^2);   % Mean Squared Error
    RMSE_trainValid_InputRul = sqrt(mean((Y_trainValid_RUL - Yfit_trainValid_InputRul).^2))  % Root Mean Squared Error
    
    RMSE_test_InputRul = sqrt(mean((Y_test_RUL - Yfit_test_InputRul).^2))
    Y_test_RUL - Yfit_test_InputRul
    Y_test_diff_InputRul = horzcat(Y_test_RUL,(Y_test_RUL-Yfit_test_InputRul))
    Y_test_diff_percentage_InputRul = abs(Y_test_RUL-Yfit_test_InputRul)./Y_test_RUL.*100
    Y_test_diff_percentage_avg_InputRul = sum(Y_test_diff_percentage_InputRul)/length(Y_test_diff_percentage_InputRul)
    Y_trainValid_diff_InputRul = horzcat(Y_trainValid_RUL,(Y_trainValid_RUL-Yfit_trainValid_InputRul))
    Y_trainValid_diff_percentage_InputRul = abs(Y_trainValid_RUL-Yfit_trainValid_InputRul)./Y_trainValid_RUL.*100
    Y_trainValid_diff_percentage_avg_InputRul = sum(Y_trainValid_diff_percentage_InputRul)/length(Y_trainValid_diff_percentage_InputRul)
    num = 1:length(Y_test_RUL);
    
    
    result = horzcat(num',Y_test_RUL,(Y_test_RUL-Yfit_test_InputRul),Y_test_diff_percentage_InputRul);
    result % 배터리 번호 / RUL 관찰값 / 오차 / 오차 퍼센티지 
    result_mdl_Linear_InputRul = table(num',Y_test_RUL,(Y_test_RUL-Yfit_test_InputRul),Y_test_diff_percentage_InputRul);
    result_mdl_Linear_InputRul.Properties.VariableNames = {'bat num','RUL','AE','APE'};
    result_mdl_Linear_InputRul
    result_mdl_Linear_InputRul_summary = table(RMSE_test_InputRul,Y_test_diff_percentage_avg_InputRul);
    result_mdl_Linear_InputRul_summary.Properties.VariableNames = {'RMSE','MAPE'};
    result_mdl_Linear_InputRul_summary 
    
    figure
    hold on
    plot(Y_trainValid_RUL,Yfit_trainValid_InputRul,'x')
    xlabel("Observed")
    ylabel("Predicted")
    xlim([0 1200]), ylim([0 1200])
    
    yyaxis right
    ylabel('Error Percentage')
    plot(Y_trainValid_RUL,Y_trainValid_diff_percentage_InputRul,'o');
    
    hold off
    title 'Denormalized - Train/Valid'
    RMSE_test_InputRul
    Y_trainValid_diff_percentage_avg_InputRul
    
    figure
    hold on
    plot(Y_test_RUL,Yfit_test_InputRul,'x')
    xlabel("Observed")
    ylabel("Predicted")
    xlim([0 1200]), ylim([0 1200])
    
    yyaxis right
    ylabel('Error Percentage')
    plot(Y_test_RUL,Y_test_diff_percentage_InputRul,'o');
    
    hold off
    title 'Denormalized - Test'

end