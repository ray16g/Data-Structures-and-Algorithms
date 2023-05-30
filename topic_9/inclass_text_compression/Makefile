BIN = text_lzw

all: $(BIN).exe

$(BIN): test_lzw test_lzw.cpp lzw.cpp lzw.h
	g++ -o $(BIN).exe *.cpp

run: $(BIN).exe
	./$(BIN).exe -c books.txt books.cmp

clean:
	rm -rf $(BIN).exe