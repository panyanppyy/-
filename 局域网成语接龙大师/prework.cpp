#include<bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
template<typename T_>void operator+=(vector<T_>&x,const T_&y){x.push_back(y);}
template<typename T_>void operator--(vector<T_>&x,int){x.pop_back();}
template<typename T_>void Min(T_&x,const T_&y){if(y<x)x=y;}
template<typename T_>void Max(T_&x,const T_&y){if(y>x)x=y;}
int a;
char b;
string c,C;
void rfile(const char*x){freopen(x,"r",stdin);}
void ofile(const char*x){freopen(x,"w",stdout);}
string s[(int)1e6];
int idx;
int main(){
	ifstream fin("used.txt");
	ofile("tmp1.txt");
	while(getline(fin,s[++idx])){
		for(int i=1;i<=5;i++)getline(fin,s[++idx]);
		getline(fin,c);getline(fin,c);
	}
	fin=(ifstream)("tmp.txt");
	for(int i=1;i<=idx;i+=6){
		for(int j=i;j<=i+5;j++)cout<<s[j]<<'\n';
		getline(fin,c),getline(fin,C);
		cout<<c<<'\n';
	}
	return 0;
}

