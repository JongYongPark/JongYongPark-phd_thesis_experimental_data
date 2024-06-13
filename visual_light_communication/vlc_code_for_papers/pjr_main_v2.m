%{
Reference 

C:\nobackup\_박종용_박사논문_준비\___vlc_ebook\Digital Communications and Signal Processing – with Matlab Examples.pdf
C:\Nobackup\Downloads\ber_awgn.pdf
C:\nobackup\_박종용_박사논문_준비\___vlc_ebook\Digital Transmission - A Simulation-Aided Introduction with VisSimComm.pdf


BER
C:\Nobackup\Downloads\umi-umd-3213.pdf

%}


clear all; close all; clc;

%NRZ_Encoder_test()
%Manchester2Bin_test()
%Led_los_power_test()
%Led_los_test()

%InverseSquareLawSimulation()
%vlc_test_packet_short();
vlc_test_packet()  % works well  % 패킷 하나만 보내는 것

%vlc_snr_test()

% N_led,led_loc_offset,h,led_power,theta,show_figure
% LED 갯수 : 1  
% LED x,y offset from (0,0)  : 0.5 => x,y 각 1 m 간격으로 LED 설치  1.5 => 3 m 간격
% LED 높이 : 2.5m / 3m
% LED 파워 : 1
% LED theta : 7 
% show figure : true
%[P_block_total,h1,h2,h3,h4] = vlc_rx_power_pola_panel_test(4, 1.5,2.5,1,15,true);

%% 
function signal = vlc_frame_composer(symbols)
	signal = symbols;
end
%% 
function symbols = vlc_frame_decomposer(signal, frame_size)
    symbols = signal(1:frame_size);
end
%% 

function DrawBinaryStream_stem(stream, strTitle,limit_y_min, limit_y_max)
    figure
    stem(stream);axis([1 length(stream) limit_y_min limit_y_max]);title(strTitle); 
    %grid on
end 

function DrawBinaryStream(stream, strTitle,limit_y_min, limit_y_max)
    figure
    stem(stream);axis([1 length(stream) limit_y_min limit_y_max]);title(strTitle); 
    %grid on
end 

function DrawSignalByCount(bitStream,Rb,Fs,count)
    figure;
    t_bit = 1:length(bitStream)*Fs;
    new_X = 1:1/Fs:length(bitStream)/Rb*Fs;
    %hold on;
    t_bitStream =  vlc_sample_stream(bitStream,Fs)
    plot(t_bit,t_bitStream);
    %xlabel('bits-->');
    ylabel('Amplitude (volts)','FontSize',8);
    title('NRZ-L encoded bit stream');
    xlim([0,count]);

%     subplot(3,1,2);
%     plot(new_X,symbolStream);
%     %xlabel('bits-->');
%     ylabel('Amplitude (volts)','FontSize',8);
%     title('Manchester-L encoded bit stream');
%     xlim([0,10]);
% 
%     subplot(3,1,3);
%     plot(new_X,Manchester_out);
%     %xlabel('bits-->');
%     ylabel('Amplitude (volts)','FontSize',8);
%     title('Manchester-L encoded bit stream');
%     xlim([0,10]);
%     %hold off;
% 
%     suptitle('Lide Code >> encoded bit stream')
end

function DrawSignal(bitStream,symbolStream,Rb,Rs,displayTime,Fs)
    figure;
    t_bit = 1:bitStream;
    new_X = 1:1/Fs:length(bitStream)/Rb*Fs;
    %hold on;
    subplot(3,1,1);
    plot(t_bit,bitStream);
    %xlabel('bits-->');
    ylabel('Amplitude (volts)','FontSize',8);
    title('NRZ-L encoded bit stream');
    xlim([0,displayTime]);

    subplot(3,1,2);
    plot(new_X,symbolStream);
    %xlabel('bits-->');
    ylabel('Amplitude (volts)','FontSize',8);
    title('Manchester-L encoded bit stream');
    xlim([0,10]);
% 
%     subplot(3,1,3);
%     plot(new_X,Manchester_out);
%     %xlabel('bits-->');
%     ylabel('Amplitude (volts)','FontSize',8);
%     title('Manchester-L encoded bit stream');
%     xlim([0,10]);
%     %hold off;
% 
%     suptitle('Lide Code >> encoded bit stream')
end
%% 
function vlc_draw_tx_rx_signal(fig_title,t_signal_sec,tx_bin,tx_bin_signal,tx_signal,rx_signal,rx_signal_awgn,rx_sym_signal,rx_bin_signal)
    figure
    %hold on;
    plot_num = 5;
    index = 1;
    
%     subplot(plot_num,1,index);
%     % 모양이 삼각형으로 나온다.
%     %plot(t_bin,tx_bin);
%     % 비트를 출력할때는 이것이 낳다.
%     stem(tx_bin);
%     %xlabel('bits-->');
%     ylabel('Amplitude (volts)','FontSize',8);
%     title('Data stream');
%     %xlim([0,10]);
%     index=index + 1;

    subplot(plot_num,1,index);
    plot(t_signal_sec,tx_bin_signal);
    %plot(t_signal_time,tx_bin_signal);
    ylim( [-0.1,1.1])
    %xlim( [0, 1 ]) % 1 sec
    xlabel('Time (sec)','FontSize',8);
    title('Tx Data');
    index=index + 1;
    
    subplot(plot_num,1,index);
%    plot(t_signal_sec,tx_sym_signal);
    plot(t_signal_sec,tx_signal);
    ylim( [-0.5,5.5])
    %xlim( [0, 1 ]) % 1 sec
    xlabel('Time (sec)','FontSize',8);
    title('Tx Symbol Signal');
    index=index + 1;
    
%     subplot(plot_num,1,index);
%     plot(t_signal_sec,rx_signal);
%     ylim( [-0.5,5.5])
%     %xlim( [0, 1 ]) % 1 sec
%     xlabel('Time (sec)','FontSize',8);
%     title('Rx Signal');
%     index=index + 1;
    
    subplot(plot_num,1,index);
    plot(t_signal_sec,rx_signal_awgn);
    ylim( [-0.5,5.5])
    %xlim( [0, 1 ]) % 1 sec
    xlabel('Time (sec)','FontSize',8);
    title('Rx Signal : AWGN + dealy ');
    index=index + 1;
    
      subplot(plot_num,1,index);
    plot(t_signal_sec,rx_sym_signal);
    ylim( [-0.1,1.1])
    %xlim( [0, 1 ]) % 1 sec
    xlabel('Time (sec)','FontSize',8);
    title('Rx Reconstructed Symbol Data');
    index=index + 1;   
    


    subplot(plot_num,1,index);
    plot(t_signal_sec,rx_bin_signal);
    ylim( [-0.1,1.1])
    %xlim( [0, 1 ]) % 1 sec
    xlabel('Time (sec)','FontSize',8);
    title('Rx Data ');
    index=index + 1;
    
    %strSupTitle = 'Rb = ' + str(Rb) + ' Fs = '+Fs    
    suptitle(fig_title )
    
end 
%%
function [crc, hex] = crc16(packet)
    % Calculates CRC16/XModem for packet
    % Input: byte content in an array
    % Ref: https://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks 
    % Usage: crc16( [49 50] ) - ASCII for 1 and 2
    % Validation: dec2hex( crc16( double('123456789') ) ) compare the result at
    % https://www.lammertbies.nl/comm/info/crc-calculation
    % J. Chen. Feb, 2020
    crc = 0;
    % crc = hex2dec('FFFF');   % for 0xFFFF version
    for i = 1:length(packet)
        crc = bitxor( crc, bitshift(packet(i),8) );
        for bit = 1:8
            if bitand( crc, hex2dec('8000') )     % if MSB=1
              crc = bitxor( bitshift(crc,1), hex2dec('1021') );
            else
              crc = bitshift(crc,1);
            end
            crc = bitand( crc, hex2dec('ffff') );  % trim to 16 bits
        end
    end
    hex = dec2hex(crc);
    % // Pseudo code
    % // https://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks
    % // Most significant bit first (big-endian)
    % // x^16+x^12+x^5+1 = (1) 0001 0000 0010 0001 = 0x1021
    % function crc(byte array string[1..len], int len) {
    %   rem := 0
    %   
    %   for i from 1 to len {
    %      rem  := rem xor (string[i] leftShift (n-8))   // n = 16 in this example
    %      for j from 1 to 8 {   // Assuming 8 bits per byte
    %          if rem and 0x8000 {   // if leftmost (most significant) bit is set
    %              rem  := (rem leftShift 1) xor 0x1021
    %          } else {
    %              rem  := rem leftShift 1
    %          }
    %          rem  := rem and 0xffff      // Trim remainder to 16 bits
    %      }
    %   }
    %   
    %   return rem
    % }
end 
%%

function [resto] = crc16_not_work(h)
    % g(X) =  X^16+X^15+X^2+1
    gx = [1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1];
    % P(X) is given input vector
    px = h;
    %Calculate P(x)x^r
    pxr=[px zeros(1,length(gx)-1)];
    % deconvolve  (r), entre pxr y gx
    [c r]=deconv(pxr,gx);

    r=mod(abs(r),2);
    % returncrc-16
    resto=r(length(px)+1:end);
end
%%
function [tx_bin, tx_bin_mimo, tx_bin_mimo_fix,n_bit_frame,n_bit_mimo_frame,n_bit_mimo_fix_frame] = vlc_generate_frame(tx_msg,n_byte_msg,mimo_chan_num, with_header)
    rng(1234);
    
    M = 2; % 0 과 1 
    
    if with_header
        n_byte_frame = n_byte_msg + 4 ; % PREAMBLE + SYNNC + msg + CRC16
        n_bit_msg = n_byte_msg * 8;
        n_bit_frame = n_byte_frame * 8 ;
        n_bit_mimo_frame = ((n_byte_msg / mimo_chan_num) + 4 ) * 8 ;
        n_bit_mimo_fix_frame = ((n_byte_msg / (mimo_chan_num - 1 )) + 4 ) * 8 ;
    else 
        n_byte_frame = n_byte_msg; 
        n_bit_msg = n_byte_frame * 8;
        n_bit_frame = n_byte_frame * 8 ;
        n_bit_mimo_frame = n_bit_frame / mimo_chan_num;
        n_bit_mimo_fix_frame = n_bit_frame /  (mimo_chan_num - 1 );
        
    end 
    % tx_bin = zeros(frame_size, 1);
    
    PREAMBLE_BYTE = 'AA';
    SYNC_BYTE='D5'; % 1101  0101 (13 / 5 )
    SYNC_BYTE_MANCHESTER  = '0x6665' ;
    ETX_BYTE=0x03; % 11
    STX_BYTE=0x02; % 10
    
    bin_vec = hexToBinaryVector('0x01',8);%,'LSBFirst');
    preamble_vec = hexToBinaryVector(PREAMBLE_BYTE,8);%'LSBFirst');
    sync_vec = hexToBinaryVector(SYNC_BYTE,8);%,'LSBFirst');
    sync_vec_manchester = Bin2Manchester(sync_vec);
    
    % https://kr.mathworks.com/help/comm/ref/comm.crcgenerator-system-object.html
    
    crcGen = comm.CRCGenerator(...
        'Polynomial','X^16 + X^12 + X^5 + 1',...
        'InitialConditions',1,...
        'DirectMethod',true,...
        'FinalXOR',1);
    crcDet = comm.CRCDetector(...
        'Polynomial','X^16 + X^12 + X^5 + 1',...
        'InitialConditions',1,...
        'DirectMethod',true,...
        'FinalXOR',1);
    
     
    if with_header
        tx_bin_header = [ preamble_vec sync_vec ] ;
        tx_bin_msg_crc = crcGen(transpose(tx_msg))';
        tx_bin = [tx_bin_header tx_bin_msg_crc ];
    else
        tx_bin = tx_msg;
    end 
    
    %% MIMO 
    tx_bin_mimo_msg = reshape(tx_msg,mimo_chan_num,[] );
    
    if with_header
        tx_bin_headers = repelem( tx_bin_header,mimo_chan_num,1);
        %tx_bin_msgs_crc = repelem( tx_bin_header,mimo_chan_num,1);
        %tmp = tx_bin_msgs_crc(1,:)
        for i = 1: mimo_chan_num
            tx_bin_msgs_crc(i,:) = crcGen(transpose(tx_bin_mimo_msg(i,:)))'; 
        end    
        tx_bin_mimo = [ tx_bin_headers  tx_bin_msgs_crc ];
    else
        tx_bin_mimo = tx_bin_mimo_msg;
    end 
    
    %% 1 bit burst error recovery
    
    len = length(tx_msg);
    if len == 32  
        tx_msg = tx_msg(1:24);
    end 
    
    if len == 8  
        tx_msg = tx_msg(1:6);
    end
    
    
    tx_bin_mimo_fix_msg_3 = reshape(tx_msg,mimo_chan_num-1,[]);
    %parity_sum_zero = zeros( 1, length(tx_bin_mimo_fix_msg_3) );
    parity_sum = sum(tx_bin_mimo_fix_msg_3,1);    
    parity_vec = rem(parity_sum , 2 );
    tx_bin_mimo_fix_msg = [tx_bin_mimo_fix_msg_3 ; parity_vec];
    
    if with_header
        % to make even parity
        for i = 1: mimo_chan_num 
            tx_bin_fix_msgs_crc(i,:) = crcGen(transpose(tx_bin_mimo_fix_msg(i,:)))'; 
        end        
        tx_bin_mimo_fix = [ tx_bin_headers  tx_bin_fix_msgs_crc ];
    else
        tx_bin_mimo_fix = [tx_bin_mimo_fix_msg_3 ; parity_vec];
    end 
    
