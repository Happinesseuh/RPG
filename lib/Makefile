##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##


### SOURCES ###
#----c_sources----#
SRC			:= files/int/compute/power_rec.c	\
			files/int/compute/square_root.c	\
			files/int/find_prime_sup.c	\
			files/int/intlen.c

SRC			+= files/is/int_prime.c	\
			files/is/str_alpha.c	\
			files/is/str_lower.c	\
			files/is/str_num.c	\
			files/is/str_numop.c	\
			files/is/str_isprintable.c	\
			files/is/str_upper.c

SRC			+= files/put/p_char.c	\
			files/put/p_str.c	\
			files/put/p_error.c	\
			files/put/p_nb_bin.c	\
			files/put/p_nb_un.c	\
			files/put/p_nb_unhex.c	\
			files/put/p_nb.c

SRC			+= files/str/revstr.c	\
			files/str/strcapitalize.c	\
			files/str/strcat.c	\
			files/str/strcmp.c	\
			files/str/strcpy.c	\
			files/str/strdup.c	\
			files/str/strlen.c	\
			files/str/strlen_tab.c	\
			files/str/strlowcase.c	\
			files/str/strncat.c	\
			files/str/strncmp.c	\
			files/str/strncpy.c	\
			files/str/strstr.c	\
			files/str/strupcase.c

SRC			+= files/to/atoi.c	\
			files/to/itoa.c	\
			files/to/itooct.c

SRC			+= files/get_next_line.c	\
			printf/printf.c	\
			printf/pf_def.c
### SOURCES ###


### COMPILE_USEFULL ###
CC			=	gcc
OBJ			=	$(SRC:.c=.o)
CPPFLAGS	=	-I ./include/
NAME		=	libmy.a
MAKEFLAGS 	:=	--no-print-directory
### COMPILE_USEFULL ###

all:		libmy.a

libmy.a:	$(NAME)
$(NAME):		$(OBJ)
			ar -rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all libmy.a clean fclean re
