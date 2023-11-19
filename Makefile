CC = cc
NAME = libftprintf.a
SRC = additionnal_functions.c c_case.c di_to_s.c di_to_s2.c di_to_s3.c di_to_s4.c format_info1.c format_info2.c ft_printf_libft.c ft_printf2.c main_ft_printf.c main_ft_printf2.c p_to_s.c p_to_s1.c p_to_s2.c p_to_s3.c s_to_print1.c s_to_print2.c s_to_print3.c u_to_s1.c u_to_s2.c
HEADER = ft_printf.h
OBJ = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJ)

re : fclean all

bonus : all

.PHONY: all fclean clean re bonus
