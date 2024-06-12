function ryan4_util_plot_scenario( rul_observed, rul_predicted, rul_ape, soh_observed,  title_str, show_regend)

%         xlabel_str, ...
%         ylabel_str, ...
%         xlabel1_str, ...
%         ylabel1_str)

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
title 'Scenario 1'

if show_regend
legend_str = cell(2,1);
legend_str{1} = 'RUL';
legend_str{2} = 'Error Percentage (%)';
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
legend_str{3} = 'Error Percentage (%)';
legend(legend_str)
end 

end