###########
# General #
###########

NAME = libft.a
CXX = c++
INCLUDES = -I./includes
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror $(INCLUDES)
ARFLAGS = rcs
SRCS = ft_strlen.cpp ft_isdigit.cpp ft_isalpha.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
