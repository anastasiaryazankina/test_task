program task5;
type 
  Tstud = record
    name:string;
    surname:string;
    class_number:string;   
  end;

var 
  f:text;
  
function cmp(c1,c2:Tstud) : boolean;
begin
  result:= c1.class_number<c2.class_number;
end;

begin
  assign (f, 'input.txt');
  reset (f);
  var c9, c10: array of Tstud;
  SetLength(c9, 0);
  SetLength(c10, 0);
  foreach var s in ReadLines('input.txt') do
    begin
      var strings := s.ToWords;
      if strings[2].Contains('10') then
        begin
          var st := new Tstud;
          st.name := strings[0];
          st.surname := strings[1];
          st.class_number := strings[2];
          SetLength(c10, c10.Length+1);
          c10[c10.Length-1] := st;
        end;   
   
      if strings[2][1] = '9' then
        begin
          var st := new Tstud;
          st.name := strings[0];
          st.surname := strings[1];
          st.class_number := strings[2];
          SetLength(c9, c9.Length+1);
          c9[c9.Length-1] := st;
        end   
    end;

  Sort(c9,cmp);
  Sort(c10,cmp);

  assign (f, 'output.txt');
  rewrite (f);
  for var i:=0 to c9.Length-1 do
    writeln(f, c9[i].name,' ', c9[i].surname, ' ', c9[i].class_number);
  for var i:=0 to c10.Length-1 do
    writeln(f, c10[i].name,' ', c10[i].surname, ' ', c10[i].class_number);

  close (f);
end.