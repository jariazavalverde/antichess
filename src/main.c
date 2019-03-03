/*H*
 * 
 * FILENAME: main.c
 * DESCRIPTION: Antichess engine
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 25.02.2019
 * COMPILING: gcc -I/usr/include -L *.h *.c -o antichess -g
 * 
 *H*/

#include <stdio.h>
#include "board.h"
#include "engine.h"



int main(int argc, char **argv) {
	Board *board = board_new_game();
	Stack *stack = stack_alloc();
	stack_push_state(stack, board);
	engine_expand(stack->states, stack);
	stack_print(stack);
	stack_free(stack);
	return 0;
}