end 
%%
function [rx_bin_msg,rx_bin_crc,rx_bin_mimo_msg,rx_bin_mimo_crc,rx_bin_mimo_fix_msg,rx_bin_mimo_fix_crc,rx_bin_mimo_fix_recoverd] = ...
    vlc_decode_frame(n_byte_msg,mimo_chan_num, with_header,rx_bin, rx_bin_mimo, rx_bin_mimo_fix,mimo_chan_err,mimo_fix_chan_err)
    
    if with_header
        n_byte_frame = n_byte_msg + 4 ; % PREAMBLE + SYNNC + MESSAGE + CRC16
        n_bit_msg = n_byte_msg * 8;
        n_bit_frame = n_byte_frame * 8 ;
    else 
        n_byte_frame = n_byte_msg; 
        n_bit_msg = n_byte_frame * 8;
        n_bit_frame = n_byte_frame * 8 ;
    end 
    % tx_bin = zeros(frame_size, 1);
    
    PREAMBLE_BYTE = 'AA';
    SYNC_BYTE='D5'; % 1101  0101 (13 / 5 )
    SYNC_BYTE_MANCHESTER  = '0x6665' ;
    ETX_BYTE=0x03; % 11
    STX_BYTE=0x02; % 10
    
    rx_bin_crc = zeros(1,16);
    rx_bin_mimo_crc = zeros(mimo_chan_num,16);
    rx_bin_mimo_fix_crc = zeros(mimo_chan_num,16);
    
    
    bin_vec = hexToBinaryVector('0x01',8);%,'LSBFirst');
    preamble_vec = hexToBinaryVector(PREAMBLE_BYTE,8);%'LSBFirst');
    sync_vec = hexToBinaryVector(SYNC_BYTE,8);%,'LSBFirst');
    sync_vec_manchester = Bin2Manchester(sync_vec);
    
    % https://kr.mathworks.com/help/comm/ref/comm.crcgenerator-system-object.html
    
    crcGen = comm.CRCGenerator(...
        'Polynomial','X^16 + X^12 + X^5 + 1',...
        'InitialConditions',1,...
        'DirectMethod',true,...
        'FinalXOR',1);
    crcDet = comm.CRCDetector(...
        'Polynomial','X^16 + X^12 + X^5 + 1',...
        'InitialConditions',1,...
        'DirectMethod',true,...
        'FinalXOR',1);
    
    
    if with_header
        rx_bin_msg  = rx_bin( 3: end - 2);
        rx_bin_crc = rx_bin( end-1: end );
    else
        rx_bin_msg = rx_bin;
    end 
    
    %% MIMO 
    if with_header
        rx_bin_mimo_msg = rx_bin_mimo(:, 3: end - 2);
        rx_bin_mimo_crc = rx_bin_mimo(:, end-1: end );
    else
        rx_bin_mimo_msg = rx_bin_mimo;
    end 
    
    %% MIMO FIX  -- 1 bit burst error recovery
    
%     len = length(rx_bin_msg);
%     if len == 32  
%         rx_bin_msg = rx_bin_msg(1:24);
%     end 
%     
%     if len == 8  
%         rx_bin_msg = rx_bin_msg(1:6);
%     end
    
    
    %rx_bin_mimo_fix_data = reshape(rx_bin_msg,mimo_chan_num-1,[]);
    rx_bin_mimo_fix_data = rx_bin_mimo_fix(1:3 , : );
    rx_bin_mimo_fix_parity = rx_bin_mimo_fix(4 , : );
    
    
    %parity_sum_zero = zeros( 1, length(tx_bin_mimo_fix_msg_3) );

    rx_bin_mimo_fix_msg = [rx_bin_mimo_fix_data ; rx_bin_mimo_fix_parity];
    
    % 가장 마지막 채널을 parity channel으로 사용시
    fixed_parity_chan = true;
    % data channel 에 에러가 발생할 경우만 수정
    % 아니면 어떤 채널에서 에러가 발생하더라도 수정
    fix_only_data_chan = false;
    
    if with_header
        % 실제 메세지에 대한 것만 crc 패킷에 넣는다.
        rx_bin_mimo_fix_msg = rx_bin_mimo_fix( : ,3: end - 2);
        rx_bin_mimo_fix_crc = rx_bin_mimo_fix( : ,end-1: end );
        rx_bin_mimo_fix_header = rx_bin_mimo_fix( : ,1: 2 );
        parity_vec = rx_bin_mimo_fixo( 3: end - 2);
        parity_sum = sum(rx_bin_mimo_fix_msg,1);    % 행(row) 열(column) 에서 1로 하면 각 열에 대해서 한다.
    else
        if fixed_parity_chan
            if fix_only_data_chan
                % rx_bin_mimo_fix_msg = rx_bin_mimo_fix_data ;
                parity_vec = rx_bin_mimo_fix_parity;
                parity_sum = sum(rx_bin_mimo_fix_data,1);    % 행(row) 열(column) 에서 1로 하면 각 열에 대해서 한다. 
                parity_vec_fixed = rem(parity_sum , 2 );

                rx_bin_mimo_fix_msg = [rx_bin_mimo_fix_data ; parity_vec];
            else
                RowIdx_error = find(ismember(mimo_fix_chan_err, 1,'rows'));
                RowIdx_correct = find(ismember(mimo_fix_chan_err, 0,'rows'));
                [numRows_error,numCols_error] = size(RowIdx_error);
                [numRows_correct,numCols_correct] = size(RowIdx_correct);
                
                if numRows_error > 2 
                   fprintf("Error happens at least more than 2 channel \n");
                end
                error_vec = rx_bin_mimo_fix(RowIdx_error,:);
                correct_vec = [ rx_bin_mimo_fix(RowIdx_correct(1),:) ; rx_bin_mimo_fix(RowIdx_correct(2),:) ; rx_bin_mimo_fix(RowIdx_correct(3),:)];
                
                parity_sum = sum(correct_vec,1);    % 행(row) 열(column) 에서 1로 하면 각 열에 대해서 한다. 
                parity_vec_fixed = rem(parity_sum , 2 );

                rx_bin_mimo_fix_msg(RowIdx_error,:) = parity_vec_fixed;
                
                rx_bin_mimo_fix_recoverd = rx_bin_mimo_fix_msg;
            end 
        end
         
    end 
    
end 
%%
function [t_signal_sec, tx_bin_signal,tx_sym, tx_signal,rx_signal,rx_signal_conv,rx_signal_awgn_with_delay] = ...
    vlc_frame_to_signal(modulation, Rb,Fs, n_bit_frame,tx_bin,impulse_response,snr,tx_amplitude,receiver_power)

    totalTime = 1/Rb * n_bit_frame;  
%    totalTime_mimo = totalTime / mimo_chan_num;
%    totalTime_mimo_recover = totalTime / ( mimo_chan_num - 1);
    bits_per_sec = Rb ;
    samples_per_sec = Fs ;
    sample_per_bit = samples_per_sec / bits_per_sec ; % Fs/Fb 
    sample_per_bit= Fs/Rb ;

    %modulation = 'OOK Manchester';
    %modulation = 'OOK NRZ';
    %modulation = 'OOK RZ';
    
    switch modulation
        case 'OOK Manchester'
            sym_per_bit=2;
        case 'OOK NRZ'
            sym_per_bit=1;
        case 'OOK RZ'
            sym_per_bit=2;
        otherwise
            sym_per_bit=2;   
    end
    
   
    sample_per_sym = sample_per_bit / sym_per_bit ; 
    
    
    t_bin = 1: length(tx_bin);
    t_signal_Rb = 1:Rb*n_bit_frame;
    t_signal_Fs = 1:Fs*n_bit_frame;
    t_signal = 1:Fs*n_bit_frame/Rb ;
    t_signal_sec = t_signal./length(t_signal)*(totalTime);
 %   t_signal_time = 1:1/length(t_signal):totalTime-1 ;


    
%    t_signal_symb = 1:Fs*n_bit_frame/Rb*2 ;
    
    if contains(modulation, 'OOK NRZ')
        tx_sym = tx_bin;
    elseif contains(modulation, 'OOK RZ')
        tx_sym = Bin2Rz(tx_bin);
    elseif contains(modulation, 'OOK Manchester')
        tx_sym = Bin2Manchester(tx_bin);
    else
        error("error !!!");
    end
    
    tx_bin_signal =  vlc_stream_by_Fs(tx_bin,sample_per_bit);
    tx_sym_signal =  vlc_stream_by_Fs(tx_sym,sample_per_sym);
    
    tx_signal = tx_sym_signal * tx_amplitude;
    rx_signal_conv = conv(tx_sym_signal, impulse_response);
    rx_signal = rx_signal_conv(1:length(tx_signal)) * tx_amplitude * receiver_power;
    %rx_signal_awgn = awgn(rx_signal, snr, 'measured');
    rx_signal_awgn_with_delay = awgn(rx_signal_conv * tx_amplitude * receiver_power, snr, 'measured');

end

function [t_signal_sec, tx_bin_signal,tx_sym, tx_signal,rx_signal,rx_signal_conv,rx_signal_awgn_with_delay] = ...
    vlc_frame_to_signal_mimo(modulation, Rb,Fs, n_bit_frame,tx_bin,impulse_response,snr,tx_amplitude,receiver_power)

    [rows,cols] = size( tx_bin );
    totalTime = 1/Rb * n_bit_frame;  
%    totalTime_mimo = totalTime / mimo_chan_num;
%    totalTime_mimo_recover = totalTime / ( mimo_chan_num - 1);
    bits_per_sec = Rb ;
    samples_per_sec = Fs ;
    sample_per_bit = samples_per_sec / bits_per_sec ; % Fs/Fb 
    sample_per_bit= Fs/Rb ;

    %modulation = 'OOK Manchester';
    %modulation = 'OOK NRZ';
    %modulation = 'OOK RZ';
    
    switch modulation
        case 'OOK Manchester'
            sym_per_bit=2;
        case 'OOK NRZ'
            sym_per_bit=1;
        case 'OOK RZ'
            sym_per_bit=2;
        otherwise
            sym_per_bit=2;   
    end
    
   
    sample_per_sym = sample_per_bit / sym_per_bit ; 
    
    
    t_bin = length(tx_bin);
    t_signal_Rb = 1:Rb*n_bit_frame;
    t_signal_Fs = 1:Fs*n_bit_frame;
    t_signal = 1:Fs*n_bit_frame/Rb ;
    t_signal_sec = t_signal./length(t_signal)*(totalTime);
 %   t_signal_time = 1:1/length(t_signal):totalTime-1 ;


    
%    t_signal_symb = 1:Fs*n_bit_frame/Rb*2 ;
    tx_sym = Bin2Manchester(tx_bin);
    
    tx_bin_signal =  vlc_stream_by_Fs(tx_bin,sample_per_bit);
    %tx_bin_signal =  vlc_stream_by_Fs(tx_bin,Fs)    
    tx_sym_signal =  vlc_stream_by_Fs(tx_sym,sample_per_sym);
    
    tx_signal = tx_sym_signal * tx_amplitude;
    
    rx_signal_conv = zeros(0,0);
    rx_signal = zeros(0,0);
    rx_signal_awgn_with_delay = zeros(0,0);
    
    for i=1:rows
        rx_signal_conv_xx = conv(tx_sym_signal(i,:), impulse_response);
        rx_signal_xx = rx_signal_conv_xx(1:length(tx_signal(i,:))) * tx_amplitude * receiver_power(i);
        %rx_signal_awgn = awgn(rx_signal, snr, 'measured');
        rx_signal_awgn_with_delay_xx = awgn(rx_signal_conv_xx * tx_amplitude * receiver_power(i), snr, 'measured');
        
        rx_signal_conv = [rx_signal_conv ; rx_signal_conv_xx ];
        rx_signal = [rx_signal ; rx_signal_xx ];
        rx_signal_awgn_with_delay = [rx_signal_awgn_with_delay ; rx_signal_awgn_with_delay_xx ];
    end     

