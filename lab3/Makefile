
Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17
CPP = g++


sorttests : Makefile   sorttests.o
	$(CPP) $(Flags) -o sorttests   sorttests.o

sorttests.o : Makefile   sorttests.cpp   timetable.h timer.h
	$(CPP) -c $(Flags) sorttests.cpp -o  sorttests.o
