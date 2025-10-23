# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aomont <aomont@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 14:35:32 by aomont            #+#    #+#              #
#    Updated: 2025/09/08 14:35:33 by aomont           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### PROJECT CONFIG
NAME		= mutantStack
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(OBJS:.o=.d)

################################################################################
## COMPILER CONFIG
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
DEPFLAGS	= -MMD -MP
RM			= rm -f

################################################################################
### BUILD RULES
all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(BLUE)✨ Linking $@...$(RESET)"
			@$(CXX) $(CXXFLAGS) $^ -o $@
			@echo "$(GREEN)🚀 Successfully compiled $@$(RESET)"

%.o:		%.cpp
			@echo "$(BLUE)✨ Compiling $<...$(RESET)"
			@$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
			@echo "$(YELLOW)💥 Cleaning object files...$(RESET)"
			@$(RM) $(OBJS) $(DEPS)

fclean:		clean
			@echo "$(YELLOW)💥 Removing $(NAME)...$(RESET)"
			@$(RM) $(NAME)

re:			fclean all

################################################################################
### DEPENDENCIES
-include $(DEPS)

################################################################################
### COLORS
GREEN		= \033[1;32m
RED			= \033[1;31m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
RESET		= \033[0m

.PHONY:	all clean fclean re
