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
#include <cstdlib>
#include <stdlib.h>
#include <vector>

using namespace std;

struct Student{
  string name;
  string surname;
  string class_number;
};

ifstream in ("input.txt");
ofstream out("output.txt");

void explode_line(string s, string arr[]){
  char *ins = new char[s.size() + 1];
  strcpy(ins, s.c_str());
  char *word = strtok(ins, " ");
  string w(word);
  arr[0] = w;
  int i=1;
  while (word = strtok(NULL, " ")){
	std::string w(word);
	arr[i++] = w;
  }
  return ;
}

void print_vector(vector<Student> v){
 for (auto s : v)
   out<<s.name<<" "<<s.surname<<" "<<s.class_number<<endl;
}

bool compare_studs(Student s1, Student s2){
  return (s1.class_number < s2.class_number);
}

int _tmain(int argc, _TCHAR* argv[]){
  if (!in){
	throw runtime_error("Can't open file");
  }
  string line;
  string arr[3];
  vector<Student> arr9,arr10;
  while(getline(in, line)){
	explode_line(line, arr);
	if ( (arr[2].find("10")==0) || (arr[2][0] == '9') ) {
	  Student stud = {arr[0], arr[1], arr[2]};
	  if (arr[2][0] == '9')
		arr9.push_back(stud);
	  else
		arr10.push_back(stud);
	};
  }
  sort(arr9.begin(), arr9.end(), compare_studs);
  sort(arr10.begin(), arr10.end(), compare_studs);
  print_vector(arr9);
  print_vector(arr10);
  in.close();
  out.close();
  cout<<"File is written!"<<endl;
  system("pause");
  return 0;
}
