class Solution {
  public:
    void removeLoop(Node* head) {
        if (head == NULL || head->next == NULL) 
            return;

        Node *slow = head, *fast = head;

        // Step 1: Detect loop using Floyd’s algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)  // Loop detected
                break;
        }

        // If no loop
        if (slow != fast) 
            return;

        // Step 2: Find the start of the loop
        slow = head;

        // Special case: when the loop starts at head
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } 
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Break the loop
        fast->next = NULL;
    }
};
