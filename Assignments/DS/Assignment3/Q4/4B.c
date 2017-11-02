Node* recursive_ordered_insert(Node* head, int val)
{
    //special case: first elem is null
    if (!head)
    {
        head = create_node(val);

        return head;
    }

    //special case 2: end of list
    if (!head->next)
    {
        head->next = create_node(val);

        return head->next;
    }

    //base case
    if (head->next && head->next->data > val)
    {
        Node* newNode = create_node(val);
        newNode->next = head->next;

        head->next = newNode;

        return newNode;
    }

    return recursive_ordered_insert(head->next, val);
}
