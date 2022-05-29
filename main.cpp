#include <iostream>

using namespace std;

#define VERBOSE false

template <typename type>
/** Node of list */
struct Node
{
    /** Data of Node */
    type data;
    /** Pointer to next one Node */
    Node<type> *next;
};

template <typename type>
/** List */
class List
{
private:
    /** Pointer to first one Node */
    Node<type> *first = nullptr;

    /** Pointer to last one Node */
    Node<type> *last = nullptr;

    /** Count of elements in collection */
    int count;

public:
    /**
     * Initialize list with one element
     */
    List(type data)
    {
        this->count = 1;
        Node<type> *element = new Node<type>();
        element->data = data;
        element->next = nullptr;
        this->first = element;
        this->last = element;
#if VERBOSE
        cout << "init list with `" << element->data << "` data\n";
#endif
    }

    /**
     * Initialize empty list
     */
    List()
    {
        this->count = 0;
#if VERBOSE
        cout << "init empty list\n";
#endif
    }

    /**
     * Add element at end
     */
    void push(type data)
    {
        Node<type> *element = new Node<type>();
        element->data = data;
        element->next = nullptr;
        if (this->count)
        {
            (this->last)->next = element;
        }
        this->last = element;
        if (this->first == nullptr)
        {
            this->first = element;
        }
#if VERBOSE
        cout << "pushed `" << element->data << "` at position " << this->count << "\n";
#endif

        this->count++;
    }

    /**
     * Pop last element from list
     */
    void pop()
    {
        /** Pointer to travel through list */
        Node<type> *ptr = this->first;
        /** Pointer to new last element */
        Node<type> *last_one = nullptr;

        do
        {
            last_one = ptr;
            ptr = ptr->next;
        } while (ptr != nullptr && ptr->next != nullptr);

        if (last_one == nullptr)
        {
            cout << "Cannot pop from empty!\n";
            return;
        }

        /** Popped element */
        Node<type> *popped = last_one->next == nullptr ? last_one : last_one->next;
#if VERBOSE
        cout << "popped `" << popped->data << "`\n";
#endif
        delete popped;

        // destroy popped;
        last_one->next = nullptr;

        if (this->last == this->first)
        {
            this->last = nullptr;
            this->first = nullptr;
        }
        else // new last element
        {
            this->last = last_one;
        }
        this->count--;
    }

    /**
     * Print all elements in list as json-like string
     */
    void print()
    {
        if (!this->count)
        {
            cout << "{}\n";
            return;
        }

        Node<type> *ptr = this->first;
        cout << "{";
        do
        {
            cout << ptr->data;
            ptr = ptr->next;
            if (ptr != nullptr)
            {
                cout << ", ";
            }
        } while (ptr != nullptr);
        cout << "}\n";
        return;
    }

    /**
     * Return count of elements in list
     */
    int size()
    {
        return this->count;
    }

    /**
     * Return min element
     */
    type min()
    {
        Node<type> *ptr = this->first;
        type min = ptr->data;
        while (ptr != nullptr)
        {
            if (ptr->data < min)
            {
                min = ptr->data;
            }
            ptr = ptr->next;
        }

        return min;
    }

    /**
     * Return max element
     */
    type max()
    {
        Node<type> *ptr = this->first;
        type max = ptr->data;
        while (ptr != nullptr)
        {
            if (ptr->data > max)
            {
                max = ptr->data;
            }
            ptr = ptr->next;
        }

        return max;
    }

    /**
     * Find element by data, and return pointer on success
     */
    Node<type> *find(type needle)
    {
        Node<type> *ptr = this->first;
        while (ptr != nullptr)
        {
            if (ptr->data == needle)
            {
                return ptr;
            }
            ptr = ptr->next;
        }

        return nullptr;
    }
};
int main()
{
    List<int> list(120);
    list.push(10);
    list.push(20);
    list.push(11);
    list.push(21);

    list.print();
    cout << list.size() << "\n";
    cout << list.min() << "\n";
    cout << list.max() << "\n";

    // Node<int> *search = list.find(22);

    // list.pop();
    // list.print();
    // list.pop();
    // list.print();
    // list.pop();
    // list.print();
    // list.pop();
    // list.print();
}