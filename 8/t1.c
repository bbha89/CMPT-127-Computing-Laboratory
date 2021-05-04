#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "point_array.h"
/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa )
{
pa->points = NULL;
pa->len = 0;
pa->reserved = 0;
pa->points = malloc(sizeof (point_t));
}
/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa )
{
	free(pa);
}
/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p )
{
	if(pa->points == NULL)
	{return 1;}
	pa->len = pa->len+1;
	pa->points = realloc(pa->points, (pa->len)*sizeof(point_t));
	pa->points[pa->len-1] = *p;
	return 0;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i )
{
	if(pa->points == NULL || i >= pa->len ||pa == NULL || pa->len == 0)
	{return 1;}
	pa->points[i] = pa->points[pa->len-1];
	pa->len = pa->len-1;
	pa->points = realloc(pa->points,(pa->len)*sizeof(point_t));
	return 0;
}
