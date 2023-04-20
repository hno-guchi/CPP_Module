############
# Variable #
############

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean class

class: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Class.cpp -o $(OBJS_DIR)/Class.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Class.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) class
