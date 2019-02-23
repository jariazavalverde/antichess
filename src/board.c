/*H*
 * 
 * FILENAME: board.c
 * DESCRIPTION: Data structures and functions for storing and manipuling chess boards
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 23.02.2019
 * 
 *H*/

#include "board.h"



/**
  * 
  * This function creates a board, returning a pointer
  * to a newly initialized Board struct.
  * 
  **/
Board *alloc_board() {
	Board *board = malloc(sizeof(Board));
	board->white_pieces = NULL;
	board->black_pieces = NULL;
	board->nb_white_pieces = 0;
	board->nb_black_pieces = 0;
	board->movement = 0;
	board->turn = COLOR_WHITE;
	return board;
}

/**
  * 
  * This function frees a previously allocated board.
  * The pieces underlying the board will also be deallocated.
  * 
  **/
void free_board(Board *board) {
	if(board->white_pieces != NULL)
		free(board->white_pieces);
	if(board->black_pieces != NULL)
		free(board->black_pieces);
	free_board(board);
}