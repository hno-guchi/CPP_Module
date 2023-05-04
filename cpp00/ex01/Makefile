###########
# General #
###########

NAME = phonebook
CXX = c++
INCLUDES = -I./includes
CXXFLAGS = -std=c++98 -pedantic -Wall -Wextra -Werror $(INCLUDES)
SRCS = main.cpp \
	error_message.cpp getline_prompt.cpp begin_message.cpp \
	PhoneBook.cpp \
	getline_valid.cpp is_index.cpp is_registered_phone_number.cpp my_stoi.cpp \
	Contact.cpp \
	print_field.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: all clean fclean re contact getline_prompt debug

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

contact: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRCS_DIR)/$@.cpp -o $(OBJS_DIR)/$@.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/$@.o

getline_prompt: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRCS_DIR)/$@.cpp -o $(OBJS_DIR)/$@.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/$@.o

$(OBJS_DIR):
	mkdir -p $@

ifdef DEBUG
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
		$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@ -DDEBUG
else
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@
endif

debug: clean
	make DEBUG=1

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
