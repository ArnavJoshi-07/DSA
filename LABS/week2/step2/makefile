all: client client_rect

client: client.c list.c rect.c list.h rect.h
	gcc -Wall client.c list.c rect.c -o client

client_rect: client_rect.c rect.c rect.h
	gcc  -Wall client_rect.c rect.c -o client_rect

clean:
	rm -f client client_rect