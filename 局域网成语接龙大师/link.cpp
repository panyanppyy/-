#include "communi.h"
#include "dictionary.h"
#include<bits/stdc++.h> 
#include <windows.h>
#include <wchar.h>
using namespace std;
// ��ɫ�б�con �е��±���Ͷ�Ӧ������ƥ�䡣
twt_client cs;
/*
 * ��������Ϣ������
 * ����ͷ���������Ϣ���շ�
 *
 * �ο���communi.h
 * �쳣�����͡�����ʧ�ܺͷ��ͳ��ȳ�������ʱ
 * 
 * rec() ���ؽ��յ�����Ϣ
 * sent(string) �������������Ϣ
 */
int id,B,c,C,D;

string name;

// vector<int> -> int
string to_string(vector<int> x) {
	string an;
	for (int c : x) an = an + to_string(c) + " ";
	return an; 
}

// Ȼ����շ��������������ֱ������������
void preWork() {
	cout<<"���Լ��������\n";
	cin>>name;
	cs.sent("online");
	string per = cs.rec();
	while (per != "over") {
		system("cls");
		cout << "�ȴ��������... "; 
		cout << per << '\n';
		per = cs.rec();
	}
}

// ������������������
void getInfo() {
	cs.sent(name);
	string c = cs.rec();
	system("cls");
	cout << "һ���� " << c << " �����\n";
	B = to_int(c);
	c = cs.rec();
	id = to_int(c);
	cout << "��ı���� " << id << '\n';
	cout << "��������� " << name << '\n';
	c = cs.rec();
	C = to_int(c);
	cout << "���������� "<<C<<'\n';
	c = cs.rec();
	D =to_int(c);
	cout<< "���ֽ��������� "<<D<<'\n';
	c = cs.rec();
	cout<<c<<'\n';
	cout<<"ע�⣺��Ҫ�ظ��ش�һ����Ϊ�𰸺�ĳ������ 20s ����ɻش�\n";
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
	cout<<"�غ� "<<rd<<":\n"<<"�õ��ĳ�����: "<<zp[c].fi.word<<"\n";
	cout<<"��Դ: "<<zp[c].fi.derivation<<'\n';
	cout<<"����: "<<zp[c].fi.example<<'\n';
	cout<<"����: "<<zp[c].fi.explanation<<'\n';
	cout<<"����: "<<zp[c].fi.pinyin<<'\n';
	cout<<"\n������Ĵ�: \n";
	auto ans=Answer();
	cs.sent(ans.fi),cs.sent(to_string(ans.se));
	system("cls");
	cout<<"�غ� "<<rd<<" �������: \n\n";
	string say =cs.rec();
	cout<<say<<'\n';
	system("pause");
}

void Round(int Rd){
	int c;
	for(int i=1;i<=D;i++)Part(c,i);
	system("cls");
	cout<<"�� "<<Rd<<" �ֽ������: \n\n";
	string say=cs.rec();
	cout<<say<<'\n';
	system("pause");
}
// ���������ӷ����������������Ϣ��Ȼ��ʼ��Ϸ��ѭ����
int main() {
	system("chcp 936");
	init(); system("cls");
	cout << "��ӭʹ�þ��������������ʦ!\n\n";
	cout << "�������ͻ��˼��������ʦ��panyanppyy\n";
	cout << "�ֵ��ṩ����߲�ı�����X��\n\n";
	cs.init(1234);
	preWork();
	getInfo();
	for(int i=1;i<=C;i++)Round(i);
	system("pause");
}