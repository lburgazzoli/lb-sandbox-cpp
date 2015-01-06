
#include <iostream>
#include <future>
#include <thread>

#include "openhft/affinity.hpp"

int main(int argc, char **argv) 
{
    std::thread t1([](){
        openhft::Affinity::get().setAffinity(1);

        std::cout 
            << "1.cpu : " << openhft::Affinity::get().getCpu()       << std::endl
            << "1.pid : " << openhft::Affinity::get().getProcessId() << std::endl
            << "1.tid : " << openhft::Affinity::get().getThreadId()  << std::endl;
    });

    t1.join();

    std::thread t2([](){
        openhft::Affinity::get().setAffinity(0);
        
        std::cout 
            << "0.cpu : " << openhft::Affinity::get().getCpu()       << std::endl
            << "0.pid : " << openhft::Affinity::get().getProcessId() << std::endl
            << "0.tid : " << openhft::Affinity::get().getThreadId()  << std::endl;
    });

    t2.join();

    return 0;
}