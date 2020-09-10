#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int tempSum = 0;
    int tempSub = 0;

    tempSum = (*a) + (*b);

    if(*a > *b)
        tempSub = (*a) - (*b);
    else
        tempSub = (*b) - (*a);    
    *a = tempSum;
    *b = tempSub;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
