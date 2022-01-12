CFLAGS=-Wall -Wextra -Werror
SERVER_SRC= server.c 
CLIENT_SRC= client.c 
CLIENT_OBJ= client.o 
SERVER_OBJ= server.o

all:server client

$(SERVER_OBJ):
	$(CC) $(CFLAGS) -c $(SERVER_SRC)
$(CLIENT_OBJ):
	$(CC) $(CFLAGS) -c $(CLIENT_SRC)

server:$(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_SRC) -o server
client:$(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o client

clean:
	rm -fr *.o 
fclean:clean
	rm -fr server client
re:fclean all