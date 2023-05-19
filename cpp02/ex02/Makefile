###########
# General #
###########

NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
OVERFLOWFLAGS = -g -fsanitize=undefined -fsanitize=integer -fsanitize=address
SRCS = main.cpp \
	Fixed.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
OBJS_DIR = ./objs
DEPENDS = $(addprefix $(OBJS_DIR)/, $(OBJS:%.o=%.d))

#################
# General Rules #
#################

.PHONY: all clean fclean re over_flow sample my_test lldb

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
	$(RM) sample

re: fclean all

over_flow: CXXFLAGS += $(OVERFLOWFLAGS)
over_flow: re

sample: CXXFLAGS += $(OVERFLOWFLAGS)
sample: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $@.cpp -o $(OBJS_DIR)/$@.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/$@.o

my_test: CXXFLAGS += -DTEST
my_test: over_flow

lldb: CXXFLAGS += -g -O0
lldb: re

-include $(DEPENDS)
