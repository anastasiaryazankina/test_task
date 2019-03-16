#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <clocale>
#include <sstream>
#include <cstdio>
using namespace std;


int _tmain(int argc, _TCHAR* argv[]){
  setlocale(LC_CTYPE, "rus");
  ifstream in ("input.txt");
  if (!in){
	throw runtime_error("Can't open file");
  }
  ofstream out("output.txt");
  string line;
  int space_cnt,u_cnt;

  while(getline(in, line)){
	space_cnt=0, u_cnt=0;
	for (int i = 0; i < line.size()-1; i++) {
	  if (line[i] == '!') break;
	  switch (line[i]){
		case ' ':
		  space_cnt++;
		  break;
		case 'u':
		 u_cnt++;
	  }
	}
	out<<line<<": Count of spaces - "<<space_cnt;
	string u_present = (u_cnt>0) ? "" : "not ";
	out<<"; U is "<<u_present<<"exist"<<endl;
  }

  in.close();
  out.close();
  cout<<"File is written!"<<endl;
  system("pause");
  return 0;
}

