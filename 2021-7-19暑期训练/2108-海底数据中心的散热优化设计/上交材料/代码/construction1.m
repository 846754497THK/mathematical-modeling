Rout=500
R=495.34
A=44.45
B=482.6
C=525
X=[0:0.1:0]
Y=[0:0.1:0]
viscircles([0 0],Rout,'Color','b','linewidth',0.2)
viscircles([0 0],R,'Color','r','linewidth',0.2)
% rectangle('Position',[0 0 400 200],'edgecolor','k','facecolor','g','linewidth',1)
% �˴�ѡ���̵ķ�ʽ
a=A
b=B

X(1)=- b*0.5
Y(1)=(R*R-X(1)*X(1))^0.5
n = 1

while Y-a >= -R
   n=n+1
   Y(n)=Y(n-1)-a
   X(n)=-(R*R-Y(n)*Y(n))^0.5
end
n=n-1
i =1
while i<n
    if X(i)<=X(i+1)
       x1=X(i+1)
       y1=Y(i+1)
       x2=x1+b
       y2=y1+a
       rectangle('Position',[x1 y1 b a],'edgecolor','k','facecolor','g')
    else
       x1=X(i)
       y1=Y(i)-a
       x2=x1+b
       y2=y1-a
       rectangle('Position',[x1 y1 b a],'edgecolor','k','facecolor','g')
    end
    i=i+1
end
rectangle('Position',[200 -300 a b],'edgecolor','g','facecolor','g')
axis equal
% ������
% rectangle('Position',[-20 -10 40 20],'edgecolor','k','facecolor','g','linewidth',1.8) 
% axis equal
% ����ת ����
% hg = hgtransform;
% rectangle('Position',[0,0,40,20],'Curvature',[0 0],'edgecolor','k','facecolor','y','parent',hg,'linewidth',2)
% hg.Matrix = makehgtform('zrotate',pi/6);	% ��ԭ�㣨z�ᣩ��ʱ����ת60��
% axis equal
%  ��Բ��
% viscircles([0 0],150,'Color','b');%Բ������Ϊ(0,0)���뾶Ϊ150,������ɫΪ��ɫ


