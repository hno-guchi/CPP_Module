###########
# General #
###########

NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
DEBUGFLAGS = -g -fsanitize=address,undefined,integer -DDEBUG
SRCS = main.cpp RPN.cpp
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
	$(RM) debug
	$(RM) integer

.PHONY:re
re: fclean all

.PHONY: debug
debug: fclean
debug: CXXFLAGS = $(DEBUGFLAGS)
debug: $(OBJS_DIR)
debug: $(OBJS)
debug:
	$(CXX) $(DEBUGFLAGS) -o debug $(OBJS)
	-./debug "8 9 * 9 - 9 - 9 - 4 - 1 +"
	-./debug "7 7 * 7 -"
	-./debug "1 2 * 2 / 2 * 2 4 - +"
	-./debug "(1 + 1)"
	-./debug
	-./debug ""
	-./debug " "
	-./debug "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 1 - 2 * 1 +"
	-./debug "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 1 - 2 * 1 + 1 +"
	-./debug "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 *"
	-./debug "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 2 *"
	-./debug "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 2 * 1 -"
	-./debug "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 *"

.PHONY: leaks
leaks: CXXFLAGS += -DLEAKS
leaks: re
leaks:
	-./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	-./$(NAME) "7 7 * 7 -"
	-./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	-./$(NAME) "(1 + 1)"
	-./$(NAME)
	-./$(NAME) ""
	-./$(NAME) " "
	-./$(NAME) "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 1 - 2 * 1 +"
	-./$(NAME) "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 1 - 2 * 1 + 1 +"
	-./$(NAME) "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 *"
	-./$(NAME) "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 2 *"
	-./$(NAME) "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 2 * 1 -"
	-./$(NAME) "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 *"


.PHONY: tests
tests: re
tests:
	-./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	-./$(NAME) "7 7 * 7 -"
	-./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	-./$(NAME) "(1 + 1)"
	-./$(NAME)
	-./$(NAME) ""
	-./$(NAME) " "
	-./$(NAME) "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 1 - 2 * 1 +"
	-./$(NAME) "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 1 - 2 * 1 + 1 +"
	-./$(NAME) "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 *"
	-./$(NAME) "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 2 *"
	-./$(NAME) "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 2 * 1 -"
	-./$(NAME) "0 8 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 *"

.PHONY: lldb
lldb: CXXFLAGS += -g -O0
lldb: re

-include $(DEPENDS)
