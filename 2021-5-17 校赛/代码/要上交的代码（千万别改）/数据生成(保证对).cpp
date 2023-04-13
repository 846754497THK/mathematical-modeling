#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=1000000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
default_random_engine E;
const double P=0.3;                   //障碍比例  
int N;
int land[100][100];			//地块状态 
int T[100][100];				//时间 
const int NANT=100*100+5;
int ans;
const int A=10,B=10;
uniform_real_distribution<double>xx(0,1);

int ram(){
	if(xx(E)<P)return 1;
	else return 0;
}

int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

struct node{
	int x,y,t;
	node(int x=0,int y=0,int t=0):x(x),y(y),t(t){};
	friend bool operator<(const node &a,const node &b ){
		return a.t<b.t;
		
	}
};

int main(){
	N=1000; 							//总数 
	freopen("test4.txt","w",stdout);
	int cnt=0;
	printf("%d\n",N);
	while(cnt<N){
		
		ans=NANT;
		for(int i=0;i<=A+1;i++){
			for(int j=0;j<=B+1;j++){
				T[i][j]=NANT;
				land[i][j]=1;
			}
		}
		for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)land[i][j]=ram();
		
		land[A][1]=3;
		land[1][B]=2;
		
		priority_queue < node , vector<node> >q;
		node str(A,1,0);
		T[A][1]=0;
		q.push(str);
		
		while( !q.empty() ){
			node tmp=q.top();
			q.pop();
			int rx,ry,rt=tmp.t+1;
			for(int r=0;r<8;r++){
			
				rx=tmp.x+dx[r];
				ry=tmp.y+dy[r];
				if( land[rx][ry]==2 ){
					if(ans>rt)ans=rt;
				}else{
					//printf("[%d][%d]: %d %d \n",rx,ry,land[rx][ry],T[rx][ry]);
					if( land[rx][ry]==0 && T[rx][ry]>rt ){
					
						T[rx][ry]=rt;
						node N(rx,ry,rt);
						q.push(N);
					}
				}
			}
			
		}
		T[1][B]=ans;
		if(T[1][B]<NANT){
			cnt++;
			for(int i=1;i<=10;i++){
				for(int j=1;j<=10;j++)printf("%d\t",land[i][j]);
				printf("\n");
			}
			printf("\n");
		}
		
	} 
	return 0;
}
