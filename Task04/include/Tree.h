#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Node.h"

using namespace std;

class Tree
{
  Node *root;

public:
  Tree()
  {
    root = NULL;
  }

  void Add(int data)
  {
    Node *node = new Node(data);

    if (root == NULL)
    {
      root = node;
    }
    else
    {
      Node *current = root, *parent;

      while (current != NULL)
      {
        parent = current;

        if (data > current->Data)
        {
          current = current->Right;
        }
        else
        {
          current = current->Left;
        }
      }

      if (data > parent->Data)
      {
        parent->Right = node;
      }
      else
      {
        parent->Left = node;
      }
    }
  }

  void Remove(int data)
  {
    Node *node = GetNodeByData(data);

    if (node == NULL)
      return;

    if (node == root)
    {
      if (root->Left == NULL && root->Right == NULL)
        root = NULL;
      else if (root->Right == NULL)
        root = root->Left;
      else if (root->Left == NULL)
        root = root->Right;
      else
      {
        Node *newRoot = root->Left;
        Node *maxRight = GetMaxRight(newRoot);
        maxRight->Right = root->Right;
        root = newRoot;
      }
    }
    else
    {
      Node *parent = GetParent(node);
      Node *newChild;

      if (node->Left == NULL && node->Right == NULL)
        newChild = NULL;
      else if (node->Right == NULL)
        newChild = node->Left;
      else if (node->Left == NULL)
        newChild = node->Right;
      else
      {
        Node *newParent = node->Left;
        Node *maxRight = GetMaxRight(newParent);
        maxRight->Right = node->Right;
        newChild = newParent;
      }

      if (parent->Left == node)
        parent->Left = newChild;
      else
        parent->Right = newChild;
    }

    delete node;
  }

  void Traverse()
  {
    Display(root);
  }

  int GetMaxDepth()
  {
    return GetMaxLevelRecursive(root);
  }

private:
  void Display(Node *node)
  {
    if (node == NULL)
      return;
    Display(node->Left);
    cout << node->Data << " ";
    Display(node->Right);
  }

  Node *GetNodeByData(int data)
  {
    Node *current = root;

    while (current != NULL)
    {
      if (data == current->Data)
        return current;
      if (data > current->Data)
        current = current->Right;
      else
        current = current->Left;
    }

    return NULL;
  }

  Node *GetParent(Node *node)
  {

    Node *current = root;

    while (current != NULL)
    {
      if (current->Right == node || current->Left == node)
        return current;

      if (node->Data > current->Data)
        current = current->Right;
      else
        current = current->Left;
    }

    return NULL;
  }

  Node *GetMaxRight(Node *node)
  {
    while (node->Right != NULL)
      node = node->Right;
    return node;
  }

  int GetMaxLevelRecursive(Node *node)
  {
    if (node == NULL)
      return -1; // Empty tree has no levels

    int leftDepth = GetMaxLevelRecursive(node->Left);
    int rightDepth = GetMaxLevelRecursive(node->Right);

    return Max(leftDepth, rightDepth) + 1;
  }

  int Max(int a, int b)
  {
      return a > b ? a : b;
  }
};

#endif // TREE_H
