NAMESRV = server
NAMECLN = client
PRINTF = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILESRV = server.c
FILECLN = client.c
# FILECLN = client.c
# FILES_BNS = 

OBJSRV =${FILESRV:%.c=%.o}
OBJCLN = ${FILECLN:%.c=%.o}
# OBJ_BN =${FILES_BNS:%.c=%.o}


all: $(NAMESRV) $(NAMECLN)

$(PRINTF) :
	make -C printf

$(NAMESRV):${OBJSRV} $(PRINTF) 
	$(CC) $(CFLAGS) $(OBJSRV) printf/libftprintf.a -o $(NAMESRV)

$(NAMECLN):${OBJCLN} $(PRINTF) 
	$(CC) $(CFLAGS) $(OBJCLN) printf/libftprintf.a -o $(NAMECLN)


# bonus:${OBJ_BN}
# 	$(AR) ${NAME} $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f ${OBJSRV}
	make clean -C printf

fclean: clean
	rm -f $(NAMESRV)
	make fclean -C printf

re : fclean all

.PHONY     : clean re all fclean bonus