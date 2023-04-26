###########
# General #
###########

NAME = phonebook
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: all clean fclean re contact

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

contact: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $@.cpp -o $(OBJS_DIR)/$@.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/$@.o

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) contact

re: fclean all
