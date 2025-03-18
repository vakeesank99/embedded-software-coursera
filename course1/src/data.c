#include "include/common/data.h"

/**
 * Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
 * All operations need to be performed using pointer arithmetic, not array indexing
 * The number you wish to convert is passed in as a signed 32-bit integer.
 * You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).
 * Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 * The signed 32-bit number will have a maximum string size (Hint: Think base 2).
 * You must place a null terminator at the end of the converted c-string
 * Function should return the length of the converted data (including a negative sign). 
 * Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
 * This function needs to handle signed data. 
 * You may not use any string functions or libraries
*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    uint8_t i=0,len=0;
    int32_t temp;
    

    if (data<0){
        *ptr=(uint8_t)(45);
        data = -1*data;
        i++;
        len++;
    }
    
    temp =data;
    while(temp!=0){
        temp = temp/base;
        len++;
    }
   
    i=1;
   
    while(data!=0) {
        // printf(" %c ",*(ptr+0));
        temp=data%base;
        if (temp<10){
        *(ptr+len-i) = (uint8_t)(temp + 48);
        } else {
            *(ptr+len-i) = (uint8_t)(temp + 55);
        }
        data = data/base;
        i++;
    }
    
    return len;
}

