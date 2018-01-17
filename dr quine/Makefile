
CC = cc
CFLAG = -Wall -Wextra -Werror

DIR_COLLEEN  = Colleen/
DIR_GRACE    = Grace/
DIR_SULLY    = Sully/

NAME_COLLEEN = Colleen
NAME_GRACE   = Grace
NAME_SULLY   = Sully

SRC_COLLEEN  = Colleen.c
SRC_GRACE    = Grace.c
SRC_SULLY    = Sully.c

OBJ_COLLEEN = $(SRC_COLLEEN:.c=.o)
OBJ_GRACE   = $(SRC_GRACE:.c=.o)
OBJ_SULLY   = $(SRC_SULLY:.c=.o)

all: $(NAME_COLLEEN) $(NAME_GRACE) $(NAME_SULLY)

$(NAME_COLLEEN): $(addprefix $(DIR_COLLEEN), $(OBJ_COLLEEN))
	@$(CC) $(CFLAG) -o $(addprefix $(DIR_COLLEEN), $(NAME_COLLEEN)) $(addprefix $(DIR_COLLEEN), $(OBJ_COLLEEN))

$(NAME_GRACE): $(addprefix $(DIR_GRACE), $(OBJ_GRACE))
	@$(CC) $(CFLAG) -o $(addprefix $(DIR_GRACE), $(NAME_GRACE)) $(addprefix $(DIR_GRACE), $(OBJ_GRACE))

$(NAME_SULLY): $(addprefix $(DIR_SULLY), $(OBJ_SULLY))
	@$(CC) $(CFLAG) -o $(addprefix $(DIR_SULLY), $(NAME_SULLY)) $(addprefix $(DIR_SULLY), $(OBJ_SULLY))

$(DIR_COLLEEN)%.o: $(DIR_COLLEEN)%.c
	@$(CC) $(CFLAG) -c $< -o $@

$(DIR_GRACE)%.o: $(DIR_GRACE)%.c
	@$(CC) $(CFLAG) -c $< -o $@

$(DIR_SULLY)%.o: $(DIR_SULLY)%.c
	@$(CC) $(CFLAG) -c $< -o $@

clean:
	@rm -f $(addprefix $(DIR_COLLEEN), $(OBJ_COLLEEN))
	@rm -f $(addprefix $(DIR_GRACE), $(OBJ_GRACE))
	@rm -f $(addprefix $(DIR_SULLY), $(OBJ_SULLY))

fclean: clean
	@rm -f $(addprefix $(DIR_COLLEEN), $(NAME_COLLEEN))
	@rm -f $(addprefix $(DIR_GRACE), $(NAME_GRACE))
	@rm -f $(addprefix $(DIR_SULLY), $(NAME_SULLY))

re : fclean all

.PHONY: all
