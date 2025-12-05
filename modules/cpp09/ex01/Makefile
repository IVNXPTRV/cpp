
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MF 
RM := rm -rf

NAME := RPN 

INCLUDE_DIRS := \
						./include/

INCLUDE := $(addprefix -I,$(INCLUDE_DIRS))

SRC := \
					./src/main.cpp \
					./src/RPN.cpp \

OBJ := $(patsubst ./src/%.cpp,./obj/%.o,$(SRC))
DEP := $(patsubst ./src/%.cpp,./dep/%.d,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CXX) $(OBJ) -o $@
	@echo ""

./obj/%.o: ./src/%.cpp | obj_dir dep_dir
	$(CXX) $(CXXFLAGS) ./dep/$(@:obj/%.o=%.d) $(INCLUDE) -c $< -o $@

obj_dir:
	@mkdir -p obj

dep_dir:
	@mkdir -p dep

clean:
	$(RM) obj
	$(RM) dep

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	@echo "--- RUN ---"
	@echo ""
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +" 
	./$(NAME) "7 7 * 7 -" 
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +" 
	./$(NAME) "(1 + 1)" 
	@echo ""
	@echo "--- END ---"
	@echo ""
	@make fclean

test: leaks

leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

-include $(DEP)
