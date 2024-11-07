# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 02:47:46 by paubello          #+#    #+#              #
#    Updated: 2024/11/07 02:18:22 by paubello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	# tester.c\

BONUS = ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			# ft_lstadd_back_bonus.c\
			# ft_lstdelone_bonus.c\
			# ft_lstclear_bonus.c\
			# ft_lstiter_bonus.c\
			# ft_lstmap_bonus.c\

SRCS = $(MANDATORY)

OBJS = $(SRCS:.c=.o)

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Main Target
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rules
all: $(NAME)

bonus:
	$(MAKE) SRCS="$(MANDATORY) $(BONUS)" OBJS="$(OBJS) $(BONUS:.c=.o)" $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
