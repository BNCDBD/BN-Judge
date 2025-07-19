#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
string name;
string type;
int datacnt;
int time_limit,subtask_cnt;
int score[114514],subtask[114514];
string in[114514],ans[114514];
string calc_all;
string calc_subtask[114514];
inline bool filecpy(string src,string dst){
    if (CopyFile(src.c_str(), dst.c_str(), FALSE)) {
        return true;
    } else {
        return false;
    }
}
signed main(){
	system("title BN-Judge Add Problem");
	printf("Problem Name:");
	cin>>name;
	printf("Judge Type(\"none\", \"subtask\" or \"spj\"):");
	cin>>type;
	if(type!="none"&&type!="subtask"&&type!="spj"){
		MessageBox(NULL,"Error!","error",MB_ICONERROR);
		return 0;
	}
	if(type=="spj"){
		MessageBox(NULL,"Sorry, the \"Special Judge\" is unfinished now.\nWe are developing! :)","Unfinished",MB_ICONINFORMATION);
		return 0;
	}
	if(type=="subtask"){
		printf("Number of Subtasks:");
		scanf("%d",&subtask_cnt);
		printf("How to compute Total Score(\"max\", \"min\" or \"sum\"):");
		cin>>calc_all;
		if(calc_all!="max"&&calc_all!="min"&&calc_all!="sum"){
			MessageBox(NULL,"Error!","error",MB_ICONERROR);
			return 0;
		}
	}
	printf("Time Limit:");
	scanf("%d",&time_limit);
	printf("Number of TestData:");
	scanf("%d",&datacnt);
	for(int i=1;i<=datacnt;++i){
		printf("Data #%d:\n",i);
		printf("*You can drag file here to enter path.\n");
		printf("Input File Path:");
		getchar();
		getline(cin,in[i]);
		printf("Answer File Path:");
		getline(cin,ans[i]);
		printf("Score:");
		scanf("%d",score+i);
		if(type=="subtask"){
			printf("Parent Subtask:");
			scanf("%d",&subtask[i]);
		}
	}
	if(type=="subtask"){
		for(int i=1;i<=subtask_cnt;++i){
			printf("Subtask %d:\n",i);
			printf("How to compute the Score of This Subtask(\"max\", \"min\" or \"sum\"):");
			cin>>calc_subtask[i];
		}
	}
	printf("Adding....\n");
	system(("md Problems\\"+name).c_str());
	fstream file;
	file.open("Problems\\"+name+"\\sysCode.log",ios::out|ios::binary);
	if(!file.is_open()){
		printf("Failed! Unknow Error.\n");
		system("pause");
		return 0;
	}
	file<<datacnt<<' '<<time_limit<<' '<<type;
	if(type=="subtask")file<<' '<<subtask_cnt<<' '<<calc_all;
	file<<'\n';
	for(int i=1;i<=datacnt;++i){
		stringstream sstream;
		sstream<<i;
		string S;
		sstream>>S;
		fstream F1;
		F1.open("Problems\\"+name+"\\"+S+".in",ios::out|ios::binary);
		F1.close();
		F1.open("Problems\\"+name+"\\"+S+".out",ios::out|ios::binary);
		F1.close();
		filecpy(in[i],"Problems\\"+name+"\\"+S+".in");
		filecpy(ans[i],"Problems\\"+name+"\\"+S+".out");
		file<<i<<".in"<<' '<<i<<".out"<<' '<<score[i];
		if(type=="subtask")file<<' '<<subtask[i];
		file<<'\n';
	}
	if(type=="subtask"){
		for(int i=1;i<=subtask_cnt;++i){
			file<<calc_subtask[i]<<'\n';
		}
	}
	file.close();
	printf("Done.\n");
	system("pause");
	return 0;
}
