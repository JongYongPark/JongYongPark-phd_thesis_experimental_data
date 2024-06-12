function discharInput = extract_discharge_preprocessing(B)
bcycle = B.cycle;
for i = 1:length(bcycle)-1
    if isequal(bcycle(i).type, 'discharge')
        % 789 % 10 = 9
        le = mod(length(bcycle(i).data.Voltage_measured), 10);
        vTemp = bcycle(i).data.Voltage_measured(:, 1:end-le); % end - le = 789 - 9 = 780 %끝을 자른다.
        vTemp = reshape(vTemp, length(vTemp)/10, []); % 열개의 row로 만든다. fill the first column and then fill the next column
        vTemp = mean(vTemp); % column 각 항목의 평균값을 구한다. 시리즈의 첫번째 블럭의 평
        
        iTemp = bcycle(i).data.Current_measured(:, 1:end-le);
        iTemp = reshape(iTemp, length(iTemp)/10, []);
        iTemp = mean(iTemp);
        
        tTemp = bcycle(i).data.Temperature_measured(:, 1:end-le);
        tTemp = reshape(tTemp, length(tTemp)/10, []);
        tTemp = mean(tTemp);
        
        % 방전사이클의 시간도 중요할 수 있을 것 같다.
        % 각 사이클에서 시간은 0 부터 시작
        tTime = bcycle(i).data.Temperature_measured(:, 1:end-le);
        tTime = reshape(tTime, length(tTime)/10, []);
        
        % 시간 평균의 의미가 없는 것 같다.시간평균은 시작부터의 거리.
        %tTime = mean(tTime);
        
        % 시간차는 각 측정간격
        tTime = max(tTime)-min(tTime);
        
        discharInput(i, :) = [vTemp, iTemp, tTemp, tTime];
    end
end
discharInput(~any(discharInput, 2), :) = [];% 빈 열 삭제 - discharge / measure 항목 삭제