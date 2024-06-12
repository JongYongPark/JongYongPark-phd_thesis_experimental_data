function [result_scenario_summary,rmse_val_2digit,mape_val_2digit] = ryan5_util_plot_scenario_rmse_mape( rul_observed, rul_predicted, rul_ape, soh_observed,  title_str, show_regend, rmse_val, mape_val)

%         xlabel_str, ...
%         ylabel_str, ...
%         xlabel1_str, ...
%         ylabel1_str)

rmse_val_2digit = sprintf('%.2f', rmse_val);
mape_val_2digit = sprintf('%.2f', mape_val);

figure
hold on
plot(rul_observed,rul_predicted,'x')
xlabel("Observed RUL")
ylabel("Predicted RUL")
%xlim([0 1200]), ylim([0 1200])

yyaxis right
ylabel('Error Percentage (%) ')
plot(rul_observed,rul_ape,'o');
ylim([0 100])

hold off
performance_str = "( RMSE = " + rmse_val_2digit + "  MAPE = " + mape_val_2digit + " )" ; 
title_with_performance = [ title_str , performance_str ]
title(title_with_performance)

if show_regend
legend_str = cell(2,1);
legend_str{1} = 'RUL';
legend_str{2} = 'Percentage Error (%)';
legend(legend_str)
end 

figure, hold on
plot(rul_observed)
plot(rul_predicted,'--')
ylabel('RUL')

yyaxis right
ylabel('SOH (Ah)'), xlabel('Cycle')
plot(soh_observed, ':')
hold off

if show_regend
legend_str = cell(3,1);
legend_str{1} = 'Predicted RUL';
legend_str{2} = 'Observed RUL';
legend_str{3} = 'Percentage Error (%)';
legend(legend_str)
end 


result_scenario_summary = table(rmse_val,mape_val);
result_scenario_summary.Properties.VariableNames = {'RMSE','MAPE'};

end