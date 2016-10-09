#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

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

/* More reference: http://spaces.isu.edu.tw/upload/18833/3/web/sorting.htm */
