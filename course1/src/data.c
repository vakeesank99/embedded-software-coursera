#include "data.h"

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
 * 
 * example: 
 *     uint8_t *ptr;
    uint8_t len=my_itoa(-16,ptr,2 );
    //  printf("%i\n",len);
    uint8_t i=0;
    while(i<len){
            printf(" %c ",*(ptr+i));
            i++;
    }
 * 
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
/**
 * ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.
 * All operations need to be performed using pointer arithmetic, not array indexing
 * The character string to convert is passed in as a uint8_t * pointer (ptr).
 * The number of digits in your character set is passed in as a uint8_t integer (digits).
 * You should be able to support bases 2 to 16. The converted 32-bit signed integer should be returned.
 * This function needs to handle signed data. You may not use any string functions or libraries
 * 
 * example:
 *     uint8_t *ptr;
    uint8_t base=16;
    int32_t data=-10;
    uint8_t len=my_itoa(data,ptr,base );
    //  printf("%i\n",len);
    // uint8_t i=0;
    // while(i<len){
    //         printf(" %c ",*(ptr+i));
    //         i++;
    // }
    int32_t num=my_atoi(ptr,len,base);
    printf("%i",num);
    
 * 
*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    uint8_t i=0;
    int32_t num=0;
    uint32_t temp_base=1;
    int8_t neg=1;
    if (*ptr==(uint8_t)(45)){
        neg =-1;
        i++;
        while(i<digits){
            if (*(ptr+digits-i) >55){
                num = (*(ptr+digits-i)-55)* temp_base + num;
            } 
            else{
                num = (*(ptr+digits-i)-48)* temp_base + num;
                
            }
            
            temp_base=temp_base*base;
            i++;
        }
                
                
    }
    else{
        while(i<digits){
        if (*(ptr+digits-i) >55){
                num = (*(ptr+digits-i-1)-55)* temp_base + num;
            } 
            else{
                num = (*(ptr+digits-i-1)-48)* temp_base + num;
                
            }
            temp_base=temp_base*base;
            i++;
        }
    }
    
    
    return (int32_t)neg*num;
}



