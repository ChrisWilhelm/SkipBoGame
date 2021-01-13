# Chris Wilhelm cwilhel8
# Derek Dang ddang8
# Udochukwu Nwosu unwosu6
#
CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CPPFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)
OBJ = main.o Card.o Pile.o DrawPile.o Player.o FaceUpPile.o Hand.o SkipBoGame.o BuildPile.o

skipbo:	$(OBJ)
	$(CC)  -o skipbo $(OBJ) $(CPPFLAGS)

main.o: 

Card.o: Card.h

Pile.o: Pile.h Card.h

DrawPile.o: DrawPile.h Pile.h

FaceUpPile.o: FaceUpPile.h Card.h Pile.h

BuildPile.o : BuildPile.h FaceUpPile.h Card.h Pile.h

Hand.o: Hand.h FaceUpPile.h Card.h

Player: Player.h FaceUpPile.h DrawPile.h

SkipBoGame: SkipBoGame.h

.PHONY: clean
clean:
	rm -f $(OBJ) skipbo *~
