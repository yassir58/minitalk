CFLAGS=-Wall -Wextra -Werror
SERVER_SRC= server.c
SERVER_SRC_BONUS= server_bonus.c 
CLIENT_SRC_BONUS= client_bonus.c
UTILS_SRC= utils.c
CLIENT_SRC= client.c
CLIENT_OBJ= client.o 
SERVER_OBJ= server.o
SERVER_BONUS_OBJ=server_bonus.o 
CLIENT_BONUS_OBJ=client_bonus.o
UTILS_OBJ = utils.o
NAME= server client

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

server:$(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o server
client:$(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o client

bonus:server_bonus client_bonus

server_bonus:$(SERVER_BONUS_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(UTILS_OBJ) -o server_bonus
client_bonus:$(CLIENT_BONUS_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(UTILS_OBJ) -o client_bonus
clean:
	rm -fr *.o 
fclean:clean
	rm -fr server client server_bonus client_bonus
re:fclean all