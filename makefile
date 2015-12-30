CPP = g++
ARGS = -Wall -Werror -Wextra

LIB = lib/
BUILD = build/
SOURCE = src/

OFILES = $(patsubst $(SOURCE)%.cpp, $(BUILD)%.o, $(wildcard $(SOURCE)*.cpp))

TARGET = output

all: $(TARGET)

$(TARGET) : $(OFILES)
	$(CPP) $(ARGS) $(OFILES) -o $(TARGET)

$(BUILD)%.o : $(SOURCE)%.cpp
	$(CPP) $(ARGS) -I $(LIB) $^ -c -o $@

clean:
	rm -f *.o
	rm-f $(TARGET)
