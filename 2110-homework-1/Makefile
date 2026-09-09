output: main.o Container1.o Container2.o Container3.o
		g++ -Wall main.o Container1.o Container2.o Container3.o -o output

main.o: main.cpp Container1.hpp Container2.hpp Container3.hpp Client.hpp
		g++ -Wall -c main.cpp

Container1.o: Container1.cpp Container1.hpp Client.hpp
		g++ -Wall -c Container1.cpp

Container2.o: Container2.cpp Container2.hpp Client.hpp
		g++ -Wall -c Container2.cpp

Container3.o: Container3.cpp Container3.hpp Client.hpp
		g++ -Wall -c Container3.cpp

clean:
		rm *.o output