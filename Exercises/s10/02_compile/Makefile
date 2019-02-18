EXE = exe
CXX = c++
CXXFLAGS = -I include -std=c++11 -g

SRC = src/src1.cc src/src2.cc main.cc
OBJ = $(SRC:.cc=.o)

all: $(EXE)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXE): $(OBJ)
	$(CXX) $^ -o  $(EXE)

clean:
	rm -rf src/*.o main.o $(EXE) */*~ *~

.PHONY: clean all