end
%%
function [rx_signal_recostructed ,rx_sym,rx_bin,rx_coding_error,rx_coding_error_total,rx_sym_signal,rx_bin_signal,chan_err ] = ...
    vlc_signal_to_frame(modulation,Rb,Fs,n_bit_frame,mimo_chan_num,rx_signal_awgn_with_delay)

    totalTime = 1/Rb * n_bit_frame;  
    totalTime_mimo = totalTime / mimo_chan_num;
    totalTime_mimo_recover = totalTime / ( mimo_chan_num - 1);
    bits_per_sec = Rb ;
    samples_per_sec = Fs ;
    sample_per_bit = samples_per_sec / bits_per_sec ; % Fs/Fb 
    sample_per_bit= Fs/Rb ;

    switch modulation
        case 'OOK Manchester'
            sym_per_bit=2;
        case 'OOK NRZ'
            sym_per_bit=1;
        case 'OOK RZ'
            sym_per_bit=2;
        otherwise
            sym_per_bit=2;   
    end
    
    sample_per_sym = sample_per_bit / sym_per_bit ; 
    
    
    chan_rx_sample_index_start = 10;
    chan_rx_sample_index_end =5;
    

    rx_signal_sample =  rx_signal_awgn_with_delay(chan_rx_sample_index_start+1:length(rx_signal_awgn_with_delay)-chan_rx_sample_index_end);
    
    %% Rx decoding => Using avarage voltage of all samples of a symbol
    rx_signal_remove_outlier1 = rmoutliers(rx_signal_sample,'mean');
    rx_signal_remove_outlier = rmoutliers(rx_signal_sample,'percentiles',[20,80]);
    max_voltage1 = max(rx_signal_remove_outlier1);
    min_voltage1 = min(rx_signal_remove_outlier1);    
    max_voltage = max(rx_signal_remove_outlier);
    min_voltage = min(rx_signal_remove_outlier);
    verdict_voltage = ( max_voltage + min_voltage ) / 2;
    chan_err = ( max_voltage - min_voltage ) < 0.3; 
    
    rx_signal_after_level_detector = rx_signal_sample > verdict_voltage ;
    
    
    
    blockSize = [1, sample_per_sym];
    % Block process the image to replace every element in the 
    % 100 element wide block by the mean of the pixels in the block.
    % First, define the averaging function for use by blockproc().
    meanFilterFunction = @(theBlockStructure) mean2(theBlockStructure.data(:));
    % Now do the actual averaging (block average down to smaller size array).
    blockAveragedDownSignal = blockproc(rx_signal_after_level_detector, blockSize, meanFilterFunction);
    % Let's check the output size.
    [rows, columns] = size(blockAveragedDownSignal);
    
    %% Rx decoding => Sample middle point of symbol
    
    sampled_symbols = rx_signal_after_level_detector(int64(sample_per_sym/2):sample_per_sym:length(rx_signal_after_level_detector));
    sampled_symbols_2sample_per_symbol = rx_signal_after_level_detector(int64(sample_per_sym/4):int64(sample_per_sym/2): length(rx_signal_after_level_detector));
    sampled_symbols_2sample_per_symbol_average = blockproc(sampled_symbols_2sample_per_symbol, [1,2], meanFilterFunction);
    %%
    % No Errors 
    %rx_signal_recostructed = blockAveragedDownSignal > 0.5;
    % Errors 
    if chan_err 
        rx_signal_recostructed = zeros(1,length(blockAveragedDownSignal));
    else 
        rx_signal_recostructed = sampled_symbols ;
    end
    %rx_signal_recostructed = sampled_symbols_2sample_per_symbol_average > 0.5 ;
 
    rx_sym = double(rx_signal_recostructed).*1;
    switch modulation
        case 'OOK Manchester'
            [rx_bin,rx_coding_error] = Manchester2Bin(rx_sym);
        case 'OOK NRZ'
            rx_bin = rx_sym;
            rx_coding_error = zeros(rows,columns);
        case 'OOK RZ'
            [rx_bin,rx_coding_error] = Manchester2Bin(rx_sym);
        otherwise
            error("error ");
    end
    
    rx_coding_error_total = sum(rx_coding_error);
    
    rx_sym_signal =  vlc_stream_by_Fs(rx_sym,sample_per_sym);
    rx_bin_signal =  vlc_stream_by_Fs(rx_bin,sample_per_bit);
   
end 


function [rx_signal_recostructed ,rx_sym,rx_bin,rx_coding_error,rx_coding_error_total,rx_sym_signal,rx_bin_signal,chan_err ] = ...
    vlc_signal_to_frame_mimo(modulation,Rb,Fs,n_bit_frame,mimo_chan_num,rx_signal_awgn_with_delay,rx_detect_policy)

    totalTime = 1/Rb * n_bit_frame;  
    totalTime_mimo = totalTime / mimo_chan_num;
    totalTime_mimo_recover = totalTime / ( mimo_chan_num - 1);
    bits_per_sec = Rb ;
    samples_per_sec = Fs ;
    sample_per_bit = samples_per_sec / bits_per_sec ; % Fs/Fb 
    sample_per_bit= Fs/Rb ;

    switch modulation
        case 'OOK Manchester'
            sym_per_bit=2;
        case 'OOK NRZ'
            sym_per_bit=1;
        case 'OOK RZ'
            sym_per_bit=2;
        otherwise
            sym_per_bit=2;   
    end
    
    sample_per_sym = sample_per_bit / sym_per_bit ; 
    
    
    chan_rx_sample_index_start = 10;
    chan_rx_sample_index_end =5;
    

    rx_signal_sample =  rx_signal_awgn_with_delay(:, chan_rx_sample_index_start+1:length(rx_signal_awgn_with_delay)-chan_rx_sample_index_end);
    
    %% Rx decoding => Using avarage voltage of all samples of a symbol
    rx_sym_signal = zeros(0,0);
    rx_bin_signal = zeros(0,0);
    rx_coding_error_total = zeros(0,0);
    rx_coding_error = zeros(0,0);
    rx_signal_recostructed = zeros(0,0);
    rx_sym = zeros(0,0);
    rx_bin_signal = zeros(0,0);
    rx_bin = zeros(0,0);
    rx_coding_error_total = zeros(0,0);
    chan_err = zeros(0,0);

    for i = 1:mimo_chan_num
        
        
        %% remove outer data
        
        % 이것은 잘 동작하지 않음.
        %rx_signal_remove_outlier1 = rmoutliers(rx_signal_sample(i,:),'mean');
        %max_voltage1 = max(rx_signal_remove_outlier1);
        %min_voltage1 = min(rx_signal_remove_outlier1); 
        
        rx_signal_remove_outlier = rmoutliers(rx_signal_sample(i,:),'percentiles',[20,80]);
        max_voltage = max(rx_signal_remove_outlier);
        min_voltage = min(rx_signal_remove_outlier);
        verdict_voltage = ( max_voltage + min_voltage ) / 2;
        chan_err_xx = ( max_voltage - min_voltage ) < 0.3; 

        rx_signal_after_level_detector = rx_signal_sample(i,:) > verdict_voltage ;

        switch rx_detect_policy
            case 'rx_level_detector_1_sample_per_symbol'
                % SNR 에 따라 적당히 변경되므로 사용하기 편하다.
                sampled_symbols = rx_signal_after_level_detector(int64(sample_per_sym/2):sample_per_sym:length(rx_signal_after_level_detector));
                
            case 'rx_level_detector_2_samples_per_symbol'
                % 잘 동작하지 않는다. 추가작업 필요
                sampled_symbols_2sample_per_symbol = rx_signal_after_level_detector(int64(sample_per_sym/4):int64(sample_per_sym/2): length(rx_signal_after_level_detector));
                sampled_symbols_2sample_per_symbol_average = blockproc(sampled_symbols_2sample_per_symbol, [1,2], meanFilterFunction);
                sampled_symbols = sampled_symbols_2sample_per_symbol_average > 0.5 ;
                
                
            case 'rx_level_detector_average_all_samples_per_symbol'
                % 항상 에러가 0 이다. 
                
                blockSize = [1, sample_per_sym];
                % Block process the image to replace every element in the 
                % 100 element wide block by the mean of the pixels in the block.
                % First, define the averaging function for use by blockproc().
                meanFilterFunction = @(theBlockStructure) mean2(theBlockStructure.data(:));
                % Now do the actual averaging (block average down to smaller size array).
                blockAveragedDownSignal = blockproc(rx_signal_after_level_detector, blockSize, meanFilterFunction);
                % Let's check the output size.
                [rows, columns] = size(blockAveragedDownSignal);
                sampled_symbols = blockAveragedDownSignal;
        end 
        
       % Errors 
        if chan_err_xx 
            rx_signal_recostructed_xx = zeros(1,length(sampled_symbols));
        else 
            rx_signal_recostructed_xx = sampled_symbols ;
        end

        rx_sym_xx = double(rx_signal_recostructed_xx).*1;
        [rx_bin_xx,rx_coding_error_xx] = Manchester2Bin(rx_sym_xx);
        rx_coding_error_total_xx = sum(rx_coding_error_xx);

        rx_sym_signal_xx =  vlc_stream_by_Fs(rx_sym_xx,sample_per_sym);
        rx_bin_signal_xx =  vlc_stream_by_Fs(rx_bin_xx,sample_per_bit);
        
        
        rx_sym_signal = [rx_sym_signal;rx_sym_signal_xx];
        rx_bin_signal = [rx_bin_signal;rx_bin_signal_xx];
        rx_coding_error_total = [rx_coding_error_total;rx_coding_error_total_xx];
        rx_coding_error = [rx_coding_error;rx_coding_error_xx];
        rx_signal_recostructed = [rx_signal_recostructed;rx_signal_recostructed_xx];
        rx_sym = [rx_sym;rx_sym_xx];
        rx_bin = [rx_bin;rx_bin_xx];
        chan_err = [chan_err;chan_err_xx];

    end
   
end 
%% 

function clearLine(amount)

    for I = 1:amount
       fprintf('\b'); 
    end
end 
%%
function lengthToErase = display_errors(errors)

    s = sprintf('%d',errors);
    preamb = 'Current errors: ';

    fprintf('%s %s', preamb, s);

    lengthToErase = 1 + length(s) + length(preamb);
end 
%%



%%
function [M,Fs,Tb,snr,max_bits,error_threshold,batch_size,tx_amplitude,LED_height_distance,LED_theta,LED_power,LED_loc_offset] = vlc_setting_parameter( ...
   modulation,mimo_chan_num,Rb)
   
    %% VARIABLES
    % Modulation depth
    M = 2;  % 1 bit ->  M = 2 symol - 0/1


    %Rb is the bit rate in bits/second
