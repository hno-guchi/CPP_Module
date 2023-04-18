############
# Variable #
############

NAME = cast

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean static

static: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Static.cpp -o $(OBJS_DIR)/Static.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Static.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) static
