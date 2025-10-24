SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = megaphone
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

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
