#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol19;
using namespace std;

/*takeaways
  - have a pointer (fast) n+1 steps of another pointer (prev)
  - when faster walks past the tail and becomes a nullptr
    prev will point at the node before the node you
    want to delete
  - delete the node by cutting it off from the list
  - you need a dummy node as we might need to delete the
    head
*/

Node *Solution::removeNthFromEnd(Node *head, int n)
{
  /* need a dummy node to make the deletion possible
     - its next is the node to be deleted
     - yes we might need to delete the head
  */
  auto dummy = new Node(-1);
  dummy->next = head;
  auto fast = head;
  for (auto i = 0; i < n; i++)
    fast = fast->next;
  auto prev = dummy;

  /* prev needs to be n+1 away from fast as we are deleting
     prev's next not prev
  */
  while (fast != nullptr)
    prev = prev->next, fast = fast->next;

  auto node = prev->next;

  /* delete the node */
  prev->next = prev->next->next;
  delete node;

  return dummy->next;
}
