###########
# General #
###########

NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
SRCS = main.cpp \
	Fixed.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
OBJS_DIR = ./objs
DEPENDS = $(addprefix $(OBJS_DIR)/, $(OBJS:%.o=%.d))

#################
# General Rules #
#################

.PHONY: all clean fclean re test lldb

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r *.dSYM
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: CXXFLAGS += -DTEST
test: re

lldb: CXXFLAGS += -g -O0
lldb: re

-include $(DEPENDS)
