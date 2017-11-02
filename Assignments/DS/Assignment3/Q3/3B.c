deleteList(struct node* temp)
{
     if(temp == NULL)
          printf("List is empty\n");

     else {
          head = temp;
          temp->next = NULL;
          free(temp);
          deleteList(head->next);
     }
     head = NULL;
 }
