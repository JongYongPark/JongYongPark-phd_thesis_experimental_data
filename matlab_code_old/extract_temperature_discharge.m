function cap = extract_temperature_discharge(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'discharge')
          cap(i) = bcycle(i).data.Temperature_measured;
    end
end
cap(cap==0) = [];