#include <iostream>
#include "Queue.h"
#include <time.h>

using namespace std;

void fill_the_queue(Queue &q);

int main() {
  Queue q1(7);
  Queue q2(7);

  fill_the_queue(q1);
  fill_the_queue(q2);

  q1.print();
  q2.print();

  int c;
  cin >> c;
  return 0;
}

void fill_the_queue(Queue &q) {
  static int r = 0;
  srand(time(NULL) + r++);
  for (int i = 0; i < q.getSize(); ++i) {
    q.push(rand() % 20 + 1 - 10);
  }
}