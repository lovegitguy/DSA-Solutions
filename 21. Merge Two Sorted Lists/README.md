# LeetCode 21 — Merge Two Sorted Lists

## Problem

Given the heads of two sorted linked lists, merge them into one sorted linked list and return its head.

### Example

```text
Input:

list1 = 1 → 2 → 4
list2 = 1 → 3 → 4

Output:

1 → 1 → 2 → 3 → 4 → 4
```

## Approach

We use two pointers to compare the current nodes of both linked lists.

1. Create a `dummy` node to make building the result easier.
2. Compare the current values of `list1` and `list2`.
3. Attach the smaller node to the result.
4. Move the pointer of the list whose node was selected.
5. Move the result pointer forward.
6. When one list becomes empty, attach the remaining list.

## Code

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        if (list1 != nullptr)
            current->next = list1;
        else
            current->next = list2;

        return dummy.next;
    }
};
```

## Important Concepts

### `dummy` Node

A dummy node is used as a starting point for the merged list.

```cpp
ListNode dummy(0);
ListNode* current = &dummy;
```

It makes it easier to add the first node without handling a special case.

### `current`

`current` points to the last node of our merged list.

```cpp
current->next = list1;
```

This connects the selected node to the result.

### `nullptr`

Checks whether a linked-list pointer has reached the end.

```cpp
list1 != nullptr
```

### `->`

Used to access a member of a node through a pointer.

```cpp
list1->val
list1->next
```

## Complexity

Let:

* `n` = number of nodes in `list1`
* `m` = number of nodes in `list2`

Every node is visited at most once.

```text
Time:  O(n + m)
Space: O(1)
```

The existing nodes are reused, so no new linked list is created.

## What I Learned

* Linked lists
* Two pointers
* Comparing nodes
* Using a dummy node
* `nullptr`
* `->` operator
* Connecting nodes using `next`
* Traversing linked lists
* Time complexity `O(n + m)`
