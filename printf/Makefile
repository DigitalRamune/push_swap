CC = cc
NAME = libftprintf.a
CFLAGS = -Werror -Wextra -Wall
SRC = utilscount.c utilsprint.c ft_printf.c



OBJ = $(SRC:.c=.o)
OBJBNS = $(BNS:.c=.o)
AR = ar rcs $(NAME)

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(OBJ)
bonus : $(OBJ) $(OBJBNS)
	$(AR) $(OBJ) $(OBJBNS)

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean :
		rm -f $(OBJ) $(OBJBNS)

fclean : clean
		rm -f $(NAME)

re :  fclean $(NAME)

.PHONY : all clean fclean re