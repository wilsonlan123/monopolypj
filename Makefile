DiceRolling.o: DiceRolling.cpp DiceRolling.h
	g++ -c $<
OneInAHundred.o: OneInAHundred.cpp OneInAHundred.h
	g++ -c $<
main.o: main.cpp OneInAHundred.h DiceRolling.h
	g++ -c $<
main: DiceRolling.o OneInAHundred.o main.o
	g++ $^ -o $@
clean: 
	rm -f main main.o OneInAHundred.o DiceRolling.o 
.PHONY: clean 

//please append codes for other minigames 
