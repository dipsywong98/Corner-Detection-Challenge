#ifndef _MANAGER_H__
#define _MANAGER_H__

#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>
#include <exception>
#include <queue>

using namespace std;

struct Process{
    int index;
    future<int> f;
};

class Manager{
public:
    Manager(int max_process);
    
private:
    int index;
    int max_process;
    vector<future<int>> processes;
    queue<int> out;
    queue<int> inp;
    
    void StartProcess();
    inline future<int> GetNextProcess(int _index){
        return  async(std::launch::async,[=]{
            inp.push(_index);
            std::this_thread::sleep_for(std::chrono::milliseconds((rand()%5)*1000));
            out.push(_index);
            return 0;
        });
    }
};

#endif
