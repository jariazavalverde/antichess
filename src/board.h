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



#ifndef ANTICHESS_BOARD_H
#define ANTICHESS_BOARD_H

typedef enum Piece {PIECE_PAWN, PIECE_KNIGHT, PIECE_BISHOP, PIECE_ROOK, PIECE_QUEEN, PIECE_KING} Piece;
typedef enum Color {COLOR_WHITE, COLOR_BLACK} Color;
typedef enum Row {ROW_1 = 1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8} Row;
typedef enum Column {COL_A = 1, COL_B, COL_C, COL_D, COL_E, COL_F, COL_G, COL_H} Column;

typedef struct PieceBoard {
	Piece piece;
	Row row;
	Column column;
} PieceBoard;

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