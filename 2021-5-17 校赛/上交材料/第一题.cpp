#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=1000000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int land[100][100];			//地块状态 
int T[100][100];				//时间 
int A,B;
const int NANT=100*100+5;
int ans;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

struct node{
	int x,y,t;
	node(int x=0,int y=0,int t=0):x(x),y(y),t(t){};
	friend bool operator<(const node &a,const node &b ){
		return a.t<b.t;
		
	}
};

void init(){
	ans=NANT;
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++){
			T[i][j]=NANT;
			land[i][j]=1;
		}
	}
	for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)scanf("%d",&land[i][j]);

}

void checkmap(){
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++)printf("%d ",land[i][j]);
		printf("\n");
	}
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++)printf("%d ",T[i][j]);
		printf("\n");
	}
}

int main(){
	freopen("t1p2_in.txt","r",stdin);
//	freopen("test4_answer(godsight).txt","w",stdout);
	
int CNT;
A=10;
B=10;

scanf("%d",&CNT);
while(CNT--){
	init();
	//checkmap();
	
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
	printf("%d\n",ans);
	if(ans==10005){
		printf("++++++\n");
		for(int i=1;i<=10;i++){
				for(int j=1;j<=10;j++)printf("%d\t",land[i][j]);
				printf("\n");
			}
		printf("++++++\n");
	}
	/*
	for(int i=1;i<=A;i++){
		for(int j=1;j<=B;j++)printf("%d\t",T[i][j]);
		printf("\n");
	}
	printf("\n");
	*/
	
/*
	1 初始化：读入每个格子的状态（0空地，1障碍，2终点，3起点），T表示每个格子的最早到达时间（初始化为正无穷)
2 将起点推入优先队列，关键字为T；
3 取出队头，观察对头所在点周围8点（边界更少）的情况；如果该点可达且经由对头达到该点用的时间 T 比当前的 T 更小，则更新并入队；否则不处理
4 重复 4 直到优先队列为空
5 从T中读出结果
*/
}

	return 0;
}
