# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaylor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:35:25 by jaylor            #+#    #+#              #
#    Updated: 2017/11/27 17:50:38 by jaylor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = lem-in
HEADERS = includes

CFLAGS +=  -g
CFLAGS += -I$(HEADERS) 

FILESO =	parse2.o \
			parse.o \
			parse3.o \
			main.o \
			utilities.o \
			make_map.o \
			print_ants.o\
			newsolver.o\
			alloc_wrap.o \

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(FILESO) $(LIBFT)
	gcc -o $(NAME) $^ $(CFLAGS)

%.o: srcs/%.c
	gcc -o $@ -c $< $(CFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(FILESO) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
