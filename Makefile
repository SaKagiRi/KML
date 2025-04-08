#------------[MANDATORY]
NAME 			= kml.a
AR_AND_FLAGS	= ar -rcs
RM				= rm -rf
CC				= cc
HEADER			= -I ./include #------------[FLAGS]
CFLAGS		= $(DEBUG_FLAGS) $(W_FLAGS)
DEBUG_FLAGS	= -g3
W_FLAGS		= -Wall -Wextra -Werror
#------------[OBJECT_AND_SOURCE]
SRC			= $(addprefix srcs/, $(FILE))
OBJ			= $(SRC:%.c=%.o)
#------------[ROOT_FILES]
FILE		= $(DIGIT) $(STRING) $(CHARACTER) $(MEMORY) $(PRINT) $(LINKED_LIST) $(GET_NEXT_LINE)
#------------[SUBFILES]
#------------[DIGIT]
DIGIT			= $(addprefix $(DIGIT_PATH)/, $(DIGIT_FILE))
DIGIT_PATH		= digit
DIGIT_FILE		= ft_atoi.c ft_atol.c ft_htol.c
#------------[STRING]
STRING			= $(addprefix $(STRING_PATH)/, $(STRING_FILE))
STRING_PATH		= string
STRING_FILE		= ft_itoa.c ft_split.c ft_strlen.c ft_strchr.c ft_strdup.c ft_substr.c ft_strlcpy.c ft_strlcat.c \
				  ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strjoin.c ft_strtrim.c ft_striteri.c \
				  fsplit.c fjoin.c 
		#------------[GET_NEXT_LINE]
		GET_NEXT_LINE			= $(addprefix $(GET_NEXT_LINE_PATH)/, $(GET_NEXT_LINE_FILE))
		GET_NEXT_LINE_PATH		= $(STRING_PATH)/get_next_line
		GET_NEXT_LINE_FILE		= get_next_line.c get_next_line_utils.c 
#------------[CHARACTER]
CHARACTER		= $(addprefix $(CHARACTER_PATH)/, $(CHARACTER_FILE))
CHARACTER_PATH	= character
CHARACTER_FILE	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_tolower.c  ft_isspace.c
#------------[MEMORY]
MEMORY			= $(addprefix $(MEMORY_PATH)/, $(MEMORY_FILE))
MEMORY_PATH		= memory
MEMORY_FILE		= ft_bzero.c ft_memset.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_memmove.c ft_malloc.c
#------------[PRINT]
PRINT			= $(addprefix $(PRINT_PATH)/, $(PRINT_FILE))
PRINT_PATH		= print
PRINT_FILE		= ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_printf.c
#------------[LINKED_LIST]
LINKED_LIST			= $(addprefix $(LINKED_LIST_PATH)/, $(LINKED_LIST_FILE))
LINKED_LIST_PATH	= linked_list
LINKED_LIST_FILE	= ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstlast.c ft_lstclear.c ft_lstdelone.c \
					  ft_lstadd_back.c ft_lstadd_front.c ft_lstiter_if.c ft_lstfind.c ft_lstremove_if.c 
#------------[PROCESS]
all: $(NAME)
$(NAME): $(OBJ)
	@$(AR_AND_FLAGS) $(NAME) $(OBJ) && printf "\033[38;5;226;1m<< Archive Libft >>\033[0m\n"
%.o: %.c Makefile
	@printf "\033[38;5;226;1m"
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
	@printf "\033[1A\033[2K"
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
	@printf "\033[38;5;196;1m<< Destroy Libft >>\033[0m\n"
re: fclean all
.PHONY: all clean fclean re lib print
