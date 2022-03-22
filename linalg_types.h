#ifndef _LINALG_TYPES_H_
#define _LINALG_TYPES_H_

#define empty_vect \
    { .size = 0, .data = NULL }
#define empty_matrix \
    { .nb_li = 0, .nb_col = 0, .data = NULL }

typedef struct Vect_t Vect_t;
struct Vect_t {
    int size;
    double* data;
};

typedef struct Matrix_t Matrix_t;
struct Matrix_t {
    int nb_li;
    int nb_col;
    double* data;
};

#endif