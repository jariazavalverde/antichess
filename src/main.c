/*H*
 * 
 * FILENAME: main.c
 * DESCRIPTION: Antichess engine
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 04.03.2019
 * COMPILING: gcc -I/usr/include -L *.h *.c -o antichess -g
 * 
 *H*/

#include <stdio.h>
#include "board.h"
#include "engine.h"



int main(int argc, char **argv) {
	int max_depth;
	Board *board = board_new_game(), *next;
	board_print(board);
	while(1) {
		scanf("%d", &max_depth);
		if(max_depth == 0)
			break;
		Action *action = engine_best_movement(board, max_depth);
		if(action != NULL) {
			next = board_perform_movement(board, action->from, action->to, action->capture);
			board_print(next);
			board_free(board);
			board = next;
			free(action);
		} else {
			break;
		}
	}
	board_free(board);
	return 0;
}
