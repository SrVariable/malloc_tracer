# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 20:47:53 by ribana-b          #+#    #+# Malaga       #
#    Updated: 2024/08/24 22:36:37 by ribana-b         ###   ########.com       #
#                                                                              #
# **************************************************************************** #

# @--------------------------------------------------------------------------@ #
# |                                 Colors                                   | #
# @--------------------------------------------------------------------------@ #

T_BLACK := \033[30m
T_RED := \033[31m
T_GREEN := \033[32m
T_YELLOW := \033[33m
T_BLUE := \033[34m
T_MAGENTA := \033[35m
T_CYAN := \033[36m
T_WHITE := \033[37m

BOLD := \033[1m
ITALIC := \033[2m
UNDERLINE := \033[3m
STRIKETHROUGH := \033[4m

CLEAR_LINE := \033[1F\r\033[2K

RESET := \033[0m

# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

NAME := libmalloctracer.a

INCLUDE_DIR := ./
SRC_DIR := ./
OBJ_DIR := ./obj/

INCLUDE_FILES := malloc_tracer.h
SRC_FILES := malloc.c free.c debug.c

INCLUDE = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC := gcc
CFLAGS := -Wall -Wextra -Werror

ifdef WITH_DEBUG
	CFLAGS += -ggdb -DDEBUG=1
endif

CPPFLAGS := -I $(INCLUDE_DIR)

RM := rm -rf

# @--------------------------------------------------------------------------@ #
# |                                Messages                                  | #
# @--------------------------------------------------------------------------@ #

COMPILE_MSG = @echo "$(CLEAR_LINE)🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "✅ 🦔 $(T_YELLOW)$(BOLD)$(NAME) Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
OUTPUT_MSG = @echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
CLEAN_MSG = @echo "🗑️  🦔 $(T_YELLOW)$(BOLD)$(NAME) Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"
FCLEAN_MSG = @echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@ar rcs $@ $(OBJ)
	$(OUTPUT_MSG)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	$(CLEAN_MSG)

fclean:
	@make -s clean
	@$(RM) $(NAME) tags a.out
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@make -s all

debug:
	@make -s WITH_DEBUG=1

example: $(NAME)
	@gcc $(NAME) main.c libmalloctracer.a
	@./a.out

example_debug:
	@make -s debug
	@gcc -DDEBUG=1 -g $(NAME) main.c libmalloctracer.a
	@./a.out

tags:
	@$(shell find . -path ./bonus_part -prune -o -print -type f \( -name "*c" -o -name "*.h" \) > temp)
	@ctags -F $(shell cat temp)
	@$(RM) temp

.PHONY = all clean debug example fclean re tags
