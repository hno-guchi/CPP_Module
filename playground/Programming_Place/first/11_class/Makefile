############
# Variable #
############

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: clean fclean class practice

class: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c Class.cpp -o $(OBJS_DIR)/Class.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/Class.o

practice: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(OBJS_DIR)/main.o
	$(CXX) $(CXXFLAGS) -c Student.cpp -o $(OBJS_DIR)/Student.o
	$(CXX) $(CXXFLAGS) -c Teacher.cpp -o $(OBJS_DIR)/Teacher.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/main.o $(OBJS_DIR)/Student.o $(OBJS_DIR)/Teacher.o

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) class
	$(RM) practice
