function [rmse,mape,ape,ae,err] = eval_perfomance(y_real, y_hat)
    err = y_real - y_hat;
    ae = abs(err);
    ape = abs(err)./y_real.*100;
    mape = mean(ape,1);
    rmse = sqrt( mean((err).^2 ));
end    