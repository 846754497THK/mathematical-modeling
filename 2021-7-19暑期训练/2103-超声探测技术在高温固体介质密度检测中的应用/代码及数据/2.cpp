#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	double a;
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	for(int i=0;i<=300;i+=10){
		printf("%d,",i);
	}
	
	printf("\n\n");
	for(int i=0;i<=300;i++){
		scanf("%lf",&a);
		if(i%10==0)printf("%.8lf,",a);
	}

	return 0;
}
