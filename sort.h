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

void merge_sort             /* Merge sort                       */
    (
    int data[],             /* The target array to be sorted    */
    int length              /* The length of the array          */
    );

void merge                  /* Merge left and right sub array   */
    (
    int *left,
    int  left_len,
    int *right,
    int  right_len
    );

#endif  /* end of H_SORT */
