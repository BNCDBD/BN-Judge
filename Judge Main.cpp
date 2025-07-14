#include<bits/stdc++.h>
#include<fstream>
#include<windows.h>
#include "BNtestlib.h"

#define int register int

#define JUDGE_POINT_LIMIT 105

using namespace std;
using namespace BN_lib;


//Change file here!(for debug only)
string FILENAME="code";//file name
string CPP_FILE="code.cpp";//.cpp file
string EXE_FILE="code.exe";//.exe file
string PROBLEM="canvas";//path of input files and answer files
string EXE_CODE="code.exe < Input.in > Output.out";//execute command


//const char* Code="\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\bin\\g++.exe\" \"C:\\Users\\Administrator\\Desktop\\Mine\\Projects\\System Projects\\Test - Program Judge\\code.cpp\" -o \"C:\\Users\\Administrator\\Desktop\\Mine\\Projects\\System Projects\\Test - Program Judge\\code.exe\" -g3 -std=c++11 -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\gcc\\x86_64-w64-mingw32\\4.9.2\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\gcc\\x86_64-w64-mingw32\\4.9.2\\include\\c++\" -L\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\" -L\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\lib\" -static-libgcc -g3";
struct RESULT_NODE{
	signed type,time,score;
}result[JUDGE_POINT_LIMIT];
struct SUBTASK{
	signed type,score;
}subtask[JUDGE_POINT_LIMIT];
signed TestDataCnt=0,SubtaskCnt=0; 
string inpath[JUDGE_POINT_LIMIT],anspath[JUDGE_POINT_LIMIT];
signed score[JUDGE_POINT_LIMIT],task[JUDGE_POINT_LIMIT],
allScore=0,allTime=0,TimeLimit,JudgeType=0,SubtaskTotalType=0;

enum ConsoleColor {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GRAY = 7,
    DARK_GRAY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};
inline void setcolor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
 
