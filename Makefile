main.exe: tutor.o student.o main.o
	g++ -o $@ -std=c++11 tutor.o student.o main.o

%.o: %.cpp
	g++ -std=c++11 -c $<  

clean:
	del *.o *.exe