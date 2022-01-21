#include <stdio.h>
#include <time.h>
#include <stdlib.h>     /* thu vien cho ham srand, rand */

/* ham tao va tra ve so ngau nhien */
int * taosoNH( )
{
  static int  r[10];
  int i;

  
  srand( (unsigned)time( NULL ) );
  for ( i = 0; i < 10; ++i)
  {
     r[i] = rand();
     printf( "r[%d] = %d\n", i, r[i]);

  }

  return r;
}

/* ham main de goi ham duoc dinh nghia o tren */
int main ()
{
   /* mot con tro p toi mot so nguyen */
   int *p;
   int i;

   p = taosoNH();
   for ( i = 0; i < 10; i++ )
   {
       printf( "*(p + %d) : %d\n", i, *(p + i));
   }
   printf("\n===========================\n");
   printf("VietJack chuc cac ban hoc tot! \n");

   return 0;
}