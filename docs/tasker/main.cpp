#include <iostream>

#include "manager.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc<3){
        cout<<"param 1 for max number of running thread at the same time, param 2 for execution path, optional param 3 for time limit (default 2)";
        return 0;
    }
    else{
        int max_count;
        sscanf(argv[1],"%d",&max_count);
        string path(argv[2]);
        int time_limit=2;
        if(argc>3)sscanf(argv[3],"%d",&time_limit);
        Manager m(max_count,path,time_limit);
        return m.StartProcess();
    }
}
