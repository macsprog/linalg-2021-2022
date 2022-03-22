#include <stdio.h>
#include <stdlib.h>

#include "linalg.h"
#include "linalg_types.h"

int main(void) {
    Vect_t vect = empty_vect;
    Matrix_t matrix = empty_matrix;
    int size = 10;
    int nb_col = 4;
    int nb_li = 3;

    Initialize_vect(&vect, size);
    int res = Get_size_vect(&vect);
    double val = 12.0;
    int i = 2;
    Set_elem_vect(&vect, i, val);
    double resval = Get_elem_vect(&vect, i);
    printf("resval = %g\n",resval);
    printf("res = %d\n",res);

    for (int i = 0; i < Get_size_vect(&vect); i++) {
        Set_elem_vect(&vect, i, i * 3.1);
    }

    for (int i = 0; i < Get_size_vect(&vect); i++) {
        double d = Get_elem_vect(&vect, i);
        printf("vect[%d] = %g \n", i, d);
    }

    /* appel à une fonction
    définie dans vect.c ou matrix.c
    à laquelle on accède via linalg.a
    */

    Initialize_matrix(&matrix, nb_li, nb_col);
    for (int i = 0; i < Get_nb_lines(&matrix); ++i) {
        for (int j = 0; j < Get_nb_columns(&matrix); ++j) {
            double tmp = i * nb_col + j + 0.5;
            Set_elem_matrix(&matrix, i, j, tmp);
        }
    }

    for (int i = 0; i < Get_nb_lines(&matrix); ++i) {
        for (int j = 0; j < Get_nb_columns(&matrix); ++j) {
            double tmp = Get_elem_matrix(&matrix, i, j);
            printf("M[%d][%d]=%g\n", i, j, tmp);
        }
    }

    Finalize_matrix(&matrix);

    Finalize_vect(&vect);

    return EXIT_SUCCESS;
}