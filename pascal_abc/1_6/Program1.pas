program task1;

var 
  inf,outf:text;
  
function to_binary(t: string):string; 
begin
  var x: integer;
  x := StrToInt(t);
  var mask := 1;
  var s:string;
  while mask <= x do
    begin
      if (mask and x) = 0 then 
        s+='0'
      else
        s+='1';
      mask := mask shl 1;
	  end;
	result := s.Inverse;
end;  

begin
  assign(inf, 'input.txt');
  reset(inf);
  assign(outf, 'output.txt');
  rewrite(outf);
  
  foreach var s in ReadLines('input.txt') do
    begin
      var k := to_binary(s).Length*3;
      var snum := k.ToString;
      writeln(outf,to_binary(snum));
    end;  
   
  close(inf);     
  close(outf); 
end.