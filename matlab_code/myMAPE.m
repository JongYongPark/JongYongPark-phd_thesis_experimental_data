function result = myRMSE(z,zfit) %#codegen
% MYINITIALMODELINCRLEARN Load and return configured linear model for
% binary classification InitialMdl
    result = mean(abs(z - zfit)./z)*100;
end


% rmsefcn = @(z,zfit)sqrt(mean((z - zfit).^2));
% msefcn = @(z,zfit)mean((z - zfit).^2);
% maefcn = @(z,zfit)abs(z - zfit);
% mapefcn = @(z,zfit)mean(abs(z - zfit)/z)*100;