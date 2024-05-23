###########
# General #
###########

NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
FSANITIZEFLAGS = -g -fsanitize=address -DDEBUG
SRCS = main.cpp PmergeMe.cpp
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
debug: CXXFLAGS = $(FSANITIZEFLAGS)
debug: $(OBJS_DIR)
debug: $(OBJS)
debug:
	$(CXX) $(FSANITIZEFLAGS) -c Int.cpp -o $(OBJS_DIR)/Int.o
	$(CXX) $(FSANITIZEFLAGS) -o debug $(OBJS) $(OBJS_DIR)/Int.o

.PHONY: leaks
leaks: CXXFLAGS += -DLEAKS
leaks: re

.PHONY: lldb
lldb: CXXFLAGS += -g -O0
lldb: re

-include $(DEPENDS)
