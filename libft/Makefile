CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I includes/

BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
GRAY	= \033[0;37m
NC		= \033[0m


AR      = ar rcs

NAME    = libft.a
HEAD    = libft.h

SRC_DIR	=	./srcs/
OBJ_DIR		=	./objs/
INC_DIR		=	./includes/

PRINT	=	ft_putchar_fd.c 
PRINT	+=	ft_putendl_fd.c 
PRINT	+=	ft_putnbr_fd.c 
PRINT	+=	ft_putstr_fd.c 
PRINT	+=	ft_putchar.c 
PRINT	+=	ft_putendl.c 
PRINT	+=	ft_putnbr.c 
PRINT	+=	ft_putstr.c 

MEM		=	ft_memccpy.c 
MEM		+=	ft_memmove.c 
MEM		+=	ft_memset.c 
MEM		+=	ft_memalloc.c 
MEM		+=	ft_memchr.c 
MEM		+=	ft_memcmp.c 
MEM		+=	ft_memcpy.c 
MEM		+=	ft_calloc.c 
MEM		+=	ft_free.c 
MEM		+=	ft_bzero.c 

STR		=	ft_strchr.c 
STR		+=	ft_strrchr.c 
STR		+=	ft_strnstr.c 
STR		+=	ft_strdup.c 
STR		+=	ft_strjoin.c 
STR		+=	ft_strtrim.c 
STR		+=	ft_strlcat.c 
STR		+=	ft_strlcpy.c 
STR		+=	ft_substr.c 
STR		+=	ft_strlen.c 
STR		+=	ft_split.c 
STR		+=	ft_strncmp.c 
STR		+=	ft_strcpy.c 
SRC		+=	ft_strmapi.c 
STR		+=	ft_strcmp.c 
STR		+=	ft_strisnum.c 

CHAR	=	ft_isdigit.c 
CHAR	+=	ft_toupper.c 
CHAR	+=	ft_tolower.c 
CHAR	+=	ft_isalpha.c 
CHAR	+=	ft_isascii.c 
CHAR	+=	ft_isalnum.c 
CHAR	+=	ft_isprint.c 

MATH		=	ft_atoi.c 
MATH		+=	ft_itoa.c 
MATH		+=	ft_itoa_base.c 


SRC		=	$(addprefix ft_put/, $(PRINT))
SRC		+=	$(addprefix ft_mem/, $(MEM))
SRC		+=	$(addprefix ft_str/, $(STR))
SRC		+=	$(addprefix char/, $(CHAR))
SRC		+=	$(addprefix ft_math/, $(MATH))

OBJ			=	$(addprefix $(OBJ_DIR),$(SRC:.c=.o))

INC			=	$(addprefix -I,$(INC_DIR))

RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INC_DIR)*.h
	@$(CC) $(CFLAGS) -c $< -o $@

all:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/ft_math
	@mkdir -p $(OBJ_DIR)/char
	@mkdir -p $(OBJ_DIR)/ft_mem
	@mkdir -p $(OBJ_DIR)/ft_put
	@mkdir -p $(OBJ_DIR)/ft_str
	@mkdir -p $(OBJ_DIR)/tab
	@$(MAKE) $(NAME) --no-print-directory

$(NAME): $(OBJ)
	@$(AR) $(NAME) $?


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

eclean: clean fclean

re: fclean all