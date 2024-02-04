Step 1.)Create Exact Duplicate Nodes:
  1.1Iterate through the original linked list.
  1.2 For each node in the original linked list, create a new node with the same value.
  1.3 During this process, maintain a mapping between the original nodes and their corresponding duplicate nodes using a hashmap. This hashmap will be used to link the original and duplicate nodes.
  1.4 Create Hashmap with Original and Duplicate Nodes:
  1.5 As you create duplicate nodes in the previous step, store each original node as a key and its corresponding duplicate node as the value in the hashmap.
Step 2.)Set Pointers Using Hashmap:
  1. Iterate through the original linked list again.
  2. For each node in the original linked list:
     2.a Retrieve the corresponding duplicate node from the hashmap using the original node as the key.
     2.b Set the next pointer of the duplicate node by looking up the next node of the original node in the hashmap.
      2.c Set the random pointer of the duplicate node by looking up the random node of the original node in the hashmap.

  Time complexity and space complexity is : O(n)

  #include <iostream>
#include <unordered_map>

using namespace std;

// Node structure for the linked list
struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int value) : val(value), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) {
        return nullptr;
    }

    // Step 1: Create Exact Duplicate Nodes
    unordered_map<Node*, Node*> originalToCopied;  // Hashmap to store mapping between original and copied nodes
    Node* current = head;

    while (current) {
        // Create a new node with the same value
        Node* copiedNode = new Node(current->val);

        // Maintain mapping in the hashmap
        originalToCopied[current] = copiedNode;

        current = current->next;
    }

    // Step 2: Set Pointers Using Hashmap
    current = head;

    while (current) {
        // Retrieve corresponding duplicate node from the hashmap
        Node* copiedNode = originalToCopied[current];

        // Set next pointer
        copiedNode->next = originalToCopied[current->next];

        // Set random pointer
        copiedNode->random = originalToCopied[current->random];

        current = current->next;
    }

    // Return the head of the copied linked list
    return originalToCopied[head];
}

// Example usage:
int main() {
    // Construct the original linked list
    Node* originalHead = new Node(7);
    originalHead->next = new Node(13);
    originalHead->next->next = new Node(11);
    originalHead->next->next->next = new Node(10);
    originalHead->next->next->next->next = new Node(1);

    // Set random pointers
    originalHead->random = originalHead->next->next;
    originalHead->next->random = originalHead;
    originalHead->next->next->next->random = originalHead->next->next;
    originalHead->next->next->random = originalHead->next->next->next->next;
    originalHead->next->next->next->next->random = originalHead;

    // Copy the linked list
    Node* copiedHead = copyRandomList(originalHead);

    // Add any further processing or printing of the copied linked list if needed

    return 0;
}
