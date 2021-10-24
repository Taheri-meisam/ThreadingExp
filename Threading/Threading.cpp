#include <thread>
#include <limits.h>
#include <iostream>
#include <time.h>
#include <Windows.h>

class T_class1 {

public:
    void looping(int nothing) {
        for (int i = 0; i < 100; i++) {
            std::cout << "Loop 1 : " << i << std::endl;
            Sleep(1000);
        }
    }

};

class T_class2 {

public:
    void looping() {
        for (int i = 0; i < 100; i++) {
            std::cout << "Loop 2 : " << i << std::endl;
            Sleep(1000);
        }
    }
};

// Normal thread with a seperate function 

void printStrings(std::string text) {
   
    for (int i = 0; i < 100; i++) {
        std::cout << text << std::endl;
        Sleep(1000);
    }
} 


int main()
{
    T_class1* c1 = new T_class1(); 
    T_class2* c2 = new T_class2();

    std::thread t1(&T_class1::looping, c1,0); // thread calling a class member function
    std::thread t2(&T_class2::looping, c2);
    std::thread t3(printStrings, "something"); // thread running a function out of a class
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Hello World!\n";
    delete c1,c2;
}


