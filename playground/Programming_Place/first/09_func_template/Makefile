############
# Variable #
############

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean template estimate practice

template: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Template.cpp -o $(OBJS_DIR)/Template.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Template.o

estimate: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Estimate.cpp -o $(OBJS_DIR)/Estimate.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Estimate.o

practice: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Practice.cpp -o $(OBJS_DIR)/Practice.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Practice.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) template
	$(RM) estimate
	$(RM) practice
