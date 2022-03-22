#ifndef _LINALG_H_HAS_BEEN_INCLUDED_
#define _LINALG_H_HAS_BEEN_INCLUDED_

#include "linalg_types.h"

/* defined in vect.c */
void Initialize_vect(Vect_t *v, int size);
void Finalize_vect(Vect_t *v);
int Get_size_vect(Vect_t *v);
double Get_elem_vect(Vect_t *v, int i);
void Set_elem_vect(Vect_t *v, int i, double val);
void Copy_vect(Vect_t *src, Vect_t *dest);
void Write_to_stream_vect(FILE *pF, Vect_t *v);

/* defined in matrix.c */
void Initialize_matrix(Matrix_t *m, int nb_li, int nb_col);
void Finalize_matrix(Matrix_t *m);
int Get_nb_columns(Matrix_t *m);
int Get_nb_lines(Matrix_t *m);
double Get_elem_matrix(Matrix_t *m, int i, int j);
void Set_elem_matrix(Matrix_t *m, int i, int j, double val);
void Write_to_stream_matrix(FILE *pF, Matrix_t *m);

#endif