#include <stdio.h>
#include <stdlib.h>

#include "linalg_types.h"

void Initialize_matrix(Matrix_t *m, int nb_li, int nb_col) {
    if (NULL != m->data) {
        free(m->data);
    }

    m->nb_col = nb_col;
    m->nb_li = nb_li;
    m->data = malloc(sizeof(double) * (m->nb_li) * (m->nb_col));
    if (NULL == m->data) {
        printf("error with malloc for matrix\n");
        exit(EXIT_FAILURE);
    }
}

int Get_nb_columns(Matrix_t *m) {
    return m->nb_col;
}
int Get_nb_lines(Matrix_t *m) {
    return m->nb_li;
}

void Finalize_matrix(Matrix_t *m) {
    free(m->data);
    m->data = NULL;
    m->nb_col = 0;
    m->nb_li = 0;
}

double Get_elem_matrix(Matrix_t *m, int i, int j) {
    return m->data[i * (m->nb_col) + j];
}

void Set_elem_matrix(Matrix_t *m, int i, int j, double val) {
    m->data[i * (m->nb_col) + j] = val;
}

void Read_from_stream_matrix(FILE *pF, Matrix_t *m) {
    int nb_li = 0;
    int nb_col = 0;
    if (2 != fscanf(pF, "# %d\n# %d\n", &nb_li, &nb_col)) {
        printf("error with fscanf!!\n");
        exit(EXIT_FAILURE);
    }

    // if (1 != fscanf(pF, "# %d\n", &nb_col)) {
    //     printf("error with fscanf!!\n");
    //     exit(EXIT_FAILURE);
    // }
    printf("## %d %d\n", nb_col, nb_li);

    Initialize_matrix(m, nb_li, nb_col);

    for (int i = 0; i < nb_li; ++i) {
        for (int j = 0; j < nb_col; ++j) {
            double val = 0.0;
            if (1 != fscanf(pF, "%lf\n", &val)) {
                printf("error with fscanf!!\n");
                exit(EXIT_FAILURE);
            }
            Set_elem_matrix(m, i, j, val);
        }
    }
}

void Write_to_stream_matrix(FILE *pF, Matrix_t *m) {
    fprintf(pF, "# %d\n", Get_nb_lines(m));
    fprintf(pF, "# %d\n", Get_nb_columns(m));
    for (int i = 0; i < Get_nb_lines(m); ++i) {
        for (int j = 0; j < Get_nb_columns(m); ++j) {
            fprintf(pF, "%g\n", Get_elem_matrix(m, i, j));
        }
    }
}
