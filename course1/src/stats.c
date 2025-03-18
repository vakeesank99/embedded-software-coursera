/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Do some statistical functions here.
 *
 *	Functions are needed to be done in this project file
 * 		Maximum
 *		Minimum
 *		Mean
 *		Average
 *		Meadin
 * 		other than this final print values in asorted order
 *
 * @author Vakeesan Karunanithy
 * @date May 2023
 *
 */



 #include <stdio.h>
 #include "stats.h"
 #include "platform.h"
 /* Size of the Data Set */
 #define SIZE (40)
 
 
//  void main() {
 
//    unsigned char test[SIZE] = { 33, 201, 190, 154,   8, 194,   2,   6,
//                                114, 88,   45,  76, 123,  87,  25,  23,
//                                200, 122, 150, 90,   92,  87, 177, 244,
//                                201,   6,  12,  60,   8,   2,   5,  67,
//                                  7,  87, 250, 230,  99,   3, 100,  90};
 
//    /* Other Variable Declarations Go Here */
//    /* Statistics and Printing Functions Go Here */
//    print_array(test,SIZE);	
//    print_statistics(test,SIZE);
//   return 0;
//  }
 
 //--print the given array 
 void print_array(unsigned char *ptr, unsigned int n){
  #ifdef VERBOSE
    PRINTF("Array is [");
    for(unsigned int i=0; i<n-1;i++) PRINTF("%d, ",*(ptr+i));
    PRINTF("%d]\n",*(ptr+n-1));
  #endif /*VERBOSE*/

 }
 //--sort the array using bubble sort
 void sort_array(unsigned char *ptr, unsigned int n){
 
   for(unsigned int i=0; i<n-1; i++){
     for(unsigned int j=0; j < n-i-1;j++)
       if(*(ptr+j)>*(ptr+j+1)){
         unsigned int temp= *(ptr+j);
         *(ptr+j)=*(ptr+j+1);
         *(ptr+j+1)=temp;
       }
   }
 }
 //--find the average in a set
 float find_mean(unsigned char *ptr, unsigned int n){
   unsigned int tot=0;
   for(unsigned int i=0;i<n;i++) tot+=*(ptr+i);
   return (float)tot/n;
 }
 //--find the middle value in a sorted set
 unsigned char find_median(unsigned char *ptr, unsigned int n){
   if(n%2==0)return *(ptr+n/2)+*(ptr+n/2+1);
   else return *(ptr+n/2);
 }
 //--find the maximum in a sorted set
 unsigned char find_maximum(unsigned char *ptr, unsigned int n){
   return *(ptr+n-1);
 }
 //--find the minimum in asorted set
 unsigned char find_minimum(unsigned char *ptr, unsigned int n){
 
   return *(ptr);
 }
 //--print the max,min,mean,median 
 void print_statistics(unsigned char *ptr, unsigned int n){
   sort_array(ptr,SIZE);
   printf("maximum is %d \n",find_maximum(ptr,SIZE));
   printf("minimum is %d \n",find_minimum(ptr,SIZE));
   printf("median is %d \n",find_median(ptr,SIZE));
   printf("mean is %.2f \n",find_mean(ptr,SIZE));
 }
 
 