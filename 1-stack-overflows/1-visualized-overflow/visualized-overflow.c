#include <stdio.h>

/* Compile with:
 * gcc -fno-stack-protector -o visualized-overflow visualized-overflow.c
*/

void main() {
    int overflowed_int = 0;
    char buffer[15] = {};
    int i;
    
    printf("     buffer    | overflowed_int\n");
    for (i = 0; i < 19; i++)
    {
        buffer[i] = 'A';
        printf("%-15.15s|%-4.4s = %i\n",buffer, (char*)&overflowed_int, overflowed_int);
    }
    return;
}
