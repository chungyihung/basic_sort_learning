#ifndef H_SORT
#define H_SORT

void insert_sort
    (
    int data[],             /* The target array to be sorted    */
    int length              /* The length of the array          */
    );

void bubble_sort
    (
    int data[],             /* The target array to be sorted    */
    int length              /* The length of the array          */
    );

void select_sort            /* This is common in-place version  */
    (
    int data[],             /* The target array to be sorted    */
    int length              /* The length of the array          */
    );

#endif  /* end of H_SORT */
