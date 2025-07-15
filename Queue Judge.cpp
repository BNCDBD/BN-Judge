#include<bits/stdc++.h>
#include<windows.h>
#include<fstream>
#include<shared_mutex>
#include<thread>
using namespace std;
struct cannot_open_file{};
cannot_open_file cof;
int tim,sc;
bool fl;
shared_timed_mutex mtx;
void catchres(string file){
	fstream f;
	f.open(file,ios::in|ios::binary);
	if(f.is_open()){
		int t1,t2,t3;
		while(f>>t1>>t2>>t3){
			fl=(t1==8?0:1);
			tim=t2;
			sc=t3;
		}
	}else{
		return;
	}
}
int main(){
	fstream file;
	shared_lock<shared_timed_mutex> lock(mtx);
	file.open("JudgeQueue.txt",ios::in|ios::binary);
	if(!file.is_open()){
		throw cof;
	}
	while(1){
		string s1,s2;
		unsigned long long recnum;
		if(!(file>>s1>>s2>>recnum)){
			file.close();
			file.open("JudgeQueue.txt",ios::out);
			file.close();
			shared_lock<shared_timed_mutex> lock(mtx);
			file.open("JudgeQueue.txt",ios::in|ios::binary);
			Sleep(500);
			continue;
		}
		string S;
		stringstream sstream;
		sstream<<recnum;
		sstream>>S;
		
		fstream TMP;
		TMP.open("flag"+S,ios::out);
		TMP.close();
		string command="\"Judge Main.exe\" "+s1+" "+s2+" O2 Npause Nout record "+S;
		system(command.c_str());
		string STRI="del flag"+S;
		system(STRI.c_str());
		catchres("sysTestResult.log");
		cout<<"\n"<<s1<<".cpp: Time: "<<tim<<" ms   Score: "<<sc<<" pts.\n\n";
//		Sleep(500);
//		system(("more Records\\record"+S+".log").c_str());
	}
	return 0;
}
