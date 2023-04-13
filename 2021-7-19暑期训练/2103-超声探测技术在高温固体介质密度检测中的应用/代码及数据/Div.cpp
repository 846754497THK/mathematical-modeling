#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double p,c=400,k=50;
double Dt=0.001,Dx=0.0001;		//���Ⱥ�ʱ��Ĳ�ּ�� 
double limx=0.05,limt=10;		//���Ⱥ�ʱ����������� 
double T[5000];					//��¼��ǰ���¶�
double q[5000];					//��¼��ǰ������
double DT[5000];					//��¼��ǰ�¶ȱ仯�� 

double T0=373.15;

int main(){
	
	freopen("div1.txt","r",stdin);
	freopen("div2.txt","w",stdout);
	
	int xI=limx/Dx;		// 500
	int tI=limt/Dt;		// 10000
	
	//��ʼ��
	for(int i=0;i<=xI;i++){
		T[i]=T0;
		q[i]=0;
		DT[i]=0;
	}
	
	while(~scanf("%lf",&p)){
		
		for(double t=0;t<=limt;t+=Dt){
			// �������� 
			q[0]= (1/300)*( pow(t+Dt,3)-pow(t,3) );
			for(int i=1;i<xI;i++){		//1-499
				q[i]=( T[i-1]-T[i] )/Dx*k;
			}
			q[500]=0;
			
			//�����¶ȱ仯�� 
			for(int i=0;i<xI;i++){
				DT[i]=( q[i]-q[i+1] )/Dx/p/c*Dt;
			}
			
			//��������¶�
			for(int i=0;i<xI;i++){
				T[i]=T[i]+DT[i];
			}
		}
		double sumT=0;
		for(int i=0;i<xI;i++){
			double v=(-0.4521)*T[i]+3383.391115;
			sumT+=Dx/v;
		}
		sumT*=2000000;
		printf("%.10lf\t\t%.5lf\n",p,sumT);
		
	}
	
	return 0;
}
