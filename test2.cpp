#include <iostream>
#include <utility>

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

cpp_int fib(cpp_int a, cpp_int b, unsigned int n)
{
    for(unsigned int i = 2; i < n; ++i)
    {
        cpp_int temp = a + b*b;
        a = b;
        b = temp;
    }
    return b;
}

int main()
{
    unsigned int a, b, n;

    std::cin >> a >> b >> n;
    std::cout << fib(a, b, n);
}

