#include <cstdio>
#include <algorithm>
#include <iostream>
#include <thread>
#include <boost/thread.hpp>
 
using namespace std;
 
void task(int num)
{
    int start = 1 + (10 * (num - 1));
    int end = num * 10;
 
    for(int i = start; i <= end; i++){
        cout << i << endl;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}
 
int main() {
 
    vector<boost::thread *> group;
 
    for(int i = 0; i < 3; i++){
        group.push_back(new boost::thread(task, i + 1));
    }
 
    for(int i = 0; i < 3; i++){
        group[i]->join();
        delete group[i];
    }
    return 0;
}
