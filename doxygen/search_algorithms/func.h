#ifndef __FUNC__H__
#define __FUNC__H__

/**
 * @warning to run - 1.make, 1. make run
 * */

/**
 * @mainpage My Homework for 14.07.2020
 * */


/**
 * @file func.h - File includes the prototypes of the functions.
 * */



/**
 * @brief Does Linear search in Array.
 * @param 1st - An array.
 * @param 2nd - The lenght of the array.
 * @param 3th - The searching value.
 * @return index -  The index of a found element.
 * */
int linearSearch(int*, int, int);

/**
 * @brief Does Binary search in Array.
 * @param 1st - An array.
 * @param 2nd - A pointer to the first element of the array.
 * @param 3th - A pointer to the first element of the array.
 * @param 4th - The searching value.
 * @return index -  The index of a found element.
 * */
int binarySearch(int*, int, int, int);

/**
 * @brief The Binary search 2.0 version.
 * @param 1st - An array.
 * @param 2nd - The lenght of the array.
 * @param 3th - The searching value..
 * @return index -  The index of a found element.
 * @todo
 * */
int binarySearch2(int*, int, int);

/**
 * @brief Does Jump search in Array.
 * @param 1st - An array.
 * @param 2nd - The lenght of the array.
 * @param 3th - The searching value.
 * @return index -  The index of a found element.
 * */
int jumpSearch(int*, int, int);

/**
 * @brief Does Binary search in Array.
 * @param 1st - An array.
 * @param 2nd - A pointer to the first element of the array.
 * @param 3th - A pointer to the first element of the array.
 * @param 4th - The searching value.
 * @return index -  The index of a found element.
 * */
int ternarySearch(int*, int, int, int);

/**
 * @brief Does Interpolation search in Array.
 * @param 1st - An array.
 * @param 2nd - A pointer to the first element of the array.
 * @param 3th - A pointer to the first element of the array.
 * @param 4th - The searching value.
 * @return index -  The index of a found element.
 * */
int interpolationSearch(int*, int, int, int);

/**
 * @brief Does Exponential search in Array.
 * @param 1st - An array.
 * @param 2nd - A pointer to the first element of the array.
 * @param 3th - A pointer to the first element of the array.
 * @param 4th - The searching value.
 * @return index -  The index of a found element.
 * @todo
 * */
int exponentialSearch(int*, int, int, int);

/**
 * @brief Function for array input.
 * @param 1st - The length of an array.
 * @return Array - The array you've entered.
 * */
int* inputArray(int);

/**
 * @brief Function for array output.
 * @param 1st - The pointer of an array.
 * @param 2nd - The length of an array.
 * @return Array - The array you've given as parametr.
 * */
void printArray(int*, int);

/**
 * @brief For sorting an array.
 * @param 1st - An array.
 * @param 2nd - The lenght of the array.
 * @todo
 * */
void insertSort (int*, int);
#endif