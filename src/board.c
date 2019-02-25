/*H*
 * 
 * FILENAME: board.c
 * DESCRIPTION: Data structures and functions for storing and manipuling chess boards
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 25.02.2019
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
	board->white_pieces = malloc(nb_white_pieces*sizeof(short));
	board->black_pieces = malloc(nb_black_pieces*sizeof(short));
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

/**
  *
  * This function transforms the arrays of pieces of a board
  * into an array of 64 cells, returning a pointer to a newly
  * initialized array of 64 integers.
  *  
  **/
short *board_pieces_to_array(Board *board) {
	int i, j, k;
	short piece, *array = malloc(64*sizeof(int));
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			for(k = 0; k < board->nb_white_pieces; k++) {
				piece = board->white_pieces[k];
				if(7 - i == piece_decode_row(piece) && j == piece_decode_column(piece)) {
					array[i*8+j] = piece;
					break;
				}
			}
			if(k == board->nb_white_pieces) {
				for(k = 0; k < board->nb_black_pieces; k++) {
					piece = board->black_pieces[k];
					if(7 - i == piece_decode_row(piece) && j == piece_decode_column(piece)) {
						array[i*8+j] = piece;
						break;
					}
				}
			}
			if(k == board->nb_black_pieces)
				array[i*8+j] = -1;
		}
	}
	return array;
}

/**
  * 
  * This function creates a board, returning a pointer
  * to a newly initialized Board struct with pieces of
  * a new game.
  * 
  **/
Board *board_new_game() {
	int i;
	Board *board = board_alloc(16, 16);
	board->white_pieces[0] = piece_encode(PIECE_ROOK, ROW_1, COL_A, COLOR_WHITE);
	board->white_pieces[1] = piece_encode(PIECE_KNIGHT, ROW_1, COL_B, COLOR_WHITE);
	board->white_pieces[2] = piece_encode(PIECE_BISHOP, ROW_1, COL_C, COLOR_WHITE);
	board->white_pieces[3] = piece_encode(PIECE_QUEEN, ROW_1, COL_D, COLOR_WHITE);
	board->white_pieces[4] = piece_encode(PIECE_KING, ROW_1, COL_E, COLOR_WHITE);
	board->white_pieces[5] = piece_encode(PIECE_BISHOP, ROW_1, COL_F, COLOR_WHITE);
	board->white_pieces[6] = piece_encode(PIECE_KNIGHT, ROW_1, COL_G, COLOR_WHITE);
	board->white_pieces[7] = piece_encode(PIECE_ROOK, ROW_1, COL_H, COLOR_WHITE);
	board->white_pieces[8] = piece_encode(PIECE_PAWN, ROW_2, COL_A, COLOR_WHITE);
	board->white_pieces[9] = piece_encode(PIECE_PAWN, ROW_2, COL_B, COLOR_WHITE);
	board->white_pieces[10] = piece_encode(PIECE_PAWN, ROW_2, COL_C, COLOR_WHITE);
	board->white_pieces[11] = piece_encode(PIECE_PAWN, ROW_2, COL_D, COLOR_WHITE);
	board->white_pieces[12] = piece_encode(PIECE_PAWN, ROW_2, COL_E, COLOR_WHITE);
	board->white_pieces[13] = piece_encode(PIECE_PAWN, ROW_2, COL_F, COLOR_WHITE);
	board->white_pieces[14] = piece_encode(PIECE_PAWN, ROW_2, COL_G, COLOR_WHITE);
	board->white_pieces[15] = piece_encode(PIECE_PAWN, ROW_2, COL_H, COLOR_WHITE);
	board->black_pieces[0] = piece_encode(PIECE_ROOK, ROW_8, COL_A, COLOR_BLACK);
	board->black_pieces[1] = piece_encode(PIECE_KNIGHT, ROW_8, COL_B, COLOR_BLACK);
	board->black_pieces[2] = piece_encode(PIECE_BISHOP, ROW_8, COL_C, COLOR_BLACK);
	board->black_pieces[3] = piece_encode(PIECE_QUEEN, ROW_8, COL_D, COLOR_BLACK);
	board->black_pieces[4] = piece_encode(PIECE_KING, ROW_8, COL_E, COLOR_BLACK);
	board->black_pieces[5] = piece_encode(PIECE_BISHOP, ROW_8, COL_F, COLOR_BLACK);
	board->black_pieces[6] = piece_encode(PIECE_KNIGHT, ROW_8, COL_G, COLOR_BLACK);
	board->black_pieces[7] = piece_encode(PIECE_ROOK, ROW_8, COL_H, COLOR_BLACK);
	board->black_pieces[8] = piece_encode(PIECE_PAWN, ROW_7, COL_A, COLOR_BLACK);
	board->black_pieces[9] = piece_encode(PIECE_PAWN, ROW_7, COL_B, COLOR_BLACK);
	board->black_pieces[10] = piece_encode(PIECE_PAWN, ROW_7, COL_C, COLOR_BLACK);
	board->black_pieces[11] = piece_encode(PIECE_PAWN, ROW_7, COL_D, COLOR_BLACK);
	board->black_pieces[12] = piece_encode(PIECE_PAWN, ROW_7, COL_E, COLOR_BLACK);
	board->black_pieces[13] = piece_encode(PIECE_PAWN, ROW_7, COL_F, COLOR_BLACK);
	board->black_pieces[14] = piece_encode(PIECE_PAWN, ROW_7, COL_G, COLOR_BLACK);
	board->black_pieces[15] = piece_encode(PIECE_PAWN, ROW_7, COL_H, COLOR_BLACK);
	return board;
}

/**
  *
  * This function prints a board for the standard output. 
  * 
  **/
void board_print(Board *board) {
	int i, j;
	short *pieces;
	pieces = board_pieces_to_array(board);
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			printf(" |");
			piece_print(pieces[i*8+j]);
		}
		printf(" |\n");
	}
	free(pieces);
}