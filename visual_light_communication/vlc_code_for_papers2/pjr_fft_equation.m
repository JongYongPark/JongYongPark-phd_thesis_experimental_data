% http://blog.naver.com/PostView.nhn?blogId=horgan&logNo=40018286782&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView

f=[0.00 1.40 2.80 4.20 4.40 3.00 1.60 0.20 -1.20 -2.60 -4.00 -4.60];
 
m=[1:3];
 
n=[0:11];
 
T=35;
 
G=sin(2*pi*(n')*(2*m-1)*T/500);
 
figure(1); clf;
 
c=(G'*G)\(f*G)';
 
n=[0:12*35-1]';
 
arg=2*pi*n/500;
 
fhat=[sin(arg) sin(3*arg) sin(5*arg)]*c;
 
plot(35*[0:11],f,'ok',n,fhat); grid
 
line(n,fhat,'color','k');
 
set(gca,'fontname','times','fontsize',18);
 
xlabel('t'); ylabel('signal, f(t)');


%%%%%%%%%%%%%%%%%
figure
N=50;
 
n=[0:N-1];
 
X=[zeros(1,28),ones(1,12),zeros(1,N-40)];
 
MM=[1 2 3 4 5 6];
 
for nfig=[1 2 3 4 5 6];
 
   M=MM(nfig);
 
   m=[0:M-1];
 
   % a and b coefficients. Note: b0=0 and a0/2 replaces a0.
 
   a=(2/N)*X*cos(2*pi*(n')*m/N);
 
   a(1)=a(1)/2;
 
   b=(2/N)*X*sin(2*pi*(n')*m/N);
 
   Xhat=a*cos(2*pi*(m')*n/N)+b*sin(2*pi*(m')*n/N);
 
   subplot(3,2,nfig);
 
   axis([0 50 -.5 1.5]);
 
   set(gca,'fontname','times','fontsize',14);
 
   line(n,X,'linestyle','-','Marker','x','color','k'); grid on;
 
   line(n,Xhat,'linestyle','none','Marker','o','color','k');
 
   text(7,1.3,['M=',int2str(M)],'fontname','times','fontsize',14);
 
    if nfig>4,
 
    xlabel('Sample number');
 
    end
 
end
 
set(gcf,'color',[1 1 1]);
