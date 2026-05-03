/**
 * Remove Loop 
 */

/**
 * 
 * 
 * Step 1: What actually happens (no math yet)

You have two pointers:

slow → moves 1 step
fast → moves 2 steps

They meet inside the loop.

At that exact moment:

👉 fast has taken exactly double the steps of slow.

That’s the only fact we need.

Step 2: Let’s count steps in plain English

Let:

a = steps from head to loop start
then both enter loop
after that, slow walks some extra steps inside loop → call that b

So:

👉 total steps of slow = a + b

Since fast moves twice:

👉 total steps of fast = 2(a + b)

Step 3: Where is fast actually?

Here’s the key observation:

Both are at the same node when they meet.

That means:

👉 the extra distance fast has covered must be some full loops

Because looping brings you back to the same node.

So:

fast distance = slow distance + (full loops)

So:

2(a + b) = (a + b) + k * (loop_length)

Now subtract (a + b) from both sides:

a + b = k * (loop_length)
Step 4: Now THIS is the important line
a + b = k * (loop_length)

Rearrange:

a = k * (loop_length) - b

Nothing magical. Just subtraction.

Step 5: Now forget algebra—interpret it

This equation says:

👉 “Distance from head to loop start” =
👉 “a full number of loops minus how far we already went inside the loop”

Now think in terms of walking:

From collision point, you are b steps ahead of loop start
To go back to loop start, you need loop_length - b steps

And from equation:

a = loop_length - b   (ignoring full extra loops)
 */

#include <iostream>

struct LL
{
  int data;
  LL*next;
  LL(int val,LL*nextPtr=nullptr)
  {
      data = val;
      next = nextPtr;
  }
};

//thge Function returns the pointer to node containing the starting point of the loop
LL *GetStarting(LL*Head)
{
    //base Condtions
    if(Head == nullptr || Head->next == nullptr)
    {
        return nullptr;
    }

    //1. First Step Find Collisino Point using Tortoise and hare algo
    LL*Slow = Head;
    LL*Fast = Head;

    while(Fast && Fast->next)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;

        //Collisino Point Found
        if(Slow == Fast)
        {
            break;
        }
    }
    if(Fast == nullptr || Fast->next == nullptr)//Means No Loop
        return nullptr;

    //2.nd Point After Collision Move Head and Fast till they collide
    while(Head != Fast)
    {
        Head = Head->next;
        Fast = Fast->next;
    }

    return Head;
}

//This Functions remove the link that results in loop
//returns updated Linked ist
LL *RemoveLoop(LL*Head,LL*StartingPoint)
{
    if(Head == nullptr || StartingPoint == nullptr)
    {
        return nullptr;
    }

    LL*Curr = StartingPoint; //we start from Loop Starting Point and not from hea

    while(Curr->next != StartingPoint)
    {
        Curr = Curr->next;
    }
    Curr->next = nullptr;//remove the looping ptr
    return Head;
}

void Display(LL* Head)
{
    if(Head == nullptr)
    {
        return ;
    }

    std::cout << "Linked List Content = ";
    while(Head)
    {
        std::cout << Head->data << "->";
        Head = Head->next;
    }
    std::cout << "nullptr \n";
}

int main()
{
    LL*node8 = new LL(8);
    LL*node7 = new LL(7,node8);
    LL*node6 = new LL(6,node7);
    LL*node5 = new LL(5,node6);
    LL*node4 = new LL(4,node5);
    LL*node3 = new LL(3,node4);
    LL*node2 = new LL(2,node3);
    LL*node1 = new LL(1,node2);//head
    node8->next = node4;//Looping ptr

    LL*StartingPoint = GetStarting(node1);

    if(StartingPoint == nullptr)
    {
        std::cout << "\n No Loop Found \n";
    }
    else
    {
        std::cout << "\n After Removing Loop at = " << StartingPoint->data << "\n";
        LL* UpdatedHead = RemoveLoop(node1,StartingPoint);
        Display(UpdatedHead);

    }
}
