#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double a[5520][105];	//Ԥ����������
double ans[5520][105];	//answer 
int main(){
	memset(ans,0,sizeof(ans));
	freopen("Autocorrelation_coefficient_in.txt","r",stdin);
	freopen("Autocorrelation_coefficient_out.txt","w",stdout);
	int tar[16]={4,7,11,17,20,21,23,41,47,57,65,71,72,73,76,96};
	//��Ŵ�1��ʼ 
	for(int i=1;i<=5519;i++){
		for(int j=1;j<=100;j++)scanf("%lf",&a[i][j]);
	}
	//��������	
	for(int J=1;J<=100;J++){
	
		//�����J������
		int c=1;
		double sum=0,y=0;
		//sum ���ڼ���ǰc���ͣ��Ա���ƽ���� 
		for(;c<=15;c++){
			sum+=a[c][J];
		} 
		
		//��ʮ����ʼ 
		for(;c<=5519;c++){
			sum+=a[c][J];
			y=sum/c;
			//�����ĸ�ϵ�var*c
			double deno=0;
			for(int i=1;i<=c;i++){
				deno+=( a[i][J] - y )*( a[i][J] - y );
			} 
			
			for(int k=1;k<=15;k++){
				double tmp=0;
				//tmp������ǰk�ӳ������µ������ϵ��
				for(int i=1;i<=c-k;i++){
					tmp+=(a[i][J]-y)*(a[i+k][J]-y)/deno;
				}
				ans[c][J]+=tmp/15;
			}
		}
	}
	for(int i=1;i<=5519;i++){
		for(int j=1;j<=100;j++){
			printf("%.10lf\t",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
