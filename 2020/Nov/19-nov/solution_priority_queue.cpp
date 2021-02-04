#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void add(int val)
    {
        while (next)
        {
            next = next->next;
        }
        next = new ListNode(val);
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    auto new_list = new ListNode();
    auto pointer = new_list;
    // This comparator will be used to build minheap.
    auto comp = [&](ListNode *a, ListNode *b) {
        return a->val > b->val;
    };

    // This priority queue is the min heap
    std::priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> p_queue(comp);

    for (auto list : lists)
    {
        if (list)
        {
            p_queue.push(list);
        }
    }
    while (not p_queue.empty())
    {
        pointer->next = p_queue.top();
        p_queue.pop();
        pointer = pointer->next;
        auto next_in_list = pointer->next;
        if (next_in_list)
            p_queue.push(next_in_list);
    }
    return new_list->next;
}

int main()
{
    size_t count{4};
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(2);
    for (size_t i = 1; i != count; i++)
    {
        l1->add(i);
        l2->add(count + i);
    }
    std::vector<ListNode *> vec = {l1, l2};
    for (auto list : vec)
    {
        while (list)
        {
            std::cout << list->val << " ";
            list = list->next;
        }
        std::cout << std::endl;
    }
    auto result = mergeKLists(vec);
    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
}