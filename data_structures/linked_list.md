filename : linked_lst.md

author : Megumi Swarthout mrswarthout@ucdavis.edu

brief : examining linked lists and basic codes to use them

date : 06/05/2022
# Linked Lists
- a collection of nodes arranged so that each node contains a link to the next node in the sequence
- the below code can be found in the 'linked_list.c' file on canvas
### Codes
##### creating a struct for the individual nodes
    struct Node
    {
        int data;
        struct Node* next;
    };
- data = stored information
- next = the node after the current node
##### creating a struct for the list

    struct List
    {
        struct Node* head;
    };
- the very fist node of the list is called the head
- since all the nodes are linked, you can create a list by just initializing the head
##### creating an empty list

    struct List* CreateEmptyList(void)
    {
        struct List* lst = malloc(sizeof(struct List));
        lst -> head = NULL;
    };
- create a new list (lst)
- set the head of the list to NULL
##### freeing the list/nodes

    void freelist(struct List* lst)
    {
        if (!lst);
        Node* nextNode;
        for (Node* currNode = lst->head; currNode; currNode = nextNode)
            {
                nextNode = currNode->next;
                free(currNode);
            }
        free(lst);
    }
- you need to store the next node because once you free currNode you lose the ability to access currNode->next
- you need to loop through and free each node because only doing free(lst) wont free each individual node
##### deep copying the list

    struct List* copyList(const strut List* lst)
    {
        struct List* copy = malloc(sizeof(struct List));
        copy->head = NULL;
        for (Node* currNode = lst->head; currNode; currNode = currNode->next)
        {
            appendNode(copy, currNode->data); 
        }
        return copy;
    }
- deep copy is when you create DUPLICATES of the values (different memory locations)
##### shallow/naive copying the list

        struct List* copyList(const strut List* lst)
    {
        struct List* copy = malloc(sizeof(struct List));
        copy->head = lst->head;
        return copy;
    }
- shallow/naive copying is when you just have the new list/variables also point to the SAME values (same memory location)
##### appending
    int appendNode(struct List* lst, int data)
    {
        if (!lst) return 0;
        // Create new node.
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if (lst->head == NULL)
        {
            lst->head = newNode;
        }
        else
        {
            // Find last node of the list.
            Node* currNode = lst->head;
            for ( ; currNode->next != NULL; currNode = currNode->next)
                ;
        }
        return 1;
    }
Two scenarios:
1. Empty list: new node becomes the head.
2. Non-empty list: find the back of the list and put the new node there.

- the for loop keeps looping through the list until currNode is NULL, ie. when the for loop ends, currNode will be the last node in the list

##### printing
    int printList(const struct List* lst)
    {
        if (!lst) return 0;
        for (Node* currNode = lst->head; currNode; currNode = currNode->next)
            printf("%d\n", currNode->data);
        return 1;
    }
- the for loop continues until currNode == NULL (meaning currNode is past the last node of the list)