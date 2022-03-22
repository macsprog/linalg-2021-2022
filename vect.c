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

// Read_from_stream_vect(){}

void Write_to_stream_vect(FILE* pF, Vect_t* v) {
    fprintf(pF, "# %d\n", Get_size_vect(v));
    for (int i = 0; i < Get_size_vect(v); ++i) {
        fprintf(pF, "%g\n", Get_elem_vect(v, i));
    }
}

void Copy_vect(Vect_t* src, Vect_t* dest) {
    // DUMB
}
