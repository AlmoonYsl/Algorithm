/**
 * leetcode no.501
 */
 
int num;
int maxCount;
TreeNode* pre;
vector<int> result;

void searchBST(TreeNode* cur) {
    if (cur == nullptr) return;
    searchBST(cur->left);
    if (pre == nullptr) {
        num = 1;
    } else if (pre->val == cur->val) {
        num++;
    } else {
        num = 1;
    }
    pre = cur;

    if (num == maxCount) {
        result.push_back(cur->val);
    }

    if (num > maxCount) {
        maxCount = num;
        result.clear();
        result.push_back(cur->val);
    }
    searchBST(cur->right);
}

vector<int> findMode(TreeNode* root) {
    result.clear();
    searchBST(root);
    return result;
}