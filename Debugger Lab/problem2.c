#include <stdio.h>
#include <stdlib.h>

static int puzzle1 = 0x40490fdb;
static int puzzle2[2] = {0x8b145769, 0x4005bf0a};
static char puzzle3[] = {87, 97, 115, 32, 116, 104, 97, 116, 32, 114, 101,
    97, 108, 108, 121, 32, 115, 111, 32, 104, 97, 114, 100, 63, 0};

int hmc_pomona_fix(int x)
{
    if (x == 42)
	return 47;
    else if (x == 47)
	return 42;
    else
	return x;
}

void fix_array(int *a, int a_size)
{
    int i;

    for (i = 0;  i < a_size;  i++, a++) {
	*a = hmc_pomona_fix(*a);
    }
}

int main(int argc, char *argv[])
{
    int *array;
    int i;

    array = (int *)malloc(argc * sizeof(int));
    /* argv[0] is the program name so we skip it */
    for (i = 1;  i < argc;  i++) {
	array[i] = atoi(argv[i]);
    }
    fix_array(array, argc - 1);
    for (i = 1;  i < argc;  i++) {
	printf ("%d ", array[i]);
    }
    printf ("\n");
    return 0;
}
