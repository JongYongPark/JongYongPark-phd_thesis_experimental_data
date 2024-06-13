function [varargout] = initialize(command,varargin) %#codegen
% Autogenerated by MATLAB, 05-Jun-2022 21:01:47
coder.inline('always')
persistent model
if isempty(model)
    model = loadLearnerForCoder('RegressionSVMModel.mat');
end
switch(command)
    case 'update'
        % Update struct fields: Alpha
        %                       SupportVectors
        %                       Scale
        %                       Bias
        model = update(model,varargin{:});
    case 'predict'
        % Predict Inputs: X
        X = varargin{1};
        if nargin == 2
            [varargout{1:nargout}] = predict(model,X);
        else
            PVPairs = cell(1,nargin-2);
            for i = 1:nargin-2
                PVPairs{1,i} = varargin{i+1};
            end
            [varargout{1:nargout}] = predict(model,X,PVPairs{:});
        end
end
end
