#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,n;
double r,sumn;
int L[50000];
double R[50000];
int a[50000];
int main(){
	int T;
	int cnt=0;
	freopen("�½��ı��ĵ�.txt","r",stdin);
	freopen("���l.txt","w",stdout);


		scanf("%d%lf",&N,&r);
		sumn=N*r;
		n=(int)sumn;
		for(int i=n+1;i*2<=N;i++)if(N%i==0){
			int p=N/i;
			a[cnt]=i;
			L[cnt]=n*p;
			R[cnt]=(double)1/p;
			cnt++;
		}
	for(int i=0;i<cnt;i++){
		printf("%d\n",L[i]);
	}
	freopen("���r.txt","w",stdout);
	for(int i=0;i<cnt;i++){
		printf("%.5lf\n",R[i]);
	}
	freopen("���a.txt","w",stdout);
	for(int i=0;i<cnt;i++){
		printf("%d\n",a[i]);
	}
	return 0;
	
}
