############
# Variable #
############

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean overload scope cast default

overload: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Overload.cpp -o $(OBJS_DIR)/Overload.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Overload.o

scope: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Scope.cpp -o $(OBJS_DIR)/Scope.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Scope.o

cast: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Cast.cpp -o $(OBJS_DIR)/Cast.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Cast.o

default: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Default.cpp -o $(OBJS_DIR)/Default.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Default.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) overload
	$(RM) scope
	$(RM) cast
