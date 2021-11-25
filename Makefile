SRCS			=	ft_advanced_stack_modifiers.c ft_check_input.c ft_display_stacks.c ft_init_stacks.c \
					ft_parsing.c ft_stack_modifiers.c ft_tri_rapide.c ft_tri_stack.c ft_utils.c \
					push_swap.c
OBJS			= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f

CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= push_swap

LIB				= libft.a

LIBPATH			= libft/

all:			$(NAME)

$(NAME):		$(OBJS)
				cd $(LIBPATH) && make && cd ..
				gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBPATH)$(LIB)

clean:
				rm -f $(OBJS) && cd $(LIBPATH) && make clean && cd ..

fclean:			clean
				rm -f $(NAME) && cd $(LIBPATH) && make fclean && cd ..

re:			fclean $(NAME)

.PHONY:			all clean fclean re
