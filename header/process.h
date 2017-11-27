#pragma once

#include "./../header/resource.h"
#include <thread>

class Process {
  private:
    char id;
    Resource* resource;
  public:
    Process(char, Resource*);
    ~Process(void) {}
    void run(void);
};
