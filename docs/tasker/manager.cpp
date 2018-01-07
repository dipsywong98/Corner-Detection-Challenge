#include "manager.h"

Manager::Manager(int max_process):index(0),max_process(max_process){
    srand(time(NULL));
    StartProcess();
}

void Manager::StartProcess(){
    while(index<100){
        while(index<100&&processes.size()<max_process){
            processes.push_back(GetNextProcess(index));
            index++;
        }
        vector<int> to_delete;
        for(int i=0; i<processes.size();i++){
            auto&& future = processes[i];
            auto status = future.wait_for(std::chrono::milliseconds(1));
            if( status == std::future_status::ready){
                future.get();
                to_delete.push_back(i);
            }
        }
        for(int i=processes.size()-1; i>=0; i--){
            processes.erase(processes.begin()+to_delete[i]);
        }
        while(!inp.empty()){
            printf("%d start\n",inp.front());
            inp.pop();
        }
        while(!out.empty()){
            printf("%d done\n",out.front());
            out.pop();
        }
    }
}
