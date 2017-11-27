#include "./../header/resource.h"

int Resource::resource = 6;

Resource::Resource() { }

void Resource::acquire(char id) {
  unique_lock<mutex> ul(mux);

  while (resource == 0) {
    cout << id << " is waiting." << endl;
    cv.wait(ul);
  }

  cout << id << " has acquired a resource." << endl;

  resource--;
  ul.unlock();
}

void Resource::release(char id) {
  unique_lock<mutex> ul(mux);
  cout << id << " has released resource" << endl;
  resource++;

  ul.unlock();
  cv.notify_all();
}
