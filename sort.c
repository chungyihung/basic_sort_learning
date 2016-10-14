#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include"sort.h"

#if 0
#define dbg_printf( data, length)    printf_list( data, length )
#else
#define dbg_printf( data, length)
#endif

void printf_list
    (
    int *data,
    int length
    )
{
    int i;
    for( i = 0; i < length; i++ )
        {
        printf("%d ", *( data + i ) );
        }
    printf("\n");
}

void swap
    (
    int *data_a,
    int *data_b
    )
{
    int tmp;

    tmp = *data_a;
    *data_a = *data_b;
    *data_b = tmp;
}

void bubble_sort
    (
    int data[],             /* The target array to be sorted    */
    int length              /* The length of the array          */
    )
{
    int i;                  /* The outer loop index             */
    int j;                  /* The inner loop index             */
    int travel_val;         /* The value of traveled element    */

    printf( "Sorting using bubble sort method\n" );

    for( i = 0; i < length - 1; i++ )
        {
        for( j = i + 1; j < length; j++ )
            {
            if( data[j - 1] > data[j] )
                {
                travel_val = data[j];
                data[j] = data[j - 1];
                data[j - 1] = travel_val;
                }
            }
        }
}

void insert_sort
    (
    int data[],             /* The target array to be sorted    */
    int length              /* The length of the array          */
    )
{
    int i;                  /* The outer loop index             */
    int j;                  /* The inner loop index             */
    int val_element;        /* The value of processed element   */

    printf( "Sorting using insertion sort method\n" );
    /*============================================
     The prupose of outer loop is to travel
     all the elements in array
     ===========================================*/
    for( i = 1; i < length; i++)
        {
        val_element = data[i];
        /*============================================
         Compare the value of the processed element to
         the elements preceding to the processed element.
         If current traveled element is greater than the
         processed element, move the traveled element to
         the next index.
         If smaller, stop the inner loop and put the processed
         element to the next index of the traveled element.
         ===========================================*/
        for( j = i; j > 0 && val_element < data[j - 1]; j-- )
            {
            data[j] = data[j - 1];
            }
        data[j] = val_element;
        }

}

void select_sort            /* This is common in-place version  */
    (
    int data[],             /* The target array to be sorted    */
    int length              /* The length of the array          */
    )
{
    printf( "Sorting using selection sort method\n" );
    int i;                  /* The outer loop index             */
    int j;                  /* The inner loop index             */
    int min;                /* Value of the selected min element*/
    int idx_min;            /* Index of min element             */

    /*============================================
     Travel all the elements in array
     ===========================================*/
    for( i = 0; i < length; i++ )
        {
        min = INT_MAX;
        for( j = i; j < length; j++ )
            {
            if( min > data[j] )
                {
                min = data[j];
                idx_min = j;
                }
            }
        swap( data + i, data + idx_min );
        }
}


/*****************************************************************
 * Simple concept
 *                     13247956
 * Split           1324        7956
 *   Stage       13    24    79    56
 *              1  3  2  4  7  9  5  6
 *    -------------------------------------------------------
 *             1  3  2  4  7  9  5  6
 * Merge        13    24    79    56
 *   Stage        1234        5679
 *                    12345678
 ****************************************************************/
void merge                  /* Merge left and right sub array   */
    (
    int *left,
    int  left_len,
    int *right,
    int  right_len
    )
{
    /* Note that here left and right pointers point to elements of the same data array
     * We don't need to worry about how to process the origin data memory */
    int *merge_idx = left;

    int * left_subarr   = malloc( left_len * sizeof(int) );
    int * right_subarr  = malloc( right_len * sizeof(int) );

    memcpy( left_subarr, left, left_len * sizeof(int) );
    memcpy( right_subarr, right, right_len * sizeof(int) );

    int * trvl_left     = left_subarr;     /* Pointer to travel the left sub array     */
    int * trvl_right    = right_subarr;    /* Pointer to travel the right sub array    */

    /* We can't ensure which the length of left/right sub array is larger each time,
     * so just travel them as two tubes until one of array is finished traveling */
    while( left_len > 0 && right_len > 0)
        {
        if( *trvl_left < *trvl_right )
            {
            *merge_idx = *trvl_left;
            trvl_left++;
            left_len--;
            }
        else
            {
            *merge_idx = *trvl_right;
            trvl_right++;
            right_len--;
            }
        merge_idx++;     // next position
        }

    if( left_len > 0)
        {
        while( left_len > 0 )
            {
            *merge_idx = *trvl_left;
            trvl_left++;
            left_len--;
            merge_idx++;
            }
        }
    else
        {
        while( right_len > 0 )
            {
            *merge_idx = *trvl_right;
            trvl_right++;
            right_len--;
            merge_idx++;
            }
        }
}

void merge_sort             /* Merge sort                       */
    (
    int data[],             /* The target array to be sorted    */
    int length              /* The length of the array          */
    )
{

    dbg_printf( data, length);
    /* Step 3: The special case for ending */
    if( length == 1 )
        {
        return;
        }

    /* Step 2: Do the same split process recursively */
    /* Need not allocate lots of sub array, just use pointer as index */
    int *left, *right;

    int left_length = length / 2;
    int right_length = length - left_length;

    left    = data;
    right   = data + left_length;

    /* Do the same merge_sort to left and right sub array */
    merge_sort( left, left_length );
    merge_sort( right, right_length );

    /* Step 1: think the last movement -> merge left and right
     * and doing sorting process while merging */
    merge( left, left_length, right, right_length );
}

/* More reference: http://spaces.isu.edu.tw/upload/18833/3/web/sorting.htm */
