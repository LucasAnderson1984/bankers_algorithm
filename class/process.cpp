#include "./../header/process.h"

Process::Process(char i, Resource* r) {
  id = i;
  resource = r;
}

void Process::run() {
  this_thread::sleep_for(chrono::milliseconds(500));
  resource->acquire(id);
  this_thread::sleep_for(chrono::milliseconds(500));
  resource->acquire(id);
  this_thread::sleep_for(chrono::milliseconds(500));
  resource->release(id);
  this_thread::sleep_for(chrono::milliseconds(500));
  resource->release(id);
}
