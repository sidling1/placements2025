# There are different types of queues:
- Simple Queue: Simple Queue simply follows FIFO Structure. We can only insert the element at the back and remove the element from the front of the queue.
- Double-Ended Queue (Dequeue): In a double-ended queue the insertion and deletion operations, both can be performed from both ends. They are of two types:
    - Input Restricted Queue: This is a simple queue. In this type of queue, the input can be taken from only one end but deletion can be done from any of the ends.
    - Output Restricted Queue: This is also a simple queue. In this type of queue, the input can be taken from both ends but deletion can be done from only one end.
- Circular Queue: This is a special type of queue where the last position is connected back to the first position. Here also the operations are performed in FIFO order.
- Priority Queue: A priority queue is a special queue where the elements are accessed based on the priority assigned to them. They are of two types:
- Ascending Priority Queue: In Ascending Priority Queue, the elements are arranged in increasing order of their priority values. Element with smallest priority value is popped first.
- Descending Priority Queue: In Descending Priority Queue, the elements are arranged in decreasing order of their priority values. Element with largest priority is popped first.

# Dequeue
- emplace_front(): Insert a new element at the front of the deque. It is similar to the insert operation, but it avoids the copy constructor of the element being inserted.
emplace_back(): Insert a new element at the back of the deque. It is similar to the insert operation, but it avoids the copy constructor of the element being inserted.

https://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

- It is frequently used in  sliding window problems (hard)

LRU Cache, Round Robin Scheduling, Expression Evaluation.

# Priority Queue

- https://www.geeksforgeeks.org/nearly-sorted-algorithm/
- https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
