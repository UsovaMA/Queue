#ifndef __QUEUE_H_
#define __QUEUE_H_

struct TNode {
  int data;
  TNode *next;
  TNode *prev;
};

class Tqueue {
  TNode *s;
  TNode *f;
  int qsize;

 public:
  Tqueue() {
    qsize = 0;
  }

  bool IsEmpty() {
    return (qsize == 0);
  }

  void push(int d) {
    TNode *node = new TNode;
    node->data = d;
    if (IsEmpty()) {
      f = node;
      f->next = f;
      f->prev = f;
      s = f;
    } else {
      f->next = node;
      node->next = s;
      node->prev = f;
      f = node;
    }
    qsize++;
  }

void pop() {
  TNode* buf = s;
  s = s->next;
  delete buf;
  qsize--;
}

  int front() {
    return s->data;
  }

  int back() {
    return f->data;
  }

  int size() {
    return qsize;
  }
};
#endif