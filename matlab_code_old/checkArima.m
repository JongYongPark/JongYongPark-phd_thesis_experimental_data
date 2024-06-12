function [minP,minQ,ar]=checkArima(y,d,pp,qq)

% https://kr.mathworks.com/help/econ/choose-arma-lags.html
% https://kr.mathworks.com/matlabcentral/answers/305577-how-to-automate-arima-model-order-selection-based-on-acf-and-pacf-plots?s_tid=srchtitle
% https://stackoverflow.com/questions/47962686/identify-parameters-of-arima-model

% pp is the maximum for p
% qq is the maximum for q
LOGL = zeros(pp+1,qq+1); %Initialize
PQ = zeros(pp+1,qq+1);
for p = 1:pp+1
    for q = 1:qq+1
        mod = arima(p-1,d,q-1);
        [fit,~,logL] = estimate(mod,y,'Display','off');
        LOGL(p,q) = logL;
        PQ(p,q) = p+q;
     end
end
LOGL = reshape(LOGL,(pp+1)*(qq+1),1);
PQ = reshape(PQ,(pp+1)*(qq+1),1);
[~,bic] = aicbic(LOGL,PQ+1,100);
ar=reshape(bic,pp+1,qq+1);
% the rows correspond to the AR degree (p) and the
% columns correspond to the MA degree (q). The smallest value is best

minBIC = min(ar,[],'all')
[minP,minQ] = find(minBIC == ar);

end
