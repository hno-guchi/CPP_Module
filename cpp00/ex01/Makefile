###########
# General #
###########

NAME = phonebook
CXX = c++
INCLUDES = -I./includes -I$(LIBFT_DIR)/includes
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror $(INCLUDES)
LIBRARIES = -lft -L$(LIBFT_DIR)
SRCS = main.cpp \
	error_message.cpp getline_prompt.cpp begin_message.cpp \
	is_phone_number.cpp is_registered_phone_number.cpp \
	PhoneBook.cpp \
	tokenize.cpp is_validation.cpp do_add.cpp \
	Contact.cpp \
	print_field.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
SRCS_DIR = ./srcs
OBJS_DIR = ./objs
LIBFT_DIR = ./libft

#################
# General Rules #
#################

.PHONY: all libft clean fclean re contact

all: libft $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBRARIES)

contact: $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRCS_DIR)/$@.cpp -o $(OBJS_DIR)/$@.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DIR)/$@.o

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@

libft:
	make -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	$(RM) -r $(OBJS_DIR)
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
