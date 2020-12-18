/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* res = new ListNode;
        ListNode* cur = res;
        res -> val = 0;
        int flag = 0;  //表示进位
        while(l1||l2||flag){
            int temp = 0;
            if(l1!=nullptr) temp += l1->val;
            if(l2!=nullptr) temp += l2->val;
            temp = temp + flag;
            flag = temp/10;
            temp = temp%10;
            ListNode* nextn = new ListNode;
            nextn->val = temp;
            cur->next = nextn;
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return res->next;
    }
};
