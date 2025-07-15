#ifndef BNTESTLIB_H
#define BNTESTLIB_H

#include<string>
#include<windows.h>
#include<fstream>

namespace BN_lib{
	struct unknown_judge_result{};
	enum JUDGE_RESULT{
		_ac=0,
		_wa=1,
		_tle=2,
		_re=3,
		_mle=4,
		_ce=6,
		_se=7,
		_uac=8,
		_aac=9
	};
	
	enum cColor {
	    black = 0,
	    blue = 1,
	    green = 2,
	    cyan = 3,
	    red = 4,
	    magenta = 5,
	    brown = 6,
	    light_gray = 7,
	    dark_gray = 8,
	    light_blue = 9,
	    light_green = 10,
	    light_cyan = 11,
	    light_red = 12,
	    light_magenta = 13,
	    yellow = 14,
	    white = 15
	};
	inline void setcolor(cColor color) {
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(hConsole, color);
	}
	
	std::string sigfile,resfile;
	std::fstream f1,f2;
	
	void setfile(std::string signal_file,std::string result_file){
		sigfile=signal_file;
		resfile=result_file;
		f1.open(sigfile,std::ios::out|std::ios::app|std::ios::binary);
		f2.open(resfile,std::ios::out|std::ios::binary);
	}
	void delfile(){
		f1.close();
		f2.close();
	}
	void sigprint(std::string sig){
		f1<<sig<<'\n';
	}
	void resprint(JUDGE_RESULT result,std::string sig,int time,int score,int ID){
		if(!f1.is_open()||!f2.is_open()){
			return;
		}
		f2<<result<<' ';
		if(result!=8&&result!=9&&result!=5&&result!=6){
			f1<<"#"<<ID<<" ";
		}
		switch(result){
			case 0:
				setcolor(green);
				f1<<"Accepted. Time: "<<time<<" ms. Score: "<<score<<". ";
				setcolor(light_gray);
				f2<<time<<' '<<score;
				break;
			case 1:
				setcolor(red);
				f1<<"Wrong Answer. Time: "<<time<<" ms. Score: "<<score<<". ";
				setcolor(light_gray);
				f2<<time<<' '<<score;
				break;
			case 2:
				setcolor(magenta);
				f1<<"Time Limit Exceeded. Time: "<<time<<" ms. Score: "<<score<<". ";
				setcolor(light_gray);
				f2<<time<<' '<<score;
				break;
			case 3:
				setcolor(magenta);
				f1<<"Runtime Error. Time: 0 ms. Score: "<<score<<". ";
				setcolor(light_gray);
				f2<<time<<' '<<score;
				break;
			case 4:
				setcolor(magenta);
				f1<<"Memory Limit Exceeded. Time: "<<time<<" ms. Score: "<<score<<". ";
				setcolor(light_gray);
				f2<<time<<' '<<score;
				break;
			case 6:
				setcolor(yellow);
				f1<<"Compile Error. ";
				break;
			case 7:
				setcolor(dark_gray);
				f1<<"System Error. ";
				break;
			case 8:
				setcolor(red);
				f1<<"Unaccepted. All time: "<<time<<" ms. Score: "<<score<<". ";
				f2<<time<<' '<<score;
				break;
			case 9:
				setcolor(green);
				f1<<"Accepted. All time: "<<time<<" ms. Score: "<<score<<". ";
				f2<<time<<' '<<score;
				break;
			default:
				unknown_judge_result THROW_ERROR;
				throw THROW_ERROR;
		}
		setcolor(light_gray);
		f1<<sig<<'\n';
		f2<<'\n';
	}
};

#endif
