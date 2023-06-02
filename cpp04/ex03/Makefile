###########
# General #
###########

NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
OVERFLOWFLAGS = -g -fsanitize=undefined -fsanitize=integer -fsanitize=address
SRCS = main.cpp debugMessage.cpp \
	AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp Character.cpp
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
over_flow: fclean
over_flow: CXXFLAGS += $(OVERFLOWFLAGS)
over_flow: $(OBJS_DIR)
over_flow: $(OBJS)
over_flow:
	$(CXX) $(OVERFLOWFLAGS) -o $(NAME) $(OBJS)

.PHONY: leaks
leaks: CXXFLAGS += -DLEAKS
leaks: re

.PHONY: while_leaks
while_leaks: CXXFLAGS += -DWHILE_LEAKS
while_leaks: re

.PHONY: materia
materia: CXXFLAGS += -DMATERIA
materia: leaks

.PHONY: materia_over_flow
materia_over_flow: CXXFLAGS += -DMATERIA
materia_over_flow: over_flow

.PHONY: m_source
m_source: CXXFLAGS += -DM_SOURCE
m_source: leaks

.PHONY: m_source_lldb
m_source_lldb: CXXFLAGS += -DM_SOURCE
m_source_lldb: lldb

.PHONY: m_source_over_flow
m_source_over_flow: CXXFLAGS += -DM_SOURCE
m_source_over_flow: over_flow

.PHONY: character
character: fclean
character: CXXFLAGS += -DCHARACTER
character: leaks

.PHONY: character_lldb
character_lldb: fclean
character_lldb: CXXFLAGS += -DCHARACTER
character_lldb: lldb

.PHONY: character_over_flow
character_over_flow: CXXFLAGS += -DCHARACTER
character_over_flow: over_flow

.PHONY: lldb
lldb: CXXFLAGS += -g -O0
lldb: re

-include $(DEPENDS)
