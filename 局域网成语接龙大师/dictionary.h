//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<bits/stdc++.h>
using namespace std;
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define fi first
#define se second
using bsi=std::basic_string<int>;
using bsc=std::string;
std::mt19937 rng(std::random_device{}());
struct idiom{
	bsc derivation,example,explanation,pinyin,word,abbreviation,pinyin1,pinyin2;
	idiom(){
		string c;
		getline(cin,c);
		derivation=c;
		getline(cin,c);
		example=c;
		getline(cin,c);
		explanation=c;
		getline(cin,c);
		pinyin=c;
		getline(cin,c);
		word=c;
		getline(cin,c);
		abbreviation=c;
		getline(cin,c);
		auto p1=c.find_first_of(' '),p2=c.find_last_of(' ');
		pinyin1.assign(c.begin(),c.begin()+p1);
		pinyin2.assign(c.begin()+p2+1,c.end());
	}
};
std::vector<std::pair<idiom,bool>>zp;
std::map<bsc,bsi>smf;
int getid(const bsc &s){
	for(int i=0;i<siz(zp);i++)
		if(zp[i].fi.word==s)return i;
	return -1;
}
int randi(){
	bsi ok;
	for(int i=0;i<siz(zp);i++)
		if(!zp[i].se)ok+=i;
	return ok[rng()%siz(ok)];
}
int randti(int x){
	bsi ok;
	cauto &mayok=smf[zp[x].fi.pinyin2];
	for(int i=0;i<siz(mayok);i++)
		if(!zp[i].se)ok+=mayok[i];
	return ok[rng()%siz(ok)];
} 
bool checki(int x,int y){
	return zp[x].fi.pinyin2==zp[y].fi.pinyin1;
}
void init(){
	freopen("dic.txt","r",stdin);
	for(int i=0;i<30896;i++){
		zp.emplace_back(idiom(),false);
		smf[zp.back().fi.pinyin1]+=i;
	}
	freopen("CON","r",stdin);
}