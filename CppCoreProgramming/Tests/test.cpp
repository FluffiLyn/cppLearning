#include <iostream>
template <typename T>
class singleList
{
public:
    singleList(): head(nullptr) {}
    ~singleList()
    {
        erase();
    }

    int size() const
    {
        int count = 0;
        Node* current = head;
        while(current)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void print() const
    {
        Node* current = this->head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool contains(const T& x) const
    {
        Node* current = head;
        while (current)
        {
            if (current->data == x)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool add(const T& x)
    {
        if(contains(x))
        {
            return false;
        }
        else
        {
            // 将新节点插入头节点的next位置
            // 形成一个头插法的单链表
            Node* newNode = new Node(x);
            newNode->next = head->next;
            head->next = newNode;
            _size++;
        }
        return true;
    }

    bool remove(const T& x)
    {
        if (!contains(x))
        {
            return false;
        }
        else 
        {
            Node* current = head->next;// 从头节点的next开始查找
            Node* prev = nullptr;
            while(current->data != x)
            {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            delete current;
            _size--;

            return true;
        }
    }

    void erase()// 将析构函数中的代码另作为一个函数
    {
        Node* current = head;
        while (current)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

private:
    struct Node
    {
        T _data;
        Node* next;
        Node(const T& data): _data(data), next(nullptr) {}
    };
    Node* head;
    int _size;
};