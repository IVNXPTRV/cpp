
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MF 
RM := rm -rf

NAME := PmergeMe 

INCLUDE_DIRS := \
						./include/

INCLUDE := $(addprefix -I,$(INCLUDE_DIRS))

SRC := \
					./src/main.cpp \
					./src/PmergeMe.cpp \

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
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "` 
	@echo ""
	./$(NAME) 3 5 9 7 4 
	@echo ""
	./$(NAME)  "-1" "2"
	@echo ""
	./$(NAME)  "A" "2"
	@echo ""
	./$(NAME)  "1" "1"
	@echo ""
	./$(NAME)  
	@echo ""
	@echo "--- END ---"
	@echo ""
	@make fclean

test: leaks

leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

-include $(DEP)
