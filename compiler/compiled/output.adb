with Ada.Text_IO;

procedure Output Is
function iloczyn(a : in out Integer; second : in out Integer) return Integer is
c : Integer := 3;
k : Boolean := true;
begin

if c /= 3 then
Ada.Text_IO.Put_Line("1");
end if;

c := a * a + 3 - (a * c);
return c;
end iloczyn;

function sum(a : in out Integer; b : in out Integer) return Integer is
c : Integer;
begin
a := a + 1;
b := b - 1;
a := a + b;
a := a / 4;
Ada.Text_IO.Put_Line("45");
return a + b;
end sum;

procedure foo is
begin
Ada.Text_IO.Put_Line("foo");
return;
end foo;

a : Integer := 1;
b : Integer := 2;
c : Integer;
i : Integer;
variable : Integer;
begin
Ada.Text_IO.Put_Line("write454356jku6h");

if a /= b then
c := a + 3;
elsif a = b then
Ada.Text_IO.Put_Line("equal");
else
c := b + 3;
end if;


if a = b then
Ada.Text_IO.Put_Line("1");
elsif a = 0 then
Ada.Text_IO.Put_Line("b");
else
b := c;
end if;


while a /= (variable) loop
b := 3;
a := variable;
end loop;


loop
Ada.Text_IO.Put_Line("abc");
exit when a /= b;
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
