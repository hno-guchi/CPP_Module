###########
# General #
###########

NAME = ex01
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
DEBUGFLAGS = -g -fsanitize=undefined -fsanitize=integer -fsanitize=address
SRCS = main.cpp debugMessage.cpp \
	   Span.cpp
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
debug: CXXFLAGS = $(DEBUGFLAGS)
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

.PHONY: construct
construct: fclean
construct: CXXFLAGS = $(DEBUGFLAGS) -DTEST -DCONSTRUCT
construct: $(OBJS_DIR)
construct: $(OBJS)
construct:
	$(CXX) $(DEBUGFLAGS) -o $(NAME) $(OBJS)

.PHONY: construct_leaks
construct_leaks: CXXFLAGS += -DTEST -DCONSTRUCT -DLEAKS
construct_leaks: re

.PHONY: copy
copy: fclean
copy: CXXFLAGS = $(DEBUGFLAGS) -DTEST -DCOPY_ASSIGNMENT
copy: $(OBJS_DIR)
copy: $(OBJS)
copy:
	$(CXX) $(DEBUGFLAGS) -o $(NAME) $(OBJS)

.PHONY: copy_leaks
copy_leaks: CXXFLAGS += -DTEST -DCOPY_ASSIGNMENT -DLEAKS
copy_leaks: re

-include $(DEPENDS)
