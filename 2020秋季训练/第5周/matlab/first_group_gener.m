%��ʾ��Χ�� d1=8/a  ��Ч��Χ�� d2=4/a;
a=4/59;
A=9.62*4;
x=-8/a:(8/a)/100:8/a;
X=x+1974
t=exp(1).^(-x.*a);
y=A.*t./(1.+t).^2;
plot(X,y);