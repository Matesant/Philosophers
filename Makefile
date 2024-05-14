CC			:= cc
NAME 		:= philo
CFLAGS		:= -Wall -Werror -Wextra -g3 -O0 -pthread
BIN			:= ./bin/
HEADER		:= ./include/
SOURCE		:=	main.c user_input.c args_check_utils.c ft_atol.c
OBJECTS		:= $(addprefix $(BIN),$(SOURCE:.c=.o))

BLUE = \033[1;34m
RED=\033[0;31m
GREEN=\033[0;32m
END=\033[0m

all: $(BIN) $(NAME)

$(BIN):
	@mkdir -p $(BIN)

$(BIN)%.o: ./src/%.c $(HEADER)philosophers.h
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(BIN)%.o: ./src/user_validations/%.c $(HEADER)philosophers.h
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(BIN)%.o: ./src/utils/%.c $(HEADER)philosophers.h
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJECTS) $(HEADER)philosophers.h
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $(NAME)...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(42LIBS) -o $(NAME)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(GREEN)--$(NAME) compiled!-$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"

clean:
	@printf "$(RED)Cleaning...$(END)\n"
	@rm -rf $(BIN)

fclean: clean
	@printf "$(RED)Cleaning...$(END)\n"
	@rm -rf $(NAME)
	@printf "$(GREEN)All cleaned!$(END)\n"

re: fclean all

val:
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo

.PHONY: all clean fclean re val
