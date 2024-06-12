
function cap_adj = match_initial_capacity(cap,initC)

        len = length(cap);
        for k = len:-1:1
            if cap(k) > initC
                cap(k) = [];
            end
        end
        
        cap_adj = cap;
end

function capRowV_adj = match_initial_capacity_v1(capRowV)
% 동작안함
    try
        capColumnV = capRowV'
        firstC = capColumnV(1,:);
        len = length(capColumnV);
        for k = len:1
            val = capColumnV(k,:);
            cmp = val > firstC;
            capColumnV(k,cmp ) = [];
        end
        capRowV_adj = capColumnV';
    catch
        print("error");
    end
end
