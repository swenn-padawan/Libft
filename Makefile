# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 21:59:22 by stetrel           #+#    #+#              #
#    Updated: 2024/10/13 21:32:12 by stetrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC			:= cc

OBJS_DIR	:= .objs

SRCS			:= ft_isalpha.c \
		   		ft_isdigit.c \
		   		ft_isalnum.c \
		   		ft_isascii.c \
		   		ft_isprint.c \
		   		ft_strlen.c \
		   		ft_memset.c \
		   		ft_bzero.c \
		   		ft_memcpy.c \
		   		ft_memmove.c \
		   		ft_toupper.c \
		   		ft_tolower.c \
		   		ft_strchr.c \
		   		ft_strrchr.c \
		   		ft_strncmp.c \
		   		ft_memchr.c \
		   		ft_memcmp.c \
		   		ft_strnstr.c \
		   		ft_atoi.c \
		   		ft_strlcpy.c \
		   		ft_strlcat.c \
		   		ft_calloc.c \
		   		ft_strdup.c \
		   		ft_split.c \
		   		ft_substr.c \
		   		ft_strjoin.c \
		   		ft_strtrim.c \
		   		ft_strmapi.c \
		   		ft_striteri.c \
		   		ft_putchar_fd.c \
		   		ft_putstr_fd.c \
		   		ft_putendl_fd.c \
		   		ft_putnbr_fd.c \
		   		ft_itoa.c \


SRCS_BONUS 		:= ft_lstnew.c \
			  	ft_lstadd_front.c \
			  	ft_lstsize.c \
			  	ft_lstlast.c \
			  	ft_lstadd_back.c \
			  	ft_lstdelone.c \
			  	ft_lstclear.c \
			  	ft_lstiter.c \
			  	ft_lstmap.c \

OBJS			:= $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

OBJS_BONUS		:= $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:%.c=%.o))

CFLAGS			:= -Wall -Wextra -Werror -g

DIR_UP			= mkdir -p $(@D)

RM				:= rm -rf

################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $^	
$(OBJS_DIR)/%.o: %.c	
	@$(DIR_UP)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus

################################################################################


