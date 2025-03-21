NAMESRV = server
NAMECLN = client
NAMEBSRV = server_bonus
NAMEBCLN = client_bonus
PRINTF = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILESRV = mandatory/server.c
FILECLN = mandatory/client.c
FILEBCLN = bonus/client_bonus.c
FILEBSRV = bonus/server_bonus.c


OBJSRV =${FILESRV:%.c=%.o}
OBJCLN = ${FILECLN:%.c=%.o}


OBJBSRV = ${FILEBSRV:%.c=%.o}
OBJBCLN = ${FILEBCLN:%.c=%.o}



all: $(NAMESRV) $(NAMECLN)

bonus: $(NAMEBSRV) $(NAMEBCLN)

$(PRINTF) :
	make -C printf

$(NAMESRV):${OBJSRV} $(PRINTF) 
	$(CC) $(CFLAGS) $(OBJSRV) printf/libftprintf.a -o $(NAMESRV)

$(NAMECLN):${OBJCLN} $(PRINTF) 
	$(CC) $(CFLAGS) $(OBJCLN) printf/libftprintf.a -o $(NAMECLN)

$(NAMEBSRV):${OBJBSRV} $(PRINTF) 
	$(CC) $(CFLAGS) $(OBJBSRV) printf/libftprintf.a -o $(NAMEBSRV)

$(NAMEBCLN):${OBJBCLN} $(PRINTF) 
	$(CC) $(CFLAGS) $(OBJBCLN) printf/libftprintf.a -o $(NAMEBCLN)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f ${OBJSRV}
	rm -f ${OBJCLN}
	rm -f ${OBJBSRV}
	rm -f ${OBJBCLN}
	make clean -C printf

fclean: clean
	rm -f $(NAMESRV)
	rm -f $(NAMECLN)
	rm -f $(NAMEBSRV)
	rm -f $(NAMEBCLN)
	make fclean -C printf

re : fclean all

.PHONY     : clean re all fclean bonus
.SECONDARY: