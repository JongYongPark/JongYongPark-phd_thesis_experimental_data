function cap = extract_impedance_re(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'impedance')
        if isequal(bcycle(i-1).type, 'discharge')
            cap(i) = bcycle(i).data.Re;
        end
    end
end
cap(cap==0) = [];