/*H*
 * 
 * FILENAME: engine.h
 * DESCRIPTION: Antichess engine
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 03.03.2019
 * 
 *H*/

#include <stdio.h>
#include "piece.h"
#include "board.h"



#ifndef ANTICHESS_ENGINE_H
#define ANTICHESS_ENGINE_H

typedef struct Action {
    short from;
    short to;
} Action;

typedef struct State {
    Board *board;
    struct State *next;
} State;

typedef struct Stack {
    State *states;
    int nb_states;
} Stack;

#endif



/**
  * 
  * This function creates a board, returning a pointer
  * to a newly initialized Board struct.
  * 
  **/
Stack *stack_alloc();

/**
  * 
  * This function frees a previously allocated stack.
  * The boards and states underlying the board will
  * be deallocated.
  * 
  **/
void stack_free(Stack *stack);

/**
  *
  * This function pushes a new board into an stack.
  * 
  **/
void stack_push_state(Stack *stack, Board *board);

/**
  *
  * This function prints an stack for the standard output.
  * 
  **/
void stack_print(Stack *stack);

/**
  * 
  * This function returns the score of the board for a
  * given player.
  * 
  **/
int engine_score_board(State *state);

/**
  * 
  * This function returns the possible actions for a
  * given player.
  * 
  **/
int engine_expand(State *state, Stack *stack);