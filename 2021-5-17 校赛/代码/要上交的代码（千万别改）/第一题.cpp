#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=1000000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int land[100][100];			//�ؿ�״̬ 
int T[100][100];				//ʱ�� 
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
	1 ��ʼ��������ÿ�����ӵ�״̬��0�յأ�1�ϰ���2�յ㣬3��㣩��T��ʾÿ�����ӵ����絽��ʱ�䣨��ʼ��Ϊ������)
2 ������������ȶ��У��ؼ���ΪT��
3 ȡ����ͷ���۲��ͷ���ڵ���Χ8�㣨�߽���٣������������õ�ɴ��Ҿ��ɶ�ͷ�ﵽ�õ��õ�ʱ�� T �ȵ�ǰ�� T ��С������²���ӣ����򲻴���
4 �ظ� 4 ֱ�����ȶ���Ϊ��
5 ��T�ж������
*/
}

	return 0;
}
