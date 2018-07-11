#include <iostream>
#include <queue>
#include <stddef.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
  bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return NULL;
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    for (ListNode *node : lists) {
      if (node != NULL)
        pq.push(node);
    }
    if (pq.empty())
      return NULL;
    ListNode *head = pq.top();
    pq.pop();
    if (head->next != NULL)
      pq.push(head->next);
    ListNode *p = head;
    while (!pq.empty()) {
      p->next = pq.top();
      pq.pop();
      p = p->next;
      if (p->next != NULL)
        pq.push(p->next);
    }
    return head;
  }
};
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}
string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(){
  string s1 = "[1,4,5]";
  string s2 ="[1,3,4]";
  string s3="[2,6]";
  vector<ListNode*> lists;
  lists.push_back(stringToListNode(s1));
  lists.push_back(stringToListNode(s2));
  lists.push_back(stringToListNode(s3));
  cout<<listNodeToString(Solution().mergeKLists(lists))<<endl;
}
