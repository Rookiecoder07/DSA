#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list
// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {

    // Create a dummy node to make it easier to build the result list
    ListNode dummy(0);
    ListNode* tail = &dummy; // Points to the last node in the merged list

    // Define how the priority queue (min-heap) should compare two ListNodes
    auto compare = [](ListNode* a, ListNode* b) {
      return a->val > b->val; // smallest value will be on top
    };

    // Create a min-heap that stores ListNode pointers
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

    // Step 1: Put the first node of each list into the min-heap
    for (ListNode* list : lists) {
      if (list != nullptr)
        minHeap.push(list);
    }

    // Step 2: Keep removing the smallest element and add it to the merged list
    while (!minHeap.empty()) {
      // Get the node with the smallest value
      ListNode* smallest = minHeap.top();
      minHeap.pop();

      // Add this node to our result list
      tail->next = smallest;
      tail = tail->next;

      // If the smallest node has a next node, add it to the heap
      if (smallest->next != nullptr)
        minHeap.push(smallest->next);
    }

    // Step 3: Return the merged list (skipping the dummy head)
    return dummy.next;
  }
};
