class Solution {
  public:
    vector<int> printList(Node *head) {
        vector<int> ans;
        while(head){
            ans.push_back(head->data);
            head = head->next;
        }
        return ans;
    }
};