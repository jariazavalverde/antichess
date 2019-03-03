/*H*
 * 
 * FILENAME: engine.c
 * DESCRIPTION: Antichess engine
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 03.03.2019
 * 
 *H*/

#include "engine.h"



/**
  * 
  * This function creates a board, returning a pointer
  * to a newly initialized Board struct.
  * 
  **/
Stack *stack_alloc() {
	Stack *stack = malloc(sizeof(Stack));
	stack->states = NULL;
	stack->nb_states = 0;
	return stack;
}

/**
  * 
  * This function frees a previously allocated stack.
  * The boards and states underlying the board will
  * be deallocated.
  * 
  **/
void stack_free(Stack *stack) {
	State *state = stack->states, *next;
	while(state != NULL) {
		board_free(state->board);
		next = state->next;
		free(state);
		state = next;
	}
	free(stack);
}

/**
  *
  * This function pushes a new board into an stack.
  * 
  **/
void stack_push_state(Stack *stack, Board *board) {
	State *state = malloc(sizeof(State));
	state->board = board;
	state->next = stack->states;
	stack->states = state;
	stack->nb_states++;
}

/**
  *
  * This function prints an stack for the standard output.
  * 
  **/
void stack_print(Stack *stack) {
	State *state = stack->states;
	while(state != NULL) {
		board_print(state->board);
		printf("\n");
		state = state->next;
	}
}

/**
  * 
  * This function returns the score of the board for a
  * given player.
  * 
  **/
int engine_score_board(State *state) {
	Board *board;
	Color color;
	int i, score;
	short *pieces, nb_pieces;
	board = state->board;
	pieces = color == COLOR_WHITE ? board->white_pieces : board->black_pieces;
	nb_pieces = color == COLOR_WHITE ? board->nb_white_pieces : board->nb_black_pieces;
	color = board->turn;
	for(i = 0; i < nb_pieces; i++) {
		switch(piece_decode_type(pieces[i])) {
			case PIECE_PAWN: score += 1; break;
			case PIECE_KNIGHT: score += 3; break;
			case PIECE_BISHOP: score += 3; break;
			case PIECE_ROOK: score += 5; break;
			case PIECE_QUEEN: score += 9; break;
			case PIECE_KING: score += 1; break;
		}
	}
	return score;
}

/**
  * 
  * This function returns the possible actions for a
  * given player.
  * 
  **/
int engine_expand(State *state, Stack *stack) {
	Color color;
	short *pieces, *array, nb_pieces, piece;
	int i, nb_actions, capture, row, column;
	Action *actions;
	Board *board;
	board = state->board;
	color = board->turn;
	pieces = color == COLOR_WHITE ? board->white_pieces : board->black_pieces;
	nb_pieces = color == COLOR_WHITE ? board->nb_white_pieces : board->nb_black_pieces;
	array = board_pieces_to_array(board);
	nb_actions = 0;
	actions = malloc(218*sizeof(Action));
	capture = 0;
	// Get possible movements
	for(i = 0; i < nb_pieces; i++) {
		row = piece_decode_row(pieces[i]);
		column = piece_decode_column(pieces[i]);
		switch(piece_decode_type(pieces[i])) {
			case PIECE_PAWN:
				if(color == COLOR_WHITE) {
					piece = board_piece_from_array(array, row+1, column+1);
					if(piece != -1 && piece_decode_color(piece) != color) {
						if(!capture) nb_actions = 0;
						capture = 1;
						actions[nb_actions].from = pieces[i];
						actions[nb_actions].to = piece_encode(PIECE_PAWN, row+1, column+1, color);
						nb_actions++;
					}
					piece = board_piece_from_array(array, row+1, column-1);
					if(piece != -1 && piece_decode_color(piece) != color) {
						if(!capture) nb_actions = 0;
						capture = 1;
						actions[nb_actions].from = pieces[i];
						actions[nb_actions].to = piece_encode(PIECE_PAWN, row+1, column-1, color);
						nb_actions++;
					}
				} else {
					piece = board_piece_from_array(array, row-1, column+1);
					if(piece != -1 && piece_decode_color(piece) != color) {
						if(!capture) nb_actions = 0;
						actions[nb_actions].from = pieces[i];
						actions[nb_actions].to = piece_encode(PIECE_PAWN, row-1, column+1, color);
						capture = 1;
						nb_actions++;
					}
					piece = board_piece_from_array(array, row-1, column-1);
					if(piece != -1 && piece_decode_color(piece) != color) {
						if(!capture) nb_actions = 0;
						actions[nb_actions].from = pieces[i];
						actions[nb_actions].to = piece_encode(PIECE_PAWN, row-1, column-1, color);
						capture = 1;
						nb_actions++;
					}
				}
				if(!capture) {
					if(color == COLOR_WHITE) {
						piece = board_piece_from_array(array, row+1, column);
						if(piece == -1) {
							actions[nb_actions].from = pieces[i];
							actions[nb_actions].to = piece_encode(PIECE_PAWN, row+1, column, color);
							nb_actions++;
						}
					} else {
						piece = board_piece_from_array(array, row-1, column);
						if(piece == -1) {
							actions[nb_actions].from = pieces[i];
							actions[nb_actions].to = piece_encode(PIECE_PAWN, row-1, column, color);
							nb_actions++;
						}
					}
				}
				break;
			case PIECE_KNIGHT:

				break;
			case PIECE_BISHOP:

				break;
			case PIECE_ROOK:

				break;
			case PIECE_QUEEN:

				break;
			case PIECE_KING:

				break;
		}
	}
	// Push states into the stack
	for(i = 0; i < nb_actions; i++) {
		stack_push_state(stack, board_perform_movement(board, actions[i].from, actions[i].to, capture));
	}
	free(actions);
	free(array);
	return nb_actions;
}