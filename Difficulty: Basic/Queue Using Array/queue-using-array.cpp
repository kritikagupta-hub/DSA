class myQueue {
    int *arr;
    int front;
    int rear;
    int cap; // internal capacity = user_capacity + 1

  public:
    // n = user requested capacity
    myQueue(int n) {
        cap = n + 1;            // one slot wasted to distinguish full/empty
        arr = new int[cap];
        front = 0;
        rear = 0;
    }

    ~myQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return ( (rear + 1) % cap ) == front;
    }

    // Returns true if enqueue succeeded, false if queue was full
    bool enqueue(int x) {
        if (isFull()) {
            return false;
        }
        arr[rear] = x;
        rear = (rear + 1) % cap;
        return true;
    }

    // Returns dequeued value, or -1 if empty
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int ans = arr[front];
        front = (front + 1) % cap;
        // optional reset (not necessary but keeps indices small)
        if (front == rear) {
            front = 0;
            rear = 0;
        }
        return ans;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        int idx = (rear - 1 + cap) % cap; // last valid element
        return arr[idx];
    }
};