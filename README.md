# Ouroboros_Queue
Ouroboros Queue: Circular Single Linked Queue Structure

Code/Slide Show demonstrating the circular single linked Queue Structure in Python, GoLang, and C.

I named this structure an Ouroboros Queue (classic serpent eating its tail in circle) due to the Queue object field tail pointing to the head rather than the normal method of keeping both a head and tail pointer in the Queue object.

A Queue is the name of a data stucture that allows you to add items to a front and remove them from the rear of a list (First in First Out, or FIFO), they are kept in order of arrival. 

There are several ways to implement a Queue such a a ring buffer that uses an array or a single or double liked list. 

A great example of use of Queue on every computer is the keyboard queue that delivers the keys you type to the program in the correct order even when the program falls behind on reading the keys.

Most linked list implementations keep a two points into the list, the head and the tail pointer. This implementation only keeps a pointer to the tail and the node at the tail of the queue points to the head. My name for this is a Ouroboros Queue.

![Ouroboros Queue](https://github.com/gerryjenkinslb/Ouroboros_Queue/blob/master/OuroborosDiagram.svg)

[Code Walkthough on my Youtube Channel](https://youtu.be/rGgn-OUeZy8)
