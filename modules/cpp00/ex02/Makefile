
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

NAME := account 

INCLUDE_DIRS := \
						./include/

INCLUDE := $(addprefix -I,$(INCLUDE_DIRS))

SRC := \
					./src/Account.cpp \
					./src/tests.cpp \

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

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)
