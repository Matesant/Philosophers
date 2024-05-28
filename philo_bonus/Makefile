CC			:= cc
NAME 		:= philo_bonus
CFLAGS		:= -Wall -Werror -Wextra -g3 -O0 -pthread
BIN			:= ./bin/
HEADER		:= ./include/
SOURCE		:=	main.c print.c tabble_manners.c time_measure.c args_check_utils.c user_input.c ft_atol.c routine.c activities.c\
				dinning.c

OBJECTS		:= $(addprefix $(BIN),$(SOURCE:.c=.o))

BLUE = \033[1;34m
RED=\033[0;31m
GREEN=\033[0;32m
END=\033[0m

all: $(BIN) $(NAME)

$(BIN):
	@mkdir -p $(BIN)

$(BIN)%.o: ./%.c $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(BIN)%.o: ./src_bonus/user_validations/%.c $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(BIN)%.o: ./src_bonus/utils/%.c $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(BIN)%.o: ./src_bonus/philosophers/%.c $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(BIN)%.o: ./src_bonus/time_management/%.c $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(BIN)%.o: ./src_bonus/philosophers_rules/%.c $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(BIN)%.o: ./src_bonus/forks_creation/%.c $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJECTS) $(HEADER)philo_bonus.h
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $(NAME)...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
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
