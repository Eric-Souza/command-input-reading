#include <cstddef>
#include <iostream>

#include <LinkedQueue.hpp>

using std::cout;
using std::endl;

// Linked queue FIFO logic implementation
LinkedQueue::LinkedQueue() : Queue()
{
  queueFront = new Cell();
  queueBack = queueFront;
}

void LinkedQueue::Enqueue(int item)
{
  Cell *new;
  new = new Cell();

  new->item = item;
  queueBack->next = new;
  queueBack = new;

  queueSize++;
}

int LinkedQueue::DesEnqueue()
{
  Cell *p;
  int auxVar;

  if (queueSize == 0)
  {
    throw "The queue is empty";
  }

  auxVar = queueFront->next->item;
  p = queueFront;
  queueFront = queueFront->next;

  delete p;
  queueSize--;

  return auxVar;
}

void LinkedQueue::Remove(int position)
{
  Cell *p = queueFront->next;
  Cell *auxVar = queueFront;

  int i = 0;

  while (i <= position)
  {
    if (i == position)
    {
      auxVar->next = p->next;
      p->next = NULL;
      delete p;
      queueSize--;

      if (p == queueBack)
      {
        queueBack = auxVar;
      }

      break;
    }

    i++;
    auxVar = auxVar->next;
    p = p->next;
  }
}

void LinkedQueue::Print()
{
  Cell *p;
  p = queueFront->next;

  while (p != NULL)
  {
    cout << p->item << endl;
    p = p->next;
  }
}