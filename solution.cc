// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        return helper(head, NULL);
    }
    
    TreeNode *helper(ListNode *head, ListNode *end) {
        if(!head) return NULL;
        if(head == end) return NULL;
        ListNode *runner = head, *walker = head;
        while(runner != end && runner->next != end) {
            runner = runner->next->next;
            walker = walker->next;
        }
        TreeNode *root = new TreeNode(walker->val);
        root->left = helper(head, walker);
        root->right = helper(walker->next, end);
        return root;
    }
   
};
