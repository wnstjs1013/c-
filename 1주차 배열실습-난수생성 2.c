/* 배열 실습1(난수생성) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number[10];

    srand(time(NULL));

    for(int i = 0; i < 10; i++)
        {
            number[i] = (rand() % 100) +1;
        }


    for(int i = 0; i < 10; i++)
        {
            printf("number = %d\n", number[i]);
        }

    return 0;
}
