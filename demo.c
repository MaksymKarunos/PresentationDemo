/******************************************************************************

    @Author Maksym Karunos
    @Credits: Prof. Jun Yuan, CS232
    
*******************************************************************************/

#include <stdio.h>
// Declaration of the function 
void flip_bits(unsigned * x,
             unsigned start,
             unsigned end);

int main()
{
    unsigned x = 1231232;
    unsigned y = 1231232;
    flip_bits(&x,0,4);
    printf("%s"," Does x equal y? 0 - False, 1 - True: ");
    printf("%d", x==y);
    return 0;
}

void flip_bits(unsigned * x,
             unsigned start,
             unsigned end) {
   for ( int i = 0; i <= end - start; i++ ){
       if (( *x & ( 1 << (i + start))) == 0){
           *x = *x | ( 1 << (i + start));
       }
       else{
           *x = *x & ~( 1 << (i + start));
       }
   }
}

