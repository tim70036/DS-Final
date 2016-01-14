CC = g++ -std=c++11

SRCS = ../*.cpp
RO_SRCS = ./*.cpp

main: RO SRC
	$(CC) -o $@ *.o

SRC: $(SRCS)
	$(CC) -c $(SRCS)

RO: $(RO_SRCS)
	$(CC) -c $(RO_SRCS)

.PHONY: clean

clean:
	rm main *.o
