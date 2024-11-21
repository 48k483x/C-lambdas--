/* lambda.c */
#include <stdio.h>
#include <stdarg.h>

#define assign(a,b) b; \
    a = &lmb ## __LINE__;

#define λ(a,_,c) \
    int lmb ## __LINE__(int a){ return c; }

int main()
{
    auto (*p)(int);

    assign(p,
       λ(x, ->, x+1)
       );

    printf("%d\n", 
            p(1));
}
