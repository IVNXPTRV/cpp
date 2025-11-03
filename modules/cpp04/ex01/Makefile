
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MF 
RM := rm -rf

NAME := animal 

INCLUDE_DIRS := \
						./include/

INCLUDE := $(addprefix -I,$(INCLUDE_DIRS))

SRC := \
					./src/main.cpp \
					./src/Animal.cpp \
					./src/Dog.cpp \
					./src/Cat.cpp \
					./src/Brain.cpp \
					./src/WrongCat.cpp \
					./src/WrongAnimal.cpp \

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

test: leaks

leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0 0 20 0 10 30 1 1

-include $(DEP)
