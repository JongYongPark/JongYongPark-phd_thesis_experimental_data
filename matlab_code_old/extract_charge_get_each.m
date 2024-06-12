function [V,I,T] = extract_charge_get_each(B)

bcycle = B.cycle;

% get max column index
max_column_index=0;
index=0;
for i = 1:length(bcycle)-1
    if isequal(bcycle(i).type, 'charge')
        sz = size(bcycle(i).data.Voltage_measured,2);
        if sz > max_column_index
            max_column_index = sz ;
            index = i;
        end
    end 
end 

max_column_index
index

V = zeros(0,max_column_index);
I = zeros(0,max_column_index);
T = zeros(0,max_column_index);

for i = 1:length(bcycle)-1
    if isequal(bcycle(i).type, 'charge')
        i
        size(V)
        size(bcycle(i).data.Voltage_measured(:,1:end))
        %bcycle(i).data.Voltage_measured
        V(i,:) = bcycle(i).data.Voltage_measured(1:end);
        I(i,:) =  bcycle(i).data.Current_measured;
        T(i,:) =  bcycle(i).data.Temperature_measured;
    end
end
V(~any(V, 2), :) = [];% 빈 열 삭제 - discharge / measure 항목 삭제
I(~any(I, 2), :) = [];
T(~any(T, 2), :) = [];
end