#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct{
    int *data;
    size_t len;
    size_t cap;
} intVec;

bool intvec_init(intVec *v);
bool intvec_push(intVec *v, int value);
int *intvec_get(intVec *v, size_t i);
void intvec_free(intVec *v);
int lnt(intVec *v);