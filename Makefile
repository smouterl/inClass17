
CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = ICA17

SRCS = ICA17.c average.c minmax.c sunspot_parser.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

ICA17.o: ICA17.c data.h minmax.h sunspot_parser.h
average.o: average.c data.h
minmax.o: minmax.c minmax.h data.h
sunspot_parser.o: sunspot_parser.c sunspot_parser.h data.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
