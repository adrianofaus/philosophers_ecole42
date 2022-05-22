# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 20:28:35 by adrianofaus       #+#    #+#              #
#    Updated: 2022/05/22 18:34:33 by afaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# #################################################################### VARIABLES
# BINARY NAME
NAME			=	philo_bonus

# BASH COMMANDS
MKDIR			=	mkdir -p
RM				=	rm -rf

# HEADERS
HEADERS			=	philo_bonus.h

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

#PATHS
PATH_OBJ		=	obj/

# FILES
SOURCES			=	philo_bonus.c \
					init_philo_bonus.c \
					utils_bonus.c \
					conversion_bonus.c \
					simulation_bonus.c \
					exec_routines_bonus.c

OBJS			=	$(SOURCES:%.c=%.o)

# ###################################################################### TARGETS
all:				makedir $(NAME)

makedir:
					$(MKDIR) $(PATH_OBJ)

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