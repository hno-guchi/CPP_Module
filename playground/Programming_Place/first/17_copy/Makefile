############
# Variable #
############

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean copy

copy: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c copy.cpp -o $(OBJS_DIR)/copy.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/copy.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) copy
