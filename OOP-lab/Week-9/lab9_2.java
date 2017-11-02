class node<T>
{
  public T data;
  public node<T>next;
  public node(T data)
    {
    this.data=data;
    }
  public void display()
    {
    System.out.println(data+"");
    }
}
class LinkedList<T>
    {
    private node<T>first;
    public LinkedList()
      {
        first=null;
      }
    public void insert(T data)
       {
        node<T> newnode=new node<T>(data);
        if(first==null)
         first=newnode;
        else
          {
            node<T>temp=first;
            while(temp.next!=null)
             {
                temp=temp.next;
             }
            temp.next=newnode;
              }
        }
      public void displayl()
     {
        if(first==null)
           System.out.println("Empty");
        else
          {
            node<T>temp=first;
            while(temp!=null)
             {
                temp.display();
                temp=temp.next;
             }
          }
      }
 }
public class lab9_2
 {
   public static void main(String args[])
     {
    LinkedList<Integer>ll=new LinkedList<Integer>();
    int x=10;
    for(int i=0;i<2;i++)
    {
    ll.insert(i);
    }ll.displayl();
     }
 }