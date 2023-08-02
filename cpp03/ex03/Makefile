###########
# General #
###########

NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
OVERFLOWFLAGS = -g -fsanitize=undefined -fsanitize=integer -fsanitize=address
SHADOWFLAGS = -Wshadow
SRCS = main.cpp \
	debugMessage.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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

.PHONY: over_flow
over_flow: CXXFLAGS += $(OVERFLOWFLAGS)
over_flow: re

.PHONY: shadow
shadow: CXXFLAGS += $(SHADOWFLAGS)
shadow: re

.PHONY: leaks
leaks: CXXFLAGS += -DLEAKS
leaks: re

.PHONY: lldb
lldb: CXXFLAGS += -g -O0
lldb: re

-include $(DEPENDS)
