#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double p,c=400,k=50;
double Dt=0.001,Dx=0.0001;		//长度和时间的拆分间隔 
double limx=0.05,limt=10;		//长度和时间的限制条件 
double T[5000];					//记录当前的温度
double q[5000];					//记录当前的热流
double DT[5000];					//记录当前温度变化量 

double T0=373.15;

int main(){
	
	freopen("div1.txt","r",stdin);
	freopen("div2.txt","w",stdout);
	
	int xI=limx/Dx;		// 500
	int tI=limt/Dt;		// 10000
	
	//初始化
	for(int i=0;i<=xI;i++){
		T[i]=T0;
		q[i]=0;
		DT[i]=0;
	}
	
	while(~scanf("%lf",&p)){
		
		for(double t=0;t<=limt;t+=Dt){
			// 计算热流 
			q[0]= (1/300)*( pow(t+Dt,3)-pow(t,3) );
			for(int i=1;i<xI;i++){		//1-499
				q[i]=( T[i-1]-T[i] )/Dx*k;
			}
			q[500]=0;
			
			//计算温度变化量 
			for(int i=0;i<xI;i++){
				DT[i]=( q[i]-q[i+1] )/Dx/p/c*Dt;
			}
			
			//计算迭代温度
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
