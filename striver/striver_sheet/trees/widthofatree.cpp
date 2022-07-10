 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
  
  if (!root)
    return 0;
  unsigned long long int ans = 0;
  queue < pair < TreeNode * , unsigned long long int >> q;
  q.push({
    root,
    0
  });
  while (!q.empty()) {
    int size = q.size();
    unsigned long long int curMin = q.front().second;
    unsigned long long int leftMost, rightMost;
    for (int i = 0; i < size; i++) {
      unsigned long long int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      TreeNode * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp -> left)
        q.push({
          temp -> left,
          cur_id * 2 + 1
        });
      if (temp -> right)
        q.push({
          temp -> right,
          cur_id * 2 + 2
        });
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;


    
    
    }
};