inline bool exists(string path){
	fstream File(path);
    if(File.is_open()){
    	File.close();
        return true;
    }else{
        return false;
    }
}
inline bool fileCmp(string outpath,string anspath){
	fstream out,ans;
	out.open(outpath,ios::in|ios::binary);
	ans.open(anspath,ios::in|ios::binary);
	if(out.is_open()&&ans.is_open()){
		while(1){
			string t1,t2;
			getline(out,t1);
			getline(ans,t2);
			while(t1[t1.length()-1]==' '||t1[t1.length()-1]=='\n'||t1[t1.length()-1]=='\r'||t1[t1.length()-1]==EOF)t1.pop_back();
			while(t2[t2.length()-1]==' '||t2[t2.length()-1]=='\n'||t2[t2.length()-1]=='\r'||t2[t2.length()-1]==EOF)t2.pop_back();
			if(t1!=t2)return false;
			if(t1=="")break;
		}
		return true;
	}else{
		return false;
	}
}
inline bool filecpy(string src,string dst){
    if (CopyFile(src.c_str(), dst.c_str(), FALSE)) {
        return true;
    } else {
        cout << "Error copying file: " << GetLastError() << endl;
        return false;
    }
}
signed main(int argc,char** argv){
	system("title BN-Judge v1.2.0");
	if(argc>=3){
		FILENAME=argv[1];
		PROBLEM=argv[2];
		CPP_FILE=FILENAME+".cpp";
		filecpy(CPP_FILE,"Main.cpp");
		EXE_FILE=FILENAME+".exe";
		EXE_CODE="Main.exe < Input.in > Output.out";
	}
	char c;
	if(argc>=4){
		if(argv[3][0]=='O')c='Y';
		else c='N';
	}else{
		cout<<"Compile Command: -std=c++14\nO2: (Y/N)";
		cin>>c;
	}
	if(argc>=6){
		if(argv[5][0]=='N'){
			freopen("TEMPO.txt","w",stdout);
		}
	}
	unsigned long long COUNT;
	if(argc>=8){
		string ST=argv[7];
		stringstream sstream;
		sstream<<ST;
		sstream>>COUNT;
	}else{
		COUNT=0;
	}
	cout<<"record "<<COUNT<<": starting\n";
	string SSS,SSS_src;
	setfile("TestLog.log","sysTestResult.log");
	if(argc>=7&&argv[6][0]=='N'){
		
	}else{
		stringstream sstream;
		sstream<<COUNT;
		string SSSSSSSSSS;
		sstream>>SSSSSSSSSS;
		SSS="Records\\record"+SSSSSSSSSS+".log";
		SSS_src="Records\\record"+SSSSSSSSSS+"_source.cpp";
	}
	string _COMMAND_;
	if(c=='Y'){
		_COMMAND_="Stdc++Files\\bin\\g++.exe Main.cpp -o Main.exe -g3 -O2 -std=c++14 -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\gcc\\x86_64-w64-mingw32\\4.9.2\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\gcc\\x86_64-w64-mingw32\\4.9.2\\include\\c++\" -L\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\" -L\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\lib\" -static-libgcc -g3";
	}else{
		_COMMAND_="Stdc++Files\\bin\\g++.exe Main.cpp -o Main.exe -g3 -std=c++14 -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\gcc\\x86_64-w64-mingw32\\4.9.2\\include\" -I\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\gcc\\x86_64-w64-mingw32\\4.9.2\\include\\c++\" -L\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\" -L\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\lib\" -static-libgcc -g3";
	}
	sigprint("Problem: "+PROBLEM+(c=='Y'?"  O2: Yes":"  O2: No"));
	cout<<"Compiling....\n\n";
	cout<<"Compile Code: \n"<<_COMMAND_<<"\n\n";
	
	string __COMMAND_="del "+EXE_FILE;
	system(__COMMAND_.c_str());
	freopen(sigfile.c_str(),"w",stderr);
	system(_COMMAND_.c_str());
	fclose(stderr);
	if(!exists(EXE_FILE)){
		resprint(_ce,"",0,0,0);
		system("pause");
		fclose(stdin);
		fclose(stdout);
		delfile(); 
		return 0;
	}else{
		setcolor(GREEN);
		cout<<"Compile Accepted. \n\n";
		setcolor(LIGHT_GRAY);
	}
	cout<<"Finding TestData....\n\n";
	fstream dataFile;
	dataFile.open("Problems\\"+PROBLEM+"\\sysCode.log",ios::in|ios::binary);
	if(dataFile.is_open()){
		string SIG;
		dataFile>>TestDataCnt>>TimeLimit>>SIG;
		if(SIG=="none"){
			JudgeType=0;
		}else if(SIG=="subtask"){
			JudgeType=1;
			string OOO;
			dataFile>>SubtaskCnt>>OOO;
			if(OOO=="sum"){
				SubtaskTotalType=0;
			}else if(OOO=="min"){
				SubtaskTotalType=1;
				allScore=INT_MAX;
			}else if(OOO=="max"){
				SubtaskTotalType=2;
			}
		}else if(SIG=="spj"){
			JudgeType=2;
		}
		for(int i=1;i<=TestDataCnt;++i){
			dataFile>>inpath[i]>>anspath[i]>>score[i];
			inpath[i]="Problems\\"+PROBLEM+"\\"+inpath[i];
			anspath[i]="Problems\\"+PROBLEM+"\\"+anspath[i];
			if(JudgeType==1)dataFile>>task[i];
			if(!exists(inpath[i])||
			!exists(anspath[i])){
				resprint(_dpe,"Judge Terminated. ",0,0,0);
				delfile(); 
				return 255;
			}
		}
		for(int i=1;i<=SubtaskCnt;++i){
			string STRt;
			dataFile>>STRt;
			if(STRt=="sum"){
				subtask[i].type=0;
				subtask[i].score=0;
			}else if(STRt=="min"){
				subtask[i].type=1;
				subtask[i].score=INT_MAX;
			}else if(STRt=="max"){
				subtask[i].type=2;
				subtask[i].score=0;
			}
		}
		setcolor(CYAN);
		cout<<"Judging....\n\n";
		for(int i=1;i<=TestDataCnt;++i){
			cout<<"\nJudging... ("<<i<<"/"<<TestDataCnt<<")\n";
			if(!exists(anspath[i])){
				result[i].type=3;
				result[i].time=0;
				result[i].score=0;
				continue;
			}
			filecpy(inpath[i],"Input.in");
			string STR="start Judge_Helper.exe Problems\\"+PROBLEM+"\\sysCode.log Main.exe";
			system(STR.c_str()); 
			double s=clock(),e;
			int return_num=system(EXE_CODE.c_str());
			//¶Î´íÎó£º-1073741819
			//³ýÒÔ0£º-1073741676 
	        e=clock();
	        system("taskkill /F -im Judge_Helper.exe");
			double time=e-s;
			if(return_num==-1073741819){
				result[i].type=3;
				result[i].time=0;
				result[i].score=0;
				if(JudgeType==1){
					if(subtask[task[i]].type==1){
						subtask[task[i]].score=min(subtask[task[i]].score,0);
					}else if(subtask[task[i]].type==2){
						subtask[task[i]].score=max(subtask[task[i]].score,0);
					}
				}
				continue;
			}else if(return_num==-1073741676){
				result[i].type=4;
				result[i].time=0;
				result[i].score=0;
				if(JudgeType==1){
					if(subtask[task[i]].type==1){
						subtask[task[i]].score=min(subtask[task[i]].score,0);
					}else if(subtask[task[i]].type==2){
						subtask[task[i]].score=max(subtask[task[i]].score,0);
					}
				}
				continue;
			}
			if(time>TimeLimit){
				result[i].type=2;
				result[i].time=time;
				result[i].score=0;
				if(JudgeType==1){
					if(subtask[task[i]].type==1){
						subtask[task[i]].score=min(subtask[task[i]].score,0);
					}else if(subtask[task[i]].type==2){
						subtask[task[i]].score=max(subtask[task[i]].score,0);
					}
				}
				allTime+=time;
				continue;
			}
			if(fileCmp("Output.out",anspath[i])){
				result[i].type=0;
				result[i].time=time;
				result[i].score=score[i];
				allTime+=time;
				if(JudgeType==1){
					if(subtask[task[i]].type==0){
						subtask[task[i]].score+=score[i];
					}else if(subtask[task[i]].type==1){
						subtask[task[i]].score=min(subtask[task[i]].score,score[i]);
					}else if(subtask[task[i]].type==2){
						subtask[task[i]].score=max(subtask[task[i]].score,score[i]);
					}
				}else{
					allScore+=score[i];
				}
			}else{
				result[i].type=1;
				result[i].time=time;
				result[i].score=0;
				if(JudgeType==1){
					if(subtask[task[i]].type==1){
						subtask[task[i]].score=min(subtask[task[i]].score,0);
					}else if(subtask[task[i]].type==2){
						subtask[task[i]].score=max(subtask[task[i]].score,0);
					}
				}
				allTime+=time;
			}
		}
		setcolor(LIGHT_GRAY);
		cout<<"\nResult....\n\n";
		for(int i=1;i<=TestDataCnt;++i){
			if(result[i].type==0){
				resprint(_ac,"the answer is ok.",result[i].time,result[i].score,i);
			}else if(result[i].type==1){
				resprint(_wa,"the answer is wrong.",result[i].time,result[i].score,i);
			}else if(result[i].type==2){
				resprint(_tle,"",result[i].time,result[i].score,i);
			}else if(result[i].type==3){
				resprint(_re,"segmentation fault.",result[i].time,result[i].score,i);
			}else if(result[i].type==4){
				resprint(_re,"arithmetic exception.",result[i].time,result[i].score,i);
			}else{
				resprint(_se,"",result[i].time,result[i].score,i);
			}
		}
		if(JudgeType==1){
			for(int i=1;i<=SubtaskCnt;++i){
				string SSSSS,SS2;
				stringstream sstream;
				sstream<<i;
				sstream>>SSSSS;
				stringstream ssstream;
				ssstream<<subtask[i].score;
				ssstream>>SS2;
				sigprint("Subtask "+SSSSS+": "+SS2+" pts.");
				if(SubtaskTotalType==0)allScore+=subtask[i].score;
				else if(SubtaskTotalType==1)allScore=min(allScore,subtask[i].score);
				else if(SubtaskTotalType==2)allScore=max(allScore,subtask[i].score);
			}
		}
		cout<<"\nScore: "<<allScore<<" pts.\nTime: "<<allTime<<" ms.\n";
		if(allScore<100){
			resprint(_uac,"",allTime,allScore,0);
		}else{
			resprint(_aac,"",allTime,allScore,0);
		}
	}else{
		setcolor(DARK_GRAY);
		cout<<"\nNo TestData.\nJudge Terminated.\n";
		setcolor(LIGHT_GRAY);
		fclose(stdin);
		fclose(stdout);
		delfile(); 
		return 255;
	}
	if(argc>=5){
		if(argv[4][0]!='N')system("pause");
	}else{
		system("pause");
	}
	delfile(); 
	if(argc<7){
		filecpy("TestLog.log",SSS);
		filecpy("Main.cpp",SSS_src);
	}else if(argv[6][0]!='N'){
		filecpy("TestLog.log",SSS);
		filecpy("Main.cpp",SSS_src);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

