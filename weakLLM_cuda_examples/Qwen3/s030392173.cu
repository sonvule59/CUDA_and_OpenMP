#include <stdio.h>

__global__ void __kernel__(int *a, int *b, int *c)
{
    int idx = threadIdx.x;
    int i = idx;
    int j = idx;
    int k = i * j;
    a[idx] = k;
    b[idx] = k;
    c[idx] = k;
}

int main()
{
    int *a = new int[10];
    int *b = new int[10];
    int *c = new int[10];
    for(int i=0; i<10; i++)
    {
        a[i] = i;
        b[i] = i;
        c[i] = i;
    }
    __kernel<<<0, 1>>>(a, b, c);
    printf("Result:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d %d %d\n", a[i], b[i], c[i]);
    }
    return 0;
}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}