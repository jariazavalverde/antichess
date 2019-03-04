/*H*
 * 
 * FILENAME: engine.h
 * DESCRIPTION: Antichess engine
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 04.03.2019
 * 
 *H*/

#include <stdio.h>
#include <math.h>
#include "piece.h"
#include "board.h"



#ifndef ANTICHESS_ENGINE_H
#define ANTICHESS_ENGINE_H

typedef struct State {
	Board **boards;
	int nb_boards;
} State;

#endif



/**
  * 
  * This function returns the best movement for
  * a given position.
  * 
  **/
Action *engine_best_movement(Board *board, int max_depth);

/**
  * 
  * This function ...
  * 
  **/
Board *engine_minimax(Board *board, Color color, int alpha, int beta, int max_depth);

/**
  * 
  * This function returns the score of the board for a
  * given player.
  * 
  **/
int engine_score_board(Board *board);

/**
  * 
  * This function returns the possible actions for a
  * given player.
  * 
  **/
State *engine_expand(Board *board);