#include <iostream>

using namespace std;

#include "Queue.h"
//pragma

Queue::Queue(int size) {
  queue = new int[size];
  this->size = size;
}

Queue::Queue(const Queue &q) :
        queue(new int[q.size]), size(q.size), end(q.end), head(q.head), count(q.count) {
  for (int i = 0; i < q.count; ++i) {
    queue[i] = q.queue[i];
  }
}

int Queue::getSize() const {
  return size;
}

void Queue::print() {
  if (end > head) {
    for (int i = head; i < end; i++)
      cout << queue[i] << " ";
  } else if (end <= head && count) {
    for (int i = head; i < size; i++)
      cout << queue[i] << " ";
    for (int i = 0; i < end; i++)
      cout << queue[i] << " ";
  } else cout << "Queue is empty";
  cout << "\n";
}

void Queue::push(int item) {
  if (count >= size) {
    cout << "Queue is full" << endl;
    return;
  }

  queue[end] = item;
  end = (end + 1) % size;
  count++;
}

Queue &Queue::operator++() {
  int item;
  cout << "Enter element: ";
  cin >> item;
  this->push(item);
  return *this;
}

Queue operator++(Queue &q, int d) {
  Queue temp(q.getSize());
  int add;
  cout << "Enter adder: ";
  cin >> add;

  for (int i = 0; i < q.getCount(); ++i) {
    int item = q.pop();
    q.push(item + add);
    temp.push(item);
  }
  return temp;
}

Queue operator--(Queue &q, int d) {
  Queue temp(q.getSize());
  int sub;
  cout << "Enter subtrahend: ";
  cin >> sub;

  for (int i = 0; i < q.getCount(); ++i) {
    int item = q.pop();
    q.push(item - sub);
    temp.push(item);
  }
  return temp;
}

Queue &Queue::operator=(const Queue &q) {
  Queue q2(q); //// чекать на самоприсваивание
  return q2;
}

Queue operator+(const Queue &q1, const Queue &q2) {
  if (q1.getSize() != q2.getSize()) {
    throw new invalid_argument("Incorrect sizes");
  }
  Queue q3(q1.getSize());
  for (int i = 0; i < q1.getCount(); ++i) {
    q3.push(q1.queue[i] + q2.queue[i]);
  }
  return q3;
}

Queue operator/(const Queue &q1, const Queue &q2) {
  if (q1.getSize() != q2.getSize()) {
    throw new invalid_argument("Incorrect sizes");
  }
  Queue q3(q1.getSize());
  for (int i = 0; i < q1.getCount(); ++i) {
    q3.push(q1.queue[i] / q2.queue[i]);
  }
  return q3;
}

Queue& Queue::operator+=(const Queue &q2){
  if (size != q2.getSize()) { //// и count
    throw new invalid_argument("Incorrect sizes");
  }
  for (int i = 0; i < count; ++i) {
    queue[i] += q2.queue[i];
  }
  return *this;
}

Queue& Queue::operator/=(const Queue &q2){
  if (size != q2.getSize()) { //// и count
    throw new invalid_argument("Incorrect sizes");
  }
  for (int i = 0; i < count; ++i) {
    queue[i] /= q2.queue[i];
  }
  return *this;
}

Queue& Queue::operator-=(const Queue &q2){
  if (size != q2.getSize()) { //// и count
    throw new invalid_argument("Incorrect sizes");
  }
  for (int i = 0; i < count; ++i) {
    queue[i] -= q2.queue[i];
  }
  return *this;
}

int Queue::getCount() const {
  return count;
}

int Queue::pop() {
  if (count <= 0) {
    cout << "Queue is empty" << endl;
    return -1;
  }
  int item = queue[head];
  head = (head + 1) % size;
  count--;
  return item;
}

Queue &Queue::operator--() {
  this->pop();
  return *this;
}