#include "linalg_types.h"

void Initialize_matrix(Matrix_t *m, int nb_li, int nb_col) {}
void Finalize_matrix(Matrix_t *m) {}

int Get_nb_columns(Matrix_t *m) {
    return 1;  // DUMB
}

int Get_nb_lines(Matrix_t *m) {
    return 1;  // DUMB
}

double Get_elem_matrix(Matrix_t *m, int i, int j) {
    return 1.0;  // DUMB
}

void Set_elem_matrix(Matrix_t *m, int i, int j, double val) {}

// Read_from_stream_matrix(){}
// Write_to_stream_matrix(){}