%     Rb=1000; 
%     Fs=Rb*10

	%modulation = 'OOK NRZ' ;
	%%modulation = 'OOK RZ' ;
	%%modulation = 'OOK Manchester' ;
	
     
    Fs=Rb*100;
    Tb=1/Rb;    
    
    %Fs=100;

    % Target SNRs in dB
    % https://en.wikipedia.org/wiki/Signal-to-noise_ratio
    %SNR = 0:2:30;
    
    snr=30; % actual 
    %snr=20;
    %snr=10;
    %snr=6; 
    %snr=4; % some errors 
    %snr=2; % some errors 
    %snr=1; % some errors 
    %snr=0.5; % some errors
    %snr=0; % some errors
    % Maximum number of bits per SNR
    %max_bits = 1e7; % Maximum detectable BER: 1e-7
    % 속도 향상을 위해 줄이자
    max_bits = 1e5; % 1000 bit
    
    % Minimum bit errors to stop current SNR
    error_threshold = 5;

    % Batch size. This is used to make an adaptive simulation, and hece reduce
    % computation cost. Measured in frames.
    
    %batch_size = 100;
    % 속도가 너무 느리다.
    batch_size = 100;

    %% RESULT CONTAINERS
    %BER = zeros(size(SNR));

    %% TX and RX and Channel
    % frame_composer and frame_decomposer functions must be implemented. They
    % have currently dummy code.

    tx_amplitude = 5; % 5Vpp

    % N_led,led_loc_offset,h,led_power,theta,show_figure
    % LED 갯수 : 1  
    % LED x,y offset from (0,0)  : 0.5 => x,y 각 1 m 간격으로 LED 설치  1.5 => 3 m 간격
    % LED 높이 : 2.5m / 3m
    % LED 파워 : 1
    % LED theta : 7 
    % show figure : true

    %SISO 1*1 / MIMO 4x4
    LED_num_siso = 1;
    LED_num_mimo = mimo_chan_num;
    
    % Distance between LED and PD
    %LED_height_distance = 0.1;
    %LED_height_distance = 0.5;
    LED_height_distance = 2.5; % defualt
    %LED_height_distance = 2.9; 
    
    %LED_theta = 3;
    %LED_theta = 7;
    LED_theta = 15; % defualt
    
    LED_power = 1; % defualt
    LED_loc_offset = 0.5; % defualt
    
end 
%%
function [chan_loss,chan_time,chan_k,chan_delay_samples,chan_rx_sample_index_start,chan_rx_sample_index_end,amp_offset ] = vlc_set_tx_switching_parameter()
	%chan_amplitude = 0.5;
	%chan_loss =0.5;
    chan_loss =1; % no loss
    %chan_loss =0; % all loss
	chan_k = 0.3;
	chan_time =  0:10;
    chan_delay_samples = 5;
    chan_lagging_samples = 10;
    chan_rx_sample_index_start = 10;
    chan_rx_sample_index_end =5;
    %%amp_offset_siso = 1; %1/4; % to compare to 4LED = 1 
    amp_offset = 1;
    %chan_loss_siso = 1;
    %%chan_loss_siso = 1/4; %1/4; % to compare to 4LED = 1 
end 
%%
function [receiver_powers,receiver_indexs] = vlc_get_receiver_powers(mimo_chan_num,P_block_total)
    
%     receivers = 1:4;
%     %receiver1_index = [ 2, 2 ];
%     %receiver2_index = [ 2, 3 ];
%     %receiver3_index = [ 3, 2 ];
%     %receiver4_index = [ 3, 3 ];
%     linearidx = sub2ind(size(P_block_total),4,4);
%     receiver1_index = 6;
%     receiver2_index = 7;
%     receiver3_index = 10;
%     receiver4_index = 11;   
%     
%     % receiver_powers = [ P_block_total(2,2) , P_block_total(2,3) , P_block_total(3,2), P_block_total(3,3)];
%     receiver_powers = [ P_block_total(receiver1_index) , P_block_total(receiver2_index) , P_block_total(receiver3_index), P_block_total(receiver4_index)];
%     receiver_power_mimo = [ P_block_total(receiver1_index) ; P_block_total(receiver2_index) ; P_block_total(receiver3_index) ; P_block_total(receiver4_index)];
%         
%     receiver_power = P_block_total_siso(receiver1_index);


    receiver_indexs = zeros(0,0);
    receiver_powers = zeros(0,0);
    if mimo_chan_num == 1
        receiver_powers = [ P_block_total(6) ];
    elseif mimo_chan_num == 4
        %receiver1_index = [ 2, 2 ];
        %receiver2_index = [ 2, 3 ];
        %receiver3_index = [ 3, 2 ];
        %receiver4_index = [ 3, 3 ];
        linearidx = sub2ind(size(P_block_total),4,4);
        receiver_indexs = [ receiver_indexs ; 6 ];
        receiver_indexs = [ receiver_indexs ; 7 ];
        receiver_indexs = [ receiver_indexs ; 10 ];
        receiver_indexs = [ receiver_indexs ; 11 ];
        for i=1:mimo_chan_num
            receiver_powers = [ receiver_powers ; P_block_total(receiver_indexs(i)) ];
        end
    else
        error("error");
    end

end
%%
function vlc_snr_test()

	modulation = 'OOK NRZ' ;
	Rb=100;
	SNR = 0:2:30;
    mimo_chan_num = 4;
    %% RESULT CONTAINERS
    BER = zeros(size(SNR));
    
	
	[M,Fs,Tb,snr,max_bits,error_threshold,batch_size,tx_amplitude,LED_height_distance,LED_theta,LED_power,LED_loc_offset] = vlc_setting_parameter( ...
   modulation,mimo_chan_num,Rb);
   
    [P_block_total_siso,h1_siso,h2_siso,h3_siso,h4_siso] = vlc_rx_power_pola_panel_test(1,LED_loc_offset,LED_height_distance,LED_power,LED_theta,false);
    %MOMI 2*2 
    [P_block_total,h1,h2,h3,h4] = vlc_rx_power_pola_panel_test(mimo_chan_num, LED_loc_offset,LED_height_distance,LED_power,LED_theta,false);

    receiver_power_siso = vlc_get_receiver_powers(1,P_block_total_siso);
    [receiver_powers] = vlc_get_receiver_powers(mimo_chan_num,P_block_total);

    [chan_loss,chan_time,chan_k,chan_delay_samples,chan_rx_sample_index_start,chan_rx_sample_index_end,amp_offset ] = vlc_set_tx_switching_parameter();
    
    impulse_responses   = vlc_get_impulse_response( receiver_power_siso * amp_offset , chan_loss, chan_k, chan_time);
    
 
	% siso 12 byte /  MIMO 3 * 4 channel  / MIMO-parity 4 * 3 channel + 4*1 parity channel
    
    
    
    %n_byte_msg = 120;
    n_byte_msg = 12;
    %n_byte_msg = 4;
    %n_byte_msg = 1;
    with_header = false;
    
    %% ERROR generation.
    %receiver_power = 0.1 % no chan_err
    %%receiver_power = 0.01; % chan_err
    receiver_powers(3) = 0.01; % 0.1 - not work ;
    % generate error on chan 3
    receiver_power_mimo(3) = 0.01;    
    

    %Please insert here your channel
    channel = 1;

    % SIMULATION WORKFLOW
    %This part of the script carries out the simulation taking into account
    %the typical Tx-> Channel -> Rx flow.

    index = 1;

    for snr = SNR
        fprintf('Simulation SNR = %1.2f\n',snr);
        to_clear = 0;

        %error counter
        bit_errors_sum = 0;
        bit_errors_sum_mimo = 0;
        bit_errors_sum_mimo_fix = 0;
        bit_errors_sum_mimo_fix_recovered = 0;
        

        %frame counter
        frame_counter = 0;
        
        n_bit_msg = n_byte_msg * 8 ;
        
        %We iterate until there are enough errors to estimate BER
        while ((bit_errors_sum < error_threshold) && (frame_counter*n_bit_msg*log2(M) < max_bits))
            %We get a batch of frames
            for I = 1:batch_size
                
                if (snr == SNR(end)) && (I == 1)
                    display = true;
                else
                    display = false;
                end
                %% MSG 
                 
                tx_msg = randi([0, M-1], 1 , n_bit_msg );
                [tx_bin, rx_bin,tx_bin_mimo, rx_bin_mimo, tx_bin_mimo_fix, rx_bin_mimo_fix, rx_bin_mimo_fix_recoverd ] = vlc_tx_rx_message( ...
                    modulation,Rb,Fs,tx_msg,n_byte_msg,mimo_chan_num,with_header,...
                    impulse_responses,snr,tx_amplitude,receiver_power_siso,receiver_power_mimo, ...
                    LED_height_distance,LED_theta,display);
    
                
                %% Frame level
                %[sym_errors, sym_error_ratio] =  symerr(tx_sym, rx_sym);
                [bit_errors, bit_error_ratio] =  symerr(tx_bin, rx_bin);

%                 %[sym_errors_mimo, sym_error_ratio_mimo] =  symerr(tx_sym_mimo, rx_sym_mimo);
%                 [bit_errors_mimo, bit_error_ratio_mimo] =  symerr(tx_bin_mimo, rx_bin_mimo);
% 
%                 % befor recovered
%                 [bit_errors_mimo_fix, bit_error_ratio_mimo_fix] =  symerr(tx_bin_mimo_fix, rx_bin_mimo_fix);
% 
%                 % after recovered 
%                 [bit_errors_mimo_fix_recovered, bit_error_ratio_mimo_fix_recovered] =  symerr(tx_bin_mimo_fix, rx_bin_mimo_fix_recoverd);
                
                bit_errors_sum = bit_errors_sum + bit_errors ;
                

            end

            if (rem(frame_counter, 10000) == 0)
                clearLine(to_clear);
                to_clear = display_errors(bit_errors_sum);
            end

            frame_counter = frame_counter + batch_size;
        end

        BER(index) = bit_errors_sum/(frame_counter*n_bit_msg*log2(M));
        fprintf('\nResult is %1.2f\n', BER(index));
        index = index + 1;
    end

    % VISUALIZATION

    figure;
    semilogy(SNR, BER);

end 
%%
function [tx_bin, rx_bin,tx_bin_mimo, rx_bin_mimo, tx_bin_mimo_fix, rx_bin_mimo_fix, rx_bin_mimo_fix_recoverd ] = vlc_tx_rx_message( ...
    modulation,Rb,Fs,tx_msg,n_byte_msg,mimo_chan_num,with_header, ...
    impulse_responses,snr,tx_amplitude,receiver_power_siso,receiver_power_mimo, ...
    LED_height_distance,LED_theta,display)


    %% Frame
    [tx_bin, tx_bin_mimo, tx_bin_mimo_fix,n_bit_frame,n_bit_mimo_frame,n_bit_mimo_fix_frame] = ...
        vlc_generate_frame(tx_msg,n_byte_msg,mimo_chan_num,with_header);
    
%     n_bit_frame = 10 ;
%     tx_bin = [ 1,0,1,0,1,1,0,0,1,0 ];



    %% SISO 
     
	[t_signal_sec, tx_bin_signal, tx_sym, tx_signal,rx_signal, rx_signal_conv,rx_signal_awgn_with_delay] = ...
        vlc_frame_to_signal(modulation,Rb,Fs,n_bit_frame, tx_bin,1,snr,tx_amplitude,receiver_power_siso);
    
    
    t_signal_sec_mimo = zeros(4,1);
    t_signal_sec_mimo_fix = zeros(4,1);
    %% MIMO
    [t_signal_sec_mimo, tx_bin_signal_mimo, tx_sym_mimo, tx_signal_mimo,rx_signal_mimo, rx_signal_conv_mimo,rx_signal_awgn_with_delay_mimo] = ...
            vlc_frame_to_signal_mimo(modulation,Rb,Fs,n_bit_mimo_frame, tx_bin_mimo,impulse_responses,snr,tx_amplitude,receiver_power_mimo);
    %% MIMO Fix    
     [t_signal_sec_mimo_fix, tx_bin_signal_mimo_fix, tx_sym_mimo_fix, tx_signal_mimo_fix,rx_signal_mimo_fix, rx_signal_conv_mimo_fix,rx_signal_awgn_with_delay_mimo_fix] = ...
            vlc_frame_to_signal_mimo(modulation,Rb,Fs,n_bit_mimo_fix_frame, tx_bin_mimo_fix,impulse_responses,snr,tx_amplitude,receiver_power_mimo);
            
    %% SISO     

    [rx_signal_recostructed ,rx_sym,rx_bin,rx_coding_error,rx_coding_error_total,rx_sym_signal,rx_bin_signal,chan_err ] = ...
        vlc_signal_to_frame(modulation,Rb,Fs,n_bit_frame,mimo_chan_num,rx_signal_awgn_with_delay);
    
     if rx_coding_error_total > 0 
%          fprintf('Error on SISO');
%          %warning('Error on SISO')
     end 
    
    %% MIMO
    [rx_signal_recostructed_mimo ,rx_sym_mimo,rx_bin_mimo,rx_coding_error_mimo,rx_coding_error_total_mimo,rx_sym_signal_mimo,rx_bin_signal_mimo, mimo_chan_err ] = ...
        vlc_signal_to_frame_mimo(modulation,Rb,Fs,n_bit_mimo_frame,mimo_chan_num,rx_signal_awgn_with_delay_mimo,'rx_level_detector_1_sample_per_symbol');    
        
    if sum(rx_coding_error_total_mimo) > 0 
