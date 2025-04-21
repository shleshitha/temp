class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertAtHead(self, head, val):
        new_node = ListNode(val)
        new_node.next = head
        return new_node
