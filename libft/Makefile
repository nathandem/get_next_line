# on static libraries
# are created via `ar rc lib_name.a <object files>`
# are used at compilation time with other object files, like: gcc -o program program_using_the_lib.o -L. -l lib`). This step is called linkage.
# this assumes the C files with which we want to use the library with must by compiled into object files before (`gcc -o name.o -c name.c`)
# note: the program using the lib may reference the lib via a header file which contains the prototype of the function


NAME = libft.a

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc includes/$@ $^

# syntax
# target:dependency
# $@ target
# -c: compile without linking, means generate .o files
# -I <dir> (a `gcc` option) is only useful to include a dir of header files
#   which are not in the directory of the sources
#   but  #include "myheader.h" is fine if myheader.h is in the same directory than the .c file
# $< refers to depencies, one by one (as opposed to $^)
# $^ refers to all the rule's dependencies (the part after the target and the colon)

%.o:%.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

.PHONY: clean fclean re

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
