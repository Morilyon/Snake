snake getche: snake.o main.c getche.c
	gcc snake.o main.c -o snake
	gcc getche.c -o getche
	clear
snake.o : snake.h snake.c
	gcc snake.h snake.c -c
	clear