%         fprintf('Error on MIMO');
%         %warning('Error on SISO')
    end 
    
    %% MIMO FIX

    [rx_signal_recostructed_mimo_fix ,rx_sym_mimo_fix,rx_bin_mimo_fix,rx_coding_error_mimo_fix,rx_coding_error_total_mimo_fix,rx_sym_signal_mimo_fix,rx_bin_signal_mimo, mimo_fix_chan_err ] = ...
        vlc_signal_to_frame_mimo(modulation,Rb,Fs,n_bit_mimo_fix_frame,mimo_chan_num,rx_signal_awgn_with_delay_mimo_fix,'rx_level_detector_1_sample_per_symbol');    
    
    %% remove header - extract MSG  / recoverer with parity channel
    [rx_bin_msg,rx_bin_crc,rx_bin_mimo_msg,rx_bin_mimo_crc,rx_bin_mimo_fix_msg,rx_bin_mimo_fix_crc,rx_bin_mimo_fix_recoverd] = ...
        vlc_decode_frame(n_byte_msg,mimo_chan_num, with_header,rx_bin, rx_bin_mimo, rx_bin_mimo_fix,mimo_chan_err,mimo_fix_chan_err);
    
    %% SISO display
    if display
        siso_title = "OOK Manchester Rb=" + Rb + " Fs="+ Fs + " Led Num=" + 1 + " Tx/Rx distance=" + LED_height_distance + " Theta="  + LED_theta + " SNR="  + snr + " Received Power="+receiver_power_siso;
        vlc_draw_tx_rx_signal(siso_title,t_signal_sec,tx_bin,tx_bin_signal,tx_signal,rx_signal,rx_signal_awgn_with_delay(1:length(rx_signal)),rx_sym_signal,rx_bin_signal);
    end 

    
end 
%%
function vlc_test_packet_short()
    % siso 12 byte /  MIMO 3 * 4 channel  / MIMO-parity 4 * 3 channel + 4*1 parity channel

	modulation = 'OOK NRZ' ;
	Rb=100;
	SNR = 0:2:30;
    snr = 30;
    mimo_chan_num = 4;
    %n_byte_msg = 120;
    n_byte_msg = 12;
    %n_byte_msg = 4;
    %n_byte_msg = 1;
    with_header = false;
    
	
	[M,Fs,Tb,snr,max_bits,error_threshold,batch_size,tx_amplitude,LED_height_distance,LED_theta,LED_power,LED_loc_offset] = vlc_setting_parameter( ...
   modulation,mimo_chan_num,Rb);
    [P_block_total_siso,h1_siso,h2_siso,h3_siso,h4_siso] = vlc_rx_power_pola_panel_test(1, LED_loc_offset,LED_height_distance,LED_power,LED_theta,false);
    receiver_power_siso = vlc_get_receiver_powers(1,P_block_total_siso);
    [chan_loss,chan_time,chan_k,chan_delay_samples,chan_rx_sample_index_start,chan_rx_sample_index_end,amp_offset ] = vlc_set_tx_switching_parameter();
    impulse_response   = vlc_get_impulse_response( receiver_power_siso .* amp_offset , chan_loss, chan_k, chan_time);
    
    %% MSG 
    n_bit_msg = n_byte_msg * 8 ; 
    tx_msg = randi([0, M-1], 1 , n_bit_msg );
    
%     n_bit_msg = 10 ;
%     tx_msg = [ 1,0,1,0,1,1,0,0,1,0 ];    
    
    %% Frame
    [tx_bin, tx_bin_mimo, tx_bin_mimo_fix,n_bit_frame,n_bit_mimo_frame,n_bit_mimo_fix_frame] = ...
        vlc_generate_frame(tx_msg,n_byte_msg,mimo_chan_num,with_header);
 	[t_signal_sec, tx_bin_signal, tx_sym, tx_signal,rx_signal, rx_signal_conv,rx_signal_awgn_with_delay] = ...
        vlc_frame_to_signal(modulation,Rb,Fs,n_bit_frame, tx_bin,impulse_response,snr,tx_amplitude,receiver_power_siso);
    
    t_signal_sec_mimo = zeros(4,1);
    t_signal_sec_mimo_fix = zeros(4,1);
  

    [t_signal_sec_mimo, tx_bin_signal_mimo, tx_sym_mimo, tx_signal_mimo,rx_signal_mimo, rx_signal_conv_mimo,rx_signal_awgn_with_delay_mimo] = ...
        vlc_frame_to_signal_mimo(modulation,Rb,Fs,n_bit_mimo_frame, tx_bin_mimo,impulse_responses,snr,tx_amplitude,receiver_power_mimo);
        
     if rx_coding_error_total > 0 
         fprintf('Error on SISO');
         %warning('Error on SISO')
     end 
    
    %% remove header - extract MSG  / recoverer with parity channel
    [rx_bin_msg,rx_bin_crc,rx_bin_mimo_msg,rx_bin_mimo_crc,rx_bin_mimo_fix_msg,rx_bin_mimo_fix_crc,rx_bin_mimo_fix_recoverd] = ...
        vlc_decode_frame(n_byte_msg,mimo_chan_num, with_header,rx_bin, rx_bin_mimo, rx_bin_mimo_fix,mimo_chan_err,mimo_fix_chan_err);
    
    %% SISO display
    siso_title = "OOK Manchester Rb=" + Rb + " Fs="+ Fs + " Led Num=" + 1 + " Tx/Rx distance=" + LED_height_distance + " Theta="  + LED_theta + " SNR="  + snr + " Received Power="+receiver_power;
    vlc_draw_tx_rx_signal(siso_title,t_signal_sec,tx_bin,tx_bin_signal,tx_signal,rx_signal,rx_signal_awgn_with_delay(1:length(rx_signal)),rx_sym_signal,rx_bin_signal);
    
    %% Frame level
    %[sym_errors, sym_error_ratio] =  symerr(tx_sym, rx_sym);
    [bit_errors, bit_error_ratio] =  symerr(tx_bin, rx_bin);
 
    return
 
end 

function vlc_test_packet()

	modulation = 'OOK NRZ' ;
	Rb=100;
	SNR = 0:2:30;
    mimo_chan_num = 4;
    %% RESULT CONTAINERS
    BER = zeros(size(SNR));
    
	
	[M,Fs,Tb,snr,max_bits,error_threshold,batch_size,tx_amplitude,LED_height_distance,LED_theta,LED_power,LED_loc_offset] = vlc_setting_parameter( ...
   modulation,mimo_chan_num,Rb);

    [P_block_total_siso,h1_siso,h2_siso,h3_siso,h4_siso] = vlc_rx_power_pola_panel_test(1, LED_loc_offset,LED_height_distance,LED_power,LED_theta,true);
    %MOMI 2*2 
    [P_block_total,h1,h2,h3,h4] = vlc_rx_power_pola_panel_test(mimo_chan_num, LED_loc_offset,LED_height_distance,LED_power,LED_theta,false);


    receiver_power_siso = vlc_get_receiver_powers(1,P_block_total_siso);
    [receiver_powers] = vlc_get_receiver_powers(mimo_chan_num,P_block_total);


    [chan_loss,chan_time,chan_k,chan_delay_samples,chan_rx_sample_index_start,chan_rx_sample_index_end,amp_offset ] = vlc_set_tx_switching_parameter();
    
 
    impulse_response   = vlc_get_impulse_response( amp_offset , chan_loss, chan_k, chan_time);
	% siso 12 byte /  MIMO 3 * 4 channel  / MIMO-parity 4 * 3 channel + 4*1 parity channel
    
    
    
    %n_byte_msg = 120;
    n_byte_msg = 12;
    %n_byte_msg = 4;
    %n_byte_msg = 1;
    with_header = false;
    
    %% MSG 
    n_bit_msg = n_byte_msg * 8 ; 
    tx_msg = randi([0, M-1], 1 , n_bit_msg );
    
    %% Frame
    [tx_bin, tx_bin_mimo, tx_bin_mimo_fix,n_bit_frame,n_bit_mimo_frame,n_bit_mimo_fix_frame] = ...
        vlc_generate_frame(tx_msg,n_byte_msg,mimo_chan_num,with_header);
    
%     n_bit_frame = 10 ;
%     tx_bin = [ 1,0,1,0,1,1,0,0,1,0 ];

    %% ERROR generation.
    %receiver_power = 0.1 % no chan_err
    %%receiver_power = 0.01; % chan_err
    receiver_powers(3) = 0.01; % 0.1 - not work ;
    % generate error on chan 3


    %% SISO 
     
	[t_signal_sec, tx_bin_signal, tx_sym, tx_signal,rx_signal, rx_signal_conv,rx_signal_awgn_with_delay] = ...
        vlc_frame_to_signal(modulation,Rb,Fs,n_bit_frame, tx_bin,impulse_response,snr,tx_amplitude,receiver_power_siso);
    
    
    t_signal_sec_mimo = zeros(4,1);
    t_signal_sec_mimo_fix = zeros(4,1);
    %% MIMO
    [t_signal_sec_mimo, tx_bin_signal_mimo, tx_sym_mimo, tx_signal_mimo,rx_signal_mimo, rx_signal_conv_mimo,rx_signal_awgn_with_delay_mimo] = ...
            vlc_frame_to_signal_mimo(modulation,Rb,Fs,n_bit_mimo_frame, tx_bin_mimo,impulse_response,snr,tx_amplitude,receiver_powers);
    %% MIMO Fix    
    [t_signal_sec_mimo_fix, tx_bin_signal_mimo_fix, tx_sym_mimo_fix, tx_signal_mimo_fix,rx_signal_mimo_fix, rx_signal_conv_mimo_fix,rx_signal_awgn_with_delay_mimo_fix] = ...
            vlc_frame_to_signal_mimo(modulation,Rb,Fs,n_bit_mimo_fix_frame, tx_bin_mimo_fix,impulse_response,snr,tx_amplitude,receiver_powers);
        
    %% SISO     

    [rx_signal_recostructed ,rx_sym,rx_bin,rx_coding_error,rx_coding_error_total,rx_sym_signal,rx_bin_signal,chan_err ] = ...
        vlc_signal_to_frame(modulation,Rb,Fs,n_bit_frame,mimo_chan_num,rx_signal_awgn_with_delay);
    
     if rx_coding_error_total > 0 
         fprintf('Error on SISO');
         %warning('Error on SISO')
     end 
    
    %% MIMO
    [rx_signal_recostructed_mimo ,rx_sym_mimo,rx_bin_mimo,rx_coding_error_mimo,rx_coding_error_total_mimo,rx_sym_signal_mimo,rx_bin_signal_mimo, mimo_chan_err ] = ...
        vlc_signal_to_frame_mimo(modulation,Rb,Fs,n_bit_mimo_frame,mimo_chan_num,rx_signal_awgn_with_delay_mimo,'rx_level_detector_1_sample_per_symbol');    
        
    if sum(rx_coding_error_total_mimo) > 0 
        fprintf('Error on MIMO');
        %warning('Error on SISO')
    end 
     
    %% MIMO FIX

    [rx_signal_recostructed_mimo_fix ,rx_sym_mimo_fix,rx_bin_mimo_fix,rx_coding_error_mimo_fix,rx_coding_error_total_mimo_fix,rx_sym_signal_mimo_fix,rx_bin_signal_mimo, mimo_fix_chan_err ] = ...
        vlc_signal_to_frame_mimo(modulation,Rb,Fs,n_bit_mimo_fix_frame,mimo_chan_num,rx_signal_awgn_with_delay_mimo_fix,'rx_level_detector_1_sample_per_symbol');    

    %% remove header - extract MSG  / recoverer with parity channel
    [rx_bin_msg,rx_bin_crc,rx_bin_mimo_msg,rx_bin_mimo_crc,rx_bin_mimo_fix_msg,rx_bin_mimo_fix_crc,rx_bin_mimo_fix_recoverd] = ...
        vlc_decode_frame(n_byte_msg,mimo_chan_num, with_header,rx_bin, rx_bin_mimo, rx_bin_mimo_fix,mimo_chan_err,mimo_fix_chan_err);
    
    %% SISO display
    siso_title = modulation +" Rb=" + Rb + " Fs="+ Fs + " Led Num=" + 1 + " Tx/Rx distance=" + LED_height_distance + " Theta="  + LED_theta + " SNR="  + snr + " Received Power="+receiver_power_siso;
    vlc_draw_tx_rx_signal(siso_title,t_signal_sec,tx_bin,tx_bin_signal,tx_signal,rx_signal,rx_signal_awgn_with_delay(1:length(rx_signal)),rx_sym_signal,rx_bin_signal);
    
    %% Frame level
    %[sym_errors, sym_error_ratio] =  symerr(tx_sym, rx_sym);
    [bit_errors, bit_error_ratio] =  symerr(tx_bin, rx_bin);
    
    %[sym_errors_mimo, sym_error_ratio_mimo] =  symerr(tx_sym_mimo, rx_sym_mimo);
    [bit_errors_mimo, bit_error_ratio_mimo] =  symerr(tx_bin_mimo, rx_bin_mimo);
    
    % befor recovered
    [bit_errors_mimo_fix, bit_error_ratio_mimo_fix] =  symerr(tx_bin_mimo_fix, rx_bin_mimo_fix);
    
    % after recovered 
    [bit_errors_mimo_fix_recovered, bit_error_ratio_mimo_fix_recovered] =  symerr(tx_bin_mimo_fix, rx_bin_mimo_fix_recoverd);
    
     return
 end
