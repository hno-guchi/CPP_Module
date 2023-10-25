###########
# General #
###########

NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
DEBUGFLAGS = -g -fsanitize=undefined -fsanitize=integer -fsanitize=address
SRCS = main.cpp debugMessage.cpp
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

.PHONY: debug
debug: fclean
debug: $(OBJS_DIR)
debug: $(OBJS)
debug:
	$(CXX) $(DEBUGFLAGS) -o $(NAME) $(OBJS)

.PHONY: leaks
leaks: CXXFLAGS += -DLEAKS
leaks: re

.PHONY: lldb
lldb: CXXFLAGS += -g -O0
lldb: re

.PHONY: sub
sub: fclean
sub: CXXFLAGS += -DTEST -DSUB -DLEAKS
sub: re

.PHONY: sub_debug
sub_debug: fclean
sub_debug: CXXFLAGS += -DTEST -DSUB
sub_debug: $(OBJS_DIR)
sub_debug: $(OBJS)
sub_debug:
	$(CXX) $(DEBUGFLAGS) -o $(NAME) $(OBJS)

.PHONY: while_leaks
while_leaks: fclean
while_leaks: CXXFLAGS += -DTEST -DWHILE_LEAKS
while_leaks: re

-include $(DEPENDS)
