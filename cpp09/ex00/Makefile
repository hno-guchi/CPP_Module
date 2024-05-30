###########
# General #
###########

NAME = btc
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP
DEBUGFLAGS = -g -fsanitize=address,undefined,integer -DDEBUG
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
OBJS_DIR = ./objs
DEPENDS = $(addprefix $(OBJS_DIR)/, $(OBJS:%.o=%.d))

#################
# General Rules #
#################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) -o $@ $(OBJS)

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r *.dSYM
	$(RM) -r $(OBJS_DIR)

.PHONY:fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) debug

.PHONY:re
re: fclean all

.PHONY: debug
debug: fclean
debug: CXXFLAGS = $(DEBUGFLAGS)
debug: $(OBJS_DIR)
debug: $(OBJS)
debug:
	$(CXX) $(DEBUGFLAGS) -o debug $(OBJS)
	-./debug ./test/ERR_00_invalid_date.txt
	-./debug ./test/ERR_01_invalid_value.txt
	-./debug ./test/ERR_02_invalid_delim.txt
	-./debug ./test/ERR_03_only_empty_line.txt
	-./debug ./test/ERR_04_only_empty_lines.txt
	-./debug ./test/ERR_05_exist_empty_line_in_head.txt
	-./debug ./test/ERR_06_exist_empty_lines_in_head.txt
	-./debug ./test/ERR_07_date_out_of_range.txt
	-./debug ./test/OK_00_empty_file.txt
	-./debug ./test/OK_01_not_exist_record.txt
	-./debug ./test/OK_02_not_exist_header.txt
	-./debug ./test/OK_03_exist_empty_lines_in_between_line.txt
	-./debug ./test/OK_04_csv_and_txt_the_same_date.txt
	-./debug ./test/input.txt

.PHONY: leaks
leaks: CXXFLAGS += -DLEAKS -DDEBUG
leaks: re
leaks:
	-./$(NAME) ./test/ERR_00_invalid_date.txt
	-./$(NAME) ./test/ERR_01_invalid_value.txt
	-./$(NAME) ./test/ERR_02_invalid_delim.txt
	-./$(NAME) ./test/ERR_03_only_empty_line.txt
	-./$(NAME) ./test/ERR_04_only_empty_lines.txt
	-./$(NAME) ./test/ERR_05_exist_empty_line_in_head.txt
	-./$(NAME) ./test/ERR_06_exist_empty_lines_in_head.txt
	-./$(NAME) ./test/ERR_07_date_out_of_range.txt
	-./$(NAME) ./test/OK_00_empty_file.txt
	-./$(NAME) ./test/OK_01_not_exist_record.txt
	-./$(NAME) ./test/OK_02_not_exist_header.txt
	-./$(NAME) ./test/OK_03_exist_empty_lines_in_between_line.txt
	-./$(NAME) ./test/OK_04_csv_and_txt_the_same_date.txt
	-./$(NAME) ./test/input.txt

.PHONY: test
test: re
test:
	-./$(NAME) ./test/ERR_00_invalid_date.txt
	-./$(NAME) ./test/ERR_01_invalid_value.txt
	-./$(NAME) ./test/ERR_02_invalid_delim.txt
	-./$(NAME) ./test/ERR_03_only_empty_line.txt
	-./$(NAME) ./test/ERR_04_only_empty_lines.txt
	-./$(NAME) ./test/ERR_05_exist_empty_line_in_head.txt
	-./$(NAME) ./test/ERR_06_exist_empty_lines_in_head.txt
	-./$(NAME) ./test/ERR_07_date_out_of_range.txt
	-./$(NAME) ./test/OK_00_empty_file.txt
	-./$(NAME) ./test/OK_01_not_exist_record.txt
	-./$(NAME) ./test/OK_02_not_exist_header.txt
	-./$(NAME) ./test/OK_03_exist_empty_lines_in_between_line.txt
	-./$(NAME) ./test/OK_04_csv_and_txt_the_same_date.txt
	-./$(NAME) ./test/input.txt

.PHONY: lldb
lldb: CXXFLAGS += -g -O0
lldb: re

-include $(DEPENDS)
