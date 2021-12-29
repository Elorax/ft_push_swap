SRCS			=	ft_advanced_stack_modifiers.c ft_check_input.c ft_display_stacks.c ft_init_stacks.c \
					ft_parsing.c ft_stack_modifiers.c ft_tri_rapide.c ft_tri_stack.c ft_utils.c \
					ft_push_swap.c

SRCS_BONUS		=	bonus/checker.c				\
					bonus/get_next_line.c		\
					bonus/get_next_line_utils.c	\
					ft_stack_modifiers.c		\
					ft_check_input.c			\
					ft_init_stacks.c			\
					ft_utils.c		
					

OBJS			= $(SRCS:.c=.o)

OBJS_BONUS			= $(SRCS_BONUS:.c=.o)

CC			= gcc
RM			= rm -f

CFLAGS			= -Wall -g -Wextra -Werror -I.

NAME			= push_swap

NAME_BONUS		= checker

LIB				= libft.a

LIBPATH			= libft/

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(LIBPATH) bonus
				gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBPATH)$(LIB)

$(NAME_BONUS):		$(OBJS_BONUS)
				make -C $(LIBPATH) bonus
				gcc $(CFLAGS) -o $(NAME_BONUS) $(SRCS_BONUS) $(LIBPATH)$(LIB)

clean:
				rm -f $(OBJS) && rm -f $(OBJS_BONUS) && make -C $(LIBPATH) clean

fclean:			clean
				rm -f $(NAME) && rm -f $(NAME_BONUS) && make -C $(LIBPATH) fclean

re:			fclean $(NAME)

bonus:		$(NAME_BONUS)

.PHONY:			all clean fclean re
