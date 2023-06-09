###########
# General #
###########

NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
OVERFLOWFLAGS = -g -fsanitize=integer -fsanitize=address
SRCS = main.cpp \
	Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
OBJS_DIR = ./objs
DEPENDS = $(addprefix $(OBJS_DIR)/, $(OBJS:%.o=%.d))

#################
# General Rules #
#################

.PHONY: all clean fclean re weapon weapon_leaks

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
	$(RM) weapon
	$(RM) weapon_leaks

re: fclean all

over_flow: CXXFLAGS += $(OVERFLOWFLAGS)
over_flow: re

leaks: CXXFLAGS += -DLEAKS
leaks: re

lldb: CXXFLAGS += -g -O0
lldb: re

weapon: CXXFLAGS += $(OVERFLOWFLAGS)
weapon: CXXFLAGS += -DWEAPON
weapon: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Weapon.cpp -o $(OBJS_DIR)/Weapon.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Weapon.o

weapon_leaks: CXXFLAGS += -DWEAPON -DLEAKS
weapon_leaks: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Weapon.cpp -o $(OBJS_DIR)/Weapon.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Weapon.o

-include $(DEPENDS)
