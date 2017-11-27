#include <iostream>
#include <thread>
#include <vector>
#include "./header/process.h"
#include "./header/resource.h"

using namespace std;

int main() {
  vector<Process*> processes;
  Resource* resource = new Resource();
  vector<thread> threads;

  for (int i = 0; i < 5; i++) {
    processes.push_back(new Process(65 + i, resource));
    threads.push_back(thread(&Process::run, processes[i]));
  }

  for (int i = 0; i < 5; i++)
    threads[i].join();

  return 0;
}
