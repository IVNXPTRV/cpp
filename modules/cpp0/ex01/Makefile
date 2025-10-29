
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

NAME := phonebook 

INCLUDE_DIRS := \
						./include/

INCLUDE := $(addprefix -I,$(INCLUDE_DIRS))

SRC := \
					./src/Contact.cpp \
					./src/PhoneBook.cpp \
					./src/main.cpp \

OBJ := $(patsubst ./src/%.cpp,./obj/%.o,$(SRC))
DEP := $(patsubst ./src/%.cpp,./dep/%.d,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CXX) $(OBJ) -o $@

./obj/%.o: ./src/%.cpp | obj_dir dep_dir
	mkdir -p $(dir $@) ./dep/$(dir $(@:obj/%.o=%))
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ -MMD -MF $(patsubst ./obj/%.o,./dep/%.d,$@)

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
