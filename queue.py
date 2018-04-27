class Node(object):

    def __init__(self, data):
        self.data = data
        self.link = self


class Queue(object):

    def __init__(self):
        self.rear = None

    def enqueue(self, data):
        n = Node(data)  # new node
        if self.rear is not None:
            n.link = self.rear.link
            self.rear.link = n
        self.rear = n

    def dequeue(self):  # returns None or data
        if self.rear is None:
            return None
        n = self.rear.link
        if n == self.rear:
            self.rear = None
        else:
            self.rear.link = n.link
        return n.data

    def __iter__(self):
        if self.rear is not None:
            n = self.rear.link  # front
            yield n.data
            while n != self.rear:
                n = n.link
                yield n.data


if __name__ == '__main__':
    print('testing\nenqueue 1, 2, 3 into Queue')
    q = Queue()
    print('q.dequeue() new Queue()', q.dequeue())
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print('q.dequeue() -> ', q.dequeue())
    print('enqueue 4, 5')
    q.enqueue(4)
    q.enqueue(5)
    print('queue is now', list(q))
    print('loop dequeue till empty')
    while True:
        data = q.dequeue()
        print(data)
        if data is None:
            break
