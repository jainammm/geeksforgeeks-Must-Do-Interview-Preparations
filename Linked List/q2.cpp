// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    printf("%d", getNthFromLast(head, k));
    cout << endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n)
{
    Node *ref=head, *mainPtr=head;
    while(n!=0 && ref != NULL){
        ref = ref->next;
        n--;
    }
    if (n != 0){
        return -1;
    }
    while (ref != NULL)
    {
        ref = ref->next;
        mainPtr = mainPtr->next;
    }
    return mainPtr->data;
    
}
