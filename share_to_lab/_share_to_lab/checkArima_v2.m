function [minP,minQ,minBIC,BIC]=checkArima(Y,d,pp,qq)

% https://kr.mathworks.com/help/econ/choose-arma-lags.html
% https://kr.mathworks.com/matlabcentral/answers/305577-how-to-automate-arima-model-order-selection-based-on-acf-and-pacf-plots?s_tid=srchtitle
% https://stackoverflow.com/questions/47962686/identify-parameters-of-arima-model

% pp is the maximum for p
% qq is the maximum for q
LogL = zeros(pp,qq); % Initialize
PQ = zeros(pp,qq);
for p = 1:pp
    for q = 1:qq
        Mdl = arima(p,d,q);
        [EstMdl,~,LogL(p,q)] = estimate(Mdl,Y,'Display','off');
        PQ(p,q) = p + q;
     end
end

logL = LogL(:);
pq = PQ(:);
[~,bic] = aicbic(logL,pq+1,100);
BIC = reshape(bic,pp,qq);

minBIC = min(BIC,[],'all');

[minP,minQ] = find(minBIC == BIC);

end
