###########
# General #
###########

NAME = convert
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
DEBUGFLAGS = -g -fsanitize=undefined -fsanitize=integer -fsanitize=address
SRCS = main.cpp debugMessage.cpp \
	   ScalarConverter.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
OBJS_DIR = ./objs
DEPENDS = $(addprefix $(OBJS_DIR)/, $(OBJS:%.o=%.d))

#################
# General Rules #
#################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) -o $@ $(OBJS)

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r *.dSYM
	$(RM) -r $(OBJS_DIR)

.PHONY:fclean
fclean: clean
	$(RM) $(NAME)

.PHONY:re
re: fclean all

.PHONY: test
test: fclean
test: CXXFLAGS = $(DEBUGFLAGS) -DTEST
test: $(OBJS_DIR)
test: $(OBJS)
test:
	$(CXX) $(DEBUGFLAGS) -o $(NAME) $(OBJS)

.PHONY: over_flow
over_flow: fclean
over_flow: CXXFLAGS = $(DEBUGFLAGS)
over_flow: $(OBJS_DIR)
over_flow: $(OBJS)
over_flow:
	$(CXX) $(DEBUGFLAGS) -o $(NAME) $(OBJS)

.PHONY: leaks
leaks: CXXFLAGS += -DLEAKS
leaks: re

.PHONY: lldb
lldb: CXXFLAGS += -g -O0
lldb: re

-include $(DEPENDS)
