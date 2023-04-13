#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	double a[50];
	double var=0,ave=0;
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);

	for(int i=0;i<50;i++){
		scanf("%lf",&a[i]);
	}
	scanf("%lf%lf",&ave,&var);
	for(int i=0;i<50;i++){
		double dis=2*pow(var,0.5);
		if( abs(a[i]-ave)>dis )printf("%.4lf\t",ave);
		else printf("%.4lf\t",a[i]);
	}
	return 0;
}
