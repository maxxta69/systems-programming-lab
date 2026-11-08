#include <stdio.h>
#include "intvec.h"

int main(void)
{
    intVec v;
    intvec_init(&v);
    if(v.data != NULL)
    {
        printf("FAIL: data should be NULL.\n");
        return 1;
    }
    if(v.len != 0)
    {
        printf("FAIL: len should be 0, but it is %zu\n", v.len);
        return 1;
    }
    if(v.cap != 0)
    {
        printf("FAIL: cap should be 0, but it is %zu\n", v.cap);
        return 1;
    }
    intvec_push(&v, 10);
    intvec_push(&v, 20);
    intvec_push(&v, 30);

    int *m = intvec_get(&v, 3);

    if(m == NULL)
    {
        printf("m is NULL\n");
    }
    else 
    {
        printf("the value of m is %d\n", *m);
    }

    
    int *a = intvec_get(&v, 1);
    printf("a = %d", *a);
    return 0;
}