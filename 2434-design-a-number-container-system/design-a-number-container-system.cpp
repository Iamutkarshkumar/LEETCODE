class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNumber.find(index) != indexToNumber.end()){
            int prevNum = indexToNumber[index];
            numberToIndices[prevNum].erase(index);
            if(numberToIndices[prevNum].empty()){
                numberToIndices.erase(prevNum);
            } 
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if(numberToIndices.find(number) != numberToIndices.end()){
            return *numberToIndices[number].begin();
        }
        return -1;
    }
    public:
        unordered_map<int,set<int>> numberToIndices;
        unordered_map<int,int> indexToNumber;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */