
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/game

SRC= main.c init_game.c init_game_byclick.c play_game.c view_game.c utility.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   -lSDL2 -lSDL2_image

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c init_game.h
init_game.o: init_game.c init_game.h
init_game_byclick.o: init_game_byclick.c init_game.h
play_game.o: play_game.c init_game.h
view_game.o: view_game.c init_game.h
utility.o: utility.c init_game.h
