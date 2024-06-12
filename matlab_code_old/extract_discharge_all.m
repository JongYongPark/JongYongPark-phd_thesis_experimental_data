function [size,cap,startTime,ambTemp,Vm,Im,Tm,Vl,Il,Time ] = extract_discharge_all(B)
bcycle = B.cycle;
for i = 1:length(bcycle)
    if isequal(bcycle(i).type, 'discharge')
        cap(i) = bcycle(i).data.Capacity;
        startTime(i)= bcycle(i).time;
        ambTemp(i)= bcycle(i).ambient_temperature;
        Im(i) = bcycle(i).data.Current_measured;
        Vm(i) = bcycle(i).data.Voltage_measured;
        Tm(i) = bcycle(i).data.Temperature_measured;
        Il(i) = cycle(i).data.Current_Load;
        Vl(i) = cycle(i).data.Voltage_Load;
        Time(i) = cycle(i).data.Time;  
    end
end
cap(cap==0) = [];
startTime(startTime==0) = [];
ambTemp(ambTemp==0) = [];
Im(Im==0) = [];
Vm(Vm==0) = [];
Tm(Tm==0) = [];
Il(Il==0) = [];
Vl(Vl==0) = [];
Time(Time==0) = [];
totalCycleNumber=sizeof(cap);
toatalMeasurePointNmuberPerCycle=sizeo(Time);
end 
