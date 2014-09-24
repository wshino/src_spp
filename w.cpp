#include<cstdio>
#include<algorithm>
#include<iostream>
#include<thread>
#include<map>
#include<boost/thread.hpp>

using namespace std;

// スレッドで実行する関数
void func1(const unsigned int low, const unsigned int upper)
{
    for(unsigned int i = low; i <= upper; ++i )
    {
        cout  << __FUNCTION__ << "i=" << i << endl; 
    }
}

 
int main()
{
    map<unsigned int, boost::thread *>thread_map;
    map<unsigned int, boost::thread *>::iterator it;
    
    // mapにスレッドを追加
    thread_map.insert(make_pair(1,new boost::thread(func1, 10, 15)));
    thread_map.insert(make_pair(2,new boost::thread(func1, 20, 25)));
    thread_map.insert(make_pair(3,new boost::thread(func1, 30, 35)));
    
    // スレッドの実行待ち
    for(it = thread_map.begin(); it != thread_map.end(); ++it)
    {
        it->second->join();
    }
    
    // スレッドの削除
    for(it = thread_map.begin(); it != thread_map.end(); ++it)
    {
        delete it->second;
    }
    
    // MAPのクリア
    thread_map.clear();
    
    return 0;
}

