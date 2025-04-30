#include <stdio.h>
#include <stdbool.h>

int main()
{

    const int i = 3;
    const int j = 5;

    bool equal = i == j;
    bool unequal = i != j;
    
    bool greater = i > j;
    bool lesser = i < j;
    
    bool greater_or_equal = i >= j;
    bool lesser_or_equal = i <= j;

    return 0;
}
