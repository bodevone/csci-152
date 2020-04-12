

Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17
CPP = g++


main : Makefile   main.o set.o 
	$(CPP) $(Flags) -o main   main.o set.o 

main.o : Makefile   main.cpp   timer.h timetable.h set.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


set.o : Makefile   set.cpp   set.h 
	$(CPP) -c $(Flags) set.cpp -o  set.o


