function linearModel = myInitialModelLearn() %#codegen
% MYINITIALMODELINCRLEARN Load and return configured linear model for
% binary classification InitialMdl
    linearModel = loadLearnerForCoder('InitialLinearMdl');
end