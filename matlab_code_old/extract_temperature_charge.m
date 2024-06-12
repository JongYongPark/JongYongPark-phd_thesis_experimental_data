function cap = extract_temperature_charge(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'charge')
          cap(i) = bcycle(i).data.Temperature_measured;
    end
end
cap(cap==0) = [];