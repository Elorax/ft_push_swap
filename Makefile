SRCS			=	ft_advanced_stack_modifiers.c ft_check_input.c ft_display_stacks.c ft_init_stacks.c \
					ft_parsing.c ft_stack_modifiers.c ft_tri_rapide.c ft_tri_stack.c ft_utils.c \
					ft_push_swap.c
OBJS			= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f

CFLAGS			= -Wall -g -Wextra -Werror -I.

NAME			= push_swap

LIB				= libft.a

LIBPATH			= libft/

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(LIBPATH) bonus
				gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBPATH)$(LIB)

clean:
				rm -f $(OBJS) && make -C $(LIBPATH) clean

fclean:			clean
				rm -f $(NAME) && make -C $(LIBPATH) fclean

re:			fclean $(NAME)

.PHONY:			all clean fclean re
