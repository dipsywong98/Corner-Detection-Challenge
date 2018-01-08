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
    Manager(int max_process,  string process_path, int time_limit);
    int StartProcess();
    
private:
    int index;
    int max_process;
    int time_limit;
    string process_path;
    vector<future<int>> processes;
    queue<string> out;
    queue<int> inp;
    vector<int> start_time;
    
    inline future<int> GetNextProcess(int _index);
};

#endif
