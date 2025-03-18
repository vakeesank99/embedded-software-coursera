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
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void print_array(unsigned char *ptr, unsigned int n);
void sort_array(unsigned char *ptr, unsigned int n);
float find_mean(unsigned char *ptr, unsigned int n);
unsigned char find_median(unsigned char *ptr, unsigned int n);
unsigned char find_maximum(unsigned char *ptr, unsigned int n);
unsigned char find_minimum(unsigned char *ptr, unsigned int n);
void prit_statistics(unsigned char *ptr, unsigned int n);


/**
 * Function: print_array
 * Description:
 * 		This function takes pointer for an array and the size of the array then  *		print the elements in the array
 * Prameters:
 * 		unsigned char *ptr: pointer to the array
 * 		unsigned int n: size of the array that we are referencing
 * Return:
 * 		Nothing
 */
void print_array(unsigned char *ptr, unsigned int n);
/**
 * Function: sort_array
 * Description:
 * 		This function takes pointer for an array and the size of the array then  *		sort the elements in the array
 * Prameters:
 * 		unsigned char *ptr: pointer to the array
 * 		unsigned int n: size of the array that we are referencing
 * Return:
 * 		Nothing
 */
void sort_array(unsigned char *ptr, unsigned int n);

/**
 * Function: find_mean
 * Description:
 * 		This function takes pointer for an array and the size of the array then  *		return the mean of the array
 * Prameters:
 * 		unsigned char *ptr: pointer to the array
 * 		unsigned int n: size of the array that we are referencing
 * Return:
 * 		the average value of te elements of the array
 */

float find_mean(unsigned char *ptr, unsigned int n);
/**
 * Function: find_median
 * Description:
 * 		This function takes pointer for an array and the size of the array then  *		return median of the array
 * Prameters:
 * 		unsigned char *ptr: pointer to the array
 * 		unsigned int n: size of the array that we are referencing
 * Return:
 * 		Median of the array
 */
unsigned char find_median(unsigned char *ptr, unsigned int n);
/**
 * Function: find_maximum
 * Description:
 * 		This function takes pointer for an array and the size of the array then  *		return maximum in the array
 * Prameters:
 * 		unsigned char *ptr: pointer to the array
 * 		unsigned int n: size of the array that we are referencing
 * Return:
 * 		the maximum element in the array
 */
unsigned char find_maximum(unsigned char *ptr, unsigned int n);

/**
 * Function: find_minimum
 * Description:
 * 		This function takes pointer for an array and the size of the array then  *		return minimum in the array
 * Prameters:
 * 		unsigned char *ptr: pointer to the array
 * 		unsigned int n: size of the array that we are referencing
 * Return:
 * 		the Minimum element in a array
 */
unsigned char find_minimum(unsigned char *ptr, unsigned int n);

/**
 * Function: print_statistics
 * Description:
 * 		This function takes pointer for an array and the size of the array then  *		call the sort_array  minimum maximum mean median functions
 * Prameters:
 * 		unsigned char *ptr: pointer to the array
 * 		unsigned int n: size of the array that we are referencing
 * Return:
 * 		Nothing
 */
void print_statistics(unsigned char *ptr, unsigned int n);

#endif /* __STATS_H__ */