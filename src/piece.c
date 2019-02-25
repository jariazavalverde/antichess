/*H*
 * 
 * FILENAME: piece.c
 * DESCRIPTION: Data structures and functions for storing and manipuling chess pieces
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 25.02.2019
 * 
 *H*/

#include "piece.h"



/**
  *
  * This function encodes a piece composed by
  * (type, row, column) as a 32-bits integer.
  * 
  */
int piece_encode(Piece type, Row row, Column col, Color color) {
	return type | (row << 8) | (col << 16) | (color << 24);
}

/**
  *
  * This function returns the type of the piece.
  * 
  */
Piece piece_decode_type(int piece) {
	return piece & 0xFF;
}

/**
  *
  * This function returns the row of the piece.
  * 
  */
Row piece_decode_row(int piece) {
	return (piece >> 8) & 0xFF;
}

/**
  *
  * This function returns the column of the piece.
  * 
  */
Column piece_decode_column(int piece) {
	return (piece >> 16) & 0xFF;
}

/**
  *
  * This function returns the color of the piece.
  * 
  */
Color piece_decode_color(int piece) {
  return (piece >> 24) & 0xFF;
}

/**
  *
  * This function prints a piece for the standard output. 
  * 
  */
void piece_print(int piece) {
    printf("%c%c%c",
        piece_print_type[piece_decode_type(piece)],
        piece_print_column[piece_decode_column(piece)],
        piece_print_row[piece_decode_row(piece)]);
}