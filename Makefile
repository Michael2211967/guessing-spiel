# Erkennung des Betriebssystems:
ifeq ($(OS),Windows_NT)
	RM = del /Q
	TARGET = guessing.exe
	EXT = .exe
	FIX_PATH = $(subst /,\,$1)
else
	# Linux-Einstellungen
	RM = rm -f
	TARGET = guessing
	EXT =
	FIX_PATH = $1
endif

CC = gcc
CFLAGS = -Wall -I./mod
MOD_DIR = mod
OBJ = guessing.o $(MOD_DIR)/tools.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

guessing.o: guessing.c
	$(CC) $(CFLAGS) -c guessing.c

$(MOD_DIR)/tools.o: $(MOD_DIR)/tools.c
	$(CC) $(CFLAGS) -c $(MOD_DIR)/tools.c -o $(MOD_DIR)/tools.o

clean:
	$(RM) $(TARGET) *.o $(call FIX_PATH,$(MOD_DIR)/*.o)