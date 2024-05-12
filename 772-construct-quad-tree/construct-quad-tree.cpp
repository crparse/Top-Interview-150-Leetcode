/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructHelper(grid, 0, 0, grid.size());
    }
    
    Node* constructHelper(vector<vector<int>>& grid, int x, int y, int size) {
        if (size == 0) return nullptr;
        
        if (size == 1) return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
        
        
        if (isLeaf(grid, x, y, size)) return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
        
        
        int newSize = size / 2;
        Node* topLeft = constructHelper(grid, x, y, newSize);
        Node* topRight = constructHelper(grid, x, y + newSize, newSize);
        Node* bottomLeft = constructHelper(grid, x + newSize, y, newSize);
        Node* bottomRight = constructHelper(grid, x + newSize, y + newSize, newSize);
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    bool isLeaf(vector<vector<int>>& grid, int x, int y, int size) {
        int val = grid[x][y];
        for (int i = x; i < x + size; ++i) {
            for (int j = y; j < y + size; ++j) {
                if (grid[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }
};
