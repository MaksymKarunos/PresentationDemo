#include <stdio.h>
#include <stdlib.h>

// Flip the bits of x within range [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
void flip_bits(unsigned * x,
              unsigned start,
              unsigned end) {
    for ( int i = 0; i <= end - start; i++ ){
        if ( ( *x & ( 1 << (i + start))) == 0){
            *x = *x | ( 1 << (i + start));
        }
        else{
            *x = *x & ~( 1 << (i + start));
        }
    }
}




void test_flip_bits(unsigned x,
                   unsigned s,
		   unsigned e,
                   unsigned expected) {
    unsigned o = x;
    flip_bits(&x, s, e);
    if(x!=expected) {
        printf("flip_bits(0x%08x,%u,%u): 0x%08x, expected 0x%08x\n",o,s,e,x,expected);
    } else {
        printf("flip_bits(0x%08x,%u,%u): 0x%08x, correct\n",o,s,e,x);
    }
}

int main(int argc,
         const char * argv[]) {
    printf("\nTesting flip_bits()\n\n");
    test_flip_bits(0b1001110,0,0,0b1001111);
    test_flip_bits(0b1001110,1,1,0b1001100);
    test_flip_bits(0b1001110,2,2,0b1001010);
    test_flip_bits(0b1001110,5,5,0b1101110);
    test_flip_bits(0b1001110,9,9,0b1001001110);

    test_flip_bits(0b1010,0,3,0b0101);
    test_flip_bits(0b0101,0,3,0b1010);
    test_flip_bits(0b0,0,0,0b1);
    test_flip_bits(0b0,4,4,0b10000);
    test_flip_bits(0b0,0,5,0b111111);
    test_flip_bits(0b1111,0,4,0b10000);

    printf("\n");
    return 0;
}
