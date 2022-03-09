#include <iostream>
#include "Queue.h"

using namespace std;

void fill_the_queue(Queue &q);

int main() {
  Queue q1(7);

  fill_the_queue(q1);

  Queue q2 = q1;

  q1.print();
  q2.print();
  printf("%d", q1 > q2);
  int c;
  cin >> c;
  return 0;
}

void fill_the_queue(Queue &q) {
  static int r = 0;
  srand(r++);
  for (int i = 0; i < q.getSize(); ++i) {
    q.push(rand() % 20 + 1 - 10);
  }
}