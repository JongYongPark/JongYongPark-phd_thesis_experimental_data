function cap = extract_impedance_by_voltage_current(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'impedance')
        cap(i) = bcycle(i).data.Re;
    end
end
cap(cap==0) = [];