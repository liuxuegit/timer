#include <iostream>
#include <thread>
#include <memory>
#include "timer/timer-manager.hh"

using namespace std;
int main(int argc, char *argv[])
{

    timer_manager& tm = timer_manager::Instance();
    tm.set_thread_pool(make_threadpool());
    timer_handle ret = tm.add_timer(std::chrono::milliseconds(10),[](){cout<<"t0 ------ timeout!"<<endl;});
    ret = tm.add_timer(std::chrono::milliseconds(12),[](){cout<<"t1 ------ timeout!"<<endl;});
    ret = tm.add_timer(std::chrono::milliseconds(14),[](){cout<<"t2 ------ timeout!"<<endl;});
    ret = tm.add_timer(std::chrono::milliseconds(13),[](){cout<<"t3 ------ timeout!"<<endl;});


    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout<<"main end"<<endl;

    return 0;
}
