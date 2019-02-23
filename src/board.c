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
Board *board_alloc(int nb_white_pieces, int nb_black_pieces) {
	Board *board = malloc(sizeof(Board));
	board->white_pieces = malloc(nb_white_pieces*sizeof(PieceBoard*));
	board->black_pieces = malloc(nb_black_pieces*sizeof(PieceBoard*));
	board->nb_white_pieces = nb_white_pieces;
	board->nb_black_pieces = nb_black_pieces;
	board->movement = 0;
	board->turn = COLOR_WHITE;
	return board;
}

/**
  * 
  * This function frees a previously allocated board.
  * The pieces underlying the board will not be deallocated.
  * 
  **/
void board_free(Board *board) {
	free(board->white_pieces);
	free(board->black_pieces);
	free(board);
}