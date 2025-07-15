#include<bits/stdc++.h>
#include<fstream>
#include<windows.h>
using namespace std;
bool exist(const string& filename) {
    ifstream file(filename);
    return file.good();
}
int main(){
	system("title Code Submit");
	string file,problem;
	cout<<"Use path mode(\"Yes\" or \"No\"):";
	string choice;
	cin>>choice;
	cout<<"Problem:";
	cin>>problem;
	if(choice=="Yes"){
		cout<<"file path:";
		getchar();
		getline(cin,file);
		file=file.substr(0,file.size()-4);
	}else{
		cout<<"Source code:(enter Ctrl+Z to stop)\n";
		fstream maincpp;
		maincpp.open("Main.cpp",ios::out|ios::binary);
		file="Main";
		while(1){
			string str;
			if(!getline(cin,str))break;
			maincpp<<str<<'\n';
		}
		maincpp.close();
	}
	fstream F;
	F.open("JudgeQueue.txt",ios::out|ios::app|ios::binary);
	if(!F.is_open()){
		return 255;
	}
	unsigned long long count;
	fstream f2;
	f2.open("Memory.txt",ios::in|ios::binary);
	if(!f2.is_open()){
		printf("Submit Falled!\n");
		return 255;
	}
	f2>>count;
	f2.close();
	++count;
	f2.open("Memory.txt",ios::out|ios::binary);
	if(!f2.is_open()){
		printf("Submit Falled!\n");
		return 255;
	}
	f2<<count<<'\n';
	f2.close();
	F<<file<<' '<<problem<<' '<<count<<'\n';
	F.close();
	system("cls");
	int tick=0;
	printf("Waiting");
	string SS;
	stringstream sstream;
	sstream<<count;
	sstream>>SS;
	bool flag=true;
	while(!exist("Records\\record"+SS+".log")){
		if(tick<5000){
			if(flag){
				printf(".");
				flag=false;
			}
		}else if(tick<10000){
			if(flag){
				printf(".");
				flag=false;
			}
		}else if(tick<15000){
			if(flag){
				printf(".");
				flag=false;
			}
		}else if(tick<20000){
			if(flag){
				printf(".");
				flag=false;
			}
		}else{
			tick=0;
			system("cls");
			if(!exist("flag"+SS))printf("Waiting");
			else printf("Judging");
		}
		++tick;
		if(tick%5000==0)flag=true;
	}
	Sleep(500);
	system("cls");
	string command="more Records\\record"+SS+".log";
	system(command.c_str());
	system("pause");
	return 0;
}
