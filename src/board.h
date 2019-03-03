/*H*
 * 
 * FILENAME: board.h
 * DESCRIPTION: Data structures and functions for storing and manipuling chess boards
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 03.03.2019
 * 
 *H*/

#include <stdio.h>
#include <stdlib.h>
#include "piece.h"



#ifndef ANTICHESS_BOARD_H
#define ANTICHESS_BOARD_H

typedef struct Board {
	short *white_pieces;
	short *black_pieces;
	short nb_white_pieces;
	short nb_black_pieces;
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
Board *board_alloc(short nb_white_pieces, short nb_black_pieces);

/**
  * 
  * This function frees a previously allocated board.
  * The pieces underlying the board will not be deallocated.
  * 
  **/
void board_free(Board *board);

/**
  *
  * This function transforms the arrays of pieces of a board
  * into an array of 64 cells, returning a pointer to a newly
  * initialized array of 64 integers.
  *  
  **/
short *board_pieces_to_array(Board *board);

/**
  *
  * This function checks if a piece is in the board.
  *  
  **/
int board_piece_in_array(short *pieces, Row row, Column column);

/**
  *
  * This function returns a piece from a board.
  *  
  **/
short board_piece_from_array(short *pieces, Row row, Column column);

/**
  *
  * This function returns a new board after
  * moving a piece. 
  * 
  **/
Board *board_perform_movement(Board *board, short from, short to, int capture);

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
  **/
void board_print(Board *board);