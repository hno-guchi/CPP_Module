###########
# General #
###########

NAME = string
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = string.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: all clean fclean re practice

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) practice

re: fclean all

practice: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c practice.cpp -o $(OBJS_DIR)/practice.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/practice.o