%%

function [P_block_total,h1,h2,h3,h4] = vlc_rx_power_pola_panel_test(N_led,led_loc_offset,h,led_power,theta,show_figure)

    %%%%%%% 실험 공간의 거리 설정 
    % 솔라패널이 1x1 이라고 하면 16 개의 패널이 사용된다.
    lx=4; 
    ly=4;
    lz=3;
    % 수신단의 높이
    %h=2.15;
    
    %%%%%%% 송신단 설정
    %N_led = 1;
    %led_power = 1;
    P_LED = led_power;
    % 0 점으로 부터 50cm 거리에 위치한다.
    x_loc = led_loc_offset;
    y_loc = led_loc_offset;
    % 각 LED 간의 x,y 각각의 거리
    x_distance = x_loc *2 ;
    y_distance = y_loc *2 ;

    %%theta = 7;
    %theta = 15;
    
    %%%%%%% 수신단 설정
    %FOV_deg is meaning less for solar panel
    %FOV_deg = 10
    FOV_deg=60;
    %FOV_deg=180
    
    % PD 가로/세로 길이
    Adet_1d = 1e-1; % 10cm
    % 솔라패널 하나는 가로/세로로 PD 20개로 묶음 - 여기서는 1M가 된다.
    block_1d = 10; % 10cm * 10 = 1m 


    P_LED1 = 0;
    P_LED2 = 0;
    P_LED3 = 0;
    P_LED4 = 0;
            
    x1_pos = 0;
    y1_pos = 0;
    x2_pos = 0;
    y2_pos = 0;
    x3_pos = 0;
    x3_pos = 0;
    y3_pos = 0;
    x4_pos = 0;
    y4_pos = 0;
            
    switch N_led
           
        case 1
            P_LED1 = led_power;
            
            x1_pos = -x_loc ;
            y1_pos = -y_loc ;
            
        case 1000
            P_LED1 = led_power;
            
        case 2
            % same y
            P_LED1 = led_power;
            P_LED2 = led_power;

            x1_pos = -x_loc;
            y1_pos = 0;
            x2_pos = x_loc;

        case 2000  
            % same x 
            P_LED1 = led_power;
            P_LED2 = led_power;

            x1_pos = 0;
            y1_pos = -y_loc;
            x2_pos = 0;
            y2_pos = y_loc;
            
        case 4
            P_LED1 = led_power;
            P_LED2 = led_power;
            P_LED3 = led_power;
            P_LED4 = led_power;

            x1_pos = -x_loc;
            y1_pos = -y_loc;
            x2_pos = x_loc;
            y2_pos = -y_loc;
            x3_pos = -x_loc;
            y3_pos = y_loc;
            x4_pos = x_loc;
            y4_pos = y_loc;

        otherwise
            warning('Only support 1,2,4 LEDs')
            return
    end

    %% 솔라패널의 위치를 바꾸어야 한다.
    
    %% 실험 
    % if P_LED1 > 0 
        [x,y, P_rec1, P_rec_dBm1,P_block_total1,H_A1] = vlc_rx_power_pola_panel(P_LED1,theta,Adet_1d,block_1d,x1_pos,y1_pos,FOV_deg,lx,ly,lz,h );
    %     P_rec = P_rec1;
    %     P_rec_dBm = P_rec_dBm1;
    %     H_A = H_A1;
    %     P_block_total = P_block_total1;
    % end
    % if P_LED2 > 0 
        [x,y, P_rec2, P_rec_dBm2,P_block_total2,H_A2] = vlc_rx_power_pola_panel(P_LED2,theta,Adet_1d,block_1d,x2_pos,y2_pos,FOV_deg,lx,ly,lz,h );
    %     P_rec = P_rec2;
    %     H_A = H_A2;
    %     P_block_total = P_block_total2;
    % end 
    % if P_LED3 > 0 
        [x,y, P_rec3, P_rec_dBm3,P_block_total3,H_A3] = vlc_rx_power_pola_panel(P_LED3,theta,Adet_1d,block_1d,x3_pos,y3_pos,FOV_deg,lx,ly,lz,h );
    %     P_rec = P_rec3
    %     P_rec_dBm = P_rec_dBm3;
    %     H_A = H_A3;
    %     P_block_total = P_block_total3;
    % end 
    % if P_LED4 > 0 
        [x,y, P_rec4, P_rec_dBm4,P_block_total4,H_A4] = vlc_rx_power_pola_panel(P_LED4,theta,Adet_1d,block_1d,x4_pos,y4_pos,FOV_deg,lx,ly,lz,h );
    %     P_rec = P_rec4;
    %     P_rec_dBm = P_rec_dBm4;
    %     H_A = H_A4;
    %     P_block_total = P_block_total4;
    % end 

    P_rec = P_rec1 + P_rec2 + P_rec3 + P_rec4;
    P_rec_dBm = P_rec_dBm1 + P_rec_dBm2 + P_rec_dBm3 + P_rec_dBm4;
    H_A = H_A1 + H_A2 + H_A3 + H_A4;
    P_block_total = P_block_total1 + P_block_total2 + P_block_total3 + P_block_total4;
    % 전체 LED 송신 파워 총합
    P_LED = P_LED1 + P_LED2 + P_LED3 + P_LED4 ;
    % 모든 패널에서 흡수한 파워 총합
    P_block_total_sum = sum(sum(P_block_total));
    
    % 전달함수는 각 패널기준으로 어디에 영향을 받는지의 비율이다.
    h1 = P_block_total1./P_block_total;
    h2 = P_block_total2./P_block_total;
    h3 = P_block_total3./P_block_total;
    h4 = P_block_total4./P_block_total;
    % 따라서 모든 셀에서 모든 LED 의 영향을 더하면 1이 된다.
    h_total = h1 + h2 + h3 + h4;

    %% 그래프 
    
    %%%%%%%%%%%% 각 PD 기준으로 dBm
    %{
    figure
    meshc(x,y,P_rec_dBm);
    xlabel('X (m)');
    ylabel('Y (m)');
    zlabel('Received power (dBm)');
    axis([-lx/2 lx/2 -ly/2 ly/2 min(min(P_rec_dBm)) max(max(P_rec_dBm))]);

    formatSpec = 'theta=%d;Ptotal=%d;FOVdeg=%d;lx=%d;ly=%d;lz=%d;h=%d;';
    str = sprintf(formatSpec,theta,P_LED,FOV_deg,lx,ly,lz,h);
    title({'LOS Channel Gain - dBm', str})
    %}
    
    %%%%%%%%%%% 각 PD 기준으로 dB
    if show_figure ~= true
        return
    end 
    
    figure
    meshc(x,y,P_rec);
    xlabel('X (m)');
    ylabel('Y (m)');
    zlabel('Received power ');
    axis([-lx/2 lx/2 -ly/2 ly/2 min(min(P_rec)) max(max(P_rec))]);

    formatSpec = 'theta=%d;Ptotal=%d;FOVdeg=%d;lx=%d;ly=%d;lz=%d;h=%d;';
    str = sprintf(formatSpec,theta,P_LED,FOV_deg,lx,ly,lz,h);
    title({'LOS Channel Gain - dB', str})

    %%%%%%%%%%% 솔라패널
    bar3_x_tick = -x_loc - x_distance : x_distance : x_loc + x_distance;
    bar3_y_tick = y_loc + y_distance : -y_distance : - y_loc - y_distance;    
    
    figure
    % mirror Y
    P_block_total_display = flipud(P_block_total);
    h_p = bar3(P_block_total_display);
    hh_p = get(h_p(3),'parent');
    ax = gca;
    ax.YLabel.String = 'Y Axis';
    ax.YLabel.FontSize = 16;
    ax.XLabel.String = 'X Axis';
    ax.XLabel.FontSize = 16;
    ax.ZLabel.String = 'Power';
    ax.ZLabel.FontSize = 16;
    ax.Title.String = 'Solar Panel';
    ax.Title.FontSize = 16;
    
    %set(hh_p,'yticklabel',[1.5 0.5 -0.5 -1.5 ]);
    %set(hh_p,'xticklabel',[-1.5 -0.5 0.5 1.5 ]);
    set(hh_p,'yticklabel',bar3_y_tick);
    set(hh_p,'xticklabel',bar3_x_tick);   
    
    % https://kr.mathworks.com/matlabcentral/answers/437532-how-to-add-text-to-3-d-bar-chart-bar3-on-the-top-of-each-bar
    
    

    %%%%%%%%% 솔라패널 MIMO 전달함수
    figure
    subplot(2,2,1)
    % mirror Y
    P_block_total_display_h1 = flipud(h1);
    h_p1 = bar3(P_block_total_display_h1);
    hh_p1 = get(h_p1(3),'parent');
    set(hh_p1,'yticklabel',bar3_y_tick);
    set(hh_p1,'xticklabel',bar3_x_tick); 
    title('H1');  
    
    subplot(2,2,2)
    % mirror Y
    P_block_total_display_h2 = flipud(h2);
    h_p2 = bar3(P_block_total_display_h2);
    hh_p2 = get(h_p2(3),'parent');
    set(hh_p2,'yticklabel',bar3_y_tick);
    set(hh_p2,'xticklabel',bar3_x_tick);   
    title('H2');  
    
    subplot(2,2,3)
    % mirror Y
    P_block_total_display_h3 = flipud(h3);
    h_p3 = bar3(P_block_total_display_h3);
    hh_p3 = get(h_p3(3),'parent');
    set(hh_p3,'yticklabel',bar3_y_tick);
    set(hh_p3,'xticklabel',bar3_x_tick); 
    title('H3');
    
    subplot(2,2,4)
    % mirror Y
    P_block_total_display_h4 = flipud(h4);
    h_p4 = bar3(P_block_total_display_h4);
    hh_p4 = get(h_p4(3),'parent');
    set(hh_p4,'yticklabel',bar3_y_tick);
    set(hh_p4,'xticklabel',bar3_x_tick); 
    title('H4');
    
    %%%%%%%%%%% 솔라셀 별로
    figure
    bar3(H_A1);
    H_A1_display = flipud(H_A);
    h_h = bar3(H_A1_display);
    hh_h = get(h_h(3),'parent');
    set(hh_h, 'XLim', [0 40]);
    set(hh_h, 'YLim', [0 40]);


end
%%

