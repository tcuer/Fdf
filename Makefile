# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcuer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/04 15:45:58 by tcuer             #+#    #+#              #
#    Updated: 2016/10/04 15:16:54 by tcuer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKEX = cc -o

SRC = main.c get_next_line.c get_info.c ft_draw.c ft_range.c

FLAGS = -Wall -Wextra -Werror

OBJECT = $(SRC:.c=.o)

COMP = cc -c

NAME = fdf

INCLUDESLIB = ./libft/includes/

all : $(NAME)

$(NAME) : $(OBJECT)
	@echo "Compilation Fdf"
	@$(MKEX) $(NAME) $(OBJECT)  -lmlx -framework OpenGL -framework AppKit -L libft/ -lft
	@echo "Done"

$(OBJECT) :
	@make -C libft/
	@$(COMP) $(SRC) $(FLAGS) -I./ -I /usr/X11/include/ -I $(INCLUDESLIB)

clean :
	@make clean -C libft/
	@/bin/rm -f $(OBJECT)
	@echo "Object deleted"

fclean : clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "Folder cleanup successful"

re : fclean all
