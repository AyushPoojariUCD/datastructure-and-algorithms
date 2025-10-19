class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        // Step 1: Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;

        // Step 2: Add digits one by one
        while (head1 != NULL || head2 != NULL || carry != 0) {
            int sum = carry;

            if (head1 != NULL) {
                sum += head1->data;
                head1 = head1->next;
            }

            if (head2 != NULL) {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            temp->next = new Node(digit);
            temp = temp->next;
        }

        // Step 3: Reverse the final list
        Node* result = reverse(dummy->next);

        // Step 4: Remove leading zeros if any
        while (result && result->data == 0 && result->next) {
            result = result->next;
        }

        return result;
    }
};
