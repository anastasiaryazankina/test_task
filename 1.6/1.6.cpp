#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif


#include <iostream>
#include <clocale>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

string to_binary(string t){
  unsigned long int x = stoi(t);
  int mask=1;
  string s;
  do{
	s+=((mask&x)?'1':'0');
	mask<<=1;
  }while(mask<=x);

  reverse(s.begin(),s.end());
  return s;
}

int _tmain(int argc, _TCHAR* argv[]){
  setlocale(LC_CTYPE, "rus");
  unsigned long int p;
  ifstream in ("input.txt");
  if (!in){
	throw runtime_error("Can't open file");
  }
  ofstream out("output.txt");
  string line;
  while(getline(in, line)){
	unsigned long int k = to_binary(line).size()*3;
	string snum = to_string(k);
	out<<to_binary(snum)<<endl;
  }
  in.close();
  out.close();
  cout<<"File is written!"<<endl;
  system("pause");
  return 0;
}


