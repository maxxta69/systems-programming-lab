#include "intvec.h"

bool intvec_init(intVec *v)
{
    v->data = NULL;
    v->len = 0;
    v->cap = 0;
    return true;
}

bool intvec_push(intVec *v, int value)
{
    if(v->len== v->cap)
    {
        size_t new_cap = (v->cap == 0) ? 1 : v->cap * 2;
        int *tmp = realloc(v->data, new_cap * sizeof(int));
        
        if(tmp == NULL)
        {
            return false;
        }
        v->data = tmp;
        v->cap = new_cap;
    }
    v->data[v->len] = value;
    v->len++;
    return true;
}

int *intvec_get(intVec *v, size_t i)
{
    if(i < v->len)
    {
        return &v->data[i];
    }
    return NULL;
}

void intvec_free(intVec *v)
{
    free(v->data);
    v->data = NULL;
    v->len = 0;
    v->cap = 0;
}

int lnt(intVec *v)
{
    return v->len;
}