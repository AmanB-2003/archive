#include <stdio.h>
#include <stdlib.h>

#define virtual_address_size 64      //64 bits
#define page_size 4                  // 4 KB


int main(char c, char *argv[]){
        unsigned long long address;    //unsigned stores in binary form
        unsigned long offset;
        unsigned long long page_no;

        address = atoll(argv[1]);      //string to long long int

    /*    +-----------------------------+
         |  page no.      |  offset     |
         |  52 bits       |  12 bits    |
         +-----------------------------+  
               64 bit address             */

        page_no = address >> 12;              //removes 12 bits from right( 1101 >> 1 = 110)
        offset = address % 4096;              // 2096 = 2^(12) extracts last 12 bits
        // OR offset = address & 0xfff        1 & 0 = 1

        printf("The address %llu contains :\n", address);
        printf("page number = %llu \n", page_no);
        printf("offset = %lu \n", offset);

    return 0;  
}
