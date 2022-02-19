##
## EPITECH PROJECT, 2020
## infin_add
## File description:
## Makefile
##

CC	= gcc

SRC	= $(wildcard *.c)

OBJ	= $(SRC:.c=.o)

INC 	= -I ./include/

LIB 	= ./lib_short/libmy_short.a

LIB_SHORT	= -I ./lib_short/include/ -L ./lib_short/ -lmy_short

CSFML_FLAGS	= -l csfml-graphics -l csfml-system -l csfml-audio

BIN 	= my_hunter

FLAGS	= -W -Wall -Wextra

all: $(LIB)
	$(CC) $(SRC) -c $(FLAGS) $(INC) $(CSFML_FLAGS) $(LIB_SHORT)
	$(CC) $(OBJ) -o $(BIN) $(FLAGS) $(INC) $(CSFML_FLAGS) $(LIB_SHORT)

$(LIB):
	make -C ./lib_short/

clean:
	$(RM) *~
	$(RM) #*#
	$(RM) *.o
	make clean -C ./lib_short/

fclean: clean
	$(RM) $(BIN)
	$(RM) $(LIB)
	make fclean -C ./lib_short/

re: fclean all