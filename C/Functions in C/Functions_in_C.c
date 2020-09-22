#include <stdio.h>

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

/*
 *	Function name: 
 *	max_of_four
 *
 *	Parameters:
 *	a: an integer that represents the first number
 *	b: an integer that represents the second number
 *	c: an integer that represents the third number
 *	d: an integer that represents the fourth number
 *
 *	return:
 *	an integer that represents the maximum of the four numbers
 *
 *
 *	Function description:	 
 *	Compares the four numbers with each other and returns the 
 *	maximum number among them  
 *
 */
int max_of_four(int a, int b, int c, int d){
    int max = a;

    if(max < b)
        max = b;
    if(max < c)
        max = c;
    if(max < d)
        max = d;
    
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