function [x,y, P_rec, P_rec_dBm,P_block_total,H_A1 ] = vlc_rx_power_pola_panel(P_LED,theta,Adet_1d,block_1d,x_pos,y_pos,FOV_deg,lx,ly,lz,h )
    index=1;
    m=-log10(2)/log10(cosd(theta));
    Adet = Adet_1d^2; % 10cm*10cm
    Ts=1;
    FOV=FOV_deg*pi/180; 
    %G_Con=(index^2)/sin(FOV);
    G_Con = 1; % ignore it - this cause result more than p_LED
    % position of LED;
    %Nx=lx*grid_num; Ny=ly*grid_num;
    % number of grid in the receiver plane
    %x=-lx/2:lx/Nx:lx/2;
    %y=-ly/2:ly/Ny:ly/2;
    x = (-lx/2) + (Adet_1d/2) :  Adet_1d : (lx/2) - (Adet_1d/2);
    y = (-ly/2) + (Adet_1d/2) :  Adet_1d : (ly/2) - (Adet_1d/2);

    [XR,YR]=meshgrid(x,y);
    D1=sqrt((XR-x_pos).^2+(YR-y_pos).^2+h^2);
    cosphi_A1=h./D1;
    H_A1=(m+1)*Adet.*cosphi_A1.^(m+1)./(2*pi.*D1.^2);
    P_rec=P_LED.*H_A1.*Ts.*G_Con;

    if (P_LED > 0) 
        P_rec_dBm=10*log10(P_rec);
    else
        P_rec_dBm=P_rec;
        H_A1=P_rec;
    end    
    P_rec_sum = sum(sum(P_rec));

    %%% sum 
    fun_sum = @(x) sum(sum(x));
    fun_sum2 = @(block_struct) sum(sum(blockStruct.data));
    P_block_sum = blkproc(P_rec, [ block_1d , block_1d ], fun_sum);
    % 동작안함.
    %P_block_sum1 = blockproc(P_rec, [ block_1d , block_1d ], fun_sum2)
    
    %%% mean
    % B = mean2(A) computes the mean of all values in array A.
    P_block_avg = blkproc(P_rec, [ block_1d , block_1d ], 'mean2');
    
    P_block_avg_sum = sum(sum(P_block_avg));
    P_block_total = P_block_avg * block_1d * block_1d;
    P_block_total_sum = sum(sum(P_block_total));
    
    %diff_value = sum(sum(P_block_sum - P_block_total )) ;
    %if diff_value ~= 0  
    %    warning('total power of solar panel is different to sum of PD ')
    %end
        
    if abs(P_rec_sum - P_block_total_sum) > 0.001
        % warning('total power of solar panels are different to sum of PD ')
        fprintf('total power of solar panels are different to sum of PD \n');
        fprintf('P_rec_sum = %1.4f  P_block_total_sum = %1.4f \n',P_rec_sum,P_block_total_sum);
    end
end

%% 
function NRZ_Encoder_test()

    % % input 값을 먼저 정하기
    % input = [ 0,1,0,1,0,0,1,1,0,1,1,1 ]
    % 
    % %numBits = size (input,2 )  % 1 - row  2 - column 
    % numBits = length(input)

    % 크기 먼저 정하기
    numBits = 40 
    input=randi([0 1], numBits, 1);

    % 비트레이트
    Rb = 1
    % 크기
    amplitude = 1
    % 라인코딩 방식
    style = 'manchester_uni'
    % 그리기 좋게 
    %sample_b = 10 
    % RZ 이 있으므로 최소 2는 되어야 한다. 화면에 보여지는 그래프는 삼각형으로 보인다.
    sample_b = 2

    [time,output,Fs]=NRZ_Encoder(input,Rb,amplitude,style,sample_b)

    figure(1)
    stem(input, 'linewidth',3)
    grid on;
    title('  Information before Transmiting ');
    % axis([ 0 numBits 0 1.5]);

    figure(2)
    plot(time,output)
    grid on;
    title(' After Line Coding ');
    xlabel('time(sec)');
    ylabel(' amplitude(volt0');

end 


%%
function [time,output,Fs]=NRZ_Encoder(input,Rb,amplitude,style,sample_b)


% C:\nobackup\_???_????_??\___vlc_ebook\Mathuranathan_Viswanathan_SIMULATION_OF (1).pdf

% NRZ_Encoder Line codes encoder
%[time,output,Fs]=NRZ_Encoder(input,Rb,amplitude,style)
%NRZ_Encoder NRZ encoder
%{
Input a stream of bits and specify bit-Rate, amplitude of the output signal and the style of encoding
Currently 3 encoding styles are supported namely 'Manchester','Unipolar'and 'Polar'.Outputs the NRZ
stream
%}

    Fs=sample_b*Rb; %Sampling frequency ,oversampling factor= 32
    Ts=1/Fs; % Sampling Period
    Tb=1/Rb; % Bit period
    output=[];



    switch lower(style)
        case {'manchester'}
            % 0 => 1 -1
            % 1 => -1 1
            for count=1:length(input),
                for tempTime=0:Ts:Tb/2-Ts,
                    output=[output (-1)^(input(count))*amplitude];
                    % -1^0 = 1 
                    % -1^1 = -1

                end
                for tempTime=Tb/2:Ts:Tb-Ts,
                    output=[output (-1)^(input(count)+1)*amplitude];
                    % -1^(0+1)= -1
                    % -1^(1+1)=-1^2=1
                end
            end

        case {'manchester_uni'}
            % 0 => 1 0   
            % 1 => 0 1
            for count=1:length(input),
                for tempTime=0:Ts:Tb/2-Ts,
                    output=[output abs((-1)+(input(count)))*amplitude];
                    % -1+0 = 1 
                    % -1+1 = 0
                end
                for tempTime=Tb/2:Ts:Tb-Ts,
                    output=[output (1)*(input(count))*amplitude];
                    % 1*0 = 0 
                    % 1*1 = 1
                end
            end        
        case {'unipolar'}
            for count=1:length(input),
                for tempTime=0:Ts:Tb-Ts,
                    output=[output input(count)*amplitude];
                end
            end
        case {'polar'}
            for count=1:length(input),
                for tempTime=0:Ts:Tb-Ts,
                    output=[output amplitude*(-1)^(1+input(count))];
                end


            end
        otherwise,
            disp('NRZ_Encoder(input,Rb,amplitude,style)-Unknown method given as ''style'' argument');
            disp('Accepted Styles are ''Manchester'', ''Unipolar'' and ''Polar''');
    end
    time=0:Ts:Tb*length(input)-Ts;
end    
   
%% 심볼만 가져오는 함수 
function output = NRZ_EncoderToSymbol(input,amplitude,style)
    output=[];

    switch lower(style)
        case {'manchester'}
            % 0 => 1 -1
            % 1 => -1 1
            for count=1:length(input),
                    output=[output (-1)^(input(count))*amplitude];
                    % -1^0 = 1 
                    % -1^1 = -1
                    output=[output (-1)^(input(count)+1)*amplitude];
                    % -1^(0+1)= -1
                    % -1^(1+1)=-1^2=1
            end

        case {'manchester_uni'}
            % 0 => 1 0   
            % 1 => 0 1
            for count=1:length(input),
                output=[output abs((-1)+(input(count)))*amplitude];
                    % -1+0 = 1 
                    % -1+1 = 0
                output=[output (1)*(input(count))*amplitude];
                % 1*0 = 0 
                % 1*1 = 1
            end        
        case {'unipolar'}
            for count=1:length(input),
                    output=[output input(count)*amplitude];
                    output=[output input(count)*amplitude];
            end
        case {'polar'}
            for count=1:length(input),
                    output=[output amplitude*(-1)^(1+input(count))];
                    output=[output amplitude*(-1)^(1+input(count))];
            end
        otherwise,
            disp('NRZ_Encoder(input,Rb,amplitude,style)-Unknown method given as ''style'' argument');
            disp('Accepted Styles are ''Manchester'', ''Unipolar'' and ''Polar''');
    end
end    

%%
function DrawAnalogModulation(t,messageSignal,carrierSignal,modulatedSignal,title1,title2,title3)

    subplot(3,1,1);%Plotting frame divided in to 3 rows and this fig appear at 1st
    plot(t,messageSignal);
    xlabel('Time');
    ylabel('Amplitude');
    title(title1);
    grid on;
    subplot(3,1,2);
    plot(t,carrierSignal);
    xlabel('Time');
    ylabel('Amplitude');
    title(title2);
    grid on;
    subplot(3,1,3);
    plot(t,modulatedSignal);
    xlabel('Time');
    ylabel('Amplitude');
    title(title3);
    grid on;

end

%%
function Manchester2Bin_test()
    % 01 => 1
    % 10 => 0
    decodedDataString = ManchesterString2BinString('01011010')
    
    manchesterVector = [0,1,0,1,1,0,1,0]
    % '1100'
    decodedDataVector = Manchester2Bin(manchesterVector)
    encodedDataVector = Bin2Manchester(decodedDataVector)
end 

%%
function [ decodedData ]      = ManchesterString2BinString(inputData)
%   ManchesterString2BinString(inputData) decodes a manchester serial
%   sequence to its corresponding binary value.
%
%   Decoding is done according to G.E. Thomas' convention 
%   (high-to-low '01' = '1', low-to-high '10'= 0), assuming LSB first
%   transmission.
%
%   Syntax: decodedData = MANCHESTER2BIN(inputData) 
%
%   Where:
%   inputData   =    string with binary values which length must be EVEN,
%                    with the MSB at at the left-most position (index = 1)
%   decodedData =    string with binary values which length is half of
%                    inputData with the MSB at the left-most position
%
%   If the inputData sequence is not a valid manchester code MANCHESTER2BIN
%   will return an empty string. 
%
%   Example: 
%       >>decodedData = manchester2bin('01011010')
%       
%       decodedData =
%       1100
%
%   Other m-files required: none
%   Subfunctions: none
%   MAT-files required: none
%
%   Author: Robert Brookhuis
%   email: r.a.brookhuis(at)gmail.com 
%   MAR 2009; Last revision: 02-Mar-2009

    nBits = length(inputData); % length of inputData

    % preallocate decodedData as array of doubles, for speed. Faster than
    % handling strings. Array is converted to string after decoding. 
    decodedData = ones(1,nBits/2); 

    if mod(nBits,2)~=0 % check if array is even, otherwise generate error
        error('Length of array must be even')
    end

    for i = nBits:-2:2 % count from max. size downwards with steps of 2
        if inputData(i) ~= inputData(i-1) % if bits are unequal
            decodedData(i/2) = inputData(i); % the first bit is the binary value
        else
            decodedData = []; %if bits are equal, it's not manchester code 
            break %exit for loop
        end
    end

    decodedData = char(decodedData); %cast decodedData back to string
end 

%%
function [decodedData,error] = Rz2Bin(inputData)
    [rows,nBits] = size(inputData);
    %nBits = length(inputData); % length of inputData
    decodedData = ones(1,nBits/2); 
    error = ones(1,nBits/2); 

    if mod(nBits,2)~=0 % check if array is even, otherwise generate error
        error('Length of array must be even')
    end

    for row = 1: rows
        % 뒤에서 부터 
        for i = nBits:-2:2 % count from max. size downwards with steps of 2
            % 뒤 비트는 항상 0 이어야 한다.
            if inputData(i) == 0 % 
                % 앞비트를 그냥 저장 
                decodedData(i/2) = inputData(i-1); % e
                error(i/2) = 0;
            else
                decodedData(i/2) = 1;
                error(i/2) =1;
            end
        end
    end
end 
%%
function [decodedData,error] = Manchester2Bin(inputData)
    [rows,nBits] = size(inputData);
    %nBits = length(inputData); % length of inputData
    decodedData = ones(1,nBits/2); 
    error = ones(1,nBits/2); 

    if mod(nBits,2)~=0 % check if array is even, otherwise generate error
        error('Length of array must be even')
    end

    for row = 1: rows
        % 뒤에서 부터 
        for i = nBits:-2:2 % count from max. size downwards with steps of 2
            % 두비트는 서로 달라야 한다.
            if inputData(i) ~= inputData(i-1) % if bits are unequal
                % 뒤비트를 그냥 저장  01 =>  1    10 => 0 
                decodedData(i/2) = inputData(i); % the first bit is the binary value
                error(i/2) = 0;
            else
                %decodedData = []; %if bits are equal, it's not manchester code 
                %break %exit for loop
                if inputData(i-1) == 0 
                    decodedData(i/2) = 1;
                else 
                    decodedData(i/2) = 1;
                end
                error(i/2) =1;
            end
        end
    end
end 
%%

function [ encodedData ] = Bin2Rz(inputData)
    nBits = length(inputData); % length of inputData
    [rows,nBits] = size(inputData);
    encodedData = ones(rows,nBits*2); 

    for row = 1: rows
        for i = 1:1:nBits % count from max. size downwards with steps of 2
                encodedData(i*2-1) = inputData(i); % 앞의 비트는 입력 신호 그대로 
                encodedData(i*2) =  0; % 뒤 비트는 0 
        end
    end
   
end

% function [ encodedData ] = Bin2Manchester(inputData)
%     nBits = length(inputData); % length of inputData
%     encodedData = ones(0,nBits*2); 
% 
%     for i = 1:1:nBits % count from max. size downwards with steps of 2
%             encodedData(i*2-1) = abs ( 1 - inputData(i)); % 앞 비트를 반전함 
%             encodedData(i*2) = inputData(i);  % 뒤 비트를 가져옴 01 => 1
%     end
% end 

