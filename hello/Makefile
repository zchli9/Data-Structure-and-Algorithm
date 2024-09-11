CC = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = hello

SOURCES = hello.cpp

$(TARGET): $(SOURCES)
	$(CC) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)