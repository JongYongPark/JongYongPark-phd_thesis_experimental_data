%%

mdl_Linear_VdRul_fitrlinear_inc = incrementalLearner(mdl_Linear_VdRul_fitrlinear, ...
    'Solver','sgd','Lambda',0.001,'BatchSize',5,'LearnRate',0.1, ...
    'Standardize',false, ...
    'MetricsWarmupPeriod',50,'MetricsWindowSize',25, ...
    'Metrics',{ 'mse' maemetric}...
    );
mdl_Linear_VdRul_fitrlinear
mdl_Linear_VdRul_fitrlinear_inc
n = numel(ytrain);
% Preallocation
numObsPerChunk = 5; %50;
nchunk = floor(n/numObsPerChunk);
ei = array2table(zeros(nchunk,2),'VariableNames',["Cumulative" "Window"]);
mse_val = array2table(zeros(nchunk,2),'VariableNames',["Cumulative" "Window"]);
mae = array2table(zeros(nchunk,2),'VariableNames',["Cumulative" "Window"]);
beta10 = zeros(nchunk,1);    
y_predict = []; %zeros();
% Incremental fitting
rng("default"); % For reproducibility
mdl_Linear_VdRul_fitrlinear_inc.Beta'
for j = 1:nchunk
    ibegin = min(n,numObsPerChunk*(j-1) + 1);
    iend   = min(n,numObsPerChunk*j);
    idx = ibegin:iend   
    % 문제는 원하는 값을 우리가 알고 있다고 가정하고 다시 Fit을 한다.
    mdl_Linear_VdRul_fitrlinear_inc = updateMetricsAndFit(...
        mdl_Linear_VdRul_fitrlinear_inc,...
        Xtrain(idx,:),...
        ytrain(idx));
    y_predict_temp = predict(mdl_Linear_VdRul_fitrlinear_inc,Xtrain(idx,:));
    mdl_Linear_VdRul_fitrlinear_inc.Beta'
    y_predict = [ y_predict ; y_predict_temp ];
    [ytrain(idx) y_predict_temp ytrain(idx)-y_predict_temp]
    %ei{j,:} = mdl_Linear_VdRul_fitrlinear_inc.Metrics{"EpsilonInsensitiveLoss",:};
    mse_val{j,:} = mdl_Linear_VdRul_fitrlinear_inc.Metrics{"MeanSquaredError",:};
    mae{j,:} = mdl_Linear_VdRul_fitrlinear_inc.Metrics{"MeanAbsoluteError",:};
    beta10(j + 1) = mdl_Linear_VdRul_fitrlinear_inc.Beta(10);
end

