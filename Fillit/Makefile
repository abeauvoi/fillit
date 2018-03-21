NAME	 = Fillit
LIB		 = libft.a

LIB_DIR		= libft
PARSER_DIR	= parser
SRC_DIR		= src
ALGO_DIR	= algo
OBJ_DIR		= obj

VPATH	 = $(SRC_DIR):$(addprefix $(SRC_DIR)/, $(PARSER_DIR) $(ALGO_DIR))

SRC		= main.c parser.c algo.c list.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -I./$(LIB_DIR)
LFLAGS	= -L $(LIB_DIR) -lft

COMP	= $(CC) $(CFLAGS) -o $@ -c $<
LINK	= $(CC) $(LFLAGS) -o $@ $(filter-out $(LIB_DIR)/$(LIB) $(OBJ_DIR), $^)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(LIB_DIR)/$(LIB):
	@make -C $(LIB_DIR)

$(NAME): $(LIB_DIR)/$(LIB) $(OBJ_DIR) $(OBJ)
	@$(LINK)

$(OBJ_DIR)/%.o: %.c
	@$(COMP)

clean:
	@rm $(OBJ) 2> /dev/null || true
	@rm -rf $(OBJ_DIR)
	@echo "cleaned .o files"

fclean: clean
	@rm $(NAME)
	@echo "removed binary"

re: fclean all

.PHONY: all clean fclean re
