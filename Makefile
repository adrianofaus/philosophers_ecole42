# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrianofaus <adrianofaus@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 20:28:35 by adrianofaus       #+#    #+#              #
#    Updated: 2022/05/05 15:25:12 by adrianofaus      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# #################################################################### VARIABLES
# BINARY NAME
NAME			=	philo

# BASH COMMANDS
MKDIR			=	mkdir -p
RM				=	rm -rf

# HEADERS
HEADERS			=	philo.h

# INCLUDES
INCLUDES		=	-I .

# DEBUG
DEBUG			=	-g3

# COMPILATION
CFLAGS			=	-Wall -Wextra -Werror -pthread
CC				=	gcc $(CFLAGS) $(INCLUDES)
VALGRIND		=	valgrind \
					--leak-check=full \
					--show-leak-kinds=all \
					--track-origins=yes \
					#--trace-children=yes \
					#--track-fds=yes

#PATHS
PATH_OBJ		=	obj/

# FILES
SOURCES			=	philo.c \
					init_philo.c \
					validation.c \
					conversion.c \
					exec_routines.c \
					philo_algorithm.c \
					exit_routines.c \
					utils.c
OBJS			=	$(SOURCES:%.c=%.o)

# ###################################################################### TARGETS
all:				makedir $(NAME)

makedir:
					@$(MKDIR) $(PATH_OBJ)

$(NAME):			$(addprefix $(PATH_OBJ),$(OBJS))
					$(CC) $(addprefix $(PATH_OBJ),$(OBJS)) -o $(NAME)

$(PATH_OBJ)%.o:		%.c $(HEADERS)
					$(CC) -c $< -o $@

run:				all
					./$(NAME)

valgrind:			all
					$(VALGRIND) ./$(NAME)

clean:				
					$(RM) $(addprefix $(PATH_OBJ), $(OBJS))

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re run valgrind