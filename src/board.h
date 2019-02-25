/*H*
 * 
 * FILENAME: board.h
 * DESCRIPTION: Data structures and functions for storing and manipuling chess boards
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 25.02.2019
 * 
 *H*/

#include <stdio.h>
#include <stdlib.h>
#include "piece.h"



#ifndef ANTICHESS_BOARD_H
#define ANTICHESS_BOARD_H

typedef enum Color {COLOR_WHITE, COLOR_BLACK} Color;

typedef struct Board {
	int *white_pieces;
	int *black_pieces;
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

/**
  * 
  * This function creates a board, returning a pointer
  * to a newly initialized Board struct with pieces of
  * a new game.
  * 
  **/
Board *board_new_game();

/**
  *
  * This function prints a board for the standard output. 
  * 
  */
void board_print(Board *board);