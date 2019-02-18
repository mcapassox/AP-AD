#include <iostream>

int main()
{
    const int size = 100; //The upper bound for finding primes
    // Since even numbers cannot be primes, size / 2 is the safest upper bound for the array size.
    int * primes{new int[size / 2]};
    int count{0};

    for (int  i{2}; i < size; ++i)
    {
        bool  is_prime{true};
        for (int  j{2}; j < i; ++j)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            std::cout << i << " ";
            primes[count++] = i;
        }
    }
    return 0;
}
