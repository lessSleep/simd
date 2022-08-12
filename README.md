# simd
Test simd in c++ .

Test avx add:
g++ simdok.cpp -march=native -O2 -o simdok

```
lingzhang@lingzhang-e470:~/code/simd$ g++ simdok.cpp -march=native -O2 -o simdok
lingzhang@lingzhang-e470:~/code/simd$ ./simdok 
add_AVX:    0.000015 seconds
add_no_AVX: 0.000013 seconds
lingzhang@lingzhang-e470:~/code/simd$ g++ simdok.cpp -march=native -O2 -o simdok
lingzhang@lingzhang-e470:~/code/simd$ ./simdok 
add_AVX:    0.000014 seconds
add_no_AVX: 0.000016 seconds
lingzhang@lingzhang-e470:~/code/simd$ ./simdok 
add_AVX:    0.000015 seconds
add_no_AVX: 0.000015 seconds
lingzhang@lingzhang-e470:~/code/simd$ g++ simdok.cpp -march=native -o simdok
lingzhang@lingzhang-e470:~/code/simd$ ./simdok 
add_AVX:    0.000059 seconds
add_no_AVX: 0.000206 seconds
lingzhang@lingzhang-e470:~/code/simd$ ./simdok 
add_AVX:    0.000059 seconds
add_no_AVX: 0.000218 seconds
lingzhang@lingzhang-e470:~/code/simd$ g++ simdok.cpp -march=native -O3 -o simdok
lingzhang@lingzhang-e470:~/code/simd$ ./simdok 
add_AVX:    0.000015 seconds
add_no_AVX: 0.000014 seconds
lingzhang@lingzhang-e470:~/code/simd$ ./simdok 
add_AVX:    0.000020 seconds
add_no_AVX: 0.000019 seconds
lingzhang@lingzhang-e470:~/code/simd$ ./simdok 
add_AVX:    0.000015 seconds
add_no_AVX: 0.000016 seconds
```
