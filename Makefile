NAME	 = avengers_api
NAME_CLI = logviewer

CC			=	cc
CFLAGS		=	-Wall -Wextra -g
INCLUDE		=	-I ./include
HEADER		=	./include/headers.h
HEADER_VI	= ./include/logvi.h

LIBS	= -lcurl -lssl -lcrypto -DMG_ENABLE_OPENSSL -pthread -lmysqlclient
EFLAGS	= -lreadline
LIBFT	= -L ./source/libs/libft/ -lft

S_FOLDER = ./source/
L_FOLDER = libs/
A_FOLDER = api/
C_FOLDER = cli/

LIB =	$(addprefix $(L_FOLDER), \
		mJson.c mongoose.c \
)

API	=	$(addprefix $(A_FOLDER), \
		avengers.c routes.c server.c utils.c mariadb.c  csv_reader.c json.c \
		route_id.c route_alias.c log.c \
)

SRC =	$(addprefix $(S_FOLDER), \
		$(LIB) $(API) \
)

CLI	=	$(addprefix $(C_FOLDER), \
		logvi.c signal.c printer.c filter.c prompt.c \
)

SRC_V =	$(addprefix $(S_FOLDER), \
		$(LIB) $(CLI)\
)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:%.c=%.o)

OBJ		= $(SRC:%.c=%.o)
OBJ_CLI = $(SRC_V:%.c=%.o)

all: $(NAME) logvi

$(NAME): $(OBJ) $(HEADER)
	rm -rf $(NAME)
	make all -C ./source/libs/libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)

logvi: $(NAME_CLI)

$(NAME_CLI): $(OBJ_CLI) $(HEADER_VI)
	rm -rf $(NAME_CLI)
	make all -C ./source/libs/libft
	$(CC) $(CFLAGS) $(OBJ_CLI) $(LIBFT) $(LIBS) $(EFLAGS) -o $(NAME_CLI)

clean:
	make clean -C ./source/libs/libft
	rm -rf $(OBJ) $(OBJ_CLI)
	rm -rf ./a.out

fclean: clean
	make fclean -C ./source/libs/libft
	rm -rf $(NAME) $(NAME_CLI)

re: fclean all

push:fclean
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push

run: all logvi
	./avengers_api

.PHONY: all bonus clean fclean re push run
