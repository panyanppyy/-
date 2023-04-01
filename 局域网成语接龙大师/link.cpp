#include "communi.h"
#include "dictionary.h"
#include<bits/stdc++.h> 
#include <windows.h>
#include <wchar.h>
using namespace std;
// 角色列表，con 中的下标需和对应变量相匹配。
twt_client cs;
/*
 * 局域网信息发送类
 * 负责和服务器间信息的收发
 *
 * 参考：communi.h
 * 异常：发送、接收失败和发送长度超过限制时
 * 
 * rec() 返回接收到的信息
 * sent(string) 向服务器发送信息
 */
int id,B,c,C,D;

string name;

// vector<int> -> int
string to_string(vector<int> x) {
	string an;
	for (int c : x) an = an + to_string(c) + " ";
	return an; 
}

// 然后接收服务器的玩家人数直到所有人连上
void preWork() {
	cout<<"给自己起个名字\n";
	cin>>name;
	cs.sent("online");
	string per = cs.rec();
	while (per != "over") {
		system("cls");
		cout << "等待其它玩家... "; 
		cout << per << '\n';
		per = cs.rec();
	}
}

// 获得玩家总数和自身编号
void getInfo() {
	cs.sent(name);
	string c = cs.rec();
	system("cls");
	cout << "一共有 " << c << " 个玩家\n";
	B = to_int(c);
	c = cs.rec();
	id = to_int(c);
	cout << "你的编号是 " << id << '\n';
	cout << "你的名字是 " << name << '\n';
	c = cs.rec();
	C = to_int(c);
	cout << "接龙轮数是 "<<C<<'\n';
	c = cs.rec();
	D =to_int(c);
	cout<< "单轮接龙次数是 "<<D<<'\n';
	c = cs.rec();
	cout<<c<<'\n';
	cout<<"注意：不要重复回答一个作为答案后的成语，并在 20s 内完成回答\n";
	system("pause");
}
pair<string,int> Answer(){
	auto t=clock();
	string ss;
	fflush(stdin);
	cin>>ss;
	cout<<ss<<'\n';
	return{ss,max(0l,clock()-t-40)};
}

void Part(int&c,int rd){
	c=to_int(cs.rec());
	system("cls");
	cout<<"回合 "<<rd<<":\n"<<"得到的成语是: "<<zp[c].fi.word<<"\n";
	cout<<"来源: "<<zp[c].fi.derivation<<'\n';
	cout<<"例句: "<<zp[c].fi.example<<'\n';
	cout<<"解释: "<<zp[c].fi.explanation<<'\n';
	cout<<"发音: "<<zp[c].fi.pinyin<<'\n';
	cout<<"\n给出你的答案: \n";
	auto ans=Answer();
	cs.sent(ans.fi),cs.sent(to_string(ans.se));
	system("cls");
	cout<<"回合 "<<rd<<" 结果如下: \n\n";
	string say =cs.rec();
	cout<<say<<'\n';
	system("pause");
}

void Round(int Rd){
	int c;
	for(int i=1;i<=D;i++)Part(c,i);
	system("cls");
	cout<<"第 "<<Rd<<" 轮结果如下: \n\n";
	string say=cs.rec();
	cout<<say<<'\n';
	system("pause");
}
// 主程序连接服务器并获得所需信息，然后开始游戏的循环。
int main() {
	system("chcp 936");
	init(); system("cls");
	cout << "欢迎使用局域网成语接龙大师!\n\n";
	cout << "服务器客户端技术及设计师：panyanppyy\n";
	cout << "字典提供及最高参谋长：蒟酱\n\n";
	cs.init(1234);
	preWork();
	getInfo();
	for(int i=1;i<=C;i++)Round(i);
	system("pause");
}