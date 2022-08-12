#include <immintrin.h>
#include <smmintrin.h>

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
  int size = 65536;
  int *first_array = new int[size];
  int *second_array = new int[size];
  for (int i = 0; i < size; ++i) {
    first_array[i] = i;
    second_array[i] = i;
  }

  struct timespec begin, end;
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // add_no_AVX(size, first_array, second_array);
  add_AVX(size, first_array, second_array);

  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  printf("add_AVX:    %f seconds\n",
         (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
             (end.tv_sec - begin.tv_sec));


  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

  add_no_AVX(size, first_array, second_array);

  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  printf("add_no_AVX: %f seconds\n",
         (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
             (end.tv_sec - begin.tv_sec));
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
