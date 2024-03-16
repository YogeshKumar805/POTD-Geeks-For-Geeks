# POTD-Geeks-For-Geeks
Geeks For Geeks Repository
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/


class Solution
{
    public:
    void deleteNode(Node *del_node)
    {
        del_node->data = del_node->next->data;
        del_node->next = del_node->next->next;
    }
};
