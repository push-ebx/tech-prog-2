#pragma once

class Queue
{
    struct Item
    {
        int value;
    };

private:
    int size;
    Item *queue;
    int end = 0;
    int head = 0;
    int count = 0;
    friend int* getQueueOfArray(const Queue& q1);

public:
    int pop();
    void clear();
    Queue(int size);
    void push(int item);
    int getSize() const;
    Queue(const Queue &);
    int getCount() const;
    void fill_the_queue();

    Queue& operator++();
    Queue& operator--();
    Queue& operator=(const Queue &);
    Queue& operator+=(const Queue&);
    Queue& operator-=(const Queue&);
    Queue& operator/=(const Queue&);

    friend Queue operator++(Queue &, int);
    friend Queue operator--(Queue &, int);
    friend bool operator>(const Queue&, const Queue&);
    friend bool operator<(const Queue&, const Queue&);
    friend bool operator>=(const Queue&, const Queue&);
    friend bool operator<=(const Queue&, const Queue&);
    friend bool operator!=(const Queue&, const Queue&);
    friend bool operator==(const Queue&, const Queue&);
    friend Queue operator+(const Queue&, const Queue&);
    friend Queue operator/(const Queue&, const Queue&);
    friend std::istream& operator>> (std::istream &in, Queue &point);
    friend std::ostream& operator<< (std::ostream &out, const Queue &q);
};