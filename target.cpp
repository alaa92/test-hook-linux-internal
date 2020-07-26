#include <iostream>
#include <thread>
#include <chrono>

int test(int num1, int num2)
{
    int sum = num1 + num2;
    std::cout << "The sum of num1 and num2 is: " << sum << std::endl;
    return sum;
}

int main()
{
    while(true)
    {
        test(10, 20);
        std::cout << "Address of test: " << (void*)&test << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
    return 0;
}