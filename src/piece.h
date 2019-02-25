/*H*
 * 
 * FILENAME: piece.h
 * DESCRIPTION: Data structures and functions for storing and manipuling chess pieces
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 25.02.2019
 * 
 *H*/

#include <stdio.h>



#ifndef ANTICHESS_PIECE_H
#define ANTICHESS_PIECE_H

static const char piece_print_type[] = "PNBRQK";
static const char piece_print_row[] = "12345678";
static const char piece_print_column[] = "abcdefgh";

typedef enum Color {COLOR_WHITE, COLOR_BLACK} Color;
typedef enum Piece {PIECE_PAWN, PIECE_KNIGHT, PIECE_BISHOP, PIECE_ROOK, PIECE_QUEEN, PIECE_KING} Piece;
typedef enum Row {ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8} Row;
typedef enum Column {COL_A, COL_B, COL_C, COL_D, COL_E, COL_F, COL_G, COL_H} Column;

#endif



/**
  *
  * This function encodes a piece composed by
  * (type, row, column) as a 32-bits integer.
  * 
  */
int piece_encode(Piece type, Row row, Column col, Color color);

/**
  *
  * This function returns the type of the piece.
  * 
  */
Piece piece_decode_type(int piece);

/**
  *
  * This function returns the row of the piece.
  * 
  */
Row piece_decode_row(int piece);

/**
  *
  * This function returns the column of the piece.
  * 
  */
Column piece_decode_column(int piece);

/**
  *
  * This function returns the color of the piece.
  * 
  */
Color piece_decode_color(int piece);

/**
  *
  * This function prints a piece for the standard output. 
  * 
  */
void piece_print(int piece);