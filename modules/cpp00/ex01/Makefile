
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MF 
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

-include $(DEP)
