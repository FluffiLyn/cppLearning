#include <iostream>
template<typename DataType>
struct Node
{
    DataType data;
    Node* child;
    Node* sibling;
};

template<typename DataType>
void traverse(Node<DataType>* node)
{
    if (node)
    {
        std::cout << node->data << std::endl;
        traverse(node->child);
        traverse(node->sibling);
    }
}