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
	**/
short piece_encode(Piece type, Row row, Column col, Color color) {
	return type | (row << 4) | (col << 8) | (color << 12);
}

/**
	*
	* This function returns the type of the piece.
	* 
	**/
Piece piece_decode_type(short piece) {
	return piece & 0xF;
}

/**
	*
	* This function returns the row of the piece.
	* 
	**/
Row piece_decode_row(short piece) {
	return (piece >> 4) & 0xF;
}

/**
	*
	* This function returns the column of the piece.
	* 
	**/
Column piece_decode_column(short piece) {
	return (piece >> 8) & 0xF;
}

/**
	*
	* This function returns the color of the piece.
	* 
	**/
Color piece_decode_color(short piece) {
	return (piece >> 12) & 0xF;
}

/**
	*
	* This function prints a piece for the standard output. 
	* 
	**/
void piece_print(short piece) {
	if(piece == -1) {
		printf(" ");
	} else if(piece_decode_color(piece) == COLOR_WHITE) {
		switch(piece_decode_type(piece)) {
			case PIECE_PAWN: printf("\u2659"); break;
			case PIECE_KNIGHT: printf("\u2658"); break;
			case PIECE_BISHOP: printf("\u2657"); break;
			case PIECE_ROOK: printf("\u2656"); break;
			case PIECE_QUEEN: printf("\u2655"); break;
			case PIECE_KING: printf("\u2654"); break;
		}
	} else {
		switch(piece_decode_type(piece)) {
			case PIECE_PAWN: printf("\u265F"); break;
			case PIECE_KNIGHT: printf("\u265E"); break;
			case PIECE_BISHOP: printf("\u265D"); break;
			case PIECE_ROOK: printf("\u265C"); break;
			case PIECE_QUEEN: printf("\u265B"); break;
			case PIECE_KING: printf("\u265A"); break;
		}
	}
}