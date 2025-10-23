# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 16:21:24 by rponomar          #+#    #+#              #
#    Updated: 2025/06/18 01:58:47 by rponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replacer

ifeq ($(origin CXX), default)
CXX = c++
endif

ifeq ($(origin RM), default)
RM = rm -rf
endif

CXXSRC = \
	main.cpp	\
	Replacer.cpp
	
HDRS = \
	Replacer.hpp

CXXFLAGS ?= -O2
override CXXFLAGS += -std=c++98 -Wall -Wextra -Werror

override CPPFLAGS += -I.

.PHONY: all
all: $(NAME)

$(NAME): $(CXXSRC) $(HDRS) Makefile
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(CXXSRC) -o $@
	@echo "$(NAME): compiled"

.PHONY: clean
clean:

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)

.PHONY: re
re: fclean all