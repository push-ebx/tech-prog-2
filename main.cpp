#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
  Queue q1(7);
  q1.fill_the_queue();
  cout << q1;
  --q1;
//  --q1;
//  --q1;
//  --q1;
  ++q1;
//  ++q1;
  Queue q2 = q1;
  cout << q1;
  cout << q2;
  q1 += q2;
  cout << q1;

  int c;
  cin >> c;
  return 0;
}