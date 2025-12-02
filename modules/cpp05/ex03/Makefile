
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MF 
RM := rm -rf

NAME := ex02

INCLUDE_DIRS := \
						./include/

INCLUDE := $(addprefix -I,$(INCLUDE_DIRS))

SRC := \
					./src/main.cpp \
					./src/Bureaucrat.cpp \
					./src/AForm.cpp \
					./src/ShrubberyCreationForm.cpp \
					./src/RobotomyRequestForm.cpp \
					./src/PresidentialPardonForm.cpp \
					./src/Intern.cpp \

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
	$(RM) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)
	make fclean

test: leaks

leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

-include $(DEP)
