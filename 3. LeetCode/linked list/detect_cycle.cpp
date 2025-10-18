class Solution {
  public:
    bool detectLoop(Node* head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        Node *slow = head, *fast = head;

        // Move slow by one and fast by two
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // If they meet, there is a loop
            if (slow == fast)
                return true;
        }

        // If fast reaches NULL, there’s no loop
        return false;
    }
};
