#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol19;

/*
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

tuple<Node *, int, string>
testFixture1()
{

  auto l = new Node(1);
  l->next = new Node(2);
  l->next->next = new Node(3);
  l->next->next->next = new Node(4);
  l->next->next->next->next = new Node(5);

  return make_tuple(l, 2, "1->2->3->5");
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see : " << get<2>(f) << endl;

  auto l = sol.removeNthFromEnd(get<0>(f), get<1>(f));
  string s;

  while (l != nullptr)
  {
    s += to_string(l->val) + "->";
    l = l->next;
  }

  if (s.back() == '>')
    s.pop_back(), s.pop_back();

  cout << s << endl;
}

main()
{
  test1();

  return 0;
}