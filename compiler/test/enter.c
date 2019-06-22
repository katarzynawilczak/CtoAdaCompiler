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


