#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>

using namespace std;

class Resource {
  private:
    condition_variable cv;
    mutex mux;
    static int resource;
    unique_lock<mutex> ul;
  public:
    Resource(void);
    ~Resource(void) {}
    void acquire(char);
    void release(char);
};
