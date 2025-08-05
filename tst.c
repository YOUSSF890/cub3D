#include <math.h>
#include <stdio.h>

int main()
{
    float x = 3.5;
    float y = 6.5;
    float new_x;
    float new_y;

    new_x = floorf(x+1);
    new_y = floorf(y);

    printf("new_xx = %f\n", new_x);
    printf("new_yy = %f\n", new_y);
}