/*H*
 * 
 * FILENAME: piece.h
 * DESCRIPTION: Data structures and functions for storing and manipuling chess pieces
 * AUTHORS: José Antonio Riaza Valverde
 *          Miguel Riaza Valverde
 * UPDATED: 23.02.2019
 * 
 *H*/



#ifndef ANTICHESS_PIECE_H
#define ANTICHESS_PIECE_H

typedef enum Piece {PIECE_PAWN, PIECE_KNIGHT, PIECE_BISHOP, PIECE_ROOK, PIECE_QUEEN, PIECE_KING} Piece;
typedef enum Color {COLOR_WHITE, COLOR_BLACK} Color;
typedef enum Row {ROW_1 = 1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8} Row;
typedef enum Column {COL_A = 1, COL_B, COL_C, COL_D, COL_E, COL_F, COL_G, COL_H} Column;

typedef struct PieceBoard {
	Piece piece;
	Row row;
	Column column;
} PieceBoard;

#endif



extern PieceBoard piece_pawn_a1;
extern PieceBoard piece_pawn_a2;
extern PieceBoard piece_pawn_a3;
extern PieceBoard piece_pawn_a4;
extern PieceBoard piece_pawn_a5;
extern PieceBoard piece_pawn_a6;
extern PieceBoard piece_pawn_a7;
extern PieceBoard piece_pawn_a8;
extern PieceBoard piece_pawn_b1;
extern PieceBoard piece_pawn_b2;
extern PieceBoard piece_pawn_b3;
extern PieceBoard piece_pawn_b4;
extern PieceBoard piece_pawn_b5;
extern PieceBoard piece_pawn_b6;
extern PieceBoard piece_pawn_b7;
extern PieceBoard piece_pawn_b8;
extern PieceBoard piece_pawn_c1;
extern PieceBoard piece_pawn_c2;
extern PieceBoard piece_pawn_c3;
extern PieceBoard piece_pawn_c4;
extern PieceBoard piece_pawn_c5;
extern PieceBoard piece_pawn_c6;
extern PieceBoard piece_pawn_c7;
extern PieceBoard piece_pawn_c8;
extern PieceBoard piece_pawn_d1;
extern PieceBoard piece_pawn_d2;
extern PieceBoard piece_pawn_d3;
extern PieceBoard piece_pawn_d4;
extern PieceBoard piece_pawn_d5;
extern PieceBoard piece_pawn_d6;
extern PieceBoard piece_pawn_d7;
extern PieceBoard piece_pawn_d8;
extern PieceBoard piece_pawn_e1;
extern PieceBoard piece_pawn_e2;
extern PieceBoard piece_pawn_e3;
extern PieceBoard piece_pawn_e4;
extern PieceBoard piece_pawn_e5;
extern PieceBoard piece_pawn_e6;
extern PieceBoard piece_pawn_e7;
extern PieceBoard piece_pawn_e8;
extern PieceBoard piece_pawn_f1;
extern PieceBoard piece_pawn_f2;
extern PieceBoard piece_pawn_f3;
extern PieceBoard piece_pawn_f4;
extern PieceBoard piece_pawn_f5;
extern PieceBoard piece_pawn_f6;
extern PieceBoard piece_pawn_f7;
extern PieceBoard piece_pawn_f8;
extern PieceBoard piece_pawn_g1;
extern PieceBoard piece_pawn_g2;
extern PieceBoard piece_pawn_g3;
extern PieceBoard piece_pawn_g4;
extern PieceBoard piece_pawn_g5;
extern PieceBoard piece_pawn_g6;
extern PieceBoard piece_pawn_g7;
extern PieceBoard piece_pawn_g8;
extern PieceBoard piece_knight_a1;
extern PieceBoard piece_knight_a2;
extern PieceBoard piece_knight_a3;
extern PieceBoard piece_knight_a4;
extern PieceBoard piece_knight_a5;
extern PieceBoard piece_knight_a6;
extern PieceBoard piece_knight_a7;
extern PieceBoard piece_knight_a8;
extern PieceBoard piece_knight_b1;
extern PieceBoard piece_knight_b2;
extern PieceBoard piece_knight_b3;
extern PieceBoard piece_knight_b4;
extern PieceBoard piece_knight_b5;
extern PieceBoard piece_knight_b6;
extern PieceBoard piece_knight_b7;
extern PieceBoard piece_knight_b8;
extern PieceBoard piece_knight_c1;
extern PieceBoard piece_knight_c2;
extern PieceBoard piece_knight_c3;
extern PieceBoard piece_knight_c4;
extern PieceBoard piece_knight_c5;
extern PieceBoard piece_knight_c6;
extern PieceBoard piece_knight_c7;
extern PieceBoard piece_knight_c8;
extern PieceBoard piece_knight_d1;
extern PieceBoard piece_knight_d2;
extern PieceBoard piece_knight_d3;
extern PieceBoard piece_knight_d4;
extern PieceBoard piece_knight_d5;
extern PieceBoard piece_knight_d6;
extern PieceBoard piece_knight_d7;
extern PieceBoard piece_knight_d8;
extern PieceBoard piece_knight_e1;
extern PieceBoard piece_knight_e2;
extern PieceBoard piece_knight_e3;
extern PieceBoard piece_knight_e4;
extern PieceBoard piece_knight_e5;
extern PieceBoard piece_knight_e6;
extern PieceBoard piece_knight_e7;
extern PieceBoard piece_knight_e8;
extern PieceBoard piece_knight_f1;
extern PieceBoard piece_knight_f2;
extern PieceBoard piece_knight_f3;
extern PieceBoard piece_knight_f4;
extern PieceBoard piece_knight_f5;
extern PieceBoard piece_knight_f6;
extern PieceBoard piece_knight_f7;
extern PieceBoard piece_knight_f8;
extern PieceBoard piece_knight_g1;
extern PieceBoard piece_knight_g2;
extern PieceBoard piece_knight_g3;
extern PieceBoard piece_knight_g4;
extern PieceBoard piece_knight_g5;
extern PieceBoard piece_knight_g6;
extern PieceBoard piece_knight_g7;
extern PieceBoard piece_knight_g8;
extern PieceBoard piece_bishop_a1;
extern PieceBoard piece_bishop_a2;
extern PieceBoard piece_bishop_a3;
extern PieceBoard piece_bishop_a4;
extern PieceBoard piece_bishop_a5;
extern PieceBoard piece_bishop_a6;
extern PieceBoard piece_bishop_a7;
extern PieceBoard piece_bishop_a8;
extern PieceBoard piece_bishop_b1;
extern PieceBoard piece_bishop_b2;
extern PieceBoard piece_bishop_b3;
extern PieceBoard piece_bishop_b4;
extern PieceBoard piece_bishop_b5;
extern PieceBoard piece_bishop_b6;
extern PieceBoard piece_bishop_b7;
extern PieceBoard piece_bishop_b8;
extern PieceBoard piece_bishop_c1;
extern PieceBoard piece_bishop_c2;
extern PieceBoard piece_bishop_c3;
extern PieceBoard piece_bishop_c4;
extern PieceBoard piece_bishop_c5;
extern PieceBoard piece_bishop_c6;
extern PieceBoard piece_bishop_c7;
extern PieceBoard piece_bishop_c8;
extern PieceBoard piece_bishop_d1;
extern PieceBoard piece_bishop_d2;
extern PieceBoard piece_bishop_d3;
extern PieceBoard piece_bishop_d4;
extern PieceBoard piece_bishop_d5;
extern PieceBoard piece_bishop_d6;
extern PieceBoard piece_bishop_d7;
extern PieceBoard piece_bishop_d8;
extern PieceBoard piece_bishop_e1;
extern PieceBoard piece_bishop_e2;
extern PieceBoard piece_bishop_e3;
extern PieceBoard piece_bishop_e4;
extern PieceBoard piece_bishop_e5;
extern PieceBoard piece_bishop_e6;
extern PieceBoard piece_bishop_e7;
extern PieceBoard piece_bishop_e8;
extern PieceBoard piece_bishop_f1;
extern PieceBoard piece_bishop_f2;
extern PieceBoard piece_bishop_f3;
extern PieceBoard piece_bishop_f4;
extern PieceBoard piece_bishop_f5;
extern PieceBoard piece_bishop_f6;
extern PieceBoard piece_bishop_f7;
extern PieceBoard piece_bishop_f8;
extern PieceBoard piece_bishop_g1;
extern PieceBoard piece_bishop_g2;
extern PieceBoard piece_bishop_g3;
extern PieceBoard piece_bishop_g4;
extern PieceBoard piece_bishop_g5;
extern PieceBoard piece_bishop_g6;
extern PieceBoard piece_bishop_g7;
extern PieceBoard piece_bishop_g8;
extern PieceBoard piece_rook_a1;
extern PieceBoard piece_rook_a2;
extern PieceBoard piece_rook_a3;
extern PieceBoard piece_rook_a4;
extern PieceBoard piece_rook_a5;
extern PieceBoard piece_rook_a6;
extern PieceBoard piece_rook_a7;
extern PieceBoard piece_rook_a8;
extern PieceBoard piece_rook_b1;
extern PieceBoard piece_rook_b2;
extern PieceBoard piece_rook_b3;
extern PieceBoard piece_rook_b4;
extern PieceBoard piece_rook_b5;
extern PieceBoard piece_rook_b6;
extern PieceBoard piece_rook_b7;
extern PieceBoard piece_rook_b8;
extern PieceBoard piece_rook_c1;
extern PieceBoard piece_rook_c2;
extern PieceBoard piece_rook_c3;
extern PieceBoard piece_rook_c4;
extern PieceBoard piece_rook_c5;
extern PieceBoard piece_rook_c6;
extern PieceBoard piece_rook_c7;
extern PieceBoard piece_rook_c8;
extern PieceBoard piece_rook_d1;
extern PieceBoard piece_rook_d2;
extern PieceBoard piece_rook_d3;
extern PieceBoard piece_rook_d4;
extern PieceBoard piece_rook_d5;
extern PieceBoard piece_rook_d6;
extern PieceBoard piece_rook_d7;
extern PieceBoard piece_rook_d8;
extern PieceBoard piece_rook_e1;
extern PieceBoard piece_rook_e2;
extern PieceBoard piece_rook_e3;
extern PieceBoard piece_rook_e4;
extern PieceBoard piece_rook_e5;
extern PieceBoard piece_rook_e6;
extern PieceBoard piece_rook_e7;
extern PieceBoard piece_rook_e8;
extern PieceBoard piece_rook_f1;
extern PieceBoard piece_rook_f2;
extern PieceBoard piece_rook_f3;
extern PieceBoard piece_rook_f4;
extern PieceBoard piece_rook_f5;
extern PieceBoard piece_rook_f6;
extern PieceBoard piece_rook_f7;
extern PieceBoard piece_rook_f8;
extern PieceBoard piece_rook_g1;
extern PieceBoard piece_rook_g2;
extern PieceBoard piece_rook_g3;
extern PieceBoard piece_rook_g4;
extern PieceBoard piece_rook_g5;
extern PieceBoard piece_rook_g6;
extern PieceBoard piece_rook_g7;
extern PieceBoard piece_rook_g8;
extern PieceBoard piece_queen_a1;
extern PieceBoard piece_queen_a2;
extern PieceBoard piece_queen_a3;
extern PieceBoard piece_queen_a4;
extern PieceBoard piece_queen_a5;
extern PieceBoard piece_queen_a6;
extern PieceBoard piece_queen_a7;
extern PieceBoard piece_queen_a8;
extern PieceBoard piece_queen_b1;
extern PieceBoard piece_queen_b2;
extern PieceBoard piece_queen_b3;
extern PieceBoard piece_queen_b4;
extern PieceBoard piece_queen_b5;
extern PieceBoard piece_queen_b6;
extern PieceBoard piece_queen_b7;
extern PieceBoard piece_queen_b8;
extern PieceBoard piece_queen_c1;
extern PieceBoard piece_queen_c2;
extern PieceBoard piece_queen_c3;
extern PieceBoard piece_queen_c4;
extern PieceBoard piece_queen_c5;
extern PieceBoard piece_queen_c6;
extern PieceBoard piece_queen_c7;
extern PieceBoard piece_queen_c8;
extern PieceBoard piece_queen_d1;
extern PieceBoard piece_queen_d2;
extern PieceBoard piece_queen_d3;
extern PieceBoard piece_queen_d4;
extern PieceBoard piece_queen_d5;
extern PieceBoard piece_queen_d6;
extern PieceBoard piece_queen_d7;
extern PieceBoard piece_queen_d8;
extern PieceBoard piece_queen_e1;
extern PieceBoard piece_queen_e2;
extern PieceBoard piece_queen_e3;
extern PieceBoard piece_queen_e4;
extern PieceBoard piece_queen_e5;
extern PieceBoard piece_queen_e6;
extern PieceBoard piece_queen_e7;
extern PieceBoard piece_queen_e8;
extern PieceBoard piece_queen_f1;
extern PieceBoard piece_queen_f2;
extern PieceBoard piece_queen_f3;
extern PieceBoard piece_queen_f4;
extern PieceBoard piece_queen_f5;
extern PieceBoard piece_queen_f6;
extern PieceBoard piece_queen_f7;
extern PieceBoard piece_queen_f8;
extern PieceBoard piece_queen_g1;
extern PieceBoard piece_queen_g2;
extern PieceBoard piece_queen_g3;
extern PieceBoard piece_queen_g4;
extern PieceBoard piece_queen_g5;
extern PieceBoard piece_queen_g6;
extern PieceBoard piece_queen_g7;
extern PieceBoard piece_queen_g8;
extern PieceBoard piece_king_a1;
extern PieceBoard piece_king_a2;
extern PieceBoard piece_king_a3;
extern PieceBoard piece_king_a4;
extern PieceBoard piece_king_a5;
extern PieceBoard piece_king_a6;
extern PieceBoard piece_king_a7;
extern PieceBoard piece_king_a8;
extern PieceBoard piece_king_b1;
extern PieceBoard piece_king_b2;
extern PieceBoard piece_king_b3;
extern PieceBoard piece_king_b4;
extern PieceBoard piece_king_b5;
extern PieceBoard piece_king_b6;
extern PieceBoard piece_king_b7;
extern PieceBoard piece_king_b8;
extern PieceBoard piece_king_c1;
extern PieceBoard piece_king_c2;
extern PieceBoard piece_king_c3;
extern PieceBoard piece_king_c4;
extern PieceBoard piece_king_c5;
extern PieceBoard piece_king_c6;
extern PieceBoard piece_king_c7;
extern PieceBoard piece_king_c8;
extern PieceBoard piece_king_d1;
extern PieceBoard piece_king_d2;
extern PieceBoard piece_king_d3;
extern PieceBoard piece_king_d4;
extern PieceBoard piece_king_d5;
extern PieceBoard piece_king_d6;
extern PieceBoard piece_king_d7;
extern PieceBoard piece_king_d8;
extern PieceBoard piece_king_e1;
extern PieceBoard piece_king_e2;
extern PieceBoard piece_king_e3;
extern PieceBoard piece_king_e4;
extern PieceBoard piece_king_e5;
extern PieceBoard piece_king_e6;
extern PieceBoard piece_king_e7;
extern PieceBoard piece_king_e8;
extern PieceBoard piece_king_f1;
extern PieceBoard piece_king_f2;
extern PieceBoard piece_king_f3;
extern PieceBoard piece_king_f4;
extern PieceBoard piece_king_f5;
extern PieceBoard piece_king_f6;
extern PieceBoard piece_king_f7;
extern PieceBoard piece_king_f8;
extern PieceBoard piece_king_g1;
extern PieceBoard piece_king_g2;
extern PieceBoard piece_king_g3;
extern PieceBoard piece_king_g4;
extern PieceBoard piece_king_g5;
extern PieceBoard piece_king_g6;
extern PieceBoard piece_king_g7;
extern PieceBoard piece_king_g8;