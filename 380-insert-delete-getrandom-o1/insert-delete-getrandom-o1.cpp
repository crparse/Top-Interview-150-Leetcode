#include <vector>
#include <unordered_map>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class RandomizedSet {
private:
    std::unordered_map<int, int> indexToValue;
    std::vector<int> values;                   
    int size;                                 
public:
    RandomizedSet() {
        srand(time(NULL));
        size = 0; 
    }
    
    bool insert(int val) {
        if (indexToValue.find(val) != indexToValue.end()) 
            return false;

        // Add value to vector and update index in map
        values.push_back(val);
        indexToValue[val] = size;
        size++;
        
        return true;
    }
    
    bool remove(int val) {
        if (indexToValue.find(val) == indexToValue.end()) // If value doesn't exist
            return false;

        // Get the index of the value to be removed
        int indexToRemove = indexToValue[val];
        // Move the last element to the position of the element to be deleted
        int lastVal = values.back();
        values[indexToRemove] = lastVal;
        indexToValue[lastVal] = indexToRemove;

        // Erase the last element
        values.pop_back();
        indexToValue.erase(val);
        size--;
        
        return true;
    }
    
    int getRandom() {
        // Generate a random index within the range of the current size
        int randomIndex = rand() % size;
        
        // Return the value at the random index
        return values[randomIndex];
    }
};
