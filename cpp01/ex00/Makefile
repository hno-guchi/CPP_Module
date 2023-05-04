###########
# General #
###########

NAME = ex00
CXX = c++
INCLUDES = -I./includes
CXXFLAGS = -std=c++98 -pedantic -Wall -Wextra -Werror $(INCLUDES)
SRCS = main.cpp \
	Zombie.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJS_DIR):
	mkdir -p $@

ifdef DEBUG
$(OBJS_DIR)/%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@ -DDEBUG
else
$(OBJS_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@
endif

debug: clean
	make DEBUG=1

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
