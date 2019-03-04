/*H*
 * 
 * FILENAME: board.c
 * DESCRIPTION: Data structures and functions for storing and manipuling chess boards
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 03.03.2019
 * 
 *H*/

#include "board.h"



/**
  * 
  * This function creates a board, returning a pointer
  * to a newly initialized Board struct.
  * 
  **/
Board *board_alloc(short nb_white_pieces, short nb_black_pieces) {
	Board *board = malloc(sizeof(Board));
	board->white_pieces = malloc(nb_white_pieces*sizeof(short));
	board->black_pieces = malloc(nb_black_pieces*sizeof(short));
	board->nb_white_pieces = nb_white_pieces;
	board->nb_black_pieces = nb_black_pieces;
	board->movement = 1;
	board->turn = COLOR_WHITE;
	board->last_action.from = -1;
	board->last_action.to = -1;
	board->last_action.capture = 0;
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
	int i, j, k, match;
	short piece, *array = malloc(64*sizeof(short));
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			match = 0;
			for(k = 0; k < board->nb_white_pieces; k++) {
				piece = board->white_pieces[k];
				if(i == piece_decode_row(piece) && j == piece_decode_column(piece)) {
					array[i*8+j] = piece;
					match = 1;
					break;
				}
			}
			if(!match) {
				for(k = 0; k < board->nb_black_pieces; k++) {
					piece = board->black_pieces[k];
					if(i == piece_decode_row(piece) && j == piece_decode_column(piece)) {
						array[i*8+j] = piece;
						match = 1;
						break;
					}
				}
			}
			if(!match)
				array[i*8+j] = -1;
		}
	}
	return array;
}

/**
  *
  * This function checks if a piece is in the board.
  *  
  **/
int board_piece_in_array(short *pieces, Row row, Column column) {
	return row >= ROW_1 && row <= ROW_8 && column >= COL_A && column <= COL_H && pieces[row*8+column] != -1;
}

/**
  *
  * This function returns a piece from a board.
  *  
  **/
short board_piece_from_array(short *pieces, Row row, Column column) {
	if(row >= ROW_1 && row <= ROW_8 && column >= COL_A && column <= COL_H)
		return pieces[row*8+column];
	return -1;
}

/**
  *
  * This function returns a new board after
  * moving a piece. 
  * 
  **/
Board *board_perform_movement(Board *board, short from, short to, int capture) {
	Color color;
	int i, j, nb_white_pieces, nb_black_pieces;
	Row row;
	Column column;
	Board *new_board;
	color = board->turn;
	nb_white_pieces = color == COLOR_WHITE || !capture ? board->nb_white_pieces : board->nb_white_pieces-1;
	nb_black_pieces = color == COLOR_BLACK || !capture ? board->nb_black_pieces : board->nb_black_pieces-1;
	new_board = board_alloc(nb_white_pieces, nb_black_pieces);
	new_board->turn = color == COLOR_WHITE ? COLOR_BLACK : COLOR_WHITE;
	new_board->movement = color == COLOR_BLACK ? board->movement+1 : board->movement;
	new_board->last_action.from = from;
	new_board->last_action.to = to;
	new_board->last_action.capture = capture;
	row = piece_decode_row(to);
	column = piece_decode_column(to);
	j = 0;
	for(i = 0; i < board->nb_white_pieces; i++) {
		if(from == board->white_pieces[i]) {
			new_board->white_pieces[j] = to;
			j++;
		} else if(piece_decode_row(board->white_pieces[i]) != row || piece_decode_column(board->white_pieces[i]) != column) {
			new_board->white_pieces[j] = board->white_pieces[i];
			j++;
		}
	}
	j = 0;
	for(i = 0; i < board->nb_black_pieces; i++) {
		if(from == board->black_pieces[i]) {
			new_board->black_pieces[j] = to;
			j++;
		} else if(piece_decode_row(board->black_pieces[i]) != row || piece_decode_column(board->black_pieces[i]) != column) {
			new_board->black_pieces[j] = board->black_pieces[i];
			j++;
		}
	}
	return new_board;
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
			piece_print(pieces[(7-i)*8+j]);
		}
		printf(" |\n");
	}
	free(pieces);
	printf("(:turn %d :movement %s)\n",
		board->movement,
		board->turn == COLOR_WHITE ? "white" : "black");
}