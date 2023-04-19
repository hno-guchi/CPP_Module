############
# Variable #
############

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean static reinterpret const

static: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Static.cpp -o $(OBJS_DIR)/Static.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Static.o

reinterpret: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Reinterpret.cpp -o $(OBJS_DIR)/Reinterpret.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Reinterpret.o

const: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Const.cpp -o $(OBJS_DIR)/Const.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Const.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) static
	$(RM) reinterpret
	$(RM) const
