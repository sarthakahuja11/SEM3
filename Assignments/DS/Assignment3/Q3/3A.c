/* deletes alternate nodes of a list starting with head */
void deleteAlt(struct node *head)
{
    if (head == NULL)
        return;
 
    /* Initialize prev and node to be deleted */
    struct node *prev = head;
    struct node *node = head->next;
 
    while (prev != NULL && node != NULL)
    {
        /* Change next link of previous node */
        prev->next = node->next;
 
        /* Free memory */
        free(node);
 
        /* Update prev and node */
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}
