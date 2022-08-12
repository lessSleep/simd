#include <immintrin.h>
#include <smmintrin.h>
#include "htimer.h"

#include "bits/stdc++.h"
// https://www.cs.virginia.edu/~cr4bd/3330/F2018/simdref.html

int add_no_AVX(int size,int* __restrict first_array,int* __restrict second_array) {
  for (int i = 0; i < size; ++i) {
    first_array[i] += second_array[i];
  }
  return 0;
}

//int add_AVX(int size, int * __restrict first_array, int * __restrict second_array) {
int add_AVX(int size, int * first_array, int * second_array) {
  int i = 0;
  for (; i + 8 <= size; i += 8) {
    // load 256-bit chunks of each array
    //__m256i first_values = _mm_loadu_si256((__m256i*) &first_array[i]);
    __m256i first_values = _mm256_loadu_si256((__m256i *)&first_array[i]);

    //__m256i second_values = _mm_loadu_si256((__m256i*) &second_array[i]);
    __m256i second_values = _mm256_loadu_si256((__m256i *)&second_array[i]);

    // add each pair of 32-bit integers in the 256-bit chunks
    first_values = _mm256_add_epi32(first_values, second_values);

    // store 256-bit chunk to first array
    //_mm_storeu_si256((__m256i*) &first_array[i], first_values);
    _mm256_storeu_si256((__m256i *)&first_array[i], first_values);
  }
  // handle left-over
  for (; i < size; ++i) {
    first_array[i] += second_array[i];
  }
  return 0;
}

int main() {
  constexpr int size = 65536;
  int *first_array = new int[size];
  int *second_array = new int[size];
  for (int i = 0; i < size; ++i) {
    first_array[i] = i;
    second_array[i] = i;
  }
 
  {
    htimer timer("add_avx");
    add_AVX(size, first_array, second_array);
  }

  {
    htimer timer("add_no_avx");
    add_no_AVX(size, first_array, second_array);
  }

  /*
  for (int i = 0; i < size; ++i) {
      printf("%d\n", first_array[i]);
  }

  for (int i = 0; i < size; ++i) {
      printf("%d\n", second_array[i]);
  }
  */

  return 0;
}
