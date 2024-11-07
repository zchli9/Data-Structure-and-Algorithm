CXX = g++
CXXFLAGS = -std=c++20 -Wall
TARGET = calculator
SRC = main.cpp expression_evaluator.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

report:
	xelatex report.tex

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
