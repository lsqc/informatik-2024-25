#include <stdio.h>

int main()
{

    const int a = 5;   // 00000000 00000000 00000000 00000101
    const int b = 3;   // 00000000 00000000 00000000 00000011

    int bitwise_and = a & b;
    int bitwise_or = a | b;

    int bitwise_xor = a ^ b;

    int bitwise_not = ~a;

    int bitwise_left_shift = a << 1; // multiplies by 2
    int bitwise_right_shift = a >> 1; //divides by 2 

    signed int c = -4;
    unsigned int u = (unsigned int)c;
    unsigned int bitwise_unsigned_right_shift = u >> 1;

    return 0;
}
