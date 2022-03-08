#ifndef QUEUE_H
#define QUEUE_H
//pragma
class Queue
{
private:
    int *queue;
    int end = 0;
    int size;
    int head = 0;
    int count = 0;

public:
    Queue(int size);
    Queue(const Queue &);
    void push(int item);
    int pop();
    void print();
    int getSize() const;
    int getCount() const;

    Queue& operator++();
    Queue& operator--();
    Queue& operator=(const Queue &);
    Queue& operator+=(const Queue&);
    Queue& operator-=(const Queue&);
    Queue& operator/=(const Queue&);

    friend Queue operator++(Queue &, int);
    friend Queue operator--(Queue &, int);
    friend Queue operator+(const Queue&, const Queue&);
    friend Queue operator/(const Queue&, const Queue&);
};

#endif