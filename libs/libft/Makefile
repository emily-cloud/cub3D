NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I headers/
HEADER = $(addsuffix .h, $(addprefix ./headers/, libft ))
FTIS = alnum alpha ascii digit print
FTMEM = bzero calloc memchr memcmp memcpy memmove memset
FTPUT = char_fd char endl_fd endl nbr_fd nbr str_fd str
FTSTR = chr dup iteri join lcat lcpy len mapi ncmp nstr rchr trim
FTSUB = split substr
FTTO = atoi_l atoi itoa tolower toupper
FTEX = gnl/get_next_line printf/ft_printf
FTPRF = hex utils

SRC = $(addsuffix .c, $(addprefix ft_is/ft_is, $(FTIS))) \
	$(addsuffix .c, $(addprefix ft_mem/ft_, $(FTMEM))) \
	$(addsuffix .c, $(addprefix ft_put/ft_put, $(FTPUT))) \
	$(addsuffix .c, $(addprefix ft_str/ft_str, $(FTSTR))) \
	$(addsuffix .c, $(addprefix ft_str/ft_, $(FTSUB))) \
	$(addsuffix .c, $(addprefix ft_to/ft_, $(FTTO))) \
	$(addsuffix .c, $(addprefix ft_, $(FTEX))) \
	$(addsuffix .c, $(addprefix ft_printf/ft_print_, $(FTPRF))) \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all clean fclean re norm
