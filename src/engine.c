/*H*
 * 
 * FILENAME: engine.c
 * DESCRIPTION: Antichess engine
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 04.03.2019
 * 
 *H*/

#include "engine.h"



/**
  * 
  * This function returns the best movement for
  * a given position.
  * 
  **/
Action *engine_best_movement(Board *board, int max_depth) {
	Board *best;
	Action *action;
	best = engine_minimax(board, board->turn, -999, 999, max_depth);
	if(best == NULL)
		return NULL;
	action = malloc(sizeof(Action));
	action->from = best->last_action.from;
	action->to = best->last_action.to;
	action->capture = best->last_action.capture;
	board_free(best);
	return action;
}

/**
  * 
  * This function ...
  * 
  **/
Board *engine_minimax(Board *board, Color color, int alpha, int beta, int max_depth) {
	int i;
	State *state;
	Board *new_board, *best = NULL;
	if(max_depth == 0) {
		board->score = engine_score_board(board);
		return board;
	}
	state = engine_expand(board);
	if(state->nb_boards == 0) {
		board->score = engine_score_board(board);
		free(state->boards);
		free(state);
		return board;
	}
	if(board->turn == color) {
		for(i = 0; i < state->nb_boards; i++) {
			if(beta > alpha) {
				new_board = engine_minimax(state->boards[i], color, alpha, beta, max_depth-1);
				if(best == NULL || new_board->score > alpha) {
					alpha = new_board->score;
					if(best != NULL) {
						board_free(best);
					}
					best = state->boards[i];
				} else {
					board_free(state->boards[i]);
				}
			} else {
				board_free(state->boards[i]);
			}
		}
		best->score = alpha;
	} else {
		for(i = 0; i < state->nb_boards; i++) {
			if(beta > alpha) {
				new_board = engine_minimax(state->boards[i], color, alpha, beta, max_depth-1);
				if(best == NULL || new_board->score < beta) {
					beta = new_board->score;
					if(best != NULL) {
						board_free(best);
					}
					best = state->boards[i];
				} else {
					board_free(state->boards[i]);
				}
			} else {
				board_free(state->boards[i]);
			}
		}
		best->score = beta;
	}
	free(state->boards);
	free(state);
	return best;
}

/**
  * 
  * This function returns the score of the board for a
  * given player.
  * 
  **/
int engine_score_board(Board *board) {
	Color color;
	int i, score;
	short *pieces, nb_pieces;
	color = board->turn;
	pieces = color == COLOR_WHITE ? board->white_pieces : board->black_pieces;
	nb_pieces = color == COLOR_WHITE ? board->nb_white_pieces : board->nb_black_pieces;
	score = 0;
	for(i = 0; i < nb_pieces; i++) {
		switch(piece_decode_type(pieces[i])) {
			case PIECE_PAWN: score -= 1; break;
			case PIECE_KNIGHT: score -= 3; break;
			case PIECE_BISHOP: score -= 3; break;
			case PIECE_ROOK: score -= 5; break;
			case PIECE_QUEEN: score -= 9; break;
			case PIECE_KING: score -= 2; break;
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
State *engine_expand(Board *board) {
	Color color;
	short *pieces, *array, nb_pieces, piece;
	int i, nb_actions, capture, row, column;
	State *state;
	Action *actions;
	color = board->turn;
	pieces = color == COLOR_WHITE ? board->white_pieces : board->black_pieces;
	nb_pieces = color == COLOR_WHITE ? board->nb_white_pieces : board->nb_black_pieces;
	array = board_pieces_to_array(board);
	actions = malloc(218*sizeof(Action));
	nb_actions = 0;
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
	state = malloc(sizeof(State));
	state->boards = malloc(nb_actions*sizeof(Board*));
	state->nb_boards = nb_actions;
	for(i = 0; i < nb_actions; i++) {
		state->boards[i] = board_perform_movement(board, actions[i].from, actions[i].to, capture);
	}
	free(actions);
	free(array);
	return state;
}