function cap = extract_discharge_voltage_by_index(B,index)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'discharge')
        cap(i) = bcycle(i).data.Voltage_measured(index);
    end
end
cap(cap==0) = [];