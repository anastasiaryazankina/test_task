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
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

class Point {
  public:
	double x,y;
	Point(double _x, double _y){x=_x;y=_y;} // конструктор класса
	double getX(){return x;}
	double getY(){return y;}
};

class Line {
  public:
	double k,b; // коэффициенты прямой
	Line(Point *p1,Point *p2) {
	  k = (p2->getY() - p1->getY()) / (p2->getX() - p1->getX());
	  b = (p1->getY() - ( (p2->getY() - p1->getY())*p1->getX() /
		 (p2->getX() - p1->getX()) ) );
	};

	double contains(Point *p){
	  return p->getY() - k*p->getX()+b;
	};

	bool points_on_the_same_side(Point *p1,Point *p2){
	  return contains(p1)*contains(p2)>0;
	};
};

class Triangle {
  public:
	Point *a,*b,*c;
	Line *ab,*bc,*ac;
	Triangle(Point *p1,Point *p2,Point *p3) {
	  a=p1;
	  b=p2;
	  c=p3;
	  ab=new Line(a,b);
	  bc=new Line(b,c);
	  ac=new Line(a,c);
	};

	double contains(Point *p1){
	  return ab->points_on_the_same_side(p1, c) &&
		bc->points_on_the_same_side(p1, a) &&
		ac->points_on_the_same_side(p1, b);
	};

};

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

int _tmain(int argc, _TCHAR* argv[]){
  ifstream in ("input_on_the_same_side_inside.txt");
	if (!in){
	  throw runtime_error("Can't open file");
	}
  ofstream out("output.txt");
  string line;
  string arr[6];
  getline(in, line);// first line of file - line' coord ;
  explode_line(line, arr);
  Point *p1 = new Point(stod(arr[0]),stod(arr[1]));
  Point *p2 = new Point(stod(arr[2]),stod(arr[3]));
  Line *l = new Line(p1,p2);

  getline(in, line);// second line of file - points coord ;
  explode_line(line, arr);
  Point *p3 = new Point(stod(arr[0]),stod(arr[1]));
  Point *p4 = new Point(stod(arr[2]),stod(arr[3]));
  if (l->points_on_the_same_side(p3,p4))
	out<<"Points on the same side!"<<endl;
  else out<<"Points on the different sides!"<<endl;

  getline(in, line);// third line of file - triangle coord ;
  explode_line(line, arr);
  Point *p5 = new Point(stod(arr[0]),stod(arr[1]));
  Point *p6 = new Point(stod(arr[2]),stod(arr[3]));
  Point *p7 = new Point(stod(arr[4]),stod(arr[5]));
  getline(in, line);// forth line of file - triangle№2 coord ;
  explode_line(line, arr);
  Point *p8 = new Point(stod(arr[0]),stod(arr[1]));
  Point *p9 = new Point(stod(arr[2]),stod(arr[3]));
  Point *p10 = new Point(stod(arr[4]),stod(arr[5]));
  Triangle *abc = new Triangle(p8,p9,p10);
  Triangle *tr2 = new Triangle(p5,p6,p7);
  if (abc->contains(tr2->a) && abc->contains(tr2->b) && abc->contains(tr2->c))
	out<<"inside!"<<endl;
  else out<<"outside!"<<endl;
  in.close();
  out.close();
  cout<<"File is written!"<<endl;
  system("pause");
  return 0;
}

