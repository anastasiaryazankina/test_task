#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <cstring>
#include <conio.h>
using namespace std;

int is_number(string w){
  for(int j = 0; j < w.length(); j++){
	if (w[j] < '0' || w[j] > '9') {
	  return 0;
	}
  }
  return 1;
}

string insert_spaces(string w){
  if (w.size() <= 3) {
	return w;
  }
  string outstr;
  for(int j = w.length()-1, k = 1; j >= 0; j--, k++){
	outstr+=w[j];
	if(k%3 == 0 && j != 0){
	  outstr+=' ';
	}
  }
  reverse(outstr.begin(),outstr.end());
  return outstr;
}

string process_word(string w){
  if (is_number(w)) {
	return insert_spaces(w);
  } else {
  return w;
  }
}

string process_line(string s){
  char *ins = new char[s.size() + 1];
  strcpy(ins, s.c_str());
  string outstr;
  char *word = strtok(ins, " ");
  std::string w(word);
  outstr+=process_word(w);
  outstr+=' ';
  while (word = strtok(NULL, " ")){
	std::string w(word);
	outstr+=process_word(w);
	outstr+=' ';
  }
  return outstr;
}

int _tmain(int argc, _TCHAR* argv[]){
  ifstream in ("input.txt");
  if (!in){
	throw runtime_error("Can't open file");
  }
  ofstream out("output.txt");
  string line;
  while(getline(in, line)){
   out<<process_line(line)<<std::endl;
  }
  in.close();
  out.close();
  cout<<"File is written!"<<endl;
  system("pause");
  return 0;
}



