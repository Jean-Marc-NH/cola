#include <iostream>
using namespace std;

struct COLA {
    int A[10];
    int* head;
    int* tail;

    COLA();
    bool push(int);
    bool pop(int&);
};


int main()
{

    COLA cola;
    int x;

    for (int i = 0; i < 11; i++)
    {
        if (cola.push(i * 10)) {
            cout << "Elemento insertado: " << i*10 << "\n";
        }
        else 
        {
            cout << "Cola llena\n";
        }
    }

    cola.pop(x);

    cout << "Elemento eliminado: " << x << "\n";

    cola.push(99);


    for (int i = 0; i < 12; i++) 
    {
        if (cola.pop(x))
        {
            cout << x << ", ";
        }
        else
        {
            cout << "\nCola Vacia";
        }
    }

}


COLA::COLA() {
    head = NULL;
    tail = head;
}

bool COLA::push(int x) 
{
    if (!head) {
        head = A;
        *head = x;
        tail = head;
        return true;
    }

    if (head < tail)
    {
        if (tail < (A + 9)) 
        {
            tail++;
            *tail = x;
            return true;
        }
        else
        {
            if (head == A) 
            {
                return false;
            }
            else 
            {
                tail = A;
                *tail = x;
                return true;
            }
        }
    }
    else if (head > tail)
    {
        if ((tail++) == head)return false;
        tail++;
        *tail = x;
    }
    else
    {
        if (tail != (A + 9)) 
        {
            tail++;
            *tail = x;
            return true;
        }
        else
        {
            tail = A;
            *tail = x;
            return true;
        }
    }
}

bool COLA::pop(int &x) 
{
    if (!head)return false;
    if (head < tail)
    {
        x = *head;
        head++;
        return true;
    }
    else if (head > tail)
    {
        if (head < (A + 9))
        {
            x = *head;
            head++;
            return true;
        }
        else
        {
           x = *head;
           head = A;
           return true;
        }
    }
    else 
    {
        x = *head;
        head = NULL;
        tail = NULL;
        return true;
    }
}
