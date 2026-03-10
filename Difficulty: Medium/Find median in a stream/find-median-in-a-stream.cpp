class Solution {
public:

    // Function to check size relation between two heaps
    // returns:
    // 0  -> both heaps equal size
    // 1  -> maxHeap bigger
    // -1 -> minHeap bigger
    int signum(int a,int b){
        if(a==b){
            return 0;
        }
        else if(a>b){
            return 1;
        }
        else{
            return -1;
        }
    }

    // Function to insert a new element into stream
    // and update median accordingly
    void make_stream(int element,
                     priority_queue<int> &maxHeap, // left half (smaller elements)
                     priority_queue<int,vector<int>,greater<int>> &minHeap, // right half (larger elements)
                     double &median){

        int size = maxHeap.size();
        int size1 = minHeap.size();

        // check size relation between heaps
        switch(signum(size,size1)){

            // CASE 1: Both heaps are of equal size
            case 0 :

                // if element greater than median → goes to right half
                if(element>median){
                    minHeap.push(element);
                    median = minHeap.top();   // median becomes smallest of right half
                }
                else{
                    // otherwise goes to left half
                    maxHeap.push(element);
                    median = maxHeap.top();   // median becomes largest of left half
                }
                break;

            // CASE 2: maxHeap has more elements
            case 1:

                // if element belongs to right half
                if(element>median){
                    minHeap.push(element);
                }
                else{
                    // balance heaps by moving top of maxHeap to minHeap
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();

                    // insert new element in maxHeap
                    maxHeap.push(element);
                }

                // median is average of two middle elements
                median = (maxHeap.top()+minHeap.top())/2.0;
                break;

            // CASE 3: minHeap has more elements
            case -1:

                // if element belongs to right half
                if(element>median){
                    // move smallest of right half to left
                    maxHeap.push(minHeap.top());
                    minHeap.pop();

                    // insert new element in right half
                    minHeap.push(element);
                }
                else{
                    // directly insert in left half
                    maxHeap.push(element);
                }

                // median becomes average of two middle values
                median = (maxHeap.top()+minHeap.top())/2.0;
                break;
        }
    }

    // Main function
    vector<double> getMedian(vector<int> &arr) {

        vector<double> ans;

        // maxHeap → stores smaller half
        priority_queue<int> maxHeap;

        // minHeap → stores larger half
        priority_queue<int,vector<int>,greater<int>> minHeap;

        double median = 0.0;

        // process each element of stream
        for(int i = 0;i<arr.size();i++){

            int element = arr[i];

            // insert element and update median
            make_stream(element,maxHeap,minHeap,median);

            // store current median
            ans.push_back(median);
        }

        return ans;
    }
};
