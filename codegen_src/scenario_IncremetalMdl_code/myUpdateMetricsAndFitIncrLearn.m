function incrementalModel = myUpdateMetricsAndFitIncrLearn(incrementalModel,X,Y) %#codegen
% MYUPDATEMETRICSINCRLEARN Measure model performance metrics on new data
      incrementalModel = updateMetricsAndFit(incrementalModel,X,Y); 
end