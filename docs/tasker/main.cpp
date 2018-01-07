#include <iostream>

#include "manager.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc<3){
        cout<<"param 1 for max number of running thread at the same time, param 2 for execution path";
    }
    else{
        int max_count;
        sscanf(argv[1],"%d",&max_count);
        string path(argv[2]);
        Manager m(max_count,path);
    }
}
