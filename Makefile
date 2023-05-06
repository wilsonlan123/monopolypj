DiceRolling.o: DiceRolling.cpp DiceRolling.h
	g++ -c $<
OneInAHundred.o: OneInAHundred.cpp OneInAHundred.h
	g++ -c $<
hangman.o: hangman.cpp hangman.h
	g++ -c $<
drawnearn.o: drawnearn.cpp drawnearn.h
	g++ -c $<

main.o: main.cpp OneInAHundred.h DiceRolling.h hangman.h drawnearn.h 
	g++ -c $<
main: DiceRolling.o OneInAHundred.o hangman.o drawnearn.o main.o
	g++ $^ -o $@
clean: 
	rm -f main main.o OneInAHundred.o DiceRolling.o hangman.o drawnearn.o
.PHONY: clean 
