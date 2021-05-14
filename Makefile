##
## EPITECH PROJECT, 2020
## BSQ
## File description:
## Makefile
##


### SOURCES ###
MAIN_SRC	:= src/main.c

SRC			:= src/base/draw.c	\
			src/base/adv.c	\
			src/base/back_to.c	\
			src/base/fill.c	\
			src/base/init.c	\
			src/base/rpg.c	\
			src/enemy/init.c	\
			src/enemy/check_enemies.c	\
			src/enemy/fill_map_with_enemy.c	\
			src/enemy/open_read_enemy_conf.c	\
			src/combat/display.c	\
			src/combat/init.c	\
			src/combat/turn.c	\
			src/combat/core.c	\
			src/player/move_player.c	\
			src/player/init.c	\
			src/player/move_direction.c	\
			src/player/lvl.c	\
			src/map/init_map_object.c	\
			src/map/init_map_base.c	\
			src/map/my_str_to_word_array.c	\
			src/map/map_data_init.c	\
			src/map/open_read.c	\
			src/map/init_quest.c	\
			src/map/init_inventory.c	\
			src/map/generate_object.c	\
			src/map/mini_map.c			\
			src/sound/init.c	\
			src/sound/man.c	\
			src/quest/quest.c	\
			src/intro.c	\
			src/tools.c	\
			src/free.c	\
			src/rain.c

UT_SRC		:= tests/.c
#UT_SRC		+= tests/.c
### SOURCES ###


### FLAGS ###
CC			=	gcc

OBJ			=	$(SRC:.c=.o)
UT_OBJ		=	$(UT_SRC:.c=.o)
MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

NAME		=	my_rpg
MAKEFLAGS 	+=	--no-print-directory
MFLAGS		+=	-sC

CFLAGS		:=	-Wall -Wextra -g3
CPPFLAGS	:=	-I ./include/

LDFLAGS		:= 	-L./lib/
LDLIBS		:= -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window -lmy

UT_NAME		=	testbin
UT_FLAGS	=	--coverage -lcriterion
### COMPILE_USEFULL ###


### COLORS ###
ccred		= @echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\033[0m"
ccyellow	= @echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\033[0m"
ccend		= @echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\033[0m"
### COLORS ###


all:		$(NAME)
$(NAME):	$(OBJ) $(MAIN_OBJ)
			$(MAKE) $(MFLAGS) lib/
			$(CC) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LDFLAGS) $(LDLIBS)
			@$(call ccend, "Project successfully compiled.")

clean:
			$(MAKE) $(MFLAGS) lib/ clean
			$(RM) $(OBJ) $(MAIN_OBJ) $(UT_OBJ) *.gc* *.vgcore vgcore.*
			@$(call ccyellow, "Project cleaned.")

fclean:		clean
			$(MAKE) $(MFLAGS) lib/ fclean
			$(RM) $(NAME) $(UT_NAME)
			@$(call ccred, "Project fully cleaned.")

re:			fclean all
.PHONY:		all tests_run utest clean fclean re
