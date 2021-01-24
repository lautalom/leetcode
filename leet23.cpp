#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void debug(ListNode *ans)
{
    ListNode *it = ans;
    int i = 0;
    while (it != nullptr)
    {
        cout << it->val << ' ';
        if (!it->next)
            cout << '\n';
        it = it->next;
    }
}
//own answer, top 96.9% runtime
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<int> j;
        ListNode *ans = nullptr;
        bool fst = 0;
        if (!lists.size())
            return ans;
        for (auto &a : lists)
        {
            ListNode *it = a;
            //using constraint of value for case [{},{1}], reading a nullptr val
            while (it != nullptr && abs(it->val) <= 10000)
            {
                //store all elems in priority queue
                j.push(it->val);
                it = it->next;
            }
        }
        while (!j.empty())
        { //building the linked list from biggest to smallest elem
            ListNode *m = new ListNode(j.top());
            m->next = ans;
            ans = m;
            j.pop();
        }
        debug(ans);
        return ans;
    }
};

//////////less memory
class Solution2
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL;
        ListNode *ptr = head;

        while (true)
        {
            int smallestIndex = -1;
            int smallestVal = INT_MAX;

            for (int i = 0; i < lists.size(); ++i)
            {
                if (lists[i] != NULL)
                {
                    if (smallestVal >= lists[i]->val)
                    {
                        smallestVal = lists[i]->val;
                        smallestIndex = i;
                    }
                }
            }

            if (smallestIndex >= 0)
            {
                if (!head)
                {
                    head = lists[smallestIndex];
                    ptr = head;
                }
                else
                {
                    ptr->next = lists[smallestIndex];
                    ptr = ptr->next;
                }
                lists[smallestIndex] = lists[smallestIndex]->next;
            }
            else
            {
                break;
            }
        }

        return head;
    }
};
int main()
{
    Solution q;
    ListNode *a = new ListNode(5), *b = new ListNode(6), *c = new ListNode(7);
    ListNode *d = new ListNode(5), *e = new ListNode(6), *f = new ListNode(7);
    ListNode *m, *n = new ListNode(6);
    a->next = b;
    b->next = c;
    d->next = e;
    e->next = f;
    vector<ListNode *> t = {m, n};
    q.mergeKLists(t);
    return 0;
}