

clear all; close all; clc;

function rolling_shutter_test()
%% written by Muhammet Balcilar, France
    % all rights reserved


    % propeller rpm
    rpm=1000;
    % frame fps
    fps=30;
    % total frame number in video
    nframe=100;


    % pixel shutter time it shows how long does the pixel's taking light takes in unit of iteration.
    pshutter=0.3*12520;
    % pixel super resolution coef, how many step does the pixel light taking  divided
    % in time, 
    supres=50;
    % initial propeller angle
    ang=0;

    % propeller image
    pr=imread('Input/propeller.jpg');
    % propeller center
    center=[101 101] ;


    m=size(pr,1);
    n=size(pr,2);

    FC=rpm/(60*fps);
    vel=FC*2*pi/(m*n);

    zmn=zeros(m,n,supres);

    for iter=1:nframe
        iter    

        [X Y]=meshgrid(1:n,1:m);
        ocolor=[255 255 255];

        zmn(:,:,1)=mod(((Y-1)*n+(X-1))*vel +zmn(end,end,1),2*pi);
        for i=2:supres
            zmn(:,:,i)=zmn(:,:,1)+pshutter*vel/supres*(i-1);
        end       

        IMG=constructFrame(X,Y,ocolor,pr,center,zmn);  

        V{iter}=IMG;
        figure(1);imshow(uint8(round(IMG)))    
        pause(0.1)

    end


    v = VideoWriter('Output/demo.avi');

    open(v)

    for i=1:iter
        i
        writeVideo(v,uint8(V{i}));
    end
    close(v);
end 


function ocolor=constructFrame(X,Y,color,P,center,angle)
    %% written by Muhammet Balcilar, France
    % all rights reserved

    my=center(1);
    mx=center(2);

    N=size(P,1);
    M=size(P,2);

    R=color(1)*ones(size(angle));
    G=color(2)*ones(size(angle));
    B=color(3)*ones(size(angle));

    %ocolor=repmat(color,[size(angle,1) 1]);
    PR=P(:,:,1);
    PG=P(:,:,2);
    PB=P(:,:,3);


    yxY =Y-my;
    yxX =X-mx;

    dist=sqrt(yxY.^2+yxX.^2);
    ang=atan2(yxY,yxX)-angle;
    yyxY=sin(ang).*dist;
    yyxX=cos(ang).*dist;

    yyxY=round(yyxY+my);
    yyxX=round(yyxX+mx);

    yI=(yyxX-1)*N+yyxY;

    I=find(yyxY>0 & yyxY<=M & yyxX>0 & yyxX<=N);

    II=find(PB(yI(I))<100);

    R(I(II))=PR(yI(I(II)));
    G(I(II))=PG(yI(I(II)));
    B(I(II))=PB(yI(I(II)));

    R=mean(R,3);
    G=mean(G,3);
    B=mean(B,3);

    ocolor=R;
    ocolor(:,:,2)=G;
    ocolor(:,:,3)=B;
end

function rolling_shutter()
% https://electronics.stackexchange.com/questions/355741/rolling-shutter-effect-simulation-on-matlab

    close all;
    %% Propeller description 
    omega = 31; % Angular speed in rotations per second 
    length = 200; % Length of the blades in cm 
    width = 10; % Cross-section width in cm. (effective projection visible 
    from the camera. assumed constant.) 
    numBlades = 2; % number of blade pairs - assume even number of blades 
    discWidth = 0; 
    %% Camera description 
    frameSize = 600*[1 3/4]; % Width & height of the picture frame (in cm) 
    at the plane of the propeller (assuming the propeller is at the center 
    of the image) 
    sensorSize = 1024*[1 3/4]; % Sensor resolution in pixels 
    frameDuration = 1/30; % Time (in seconds) taken to scan all pixels in 
    the sensor 
    %% Initializations 
    initAngle = 0; % Initial orientation of the propeller. Can be assumed 
    to be anything without loss of generality. 
    numPixels = prod(sensorSize); % total number of pixels 
    tArrScan = [1:numPixels]'*frameDuration/numPixels; % Time instants at 
    which different pixels are sampled. Starting top-left. 
    % posPixels: position of the pixels. matrix of dimension numPixels x 2. 
    1 row for each pixel. 2 elements 
    % per pixel for X & Y coordinates. 
    posPixels = -0.5+[reshape(repmat([sensorSize(2):-1:1], sensorSize(1), 
    1), numPixels, 1)-sensorSize(2)/2 mod([0:numPixels-1]', 
    sensorSize(1))+1-sensorSize(1)/2]; 
    posPixels = posPixels*frameSize(1)/sensorSize(1); % scaling to 
    translate the pixels on plane of the propeller. 
    distPixels = abs(posPixels * [1 i]'); % distance of the pixels from the 
    center of the frame. 
    angPixels = angle(posPixels * [i 1]'); % distance of the pixels from 
    the center of the frame.
    figure(1);
    %k = 0;                        %%to record specified number offrames
    %filename='test'; % File name for video , you can change it 
    %combinedStr = strcat(filename,'.mp4');       %%combine name of video 
    to make it mp4
    %vidObj = VideoWriter(combinedStr,'MPEG-4');  %%create video object and 
    tells type of video here type is .mp4
    %vidObj.Quality = 100;         %%defines quality of video, more the 
    value better is quality (slower the process)
    %vidObj.FrameRate = 60;        %%defines frame rate of video to be 
    stored
    %open(vidObj);                 %%opens video object to record


    while 1
     %     %%Camera operation 

     img = zeros(numPixels,1); % initialization

     for kk=0:numBlades-1 % do for each balde 
    angleBlade = (2*pi/numBlades*kk)+initAngle+2*pi*mod(tArrScan*omega, 1); 
    % position of the blade when the pixels are being scanned. 
    distPixel2Blade = sum(posPixels .* [-cos(angleBlade) sin(angleBlade)], 
    2); % distance of the pixels (when they are scanned) from the axis of 
    the 
    blade 
     distPixel2PerpOrigin = sum(posPixels .* [sin(angleBlade) 
     cos(angleBlade)], 2); % distance of the pixels from the axis 
     perpendicular to the blade at origin 
        distPixel2PerpOutEnd = distPixel2PerpOrigin - length; % distance of 
    the 
    pixels from the axis perpendicular to the blade at the ouward end of 
    the 
    blade 
     pixelIsBesideTheBlade = (distPixel2PerpOrigin .* distPixel2PerpOutEnd) 
    <= 0; % Pixel is within the two ends of the blade 
     img = img+ min(abs(distPixel2Blade)<width, pixelIsBesideTheBlade); % 
    add 1 to the pixels that are: (1) within distance width/2 from the line 
    of 
    axis of the blade, and (2) within the two ends of the blade. 

     end 
     %figure; imagesc(min([reshape(img, sensorSize(1), 
    sensorSize(2))]',1)); 
    colormap(gray); axis equal; % convert the pixels to 2-D image 
    %% Create a video to show the results progressively 


     initAngle=initAngle+2*pi*mod(tArrScan(786432)*omega, 1);
     pause(1/100000); 
     imagesc(min([reshape(img, sensorSize(1), sensorSize(2))]',1)); 
     colormap(gray); axis equal;
    %     imagesc(min([reshape(tmpimg+scnimg+bldimg, sensorSize(1), sensorSize(2))]',1)); colormap(gray); axis equal; 
    %  imagesc(min([reshape(max(max(2*tmpimg,scnimg),bldimg), sensorSize(1), sensorSize(2))]',1)); colormap(gray); axis equal; 

    end

     %close(figure(1))
    %k=k+1

    %close(vidObj); %% close video object 

end 
