NAME = libft.a

#==============#
#_- Compiler -_#
#==============#
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -rf

#====================#
#_- Programes Path -_#
#====================#
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
LIB_PATH =

#===========#
#_- Color -_#
#===========#

# color #
# red = 9
# hard_red = 196
# orange = 214
# violet = 140
# green = 47

TITLE_COLOR = 214
CLEAN_COLOR = 9
LINK_COLOR = 47
OBJ_COLOR = 47

MAKE_COLOR = 47
MAKE_ALREADY = 140
MAKE_FAIL = 9

NORME_COLOR = 47
NORME_COLOR_ERR = 9
NORME_COLOR_WAR = 196

#==============#
#_- Fonction -_#
#==============#

cmd_make = echo "\033[38;5;$(MAKE_COLOR)m$(MAKE) $(1)\033[0m"; \
		   $(MAKE) $(1)

cmd_color = echo "\033[38;5;$(1)m$(2)\033[0m"; \
			$(2)

put_title = echo "\033[38;5;$(TITLE_COLOR)m[ $(1) ]\033[0m"

#==================#
#_- Source Files -_#
#==================#

MEM = $(addprefix mem/,ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c)

CTYPE = $(addprefix ctype/,ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_isspace.c ft_tolower.c ft_toupper.c)

IO = $(addprefix io/,ft_putchar.c ft_putchar_fd.c ft_putchar_while.c \
	 ft_putstr.c ft_putstr_fd.c ft_putnstr.c ft_putendl.c ft_putendl_fd.c \
	 ft_putcol.c ft_putcol_fd.c ft_putwchar.c ft_putwchar_fd.c ft_putwstr.c \
	 ft_putwstr_fd.c ft_putnwstr.c ft_putnwstr_fd.c ft_putnbr.c ft_putnbr_fd.c \
	 ft_putnbr_ndl.c ft_putnstr_fd.c get_next_line.c ft_putncol_fd.c ft_putncol.c \
	 $(addprefix printf/,ft_printf.c parse_format.c format/type_char.c \
	 	format/type_str.c format/type_int.c utils/length_cast.c \
		format/type_unsigned.c put_result.c format/type_pointer.c \
		utils/syntax_numeric.c format/type_wstr.c format/type_long.c))

LIST = $(addprefix list/,ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c)

MISC = $(addprefix misc/,ft_itoa.c ft_atoi.c ft_nbrlen.c ft_nbrlenbase.c \
		ft_range.c ft_tablen.c ft_ultoabase.c ft_wcharlen.c ft_wstrlen.c \
		ft_atol.c)

STRING = $(addprefix string/,ft_strdup.c ft_strcpy.c ft_strncpy.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strrev.c \
	ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_strtoupper.c ft_strtolower.c \
	ft_strnew.c ft_strlen.c ft_strlen_c.c ft_seekstr.c)

SRC_NAME = $(MEM) $(CTYPE) $(IO) $(LIST) $(MISC) $(STRING)

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = $(addprefix -I, $(INC_PATH))

#===========#
#_- Rules -_#
#===========#
all: $(NAME)

#	linking
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(call cmd_color,$(LINK_COLOR),$(CC) $(CFLAGS) $(INC) -o $@ -c $<)

#	preLinking
$(OBJ_PATH):
	@$(call put_title,Linking)

#	Object Compiation
$(NAME): $(OBJ_PATH) $(OBJ)
	@$(call put_title,Compilation)
	@$(call cmd_color,$(OBJ_COLOR),ar rc $@ $(OBJ))
	@$(call cmd_color,$(OBJ_COLOR),ranlib $@)

#	Removing object
clean:
	@$(call put_title,Cleaning)
	@$(RM) $(OBJ_PATH)
	@$(call cmd_color,$(CLEAN_COLOR),rm -rf $(OBJ))

#	Removeing binary
fclean : clean
	@$(RM) $(NAME)
	@$(call cmd_color,$(CLEAN_COLOR),rm -rf $(NAME))

re: fclean all

#	check norme for includes and ./srcs/ files
norme:
	@norminette $(SRC) $(INC_PATH) | sed "s/Norme/[0;1;47m\
	[0;38;5;$(NORME_COLOR)mNorme/g; s/Warning/[38;5;$(NORME_COLOR_WAR)m\
	Warning/g; s/Error/\[38;5;$(NORME_COLOR_ERR)m Error/g"

size:
	cat $(SRC) | wc -l

.PHONY: all clean fclean re norme size
