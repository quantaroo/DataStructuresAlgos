#include "DblList.h"
#include "ListStack.h"
#include "ListQueue.h"
#include <iostream>
using namespace std;

int main(){
  DblList<char> myList;
  myList.addFront('a');
  myList.addFront('e');
  myList.addBack('c');
  myList.add(1,'b');
  myList.add(2,'q');
  myList.removeBack();
  myList.removeFront();
  myList.remove(1);
  cout << myList.get(1) << endl;
  cout << myList.contains('a') << endl;

  while(!myList.isEmpty()){
    char d = myList.removeFront();
    cout << d << endl;
  }
  cout << "======" << endl;
  ListStack<int> stack;
  stack.push(2);
  stack.push(4);
  while(!stack.isEmpty()){
    cout << stack.pop() << endl;
  }
}
