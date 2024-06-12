function cap = extract_discharge_first_voltage(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'discharge')
        cap(i) = bcycle(i).data.Voltage_measured(1);
    end
end
cap(cap==0) = [];