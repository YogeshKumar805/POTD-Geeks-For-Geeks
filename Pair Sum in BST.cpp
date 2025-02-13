class Solution {
  public:
    unordered_map<int,bool>map;
    bool findTarget(Node *root, int target) {
        // your code here.
        if(root == NULL) return false;
        if(map.find(target - root -> data) != map.end()) return true;
        map[root -> data] = true;
        return findTarget(root -> left , target) || findTarget(root -> right , target);
    }
};
