package main

import "fmt"
import "errors"

// Ouroboros Queue Go implementation

type Node struct {
    link *Node
    data  interface{}
}

type Queue struct {
    rear *Node
}

func (q *Queue) EnQueue(data interface{}) {
    n := &Node{
        link: nil,
        data: data,
    }
    if q.rear == nil {
        n.link = n  // point to self
    } else {
        n.link = q.rear.link // point new rear to front
        q.rear.link = n // old rear points to new rear
    }
    q.rear = n
}

func (q *Queue) DeQueue() (*interface{}, error) {
    if q.rear == nil {
        return nil, errors.New("empty Qeue")
    }
    front := q.rear.link
    if front.link == front {
        q.rear = nil
    } else {
        q.rear.link = front.link
    }
    return &front.data, nil
}

func (q *Queue) DisplayQueue() {
    if q.rear == nil {
        return
    }
    n := q.rear.link // front
    fmt.Printf("Elements in Circular Queue are: ")
    fmt.Printf("%+v ->", n.data)
    for n != q.rear {
        n = n.link
        fmt.Printf("%+v ->", n.data)
    }
    fmt.Println()
}


// test it
func main() {
    // Create a queue and initialize front and rear
    fmt.Printf("testing\nenqueue 1, 2, 3 into Queue\n");
    
    q := Queue{}
    q.EnQueue(1)
    q.EnQueue(2)
    q.EnQueue(3)
    data, error := q.DeQueue()
    if error != nil {
       fmt.Printf("Queue is empty in error")
       return
    }
    fmt.Printf("q.DeQueue() -> %+v\n", *data)
    q.DisplayQueue()

    fmt.Printf("enqueue 4, 5\n");
    q.EnQueue(4)
    q.EnQueue(5)
    
    q.DisplayQueue()

    fmt.Printf("loop DeQueue till empty\n");
    for {
        data, error := q.DeQueue()
        if error != nil {
            break
        }
        fmt.Printf("%+v\n", *data)
    }
    
}