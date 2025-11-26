# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 11:56:08 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/09/25 19:51:08 by megiazar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJS = ft_atoi.o \
	ft_atof.o \
	ft_bzero.o \
	ft_calloc.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_itoa.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_split.o \
	ft_strchr.o \
	ft_strdup.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	ft_strmapi.o \
	ft_strncmp.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strtrim.o \
	ft_substr.o \
	ft_tolower.o \
	ft_toupper.o

OBJS_BONUS = ft_lstadd_back.o \
	ft_lstadd_front.o \
	ft_lstclear.o \
	ft_lstdelone.o \
	ft_lstiter.o \
	ft_lstlast.o \
	ft_lstmap.o \
	ft_lstnew.o \
	ft_lstsize.o

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : .bonus

.bonus : $(OBJ) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)
	touch .bonus

clean :
	-rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	-rm -f $(NAME) .bonus

re : fclean all

.PHONY : all clean fclean re bonus