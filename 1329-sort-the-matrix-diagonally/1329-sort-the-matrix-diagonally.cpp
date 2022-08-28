class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        // Our idea is create min priority_queue(min heap) for each diagonal
        // And How to store the min_heap for each diagonal. So we know that all element in diagonal of matrix have same i-j value. So we can store in unordered_map 
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> umap;

        // iterating through each cell
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                umap[i-j].push(mat[i][j]); // Pushing item in min priority_queue. So top element will be smallest in that diagonal. and adding priority queue to map with key i-j
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mat[i][j] = umap[i-j].top();
                umap[i-j].pop();// after poping out smallest. If we have more element in that priority queue then we again get new smallest at the top of min priority_queue because  of heapify.
            }
        }
        return mat;
    }
};