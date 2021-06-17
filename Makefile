NAME		=	push_swap
NAME_B		=	checker

CC			=	gcc 
CFLAGS		=	-Wall -Wextra -Werror 

SRCS_DIR	=	./srcs/
OBJ_DIR		=	./objs/

SRCS		= 	push_swap.c
SRCS		+= 	stack_tools.c
SRCS		+= 	instruction.c 
SRCS		+= 	parse.c
SRCS		+= 	sort.c
SRCS		+= 	sort_a.c
SRCS		+= 	utils.c

SRCS_B		= 	checker.c
SRCS_B		+= 	stack_tools.c
SRCS_B		+= 	instruction.c 
SRCS_B		+= 	parse.c
SRCS_B		+= 	utils.c
SRCS_B		+= 	get_next_line.c



OBJ			=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
OBJ_B		=	$(addprefix $(OBJ_DIR),$(SRCS_B:.c=.o))

RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf

$(OBJ_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS)	$(INC) -c $< -o $@

all:
	@mkdir -p $(OBJ_DIR)
	@make $(NAME) 

make_libft:
	@make -C libft/ 

$(NAME): $(OBJ)  make_libft
	@$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

bonus:
	@mkdir -p $(OBJ_DIR)
	@make $(NAME_B) 

$(NAME_B): $(OBJ_B)  make_libft
	@$(CC) $(CFLAGS) $(OBJ_B) ./libft/libft.a   -o $(NAME_B)

clean:
	@make clean -C libft/ 
	$(RM_DIR) $(OBJ_DIR)

fclean: clean
	rm -rf ${NAME_B} ${NAME}
	@make fclean -C libft/ 
re: clean all