# C2Ada Compiler
Program compiles chosen elements of C programming language to Ada. Compiler was written in C++ and it uses scanner generator Flex and parser generator Bison.

# Project structure
Packages:
 * **compiler** - contains list of tokens and grammar of the project
 * **SyntaxTree** - code generator, represented by syntactic tree
 * **compiled** - contains generated file in Ada
 * **test** - contains input files written in C

**Makefile** consist of necessary commands to compile code, generate scanner and parser, create directories, clean files and run output code in Ada

# Run
To run program you need to put input code in **test/enter.c**. Then run **makefile** using command:
``make run``
The output code will be placed in **compiled/output.adb**. Then it will be compiled and the result will be presented in terminal.

# Examples
Input:
```
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int iloczyn (int a, int b) {
	int c = 0;
	printf("Iloczyn");
	c = a*b;
	return c;
}

void foo(bool param){
	if(param==true) printf("foo");
	else printf("falseFoo");
}

/* funkcja main */

int main() {
	int a=2;
	int b=5;
	int c=10;
	int d;
	
	d=iloczyn(b, c);
	printf("%d", b);
	printf("%d", d);
	
	while(a!=b){
		printf("loop");
		a++;
	}

	
	do a++;
	while(a!=c);

	/*do printf("def");
	while(a!=c);*/
	

	switch(a){
		case 1:
			printf("1");
 			break;
		case 2:
			printf("2");
			break;
		default:
			printf("0");
			break;
	}			

	
}
```
After compilation:
```
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
```

# Restrictions
Chosen elements of C language approved in input file:

* one file only
* main function
* functions return void or chosen types
* variables declarations at the beginning of functions
* types: int, char, string, bool
* instructions: while, do while, if else, switch
* chosen mathematical and logic operators
* printf with strings and numbers only
* linear and block comments
 