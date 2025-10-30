
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MF 
RM := rm -rf

NAME := megaphone

INCLUDE_DIRS := \
						./

INCLUDE := $(addprefix -I,$(INCLUDE_DIRS))

SRC := \
					./src/megaphone.cpp

OBJ := $(patsubst ./src/%.cpp,./obj/%.o,$(SRC))
DEP := $(patsubst ./src/%.cpp,./dep/%.d,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CXX) $(OBJ) -o $@

./obj/%.o: ./src/%.cpp | obj_dir dep_dir
	$(CXX) $(CXXFLAGS) ./dep/$(@:obj/%.o=%.d) $(INCLUDE) -c $< -o $@

obj_dir:
	@mkdir -p obj

dep_dir:
	@mkdir -p dep

clean:
	$(RM) obj
	$(RM) dep
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean fclean all

test:
	@echo "expect: -----------------------------------"
	@echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
	@echo "result: -----------------------------------"
	@./megaphone "shhhhh... I think the students are asleep..."
	@echo
	@echo "expect: -----------------------------------"
	@echo "DAMNIT  !  SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
	@echo "result: -----------------------------------"
	@./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	@echo
	@echo "expect: -----------------------------------"
	@echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
	@echo "result: -----------------------------------"
	@./megaphone

-include $(DEP)
