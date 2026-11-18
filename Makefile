CC = gcc
CFLAGS = -Wall -O2 -I./data -I./src
LIBS = -lm

SRC = src/main.c src/puff.c data/params.c
TARGET = simulation

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET) output.csv