NAME	=	cub3D

rm	=	rm -f
cc	=	cc
CFLAGS	=	-Wall -Wextra -Werror 
DFLAGS	=	-MMD -MP

SRCS	=	cub3d.c renderer_1.c renderer_2.c renderer_3.c \
			renderer_4.c \
			raycaster_1.c raycaster_2.c rend_move.c \

DEPS	=	${patsubst %.c,%.d, ${SRCS}}
OBJS	=	$(addprefix srcs/, $(SRCS:.c=.o))

INCS	=	-I includes -I libft -Imlx_linux -O3 -I colours

LIBFT	=	libft/libft.a
LFT_HDR	=	libft/libft.h
LIB_SRCS=	libft/ft_strjoin.c
LFLAGS	=	-L libft -l ft
LMAKE	=	make -C libft

.PHONY:	all clean fclean re bonus

all:	${NAME}

clean:
	${RM} ${OBJS} $(addprefix srcs/, ${DEPS})
	${RM} ${B_OBJS} $(addprefix srcs/, ${B_DEPS})
	${LMAKE} clean 

%.o:	%.c
	${CC} ${CFLAGS} -c ${DFLAGS} ${INCS} $< -o $@ 

$(NAME):	$(OBJS)	$(LIBFT) includes/cub3d.h
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

mlx_get:
	git clone https://github.com/lemal/mlx_store.git mlx_linux; \
	cd mlx_linux; \
	bash configure; \
	cd ..;

${LIBFT}:	${LIB_SRCS} ${LFT_HDR}
	${LMAKE} 

-include ${DEPS} ${B_DEPS}

fclean: clean
	${RM} ${NAME} ${B_NAME}
	${LMAKE} fclean

re: clean all