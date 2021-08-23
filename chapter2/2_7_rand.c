unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */
int rand(void) {
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

/* srand: set seed for rand() */
// 如果seed相同，生成的随机数也相同
void srand(unsigned int seed) { next = seed; }

#include <stdio.h>

int main(void){
    int count;
    unsigned seed;
    printf("please enter your choice for seed.\n");
    while (scanf("%u", &seed) == 1)
    {
        srand(seed);
        for (count = 0; count < 5; count++)
        {
           printf("%d\n", rand());
        }
        printf("please enter next seed (q to quit):\n");
    }
    printf("Done\n");
    return 0;
}
