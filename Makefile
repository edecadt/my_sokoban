##
## EPITECH PROJECT, 2023
## MyHunter
## File description:
## main
##

SRC = src/main.c \
	  src/sokoban.c \
	  src/game/loop.c \
	  src/game/check.c \
	  src/input/down.c \
	  src/input/up.c \
	  src/input/left.c \
	  src/input/right.c \
	  src/input/handle.c \
	  src/input/reset.c \
	  src/map/analyze.c \
	  src/map/display.c \
	  src/map/free.c \
	  src/map/init.c \
	  src/map/load.c \
	  src/map/parse.c \
	  src/utils/can_move.c \
	  src/utils/get_element_on_pos.c \
	  src/utils/move_box.c \
	  src/utils/move_player.c
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
