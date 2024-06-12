function cap = extract_temperature(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    % https://kr.mathworks.com/matlabcentral/answers/27899-if-statement-using-or-operator
    if isequal(bcycle(i).type, 'charge') % | isequal(bcycle(i).type, 'discharge')
          cap(i) = bcycle(i).data.Temperature_measured;
    end
    
    if isequal(bcycle(i).type, 'discharge')
        cap(i) = bcycle(i).data.Temperature_measured;
    end
        
end
cap(cap==0) = [];