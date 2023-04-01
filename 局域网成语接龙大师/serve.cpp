#include"communi.h"
#include"dictionary.h"
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

unsigned seed;
// 随机种子 
int B, C, D;
// B 人数,C 单轮次数 

twt_server cs;

vector<int> all;

string name[1200];

void tele(vector<int> a, string s) { for(int c : a) cs.sent(c, s); }

void twt_server::contect() {
	for (int i = 1; i <= B; ) {
		s_accept[i] = accept(s_server, (SOCKADDR *)&accept_addr, &len);
		string cu = rec(i);
		if (i > B) sent(i, "人数已满！请退出！"); 
		else { 
			all.push_back(i);
			system("cls");
			tele(all, to_string(i) + "/" + to_string(B));
			i ++;
		}
	}
	tele(all, "over");
}
void getInfor(){
	cout<< "设置房间大小:\n";
	cin>>B;
	cout<< "设置接龙轮数:\n";
	cin>>C;
	cout<< "设置单轮接龙次数:\n";
	cin>>D;
}

// 等待玩家加入
void preWork() {
	cout << "等待成员加入...\n";
	cs.init(1234, B);
	system("cls");
	cout << "开始!\n";
	tele(all, to_string(B));
	for (int i = 1; i <= B; i++) cs.sent(i, to_string(i));
	tele(all,to_string(C));
	tele(all,to_string(D));
	tele(all, "开始!\n");
	for(int i=1;i<=B;i++)name[i]=cs.rec(i);
}
int score[1200],tsc[1200],cy[1200],bst[1200],ti[1200];
string Cy[1200];
void Part(int&c,int rd){
	int cnt=0;
	tele(all,to_string(c));
	for(int i=1,x;i<=B;i++){
		cy[i]=getid(Cy[i]=cs.rec(i)),ti[i]=tsc[i]=to_int(cs.rec(i));
		if(!~cy[i]||!checki(c,cy[i])||zp[cy[i]].second)tsc[i]=10000;
		else if(tsc[i]>20000)tsc[i]=5000;
		else tsc[i]/=4,cnt++;
	}
	int p=-1;
	for(int i=1;i<=B;i++)
		if(tsc[i]>=5000)continue;
		else if(!~p||tsc[i]<tsc[p])p=i;
	if(!~p)c=randti(c);
	else{
		c=cy[p],tsc[p]=tsc[p]*cnt/B,bst[p]++;
	}
	string say;
	for(int i=1;i<=B;i++){
		say+="玩家 "+name[i]+"\n";
		say+="  回答:"+Cy[i]+"\n";
		say+="  用时:"+to_string(int(ti[i]/1000))+"."+to_string(ti[i]%1000)+"\n";
		tsc[i]=10000-tsc[i];
		score[i]+=tsc[i];
		say+="  得分:";
		if(tsc[i]==0)say+="错误\n";
		else if(tsc[i]==5000)say+="超时答对\n";
		else say+=to_string(tsc[i])+"\n";
		if(i==p)say+=" 最快解!\n";
		say+="\n";
	}
	tele(all,say);
	zp[c].second=1;
}
void Round(int x){
	int c=randi();
	for(int i=1;i<=D;i++)Part(c,i);
	string say;
	vector<pair<int,int>>tmp;
	for(int i=1;i<=B;i++)tmp.emplace_back(score[i],i),score[i]=0;
	sort(all(tmp),greater<>());
	say+=name[tmp[0].se];
	for(int i=1;i<(int)tmp.size();i++)
		if(tmp[i].first==tmp[i-1].first)say+=","+name[tmp[i].second];
	say+=" 夺冠了!!!\n\n";
	for(int i=1;i<=B;i++){
		say+="玩家 "+name[tmp[i-1].second]+"\n";
		say+="  得分:"+to_string(tmp[i-1].first)+"\n";
		say+="  最优解:"+to_string(bst[tmp[i-1].second])+" 次\n";
		say+="  排名:"+to_string(i)+"\n\n";
	}
	for(auto&i:zp)i.second=0;
	for(int i=1;i<=B;i++)score[i]=bst[i]=0;
	tele(all,say);
}
// 主程序，获得一些信息后开始循环
int main() {
	system("chcp 936"); system("cls");
	init();
	getInfor();
	preWork();
	for(int i=1;i<=C;i++)Round(i);
	string say;
	tele(all,say);
	system("pause");
}
