#include "./../header/process.h"

Process::Process(char i, Resource* r) {
  id = i;
  resource = r;
}

void Process::run() {
  for (int i = 0; i < 2; i++) {
    this_thread::sleep_for(chrono::milliseconds(500));
    resource->acquire(id);
  }

  for (int i = 0; i < 2; i++) {
    this_thread::sleep_for(chrono::milliseconds(500));
    resource->release(id);
  }
}
