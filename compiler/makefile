all:
	$(MAKE) grammar
	$(MAKE) lex
	g++ -c compiler/grammar.tab.c compiler/lex.yy.c
	mv *.o compiler
	ar rvs compiler/lexgram.a compiler/grammar.tab.o compiler/lex.yy.o
	g++ -std=c++11 -Wall -Wextra compiler/main.cpp compiler/lexgram.a
	mkdir -p bin
	mv a.out bin

grammar:
	@echo "\033[92m"grammar compile:"\033[0m"
	#bison -v -d compiler/grammar.y # grammar.output generate for debugging
	bison -d compiler/grammar.y
	mv grammar.tab.* compiler

lex:
	@echo "\033[92m"lex compile:"\033[0m"
	flex compiler/lex.l
	mv lex.yy.* compiler
	@echo "\033[92m"end of lex compile"\033[0m"

run:
	$(MAKE) all
	mkdir -p compiled
	./bin/a.out < test/enter.c > compiled/output.adb
	
	@echo "\033[92m"output.adb compile:"\033[0m"
	gnatmake compiled/output.adb
	@echo "\033[92m"output.adb run:"\033[0m"
	./output
	$(MAKE) clean
	
clean:
	@echo "\033[92m"cleaning:"\033[0m"
	rm -f compiled/output.out bin/a.out compiler/grammar.tab.* compiler/lex.yy.* compiler/lexgram.a
	find . -empty -type d -delete
	rm output.o output.ali output
