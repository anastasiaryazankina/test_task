program task3;

type
  Point = class
  public 
    x, y: real;
    Constructor Create(_x, _y: real);
    begin
      x := _x;
      y := _y;
    end;
  end;

  Line = class
  public 
    k, b: real;
    Constructor Create(p1,p2:Point); 
      begin
	      k := (p2.y - p1.y) / (p2.x - p1.x);
	      b := (p1.y - ( (p2.y - p1.y)*p1.x / (p2.x - p1.x) ) );
	    end;

    function Contains(p: Point): real;
    begin
      result := p.y - k*p.x+b;
    end;
    
    function points_on_the_same_side(p1,p2: Point):boolean;
    begin
      result := Contains(p1)*Contains(p2)>0;
    end;
  end;
    
  Triangle = class
  public 
    a,b,c:Point;
    ab,bc,ac:Line;
    constructor Create(p1,p2,p3:Point); 
    begin
		  a := p1;
	    b := p2;
	    c := p3;
	    ab := new Line(a,b);
	    bc := new Line(b,c);
	    ac := new Line(a,c);
	  end;
	  
	  function Contains(p:Point):boolean;
	  begin
	    result := ab.points_on_the_same_side(p, c) and
		  bc.points_on_the_same_side(p, a) and
		  ac.points_on_the_same_side(p, b);
  	end;
 end;

var 
  inf,outf:text;
  p1,p2,p3,p4,p5,p6,p7,p8,p9,p10:Point;
  l:Line;
  abc,tr2:Triangle;
  

begin
  assign(inf, 'input_on_the_different_sides_outside.txt');
  reset(inf);
  assign(outf, 'output.txt');
  rewrite(outf);
  var lines : string;
  
  readln(inf,lines);
  var words := lines.ToWords;
  p1 := new Point(StrToFloat(words[0]),StrToFloat(words[1]));
  p2 := new Point(StrToFloat(words[2]),StrToFloat(words[3]));
  l := new Line(p1,p2);
  
  readln(inf,lines);
  words := lines.ToWords; 
  p3 := new Point(StrToFloat(words[0]),StrToFloat(words[1]));
  p4 := new Point(StrToFloat(words[2]),StrToFloat(words[3]));
  if (l.points_on_the_same_side(p3,p4)) then
    writeln(outf, 'Points on the same side!')
  else 
    writeln(outf, 'Points on the different sides!');
    
  readln(inf,lines);
  words := lines.ToWords;
  p5 := new Point(StrToFloat(words[0]),StrToFloat(words[1]));
  p6 := new Point(StrToFloat(words[2]),StrToFloat(words[3]));
  p7 := new Point(StrToFloat(words[4]),StrToFloat(words[5])); 
  
  readln(inf,lines);
  words := lines.ToWords;  
  p8 := new Point(StrToFloat(words[0]),StrToFloat(words[1]));
  p9 := new Point(StrToFloat(words[2]),StrToFloat(words[3]));
  p10 := new Point(StrToFloat(words[4]),StrToFloat(words[5]));
  abc := new Triangle(p8,p9,p10);
  tr2 := new Triangle(p5,p6,p7);
  if (abc.Contains(tr2.a)) and (abc.Contains(tr2.b)) and (abc.Contains(tr2.c)) then
    writeln(outf, 'inside!')
  else 
    writeln(outf, 'outside!');
   
  close(inf);     
  close(outf); 
end.