function [ encodedData ] = Bin2Manchester(inputData)
    nBits = length(inputData); % length of inputData
    [rows,nBits] = size(inputData);
    encodedData = ones(rows,nBits*2); 

    for row = 1: rows
        for i = 1:1:nBits % count from max. size downwards with steps of 2
                encodedData(row,i*2-1) = abs ( 1 - inputData(row,i)); % 앞 비트를 반전함 
                encodedData(row,i*2) = inputData(row,i);  % 뒤 비트를 가져옴 01 => 1
        end
    end 
end 

%%
function Led_los_power_test()
    semi_angle = 70
    total_power = 10
    room_dimension_x = 5
    room_dimension_y = 5
    room_dimension_z = 5
    distance_from_source = 1
    show_power = true
    show_h = true

    peak = Led_los_power( semi_angle , total_power, room_dimension_x, room_dimension_y, room_dimension_z, distance_from_source, show_power, show_h )
end 

%%
function peak = Led_los_power( semi_angle , total_power, room_dimension_x, room_dimension_y, room_dimension_z, distance_from_source, show_power, show_h )
%
%   theta : LED ±¤°¢µµ - semi anglie
%   total_power : 20
%   room_x_sie ; 5 5 3  meter
%   FOV of receiver : 60 degree
%
%
%
%

    theta=semi_angle;
    % semi-angle at half power
    m=-log10(2)/log10(cosd(theta));
    %Lambertian order of emission - m= -ln 2 / ln cos (theta : 1/2 power )
    P_total=total_power; %20;
    %transmitted optical power by individual LED
    Adet=1e-4;
    %detector physical area of a PD
    Ts=1;
    %gain of an optical filter; ignore if no filter is used
    index=1.5;
    %refractive index of a lens at a PD; ignore if no lens is used
    piiii = pi;
    FOV=60*pi/180;
    %FOV of a receiver
    G_Con=(index^2)/sin(FOV);
    %gain of an optical concentrator; ignore if no lens is used
    %lx=5; ly=5; lz=3;
    lx=room_dimension_x; ly=room_dimension_y; lz=room_dimension_z;
    % room dimension in metre
    %h=2.15;
    h = distance_from_source;
    %the distance between source and receiver plane
    %[XT,YT]=meshgrid([-1.25 1.25],[-1.25 1.25]);
    XT=0; YT=0;
    % position of LED;
    Nx=lx*10; Ny=ly*10;
    % number of grid in the receiver plane
    x=-lx/2:lx/Nx:lx/2;
    y=-ly/2:ly/Ny:ly/2;
    [XR,YR]=meshgrid(x,y);
    % receiver plane grid84 Optical Wireless Communications
    D1=sqrt((XR-XT(1,1)).^2+(YR-YT(1,1)).^2+h^2);
    % distance vector from source 1
    cosphi_A1=h./D1;
    % angle vector
    H_A1=(m+1)*Adet.*cosphi_A1.^(m+1)./(2*pi.*D1.^2);
    % channel DC gain for source 1  ----
    P_rec=P_total.*H_A1.*Ts.*G_Con;
    % received power from source 1;
    P_rec_dBm=10*log10(P_rec);
    peak = max(max(P_rec_dBm));

    if show_power
        figure;
        meshc(x,y,P_rec_dBm);

       % title( [' Theta =',numstr(theta), ' distance =',numstr(distance_from_source), ' ']);
        xlabel('X (m)');
        ylabel('Y (m)');
        zlabel('Received power (dBm)');
        axis([-lx/2 lx/2 -ly/2 ly/2 min(min(P_rec_dBm)) max(max(P_rec_dBm))]);
        colorbar;
    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if show_h
        figure;
        meshc(x,y,H_A1);
        %hold on
        %meshc(x,y,D1);

        xlabel('X (m)');
        ylabel('Y (m)');
        zlabel('Impulse Response (dB)');
        %axis([-lx/2 lx/2 -ly/2 ly/2 min(min(H_A1), min(D1)) max(max(D1))]);
        colorbar;
        % hold off
    end

end

%%
function InverseSquareLawSimulation() 

    R = 1:1:50; % distance vector 
    F=1./R.^2; % force vector 
    plot(R,F) 
    grid 
    xlabel('RADIAL DISTANCE R')
    ylabel('FORCE F')

end

%%
function Led_los_test()

    theta=70;
    % semi-angle at half power
    m=-log10(2)/log10(cosd(theta));
    %Lambertian order of emission - m= -ln 2 / ln cos (theta : 1/2 power )
    P_total=20;
    %transmitted optical power by individual LED
    Adet=1e-4;
    %detector physical area of a PD
    Ts=1;
    %gain of an optical filter; ignore if no filter is used
    index=1.5;
    %refractive index of a lens at a PD; ignore if no lens is used
    piiii = pi;
    FOV=60*pi/180;
    %FOV of a receiver
    G_Con=(index^2)/sin(FOV);
    %gain of an optical concentrator; ignore if no lens is used
    lx=5; ly=5; lz=3;
    % room dimension in metre
    h=2.15;
    %the distance between source and receiver plane
    %[XT,YT]=meshgrid([-1.25 1.25],[-1.25 1.25]);
    XT=0; YT=0;
    % position of LED;
    Nx=lx*10; Ny=ly*10;
    % number of grid in the receiver plane
    x=-lx/2:lx/Nx:lx/2;
    y=-ly/2:ly/Ny:ly/2;
    [XR,YR]=meshgrid(x,y);
    % receiver plane grid84 Optical Wireless Communications
    D1=sqrt((XR-XT(1,1)).^2+(YR-YT(1,1)).^2+h^2);
    % distance vector from source 1
    cosphi_A1=h./D1;
    % angle vector
    H_A1=(m+1)*Adet.*cosphi_A1.^(m+1)./(2*pi.*D1.^2);
    % channel DC gain for source 1  ----    
    P_rec=P_total.*H_A1.*Ts.*G_Con;
    % received power from source 1;
    P_rec_dBm=10*log10(P_rec);
    %%%%%%%%%%%%%%%%
    figure(1)
    meshc(x,y,P_rec_dBm);
    xlabel('X (m)');
    ylabel('Y (m)');
    zlabel('Received power (dBm)');
    axis([-lx/2 lx/2 -ly/2 ly/2 min(min(P_rec_dBm)) max(max(P_rec_dBm))]);
    colorbar;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    figure(2)
    meshc(x,y,H_A1);
    %hold on
    %meshc(x,y,D1);

    xlabel('X (m)');
    ylabel('Y (m)');
    zlabel('Chanel DC Gain');
    %axis([-lx/2 lx/2 -ly/2 ly/2 min(min(H_A1), min(D1)) max(max(D1))]);
    colorbar;
    hold off
    %%%%%%%%%%%%%%%%%%%%%%%%
end
%%
function out = vlc_stream_by_Fs_single_vector(x, sampleFreq)
    out = x;
    if sampleFreq > 1 
       for i = 2:sampleFreq
        out = [out ; x];
       end

       % x*1
       %out = reshape(out,[],1);
       % 1*x
       out = reshape(out,1,[]);
    end
 

% not work
%     if sampleFreq > 1 
%        for i = 2:sampleFreq
%         out = [out x];
%        end
%     end
    
end 

function out = vlc_stream_by_Fs(x, sampleFreq)
    [rows,cols] = size(x); 
    out = zeros(0,0);
    for i=1:rows
        % x(i,:)
        z = vlc_stream_by_Fs_single_vector(x(i,:),sampleFreq);
        out =  [ out ; z ]; 
    end
end 


function impulse_responses = vlc_get_impulse_response( amplitude, loss, k, time_vector)

    [rows,cols] = size(amplitude); 
    impulse_responses = zeros(0,0);
    
    amp = 0.5;
    chan = amp*exp(-k*time_vector);  % Try applying different functions here.
    chan = [[0 0 0 0 0] chan];  % Change this array if you want to change the characteristics of channel
   
    % org 
%     chan = chan / chan(6);
    
    
    %pjr 
    chan_old = chan;
    chan_sum = sum(chan);
    chan = chan/sum(chan);
    
    for i=1:rows
        chan = chan * loss * amplitude(1,:)
        impulse_responses = [impulse_responses ; chan ];
    end
end 

function conv_ExponentialDecaying_new(x,sampleFreq,amplitude,loss,k,time_vector) 

    p_x = vlc_stream_by_Fs(x, sampleFreq)
    impulse_responses = vlc_get_impulse_response( amplitude, loss, k, time_vector)
    y = conv(p_x,impulse_responses);


    subplot(2,5,[1 2]);stem(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal"); grid on
    subplot(2,5,3);stem(impulse_responses,'MarkerFaceColor',[0 0 1]);axis([1 length(impulse_responses) -0.5 0.5]);title("impulse_responses"); grid on
    subplot(2,5,[4 5]);stem(y);axis([1 length(y) -1.5 1.5]);title("rx signal"); grid on
    subplot(2,5,[6 7]);plot(p_x);axis([1 length(p_x) -1.5 1.5]);title("tx signal"); grid on
    subplot(2,5,8);stem(impulse_responses,'MarkerFaceColor',[0 0 1]);axis([1 length(impulse_responses) -0.5 0.5]);title("impulse_responses"); grid on
    subplot(2,5,[9 10]);plot(y);axis([1 length(y) -1.5 1.5]);title("rx signal"); grid on
end
%%
%%

function block_average_test()
    x = randi(1000,399277,1);
    n = 1000;
    m = numel(x);
    out = nanmean(reshape( [x(:);nan(mod(-m,n),1)],n,[]));
    
    
    x = randi([0,1],100,1);
    x1 = [ 1 1 1 1 0 0 0 0 ]
    data_mean = block_average(x,[1 10],10)
    data_mean1 = block_average(x,[1 4],4)

end 

%%
% https://kr.mathworks.com/matlabcentral/fileexchange/41981-block-average-of-signal
function data_mean = block_average(data,start_end,shift)
    % 
    %USAGE
    %-----
    % data_mean = block_average(data,start_end)
    % data_mean = block_average(data,start_end,shift)
    % 
    % 
    %INPUT
    %-----
    % - DATA     : NxM matrix with M signals along the rows
    % - START_END: Bx2 matrix with the first and last elements to take the
    %   average
    % - SHIFT    : maximum number of data points to shift the elements in
    %   START_END to find the best match (greatest correlation coefficient).
    %   Only the first column in DATA is optimized. The same shift will be
    %   applied to all other columns. Default: 0
    % 
    % 
    %OUTPUT
    %------
    % - DATA_MEAN: average of DATA for the elements in START_END
    % 
    % 
    %EXAMPLE
    %-------
    % >> data_mean = block_average(data,[5 35;35 65;65 95],3);
    % 
    % Guilherme Coco Beltramini (guicoco@gmail.com)
    % 2013-Feb-25, 12:10 pm
    % Input
    %==========================================================================
    if isvector(data)
        data = data(:);
    end
    if nargin<3
        shift = 0;
    elseif ceil(shift)~=floor(shift)
        error('"SHIFT" must be integer')
    end
    if any(start_end(:,1)>start_end(:,2))
        error('The numbers in the 2nd column in "start_end" must be greater than the ones in the 1st column')
    end
    if any(start_end(:,1)<1)
        error('Invalid element. The smallest number must be 1')
        %start_end(start_end(:,1)<1,1) = 1;
    end
    if any(start_end(:,2)>size(data,1))
        error('Invalid element. The greatest number must be %d',size(data,1))
        %start_end(start_end(:,2)<size(data,1),2) = size(data,1);
    end
    % Number of data points must be the same
    if any(diff(start_end(:,2)-start_end(:,1)))
        error('The number of data points is not the same for all intervals')
    end
    % Find the best intervals
    %==========================================================================
    num_int   = size(start_end,1); % number of intervals
    data_mean = zeros(start_end(1,2)-start_end(1,1)+1,size(data,2),num_int);
    data_mean(:,:,1) = data(start_end(1,1):start_end(1,2),:);
    shift = abs(shift);
    for ii=2:num_int % loop for the intervals
        best = -1;
        for ss=-shift:shift
        % look for a better interval by shifting the interval back and forth

            tmp = (start_end(ii,1):start_end(ii,2)) + ss;
            if any(tmp(:,1)<1) || any(tmp(:,2)>size(data,1))
            % indices out of bounds
                continue
            end

            tmp = corrcoef(data_mean(:,1,1),data(tmp,1));
            tmp = tmp(2);
            if tmp>best
                best = tmp;
                data_mean(:,:,ii) = data( (start_end(ii,1):start_end(ii,2)) + ss,:);
            end

        end
    end
    % Calculate the average
    %==========================================================================
    data_mean = mean(data_mean,3);
end 
