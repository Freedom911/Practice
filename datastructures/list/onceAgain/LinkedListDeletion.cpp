/**
 *
 * We will be doing linked list deletion from the begining, at the end ,single element deletion and multiple
 * 
 * Case 1 - Deletion at the begining. we simple return head next
 * Case 2 - we travrse till last and delete the last node
 * Case 3 - deletion of an element . eg 1->3->4->5 deleting at position 3 then we keep previous pointer
 * attach previous pointer->next to delete pointer next 
 * Case 4 - Multi Deletion For Case 4 we say in a linked list we can have multiple elements
 * So the algo is first we check if it the element is in the starting itself. so we iterative/recursively remove
 * those elements and update Head.
 *
 * Then we Keep a prevous pointer. 
 * We set previous pointer next to del->next
 * we del the node. but we dont break we continue
 *
 */
#include <iostream>

class LinkedList
{
    public:
        int data;
        LinkedList * next;
        LinkedList(int elem,LinkedList * nextPtr = nullptr)
        {
            data = elem;
            next = nextPtr;
        }
};

class LinkedListOp
{
    public:
        LinkedList * DeleteAtBegining(LinkedList * Head)
        {
            if(Head == nullptr)
            {
                return nullptr;
            }
            LinkedList * HeadsNext = Head->next;
            delete Head;
            return HeadsNext;
        }


        LinkedList * DeleteAtEnd(LinkedList * Head)
        {
            if(Head == nullptr)
            {
                return nullptr;
            }

            //Means only single Element present
            if(Head->next == nullptr)
            {
                delete Head;
                return nullptr;
            }

            LinkedList * prev = nullptr;
            LinkedList * HeadCopy = Head;

            //1->2->3
            //then prev will be at 2
            //HeadCopy will be at 3
            //We delete Headcopy and set prev next to nullptr
            while(HeadCopy->next != nullptr)
            {
                prev = HeadCopy;
                HeadCopy = HeadCopy->next;
            }

            delete HeadCopy;
            prev->next = nullptr;

            return Head;

        }

        //The Function First Finds an Element and then Deletes it
        LinkedList * DeleteSingleElement(LinkedList * Head,int Element)
        {
            if(Head == nullptr)
            {
                return nullptr;
            }

            //The element can be present in the begining or at the end as well
            if(Head->data == Element)
            {
                LinkedList * HeadsNext = Head->next;
                delete Head;
                return HeadsNext;
            }

            //First Find the Element
            LinkedList * prev = nullptr;
            LinkedList * HeadCopy = Head;


            //1->2->3->4 and we want to delete 3
            //then prev will be at 2
            //HeadCopy will be at 3
            //We delete Headcopy and set prev next to HeadCopy->next
            while(HeadCopy != nullptr)
            {
                if(HeadCopy->data == Element)
                {
                    prev->next = HeadCopy->next;
                    delete HeadCopy;
                    break;
                }
                prev = HeadCopy;
                HeadCopy = HeadCopy->next;
            }

            return Head;

        }

        //The Function deletes all Elements
        LinkedList * DeleteMultiElements(LinkedList * Head,int Element)
        {
            if(Head == nullptr)
            {
                return nullptr;
            }

            //Check if we have in the starting then we need to update Head
            while(Head && Head->data == Element)
            {
                LinkedList * temp = Head->next;
                delete Head;
                Head = temp;
            }

            //Now Find the Element
            LinkedList * prev = nullptr;
            LinkedList * HeadCopy = Head;


            while(HeadCopy != nullptr)
            {
                if(HeadCopy->data == Element)
                {
                    prev->next = HeadCopy->next;
                    delete HeadCopy;
                    HeadCopy = prev->next;
                    continue;
                }
                prev = HeadCopy;
                HeadCopy = HeadCopy->next;
            }

            return Head;

        }

        void Display(LinkedList *Head)
        {
            std::cout << "\n Linked List Content = ";
            while(Head != nullptr)
            {
                std::cout << Head->data << "->";
                Head = Head->next;
            }
            std::cout << "nullptr \n";
        }


};

int main()
{
    {
        LinkedList * Root = new LinkedList(1);
        LinkedList * Node1 = new LinkedList(2);
        LinkedList * Node2 = new LinkedList(3);
        LinkedList * Node3 = new LinkedList(4);
        LinkedList * Node4 = new LinkedList(5);
        Root->next = Node1;
        Node1->next = Node2;
        Node2->next = Node3;
        Node3->next = Node4;

        LinkedListOp op;
        op.Display(Root);

        //Case 1 - Deletion at begining
        //2-3-4-5
        std::cout << "\n Deletion from Begning ";
        Root = op.DeleteAtBegining(Root);
        op.Display(Root);

        //Case 2 - Deletion at end
        //2-3-4
        std::cout << "\n Deletion at end ";
        Root = op.DeleteAtEnd(Root);
        op.Display(Root);


        //Case 3 - Deletion of element
        //2-4
        std::cout << "\n Deletion of 3 ";
        Root = op.DeleteSingleElement(Root,3);
        op.Display(Root);
    }


    {

        LinkedList * Root = new LinkedList(1);
        LinkedList * Node1 = new LinkedList(2);
        LinkedList * Node2 = new LinkedList(2);
        LinkedList * Node3 = new LinkedList(2);
        LinkedList * Node4 = new LinkedList(3);
        Root->next = Node1;
        Node1->next = Node2;
        Node2->next = Node3;
        Node3->next = Node4;

        LinkedListOp op;
        op.Display(Root);

        //Case 4 - Deletion of Multi Element
        //2-2-2-3
        int toDel = 3;
        std::cout << "\n Multi Deletion of " << toDel;
        Root = op.DeleteMultiElements(Root,toDel);
        op.Display(Root);
    }



}
