Brute Force approach:

We have to move the last element to first for each k.
For each k, find the last element from the list. Move it to the first.

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
        }
};
//utility function to insert node at the end of the list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}
//utility function to rotate list by k times
node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
//utility function to print list
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}

int main() {
    node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    int k = 2;
    node* newHead = rotateRight(head,k);//calling function for rotating right of 
    the nodes by k times
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);//list after rotating nodes
    return 0;
}

//Optimised approach
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Find the length of the linked list
        ListNode *current = head;
        int length = 0;
        while (current->next != nullptr) {
            length++;
            current = current->next;
        }

        // Make the last node point to the head of the linked list
        current->next = head;

        // If k is greater than the length of the linked list
        k = k % (length + 1); // Update to (length + 1) to consider the original length

        // Calculate the position to break the circular link
        int end = length - k;

        current = head;
        // Traverse to the node before the new head
        while (end--) {
            current = current->next;
        }

        // Break the circular link and update the new head
        head = current->next;
        current->next = nullptr;

        return head;
    }
};
