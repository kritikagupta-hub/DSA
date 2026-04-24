class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /*vector<int> row(1,1);

        for(int i=0;i<rowIndex;i++){
            vector<int> newR;
            newR.push_back(1);
            for(int j=1;j<row.size();j++){
                newR.push_back(row[j-1]+row[j]);
            }
            newR.push_back(1);
            row=newR;
        }
        return row;*/
        vector<int> arr(rowIndex+1);
        long long val=1;
        for(int i=0;i<=rowIndex;i++){
            arr[i] = val;
            val = val*(rowIndex-i)/(i+1); 
        }
        return arr;
    }
};