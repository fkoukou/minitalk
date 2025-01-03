# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Executables
SERVER = server
CLIENT = client

# Source files
SSRC = server.c
CSRC = client.c utils.c

# Library
PRINTF = libftprintf.a
PRINTF_DIR = My_printf

# Object files
SOBJ = $(SSRC:.c=.o)
COBJ = $(CSRC:.c=.o)

# Targets
all: $(SERVER) $(CLIENT)

$(SERVER): $(SOBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(SOBJ) $(PRINTF) -o $@

$(CLIENT): $(COBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(COBJ) $(PRINTF) -o $@

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
	mv $(PRINTF_DIR)/$(PRINTF) .

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(SOBJ) $(COBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re

