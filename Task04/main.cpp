#include <iostream>

#include "Tree.h"

using namespace std;

int main()
{
  Tree tree;

  tree.Add(5);
  tree.Add(3);
  tree.Add(7);
  tree.Add(2);
  tree.Add(4);
  tree.Add(6);
  tree.Add(8);
  tree.Add(9);

  cout << "Max Level: " << tree.GetMaxDepth() << endl;

  return 0;
}
