function cap = extract_impedance_rct(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'impedance')
        if isequal(bcycle(i-1).type, 'charge')
            cap(i) = bcycle(i).data.Rct;
        end
    end
end
cap(cap==0) = [];