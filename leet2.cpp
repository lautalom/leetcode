#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode preNode(-1), *p = &preNode, *h = l1, *i = l2;
        int carry = 0, sum;

        while (h || i || carry)
        { //you could optimize by remembering if either h or i has no more elems
            sum = (h ? h->val : 0) + (i ? i->val : 0) + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;

            p = p->next;
            h = h ? h->next : h;
            i = i ? i->next : h;
        }
        return preNode.next;
    }
};

int main()
{
    Solution obj1;
    ListNode *head, *second, *third;
    ListNode *headd, *secondd, *thirdd;

    // allocate 3 ListNodes in the heap
    third = new ListNode(3);
    second = new ListNode(4, third);
    head = new ListNode(2, second);
    // l1 = [2,4,3], l2 = [5,6,4], output =[7,0,8]?
    thirdd = new ListNode(4);
    secondd = new ListNode(6, thirdd);
    headd = new ListNode(5, secondd);
    printf("[");
    for (ListNode *it = (obj1.addTwoNumbers(head, headd)); it != NULL; it = it->next)
    {
        printf("%d", it->val);
        if (it->next != NULL)
        {
            printf(",");
        }
    }
    printf("]\n");
    return 0;
}