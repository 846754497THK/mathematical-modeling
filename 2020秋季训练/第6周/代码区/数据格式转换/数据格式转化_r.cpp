#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n=28;
	double x[99];
	double E[99];
	double a[99];
	memset(x,0,sizeof(x));
	memset(a,0,sizeof(a));
	memset(E,0,sizeof(E));
	
	freopen("新建文本文档.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
	for(int i=1;i<=28;i++){
		string s;
		scanf("N=%lf\n",&x[i]);
	//	cout<<x[i]<<endl;
		cin>>s;
	//	cout<<s<<endl;
		for(int j=0;j<5;j++){
			double e,tmp;
			scanf("%lf%lf",&tmp,&e);
			E[i]+=e;
			a[i]+=tmp;
		}
		scanf("\n");
		a[i]/=5;
		E[i]/=5;
	}
	
	for(int i=1;i<=28;i++)printf("%.5lf\n",x[i]);
	printf("\n");
	for(int i=1;i<=28;i++)printf("%.5lf\n",a[i]);
	printf("\n");
	for(int i=1;i<=28;i++)printf("%.5lf\n",E[i]);
	printf("\n");
	
	return 0;
}
