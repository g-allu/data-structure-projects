CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJS = main.o DriverDatabase.o LinkedList.o HashTable.o Stack.o Queue.o \
       Driver.o DerivedDrivers.o Ticket.o Address.o Date.o
       
TARGET = driver_db

all: $(TARGET) data_gen

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

data_gen: generate_data.cpp
	$(CXX) $(CXXFLAGS) -o generate_data generate_data.cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) generate_data drivers.txt
