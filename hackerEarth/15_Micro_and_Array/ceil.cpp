#include <stdio.h>      /* printf */
#include <math.h>       /* ceil */

int main ()
{
printf ( "ceil of 2.3 is %.1f\n", ceil(2.3) );
printf ( "ceil of 3.8 is %.1f\n", ceil(3.8) );
printf ( "ceil of -2.3 is %.1f\n", ceil(-2.3) );
unsigned int x= ceil(double(5)/double(3));
printf ( "ceil of 5/3 is %.1u\n", x );

return 0;
}
