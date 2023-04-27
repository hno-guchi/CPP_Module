###########
# General #
###########

NAME = phonebook
CXX = c++
INCLUDES = -I./includes
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror $(INCLUDES)
SRCS = main.cpp error_message.cpp ft_isdigit.cpp \
	PhoneBook.cpp ft_isalpha.cpp input_data.cpp tokenize.cpp is_validation.cpp do_add.cpp \
	Contact.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: all clean fclean re contact

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

contact: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRCS_DIR)/$@.cpp -o $(OBJS_DIR)/$@.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/$@.o

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
