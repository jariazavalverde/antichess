/*H*
 * 
 * FILENAME: board.h
 * DESCRIPTION: Data structures and functions for storing and manipuling chess boards
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 23.02.2019
 * 
 *H*/

#include <stdlib.h>
#include "piece.h"



#ifndef ANTICHESS_BOARD_H
#define ANTICHESS_BOARD_H

typedef struct Board {
	PieceBoard **white_pieces;
	PieceBoard **black_pieces;
	int nb_white_pieces;
	int nb_black_pieces;
	int movement;
	Color turn;
} Board;

#endif



/**
  * 
  * This function creates a board, returning a pointer
  * to a newly initialized Board struct.
  * 
  **/
Board *board_alloc(int nb_white_pieces, int nb_black_pieces);

/**
  * 
  * This function frees a previously allocated board.
  * The pieces underlying the board will not be deallocated.
  * 
  **/
void board_free(Board *board);