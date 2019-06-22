with Ada.Text_IO;

procedure Output Is

function iloczyn(a : in out Integer; b : in out Integer) return Integer is
c : Integer := 0;
begin
Ada.Text_IO.Put_Line("Iloczyn");
c := a * b;
return c;
end iloczyn;

procedure foo(param : in out Boolean) is
begin

if param = true then
Ada.Text_IO.Put_Line("foo");
else
Ada.Text_IO.Put_Line("falseFoo");
end if;

end foo;

a : Integer := 2;
b : Integer := 5;
c : Integer := 10;
d : Integer;
begin
d := iloczyn(b, c);
Ada.Text_IO.Put_Line(b'Image);
Ada.Text_IO.Put_Line(d'Image);

while a /= b loop
Ada.Text_IO.Put_Line("loop");
a := a + 1;
end loop;

loop
a := a + 1;
exit when a /= c;
end loop;

case a is
when 1 =>
Ada.Text_IO.Put_Line("1");
when 2 =>
Ada.Text_IO.Put_Line("2");
when others =>
Ada.Text_IO.Put_Line("0");
end case;

end Output;
