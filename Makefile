NAME	=	libasm.so

CC	=	gcc

SRC	=	memcpy.asm	\
		memmove.asm	\
		memset.asm	\
		rindex.asm	\
		strcasecmp.asm	\
		strchr.asm	\
		strcmp.asm	\
		strlen.asm	\
		strncmp.asm	\
		strpbrk.asm

OBJ	=	$(SRC:.asm=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -shared $(OBJ) -o $(NAME)

%.o	:	%.asm
		nasm -f elf64 $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:
	rm -f $(OBJ) $(NAME)

re	:	fclean all
