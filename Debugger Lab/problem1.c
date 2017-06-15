#include <stdio.h>

int loop_while(int a, int b)
{
    int i = 0;
    int result = a;
    while (i < 256) {
	result += a;
	a -= b;
	i += b;
    }
    return result;
}

int main(int argc, char *argv[])
{
    printf("%d\n", loop_while(atoi(argv[1]), 16));
    return 0;
}
