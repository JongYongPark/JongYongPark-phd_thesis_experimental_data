function [labels] = myPredictIncrLearn(incrementalModel,X) %#codegen
% MYPREDICTINCRLEARN Predict labels and classification scores on new data
      [labels] = predict(incrementalModel,X); 
end