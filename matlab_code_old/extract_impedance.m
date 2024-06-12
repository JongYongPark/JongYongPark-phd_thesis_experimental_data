function cap = extract_impedance(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'impedance')
        cap(i) = bcycle(i).data.Re + bcycle(i).data.Rct;
    end
end
cap(cap==0) = [];