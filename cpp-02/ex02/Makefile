# **************************************************************************** #
#                                     VARS                                     #
# **************************************************************************** #

END				=	\033[0m

# COLORS
BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

NAME			=	fixed

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC				=	c++
RM				=	rm -rf
CFLAGS			+=	-Wall -Wextra -Werror -std=c++98

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

OBJ_PATH		=	.obj

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

HEADERS			=	$(addsuffix .hpp, \
					Fixed)

SRCS 			=	$(addsuffix .cpp, \
					Fixed \
					main)

OBJS			=	$(SRCS:%.cpp=$(OBJ_PATH)/%.o)

DEPS			=	$(OBJS:.o=.d)

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n${GREEN}> $(NAME) was successfuly compiled 🎉${END}"

$(OBJ_PATH)/%.o: %.cpp $(HEADERS)
			@mkdir -p $(dir $@)
			@printf "${BLUE}> Generating $(NAME) objects... %-33.33s\r${END}" $@
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_PATH)
	@printf "${YELLOW}> Cleaning $(NAME)'s objects has been done ❌${END}\n"

fclean:	clean
	@$(RM) $(NAME)
	@printf "${YELLOW}> Cleaning of $(NAME) has been done ❌${END}\n"

re: clean all

-include $(DEPS)

.PHONY: all clean re fclean
