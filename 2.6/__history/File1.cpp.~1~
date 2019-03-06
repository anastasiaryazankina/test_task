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
using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
  int n, cnt = 0;
  cout << "Enter the number of characters: ";
  cin >> n;
  char mass[n];
  for (int i = 0; i < n; i++) {
    std::cin.getline (mass,n);
  }
  for (int i = 0; i < n-1; i++) {
	if (mass[i] == '!') break;
	if (mass[i] == ' ')
      cnt++;
	if (mass[i] == 'u') {
      cout << "u - EXIST"<<"\n";
    return 0;
	}
  }
  cout << "u - NOT EXIST"<<"\n";
  cout<<"Count of spaces - "<<cnt<<endl;
  system("pause");
  return 0;
}


