program task4;

var 
  inf,outf:text;
  
function is_number(w: string): boolean;
begin
  for var j := 1 to w.Length do
    begin
	    if (w[j] < '0') or (w[j] > '9') then
	      begin
	        result :=false;
	        exit;
	      end; 
    end;
  result :=true;
end;

function insert_spaces(w:string): string;
begin
  if (w.Length <= 3) then
	  result := w
	else
	begin
    var outstr: string;
    var k := 0;
    for var j:= w.Length downto 1 do
      begin 
        outstr+=w[j];
        Inc(k);
        if (k mod 3 = 0) and (j <> 0) then
          outstr+=' '; 
      end;
    result := outstr.Inverse;
  end;
end;

function process_word(w: string): string;
begin
  if is_number(w) then
	  result := insert_spaces(w)
  else 
    result := w;
end;
  
begin
  assign(inf, 'input.txt');
  reset(inf);
  assign(outf, 'output.txt');
  rewrite(outf);

  var ss: array of string;
  SetLength(ss, 0);
  foreach var s in ReadLines('input.txt') do 
  begin
    var words := s.ToWords;
    for var i := 0 to words.Length-1 do
      words[i] := process_word(words[i]);  
    writeln(outf, words.JoinIntoString(' '));
  end;
   
  close(inf);     
  close(outf);     
end.
