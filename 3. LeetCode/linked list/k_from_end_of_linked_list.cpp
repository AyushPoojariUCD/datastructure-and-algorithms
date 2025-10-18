class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        if (head == NULL) return -1;

        Node *first = head, *second = head;

        // Move first pointer k steps ahead
        for (int i = 0; i < k; i++) {
            if (first == NULL) return -1; 
            // If k > length of list
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        // second now points to Kth node from the end
        return second->data;
    }
};
