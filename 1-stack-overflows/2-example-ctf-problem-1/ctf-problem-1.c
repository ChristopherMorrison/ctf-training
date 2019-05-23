#include <stdio.h>

/* Compile with:
 * gcc -fno-stack-protector -o visualized-overflow visualized-overflow.c
*/

void main(int argc, char** argv) {
    int overflowed_int = 0;
    char buffer[15] = {};
    int i;
    
    strcpy(buffer, argv[1]);

    printf("     buffer    | overflowed_int\n");
    printf("%-15.15s|%-4.4s = %i\n",buffer, (char*)&overflowed_int, overflowed_int);
    
    if (overflowed_int == 0xf00dbabe){
        printf("Success!\n");
    } else{
        printf("Try Again\n");
    }


    return;
}
