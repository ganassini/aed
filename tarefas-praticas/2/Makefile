CC = gcc
CFLAGS = -Wall -Wextra -g

SRC_AULA = 1792-aula.c
TARGET_AULA = 1792-aula

SRC_CASA_1 = 1792-casa-1.c
TARGET_CASA_1 = 1792-casa-1

SRC_CASA_2 = 1792-casa-2.c
TARGET_CASA_2 = 1792-casa-2

SRC_CASA_3 = 1792-casa-3.c
TARGET_CASA_3 = 1792-casa-3

aula: $(SRC_AULA)
	$(CC) $(CFLAGS) $(SRC_AULA) -o $(TARGET_AULA)

casa-1: $(SRC_CASA)
	$(CC) $(CFLAGS) $(SRC_CASA_1) -o $(TARGET_CASA_1)

casa-2: $(SRC_CASA)
	$(CC) $(CFLAGS) $(SRC_CASA_2) -o $(TARGET_CASA_2)

casa-3: $(SRC_CASA)
	$(CC) $(CFLAGS) $(SRC_CASA_3) -o $(TARGET_CASA_3)

clean:
	rm -f $(TARGET_AULA) $(TARGET_CASA_1) $(TARGET_CASA_2) $(TARGET_CASA_3)

.PHONY: all clean

