#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double ans[5760][105];	//answer 
struct A{
	double s1,s2,s3;
	double score;
	int rank;
	friend bool operator<(A x,A y){
		return x.score>y.score;
	}
	A(double s1=0,double s2=0,double s3=0,double score=0,int r=0):s1(s1),s2(s2),s3(s3),score(score),rank(r){}
}a[5760];
int main(){
	
	freopen("Autocorrelation_coefficient_3_out_100.txt","r",stdin);
	freopen("score_3_out.txt","w",stdout);
	for(int i=1;i<=5759;i++){
		for(int j=1;j<=100;j++)scanf("%lf",&ans[i][j]);
	}	
	double p1=1.151329,p2=3.0625,p3=1.331716;
	for(int i=1;i<=5759;i++){
		a[i].s1=a[i].s2=a[i].s3=0;
		//分别计算s1 s2 s3 的平均值
		a[i].s1=( ans[i][4]+ans[i][17] )/2;
		a[i].s2=(
			+ans[i][7]
			+ans[i][20]
			+ans[i][21]
			+ans[i][41]
			+ans[i][65]
			
			+ans[i][72]
			+ans[i][73]
			+ans[i][76]
			+ans[i][71]
			+ans[i][96]
			
			+ans[i][23]
			+ans[i][47]
			+ans[i][57]
			)/13;
		a[i].s3=( ans[i][11]+ans[i][94] )/2;
		a[i].score=p1*a[i].s1 + p2*a[i].s2 + p3*a[i].s3;
		a[i].rank=i;
	}
	
	sort(a+5520,a+5580);
	printf("%d\t%.8lf\n",a[5520].rank,a[5520].score);
	sort(a+5580,a+5640);
	printf("%d\t%.8lf\n",a[5580].rank,a[5580].score);
	sort(a+5640,a+5700);
	printf("%d\t%.8lf\n",a[5640].rank,a[5640].score);
	sort(a+5700,a+5760);
	printf("%d\t%.8lf\n",a[5700].rank,a[5700].score);
	
	return 0;
}
