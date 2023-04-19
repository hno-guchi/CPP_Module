############
# Variable #
############

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean

: $(OBJS_DIR)
$(CXX) $(CXXFLAGS) -c .cpp -o $(OBJS_DIR)/.o
$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
