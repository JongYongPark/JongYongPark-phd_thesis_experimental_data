
clear ;
close all;

batchNum = 1;
load C:\nobackup\_phd_work\_battery_soh\_dataset\data.matr.io\2017-05-12_batchdata_updated_struct_errorcorrect.mat
trainData = batch;
clear batch
clear batch_date

load C:\nobackup\_phd_work\_battery_soh\_dataset\data.matr.io\2017-06-30_batchdata_updated_struct_errorcorrect.mat
trainData2 = batch;
clear batch
clear batch_date

load C:\nobackup\_phd_work\_battery_soh\_dataset\data.matr.io\2018-04-12_batchdata_updated_struct_errorcorrect.mat
trainData3 = batch;
clear batch
clear batch_date

% ryan5_battery_dataset_raw_org_sample1 = trainData(1);
% ryan5_battery_dataset_raw_org_sample2 = trainData(2);
% ryan5_battery_dataset_raw_org_sample3 = trainData(3);
% 
% save('ryan5_battery_dataset_raw_org_sample1.mat','ryan5_battery_dataset_raw_org_sample1' )
% save('ryan5_battery_dataset_raw_org_sample2.mat','ryan5_battery_dataset_raw_org_sample2' )
% save('ryan5_battery_dataset_raw_org_sample3.mat','ryan5_battery_dataset_raw_org_sample3' )

%% 

% 
%global ryan5_battery_dataset_raw 
ryan5_battery_dataset_raw = zeros();
% 이 코드가 중요함. ryan5_battery_dataset_raw 이 structure를 가짐을 알려주어야 함.
ryan5_battery_dataset_raw = ryan5_util_extract_feature(1,1,trainData(1));

%% 

% % 1.1 * 0.8 = 0.88 Ah = EOL
% % batch 2 = get data under 0.88 Ah - to remove this data under EOL
% test2 = ryan5_util_extract_feature(2,1,trainData2(1));
% test1 = ryan5_util_extract_feature(1,1,trainData(1));
% test3 = ryan5_util_extract_feature(3,1,trainData3(1));

new_index = 1;
skip_bat1 = [8 10 12 13 22 ]; % base 0 index
skip_bat1 = skip_bat1 +1; % to 1 index

% # There are four cells from batch1 that carried into batch2, we'll remove the data from batch2
% # and put it with the correct cell from batch1
% batch2_keys = ['b2c7', 'b2c8', 'b2c9', 'b2c15', 'b2c16']
% batch1_keys = ['b1c0', 'b1c1', 'b1c2', 'b1c3', 'b1c4']
% add_len = [662, 981, 1060, 208, 482];

skip_bat2 = [7 8 9 15 16 ]; % base 0 index
skip_bat2 = skip_bat2 +1; % to 1 index

batch2_keys = ["b2c8", "b2c9", "b2c10", "b2c16", "b2c17"];
batch2_fix = [8 9 10 16 17];
batch1_keys = ["b1c1","b1c2","b1c3","b1c4","b1c5"];
batch1_fix = [1 2 3 4 5];

batchNum =1;
for batNum = 1:size(trainData,2)
    if numel(trainData(batNum).summary.cycle) == numel(unique(trainData(batNum).summary.cycle))
        if ismember(batNum,skip_bat1) 
            batNum;
        elseif ismember(batNum,batch1_fix) 
            %ismember(batNum,batch1_fix) % true or fale
            idx = find(batch1_fix==batNum);
            % find(strcmp
%             batch1_fix(idx)
%             batch2_fix(idx)
            src = trainData(batch1_fix(idx));
            dest = trainData2(batch2_fix(idx));
            merge = merge_struct(trainData(batch1_fix(idx)),trainData2(batch2_fix(idx)));
            ryan5_battery_dataset_raw(new_index) = ryan5_util_extract_feature(batchNum,batNum,merge);
            batNum;      
        else
            ryan5_battery_dataset_raw(new_index) = ryan5_util_extract_feature(batchNum,batNum,trainData(batNum));
            new_index = new_index + 1;
            batNum;            
        end
    else
        batchNum
        batNum
    end
end
%%%%%%%%%%%%%
batchNum = 2;
for batNum = 1:size(trainData2,2)
    if numel(trainData2(batNum).summary.cycle) == numel(unique(trainData2(batNum).summary.cycle))
        if ismember(batNum,batch2_fix) 
            batNum;
        else
            ryan5_battery_dataset_raw(new_index) = ryan5_util_extract_feature(batchNum,batNum,trainData2(batNum));
            new_index = new_index + 1;
            batNum;            
        end
    else
        batchNum
        batNum
    end
end


%%%%%%%%%%%%%%%
batchNum = 3;
skip_bat3 = [37 2 23 32 42 43 ]; % base 0 index
skip_bat3 = skip_bat3 +1; % to 1 index

% # remove noisy channels from batch3
% del batch3['b3c37']
% del batch3['b3c2']
% del batch3['b3c23']
% del batch3['b3c32']
% del batch3['b3c42']
% del batch3['b3c43']

for batNum = 1:size(trainData3,2)
    if numel(trainData3(batNum).summary.cycle) == numel(unique(trainData3(batNum).summary.cycle))
        if ismember(batNum,skip_bat3) 
            batNum;
        else
            ryan5_battery_dataset_raw(new_index) = ryan5_util_extract_feature(batchNum,batNum,trainData3(batNum));
            new_index = new_index + 1;
            batNum;            
        end
    else
        batchNum
        batNum
    end
end

%% 첫번째 정제된 데이타

ryan5_battery_dataset_raw_desc = 'basic data extracting feature from trainData set '; 
save('ryan5_battery_dataset_raw.mat','ryan5_battery_dataset_raw_desc')
save('ryan5_battery_dataset_raw.mat','ryan5_battery_dataset_raw')

% ryan5_battery_dataset_raw_sample1 = ryan5_battery_dataset_raw(1);
% ryan5_battery_dataset_raw_sample2 = ryan5_battery_dataset_raw(2);
% ryan5_battery_dataset_raw_sample3 = ryan5_battery_dataset_raw(3);
% 
% save('ryan5_battery_dataset_raw_sample1.mat','ryan5_battery_dataset_raw_sample1' )
% save('ryan5_battery_dataset_raw_sample2.mat','ryan5_battery_dataset_raw_sample2' )
% save('ryan5_battery_dataset_raw_sample3.mat','ryan5_battery_dataset_raw_sample3' )

%%
clear trainData  trainData2  trainData3 merge src dest 
% clear ryan5_battery_dataset_raw_org_sample1  ryan5_battery_dataset_raw_org_sample2  ryan5_battery_dataset_raw_org_sample3
% clear ryan5_battery_dataset_raw_sample1  ryan5_battery_dataset_raw_sample2  ryan5_battery_dataset_raw_sample3
%% 시작  Ah을 고정하자. 이보다 큰 데이타는 모두 지우자.
%% 전체 데이타에 대해 특정 Ah보다 큰 것은 모두 지우자 

%%%%%%%%%%%%%%%%%%
% get first capacity

%ryan5_battery_dataset_raw = ryan5_util_remove_data_over_specific_soh(1,1,trainData(1));

[ryan5_battery_dataset,data_conversion_param] = ryan5_util_remove_data_over_specific_soh(1.048);


%%

data_conversion_param 
max(data_conversion_param(:,2))
min(data_conversion_param(:,2))
