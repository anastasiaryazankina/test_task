program task2;

var   
  f:text;

begin
  assign (f, 'input.txt');
  reset (f);
  foreach var s in ReadLines('input.txt') do
    begin
    	var space_cnt := 0; 
    	var u_cnt := 0;
      for var i := 1 to Length(s) do
        begin 
          if  (s[i] = '!') then break;
          case s[i] of
            ' ' : Inc(space_cnt);
            'u': Inc(u_cnt);
          end;
        end;
        assign (f, 'output.txt');
        rewrite (f);
        writeln(f, 'Count of spaces - ', space_cnt);
        if (u_cnt > 0) then 
          writeln(f, 'u - exist ')
        else
          writeln(f, 'u - not exist');
    end;
  close(f);
end.