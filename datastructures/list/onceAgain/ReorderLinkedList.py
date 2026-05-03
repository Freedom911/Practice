
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def findHalf(self,head: ListNode) -> ListNode:
        fast = head
        slow = head
        prev = None

        while fast != None and fast.next != None:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        # We sever the connection
        if prev:
            prev.next = None
        return slow
    
    def reverse(self,head:ListNode) ->ListNode:
        if head == None:
            return None
        nextNode = None
        prevNode = None
        
        while head:
            nextNode = head.next
            head.next = prevNode
            prevNode = head
            head = nextNode
        
        return prevNode

    def reorderList(self, head: ListNode) -> None:

        if head is None or head.next is None:
            return

        #1st Find the Half
        half = self.findHalf(head)

        #2nd Reverse Half Position
        revHead = self.reverse(half)
 

        #3rd Keep the Head Pointer and Insert Node in odd position
        n2 = None
        n1 = None
        while revHead and head:
            n2 = revHead.next
            n1 = head.next

            head.next = revHead
            # Edge case if head is smaller
            # then head->next will be null
            # so we will be joining revHead->next = none so it will skip the last iteration
            # 1-2-3-4-5
            # first half 1-2 second will be 5-4-3 after reversal
            # so 4->next will be none so it will skipp the 3rd. so in the last case
            # we will skip updating revHead next to None as revHead is already potining to 3 so no need
            if n1 is None:
                break
            revHead.next = n1
            head = n1
            revHead = n2

    def print(self,head :ListNode)->None:
        while head:
            print(head.val)
            head = head.next

obj = ListNode(2,ListNode(4,ListNode(6,ListNode(8))))
sol = Solution()
sol.reorderList(obj)
print('FINAL RLIST')
sol.print(obj)