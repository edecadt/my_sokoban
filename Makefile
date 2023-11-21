##
## EPITECH PROJECT, 2023
## MyHunter
## File description:
## main
##

SRC = src/main.c \
	  src/sokoban.c \
	  src/ncurses.c \
	  src/files.c \
	  src/map.c \
	  src/player.c \
	  src/utils.c
OBJ_DIR = build
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))
CFLAGS += -Wextra -I./include
LDFLAGS += -L./lib \
           -lmy \
           -lncurses
NAME = my_sokoban
MKDIR_P = mkdir -p

$(shell $(MKDIR_P) $(OBJ_DIR))

all: libmy $(NAME)

libmy:
	make -C lib/my

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C lib/my clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmy
