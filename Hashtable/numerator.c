#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "hash_types.h"

#include "pcg_basic.h"

typedef struct {
    pcg32_random_t gen[2];
} pcg32x2_random_t;

void pcg32x2_srandom_r(pcg32x2_random_t* rng, uint64_t seed1, uint64_t seed2,
                       uint64_t seq1,  uint64_t seq2)
{
    uint64_t mask = ~0ull >> 1;
    // The stream for each of the two generators *must* be distinct
    if ((seq1 & mask) == (seq2 & mask)) 
        seq2 = ~seq2;
    pcg32_srandom_r(rng->gen,   seed1, seq1);
    pcg32_srandom_r(rng->gen+1, seed2, seq2);
}

uint64_t pcg32x2_random_r(pcg32x2_random_t* rng)
{
    return ((uint64_t)(pcg32_random_r(rng->gen)) << 32)
           | pcg32_random_r(rng->gen+1);
}

/* See other definitons of ..._boundedrand_r for an explanation of this code. */

uint64_t pcg32x2_boundedrand_r(pcg32x2_random_t* rng, uint64_t bound)
{
    uint64_t threshold = -bound % bound;
    for (;;) {
        uint64_t r = pcg32x2_random_r(rng);
        if (r >= threshold)
            return r % bound;
    }
}

int dummy_global;
int bunny_global;

hashinfo numerator()  //get hash info
{
	pcg32_random_t rng1;
	pcg32x2_random_t rng2;
	hashinfo info;

	pcg32_srandom_r(&rng1, time(NULL) ^ (intptr_t)&malloc, (intptr_t)&dummy_global);

	pcg32x2_srandom_r(&rng2, time(NULL), ~time(NULL)^(intptr_t)&pcg32_random_r,
			  ~(intptr_t)&pcg32x2_srandom_r, (intptr_t)&bunny_global);

	info.w = 8 * sizeof(long int);  // machine word
	info.M = 20;
	if(info.w == 32)
	{
		info.p = 2147483647;  // 2^31 - 1
		info.ppower = 31;
		info.a_str = (unsigned int)pcg32_boundedrand_r(&rng1, info.p);
		info.a_int = (unsigned int)pcg32_boundedrand_r(&rng1, (unsigned int)1<<info.w - 1);
		if(info.a_int&1 == 0)
			info.a_int++;
		info.b_int = (unsigned int)pcg32_boundedrand_r(&rng1, (unsigned int)1<<(info.w - info.M));
	}
	else
	{
		info.p = 2305843009213693951;  // 2^61 - 1
		info.ppower = 61;
		info.a_str = (unsigned long)pcg32x2_boundedrand_r(&rng2, info.p);
		info.a_int = (unsigned long)pcg32x2_boundedrand_r(&rng2, (unsigned long)1<<info.w - 1);
		if(info.a_int&1 == 0)
			info.a_int++;
		info.b_int = (unsigned long)pcg32x2_boundedrand_r(&rng2, (unsigned long)1<<(info.w - info.M));
	}
	info.m = (unsigned long)1<<info.M;  // m = 2^M

	return info;
}
