function [model, y_predict, cnt]= ryan5_run_inc_learning(model,n,updatePolicy,xnorm,ynorm,ynorm_reference)

global scenario3_mdl;

    if strcmp(updatePolicy,'use_yref_and_legacy_learning')
        ynorm_legacy_larning = predict(scenario3_mdl,xnorm);
    else
        ynorm_legacy_larning = [ 1;2;3;4;5];
    end
    
    pred_len = length(ynorm);
    ref_len = length(ynorm_reference);
   
    if pred_len == ref_len
        len_new = pred_len;
        len_modified = false;
    elseif pred_len > ref_len 
        len_new = ref_len;
        len_modified = true; 
    else 
        len_new = pred_len;
        len_modified = true; 
    end

    len_new_mod = mod(len_new,5 ); 

    if len_new_mod ~= 0
        len_new = len_new - len_new_mod;
    end

    n = len_new;

    numObsPerChunk = 5; %50;
    nchunk = floor(n/numObsPerChunk);
    ei = array2table(zeros(nchunk,2),'VariableNames',["Cumulative" "Window"]);
    mse_val = array2table(zeros(nchunk,2),'VariableNames',["Cumulative" "Window"]);
    % mae = array2table(zeros(nchunk,2),'VariableNames',["Cumulative" "Window"]);
    beta10 = zeros(nchunk,1);    
    y_predict = []; %zeros();
    % Incremental fitting
    rng("default"); % For reproducibility
%     model.Beta' ;  
    
    y_predict_temp = predict(model, xnorm(1:numObsPerChunk,:));
   
    
    for j = 1:nchunk
        ibegin = min(n,numObsPerChunk*(j-1) + 1);
        iend   = min(n,numObsPerChunk*j);
        idx = ibegin:iend ;  
        if strcmp(updatePolicy,'use_y')
            model = updateMetricsAndFit(...
                model,...
                xnorm(idx,:),...
                ynorm(idx));
        elseif strcmp(updatePolicy,'use_yref')
            model = updateMetricsAndFit(...
                model,...
                xnorm(idx,:),...
                ynorm_reference(idx));
        elseif strcmp(updatePolicy,'use_yref_and_legacy_learning')
            model = updateMetricsAndFit(...
                model,...
                xnorm(idx,:),...
                (ynorm_reference(idx) + ynorm_legacy_larning(idx))/2);
        elseif strcmp(updatePolicy,'use_own_predict')   
            model = updateMetricsAndFit(...
                model,...
                xnorm(idx,:),...
                y_predict_temp(1:numObsPerChunk));
        elseif strcmp(updatePolicy,'use_yref_and_own_predict')   
            model = updateMetricsAndFit(...
                model,...
                xnorm(idx,:),...
                (ynorm_reference(idx) + y_predict_temp(1:numObsPerChunk))/2);
        else
            error_msg = ' not supported policy'
        end

        y_predict_temp = predict(model,xnorm(idx,:));
        %model.Beta' ;
        y_predict = [ y_predict ; y_predict_temp ];
        [ynorm(idx) y_predict_temp ynorm(idx)-y_predict_temp] ;
        %ei{j,:} = model.Metrics{"EpsilonInsensitiveLoss",:};
        mse_val{j,:} = model.Metrics{"MeanSquaredError",:};
        %mae{j,:} = model.Metrics{"MeanAbsoluteError",:};
        beta10(j + 1) = model.Beta(10);
    end

%     tiledlayout(2,1)
%     nexttile
%     plot(beta10)
%     ylabel('\beta_{10}')
%     xlim([0 nchunk])
%     xline(model.MetricsWarmupPeriod/numObsPerChunk,'g-.')
%     xlabel('Iteration')
%     
%     nexttile
%     h = plot(mse_val.Variables);
%     xlim([0 nchunk])
%     ylabel('MSE')
%     xline(model.MetricsWarmupPeriod/numObsPerChunk,'g-.')
%     legend(h,mse_val.Properties.VariableNames)
%     xlabel('Iteration')

    cnt = length(y_predict);
end 