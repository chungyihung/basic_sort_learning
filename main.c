#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

#define sort( method,data, length ) method##_sort( data, length )

void init_sorted_array
    (
    int data[],
    int data_origin[],
    int length
    )
{
    int i = 0;
    for( i = 0; i < length; i++ )
        {
        data[i] = data_origin[i];
        }
}

void print_array
    (
    int data[],
    int length
    )
{
    int i = 0;
    for( i = 0; i < length; i++ )
        {
        printf( "%d ", data[i] );
        }
    printf( "\n" );
}

void main()
{
    int data_origin[10] = { 5, 2, 3, 12, 54, 21, 43, 75, 76, 67 };
    int data[10];
    int i;
    int length = sizeof( data ) / sizeof( data[0] );

    init_sorted_array( data, data_origin, length );
    sort( bubble, data, length);
    print_array( data, length );

    init_sorted_array( data, data_origin, length );
    sort( insert, data, length );
    print_array( data, length );

}
