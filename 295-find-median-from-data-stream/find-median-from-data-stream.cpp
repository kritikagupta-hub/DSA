class MedianFinder {
public:
    
    // Max Heap -> stores smaller half of numbers
    priority_queue<int> maxHeap;

    // Min Heap -> stores larger half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Constructor
    MedianFinder() {
        
    }
    
    // Function to add number into the stream
    void addNum(int num) {
        
        // Step 1: Insert element into appropriate heap
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        // Step 2: Balance the heaps
        // Size difference should not be more than 1
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    // Function to return median of current stream
    double findMedian() {
        
        // Case 1: Both heaps have equal size
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // Case 2: maxHeap has one extra element
        return maxHeap.top();
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */