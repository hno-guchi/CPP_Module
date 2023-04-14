############
# Variable #
############

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean output input getline eof

output: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Output.cpp -o $(OBJS_DIR)/Output.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Output.o

input: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Input.cpp -o $(OBJS_DIR)/Input.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Input.o

getline: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c GetLine.cpp -o $(OBJS_DIR)/GetLine.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/GetLine.o

eof: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Eof.cpp -o $(OBJS_DIR)/Eof.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Eof.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) output
	$(RM) input
	$(RM) getline
	$(RM) eof
