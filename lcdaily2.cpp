#include <iostream>
using namespace std;

struct ListNode {
   int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head;
        ListNode* temp;
       

        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        if(temp1!= NULL && temp2 != NULL){
            int val = temp1->val + temp2->val + carry;
            if(val>9){
                carry = val%10;
                val = val/10;
            }
            ListNode* newNode = new ListNode(val);
            head = newNode;
            temp = newNode;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
            
        while(temp1!= NULL && temp2 != NULL){
            int val = temp1->val + temp2->val + carry;
            if(val>9){
                carry = val%10;
                val = val/10;
            }
            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = temp->next;

            temp1 = temp1->next;
            temp2 = temp2->next;


        }
        while(temp1!=NULL){
            int val = temp1->val + carry;
            if(val>9){
                carry = val%10;
                val = val/10;
            }
            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = temp->next;

            temp1 = temp1->next;

        }
        while(temp2!=NULL){
            int val = temp2->val + carry;
            if(val>9){
                carry = val%10;
                val = val/10;
            }
            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = temp->next;

            temp2= temp2->next ;
        }
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = temp->next;
        }

         return head;
    }

int main()
{
    int val = 10;
    int carry = 0;
    if(val>9){
        carry = val%10;
        val = val/10;
    }
    cout<<val<<" "<<carry<<endl;

    return 0;
}