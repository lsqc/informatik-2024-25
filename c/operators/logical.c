#include <stdio.h>
#include <stdbool.h>

int main()
{
    const bool b = true;
    const bool c = false;

    bool logical_and = b && c;
    bool logical_or = b || c;
    
    bool logical_not = !b;

    return 0;
}
