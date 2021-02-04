/// MERGE K LISTS ///

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

/*
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output:
[1->1->2->3->4->4->5->6]


Input: lists = []
Output: []

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
lists[i] is sorted in ascending order.

Answers:

Time: O(nlogn)
Space:  O(n)


Time: O(nlogk) or O(kN)
Space: O(k) or O(1)

*/
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class ListNode {
public:
	int value;
	ListNode *next;
	ListNode() : value(0), next(nullptr) {}
	ListNode(int x) : value(x), next(nullptr) {}
	ListNode (vector<int>&values){
		ListNode* node = this;
		for (size_t i {}; i < values.size(); i++){
			node->value = values[i];
			if (i != values.size()-1){
				node->next = new ListNode();
				node = node->next;
			}	
		}
	}

	friend bool operator< (const ListNode &node_1, const ListNode &node_2)
	{
	    return node_1.value < node_2.value;
	}

	void print(){
		ListNode* node = this;
		while (node){
			cout << node->value << " ";
			node = node->next;
		}
		cout << endl;
	}
};

struct comp{
	bool operator()(ListNode *a, ListNode *b){
		return a->value > b->value;
	}  
};

ListNode* group_1(vector<ListNode*>& lists) {
}

ListNode* group_2(vector<ListNode*>& lists) {
	priority_queue<ListNode*, vector<ListNode*>, comp > pq;
	for (auto& node : lists){
		if (node){
			pq.push(node);
		} 
	}
	if(pq.empty()){
		return NULL;
	}

	auto res_head = pq.top();
	cout << res_head->value << endl;
	auto res_tail = res_head;
	pq.pop();
	if (res_head->next){
		pq.push(res_head->next);
	}

	while (!pq.empty()){
		res_tail->next = pq.top();
		res_tail = res_tail->next;
		pq.pop();
		if (res_tail->next){
			pq.push(res_tail->next);
		}
	}

	return res_head;
}

int main(){
	vector<int> val_1 {1,3,4,5,6};
	vector<int> val_2 {3,5,7,10,16};
	ListNode list_1(val_1);
	ListNode list_2(val_2);
	vector<ListNode*> problem {&list_1,&list_2};
	problem[0]->print();
	problem[1]->print();
	auto res = mergeKLists(problem);
	res->print();
}