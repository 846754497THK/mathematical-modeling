#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//int find(const char *s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
//string substr(int pos = 0,int n = npos) const;//返回pos开始的n个字符组成的字符串
int main(){
	
	string s;
	freopen("SW_test_in.txt","r",stdin);
	freopen("SW_test_out.txt","w",stdout);
	for(int i=0;i<100;i++){
		getline(cin,s);
		string s1,s2,s3;
		int a1=s.find('=');
		int a2=s.find(',');
		s1=s.substr(a1,a2-a1);
		cout<<s1;
		printf("\t");
		s=s.substr(a2);
		a1=s.find('=');
		a2=s.find(')');
		s1=s.substr(a1,a2-a1);
		cout<<s1<<endl;
	}
	return 0;
} 
