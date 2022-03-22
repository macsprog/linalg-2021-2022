#include <stdlib.h>
#include <stdio.h>

#include "linalg.h"
#include "linalg_types.h"

int main(void) {
    Vect_t vect;
    Matrix_t matrix;
    int size = 10;

    Initialize_vect(&vect, size);
    int res = Get_size_vect(&vect);
    double val = 12.0;
    int i = 2;
    Set_elem_vect(&vect, i, val);
    double resval = Get_elem_vect(&vect, i);

    for (int i = 0; i < Get_size_vect(&vect); i++) {
        Set_elem_vect(&vect, i, i * 3.1);
    }

    for (int i = 0; i < Get_size_vect(&vect); i++) {
        double d = Get_elem_vect(&vect, i);
        printf("vect[%d] = %g \n", d);
    }

    /* appel à une fonction
    définie dans vect.c ou matrix.c
    à laquelle on accède via linalg.a
    */

    Finalize_vect(&vect);

    return EXIT_SUCCESS;
}