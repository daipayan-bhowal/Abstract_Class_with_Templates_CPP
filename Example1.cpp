#include <iostream>
using namespace std;


template <typename T>
class queue {
public:
    ~queue();
    virtual bool empty()=0;
    virtual size_t size()=0;
    virtual T front()=0;
    virtual void push(T data)=0;
    virtual T pop()=0;

//protected:
};

template <typename T>
queue<T>::~queue()
{}

template <typename T>
class my_queue: public queue<T> {
public:
    struct node {
        T data;
        node *next;

        node()
            : data(0)
            , next(NULL) {
        }

        node(T data, node* next)
            : data(data)
            , next(next) {
        }

    };
     bool empty();
     size_t size();
     T front();
     void push(T data);
     T pop();
private:
    size_t elements = 0;
    node *head;
    node *tail;
};
template <typename T>
bool my_queue<T>::empty()
{
    return elements == 0;
}

template <typename T>
size_t my_queue<T>::size()
{
    return elements;
}

template <typename T>
T my_queue<T>::front()
{
    if(elements == 0)
        std::cout <<"Empty Queue"<<std::endl;
    return head->data;
}

template <typename T>
 void  my_queue<T>::push(T data)
{
    node *newNode = new node(data, NULL);
    if(!elements)
       head = newNode;
    else
       tail->next = newNode;
    tail = newNode;
    ++elements;
}
template <typename T>
T my_queue<T>::pop()
{
    int pop_elem;
    if(elements == 0)
        std::cout <<"Empty Queue"<<std::endl;
    node *tmp = new node();
    if(elements != 0)
       tmp = head;
   
    pop_elem = tmp->data;
    head = head->next;
    --elements;
    delete tmp;
    return pop_elem;
}

int main()
{
  my_queue<int> q;
    q.push(5);
    q.push(4);
    q.push(6);

    cout << q.pop()<<std::endl;
}
