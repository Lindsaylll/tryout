



// some notes


#include <iostream>
using namespace std;
// class List {
//   struct Node; // private nested class
//   Node *theList = nullptr;
//   public:
//   void addToFront(int n);
//   int ith(int i);
//   ~List();
// }
// ======================================================================================

// list.cc
// ======================================================================================
// struct List::Node { 
// 	// since it is already an instance of a private class, 
//   // we make everything inside Node public so List can have access to it
//   int data;
//   Node *next;
//   Node(int d, Node* n) : data{d}, next{n}{} 
//   ~Node() { delete next; };
// };

struct Node {
  int data;
  Node *next;
  Node(int, Node*);
  ~Node() { delete next; }
};






class List {
  struct Node;
  Node *theList = nullptr;
  public:

    class Iterator {
      Node *curr;
      public:
        explicit Iterator(Node *n) : curr{n} {}
        int &operator*() { return curr->data; } // reference is used to allow updating

        Iterator &operator++() { // unary PREFIX (i.e. ++p)
          curr = curr->next;
          return *this;
        }

        // If we instead wanted to implement the postfix operator, we use a dummy int:
        Iterator &operator++(int x) { // POSTFIX increment
          curr = curr->next;
          return *this;
        }

        bool operator!=(const Iterator &other) {
           return curr != other.curr;
        }
    }; // End of the iterator
  // Now for some List methods:
  Iterator begin() { return Iterator{theList}; }
  Iterator end() { return Iterator{nullptr}; }
  void addToFront(int n);
  ~List();

}; // End the list

List::~List() {
  delete theList;
}


void List::addToFront(int n) {
  theList = new Node{n, theList};
}

// Now, we can implement the client:
int main(void) {
  using namespace std;
  List l;
  l.addToFront(3);
  l.addToFront(2);
  l.addToFront(1); // [1|-]--> [2|-]--> [3|/]
  for (List::Iterator it = l.begin(); it != l.end(); ++it) {
  // for (auto it = l.begin(); ~~~) {
    cout << *it << endl;
    // *it = ~~~; // Make any necessary modifications
  }
}
