#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double X[105],r[105],h[105];
int cnt[105];

const double A=44.45,B=482.6,C=525;
const double R=500-46.6;
double a,b,c;
	
void init(){
	memset(X,0,sizeof(X));
	memset(r,0,sizeof(r));
	memset(h,0,sizeof(h));
	memset(cnt,0,sizeof(cnt));
	
	return;
}
void DO(int l1){		//当第一行放l1个时情况 
	init();
	int i=0;
	int sum=0; 
	int cntL=0;			//机箱总行数 
	printf("第一排放 %d 个：\n",l1);
	X[i]=b*l1;
	r[i]=R-sqrt( R*R - (X[i]/2)*(X[i]/2) );
	
	while( r[i]+a<2*R ){
		r[i+1]=r[i]+a;
		X[i+1]=2*sqrt( R*R - (R-r[i+1])*(R-r[i+1]) );
		cntL++;
		i++;
		cnt[i]=min(X[i-1],X[i])/b;
		sum+=cnt[i];
		h[i]=min(X[i-1],X[i]) - b*cnt[i];
		if(cnt[i]==0){
			cntL--;
			break;
		}
	
	}
	printf("共 %d 行, %d 块\n",cntL,sum);
	printf("---%.2lf---\n",X[0]);
	for(int j=1;j<=cntL;j++){
		printf("  %d   remain: %.2lf\n",cnt[j],h[j]);
		printf("---%.2lf---\n",X[j]);
	}
}
int main(){
	freopen("ABC.txt","w",stdout);
	//先确定摆放方法 
	a=A,b=B,c=C;
	
	//算出第二层堆多少个，剪枝
	int L2=0;
	X[0]=b;
	h[0]=R - sqrt( R*R - (b/2)*(b/2) );
	h[1]=h[0]+a;
	X[1]= 2*sqrt( R*R - (R-h[1])*(R-h[1]) );
	h[2]=h[1]+a;
	if(h[2]>=2*R)L2=0;
	else{
		X[2]= 2*sqrt( R*R - (R-h[2])*(R-h[2]) );
		L2=min(X[1],X[2])/b;
	}
	
	
	//已经找出第一层有多少种排法了
	printf("a= %.2lf\n",a);
	printf("b= %.2lf\n",b);
	printf("c= %.2lf\n",c);
	if(L2==0){
		printf("放一排：\n");
		double tmpx=2*sqrt( R*R - (a/2)*(a/2) );
		int Cnt=tmpx/b;
		printf("共 %d 个\n",Cnt);
	}else{
		if(L2==1)L2=2;
		for(int I=1;I<L2;I++){
			DO(I);
			
		}
	}
	
	
	return 0;
}
