class Solution {
  public:
    int getCount(Node* head) {
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
};