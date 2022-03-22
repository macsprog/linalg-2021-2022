#include <stdio.h>
#include <stdlib.h>

#include "linalg_types.h"

void Initialize_vect(Vect_t* v, int size) {
    if (NULL != v->data) {
        free(v->data);
        v->data = NULL;
    }
    v->size = size;
    v->data = malloc(sizeof(double) * size);
    if (NULL == v->data) {
        printf("error in initialize_vect\n");
        exit(-1);
    }
}

void Finalize_vect(Vect_t* v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
}

int Get_size_vect(Vect_t* v) {
    return v->size;
}

// Set_size_vect();

//#define DEBUG 0

double Get_elem_vect(Vect_t* v, int i) {
    // #if DEBUG
    //     if(i>= v->size || i<0){
    //         printf("error with id %d\n",i);
    //     }
    // #endif
    return v->data[i];
}

void Set_elem_vect(Vect_t* v, int i, double val) {
    v->data[i] = val;
}

#define LINESIZE 1024
void Read_from_stream_vect(FILE* pF, Vect_t* v) {
    int size = 0;
    char buffer[LINESIZE] = "";
    if (NULL == fgets(buffer, LINESIZE, pF)) {
        printf("cannot use fgets!\n");
        exit(EXIT_FAILURE);
    }
    if (1 != sscanf(buffer, "# %d", &size)) {
        printf("wrong sscanf\n");
        exit(EXIT_FAILURE);
    }

    Initialize_vect(v, size);
    for (int i = 0; i < size; ++i) {
        double val = 0.0;
        if (NULL == fgets(buffer, LINESIZE, pF)) {
            printf("cannot use fgets!\n");
            exit(EXIT_FAILURE);
        }
        val = atof(buffer);
        Set_elem_vect(v, i, val);
    }
}

void Write_to_stream_vect(FILE* pF, Vect_t* v) {
    fprintf(pF, "# %d\n", Get_size_vect(v));
    for (int i = 0; i < Get_size_vect(v); ++i) {
        fprintf(pF, "%g\n", Get_elem_vect(v, i));
    }
}

void Copy_vect(Vect_t* src, Vect_t* dest) {
    // DUMB
}
