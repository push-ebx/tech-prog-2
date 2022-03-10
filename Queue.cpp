#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(int size) {
  queue = new Item[size];
  this->size = size;
}

Queue::Queue(const Queue &q) :
        queue(new Item[q.size]), size(q.size), end(q.end), head(q.head), count(q.count) {
  for (int i = 0; i < q.count; ++i) {
    queue[i].value = q.queue[i].value;
  }
}

int Queue::getSize() const {
  return size;
}

std::ostream &operator<<(std::ostream &out, const Queue &q) {
  int *items = getQueueOfArray(q);
  for (int i = 0; i < q.getCount(); ++i) {
    out << items[i] << " ";
  }
  out << "\n";
  return out;
}

std::istream &operator>>(std::istream &in, Queue &q) {
  int item;
  cout << "Enter item: ";
  in >> item;
  q.push(item);
  return in;
}

void Queue::clear(){
  end = 0;
  head = 0;
  count = 0;
}

void Queue::push(int item) {
  if (count >= size) {
    cout << "Queue is full" << endl;
    return;
  }

  queue[end].value = item;
  end = (end + 1) % size;
  count++;
}

Queue &Queue::operator++() {
  cin >> *this;
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

bool operator!=(const Queue &q1, const Queue &q2) {
  if (q1.getSize() != q2.getSize() || q1.getCount() != q2.getCount()) {
    return true;
  }
  int *items1 = getQueueOfArray(q1);
  int *items2 = getQueueOfArray(q2);

  for (int i = 0; i < q1.getCount(); ++i) {
    if (items1[i] != items2[i])
      return true;
  }
  return false;
}

bool operator==(const Queue &q1, const Queue &q2) {
  return !(q1 != q2);
}

bool operator>(const Queue &q1, const Queue &q2) {
  return q1.getCount() > q2.getCount();
}

bool operator>=(const Queue &q1, const Queue &q2) {
  return q1.getCount() >= q2.getCount();
}

bool operator<(const Queue &q1, const Queue &q2) {
  return q1.getCount() < q2.getCount();
}

bool operator<=(const Queue &q1, const Queue &q2) {
  return q1.getCount() <= q2.getCount();
}

Queue &Queue::operator=(const Queue &q) {
  if (this == &q) {
    return *this;
  }
  Queue q2(q);
  return q2;
}

int *getQueueOfArray(const Queue &q1) {
  int *items = new int[q1.count];
  int pos = 0;
  if (q1.end > q1.head) {
    for (int i = q1.head; i < q1.end; i++)
      items[pos++] = q1.queue[i].value;
  } else if (q1.end <= q1.head && q1.count) {
    for (int i = q1.head; i < q1.size; i++)
      items[pos++] = q1.queue[i].value;
    for (int i = 0; i < q1.end; i++)
      items[pos++] = q1.queue[i].value;
  }
  return items;
}

Queue operator+(const Queue &q1, const Queue &q2) {
  if (q1.getSize() != q2.getSize()) {
    throw new invalid_argument("Incorrect sizes");
  }
  Queue q3(q1.getSize());
  int *items1 = getQueueOfArray(q1);
  int *items2 = getQueueOfArray(q2);

  for (int i = 0; i < q1.getCount(); ++i) {
    q3.push(items1[i] + items2[i]);
  }
  return q3;
}

Queue operator/(const Queue &q1, const Queue &q2) {
  if (q1.getSize() != q2.getSize()) {
    throw new invalid_argument("Incorrect sizes");
  }
  Queue q3(q1.getSize());
  int *items1 = getQueueOfArray(q1);
  int *items2 = getQueueOfArray(q2);

  for (int i = 0; i < q1.getCount(); ++i) {
    q3.push(items1[i] / items2[i]);
  }
  return q3;
}

Queue &Queue::operator+=(const Queue &q2) {
  if (size != q2.getSize() || count != q2.getCount()) {
    throw new invalid_argument("Incorrect sizes");
  }
  int *items1 = getQueueOfArray(*this);
  int *items2 = getQueueOfArray(q2);

  clear();
  for (int i = 0; i < q2.getCount(); ++i) {
    push(items1[i] + items2[i]);
  }
  return *this;
}

Queue &Queue::operator/=(const Queue &q2) {
  if (size != q2.getSize() || count != q2.getCount()) {
    throw new invalid_argument("Incorrect sizes");
  }
  int *items1 = getQueueOfArray(*this);
  int *items2 = getQueueOfArray(q2);

  clear();
  for (int i = 0; i < q2.getCount(); ++i) {
    push(items1[i] / items2[i]);
  }
  return *this;
}

Queue &Queue::operator-=(const Queue &q2) {
  if (size != q2.getSize() || count != q2.getCount()) {
    throw new invalid_argument("Incorrect sizes");
  }
  int *items1 = getQueueOfArray(*this);
  int *items2 = getQueueOfArray(q2);

  clear();
  for (int i = 0; i < q2.getCount(); ++i) {
    push(items1[i] - items2[i]);
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
  int item = queue[head].value;
  head = (head + 1) % size;
  count--;
  return item;
}

Queue &Queue::operator--() {
  this->pop();
  return *this;
}

void Queue::fill_the_queue() {
  static int r = 0;
  srand(r++);
  for (int i = 0; i < this->getSize(); ++i) {
    this->push(rand() % 20 + 1 - 10);
  }
}