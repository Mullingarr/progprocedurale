//
// Created by Mattia Lunardi on 01/05/22.
//
#include <iostream>
#include <thread>

void foo(int z){
    for(int i = 0; i < z; i++)
        std::cout << "Thread using function pointer as callable\n";
}

class thread_object{
public:
    void operator()(int x){
        for(int i = 0; i < x; i++)
            std::cout << "Thread using function object as callable\n";
    }
};

int main(){
    std::cout << "Threads 1, 2, 3 operating independently" << std::endl;

    //thread launched by using function pointer as callable
    std::thread th1(foo, 3);
    //thread launched by using function object as callable
    std::thread th2(thread_object(), 3);

    //lambda expression
    auto f = [](int x){
        for(int i = 0; i < x; i++)
            std::cout << "thread using lambda expression as callable\n";
    };

    //thread launched by using lambda expression as callable
    std::thread th3(f, 3);

    //wait for the threads to finish
    th1.join();
    th2.join();
    th3.join();

    return 0;
}
