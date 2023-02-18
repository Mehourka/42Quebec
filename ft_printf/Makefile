LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

$(LIB): 
	make -C libft

test : cleantest main.c $(LIB)
	gcc -o test main.c  -Llibft -lft -I libft && ./test

cleantest : 
	rm -f ./test