import java.util.*;
class employee
{
    String name;
    int no;
    employee(String n,int n1)
    {
        name=n;
        no=n1;
    }
    public String toString()
    {
        return ("name="+name+"\nno="+no);
    }
}
class student
{
    String name;
    int roll;
    student(String n,int r)
    {
        name=n;
        roll=r;
    }
    public String toString()
    {
        return ("name="+name+"\nno="+roll);
    }
}
class stack<E>
{
    E arr[];
    int top;
    int size;
    stack(int a)
    {
        size=a;
        top=-1;
        arr=(E[]) new Object[size];
    }
    public void push(E val) throws StackOverflow
    {
        if(top==size-1)
        {
            throw new StackOverflow("full");
        }
        arr[++top]=val;
    }
    public E pop() throws StackUnderflow
    {
        if(top==-1)
        {
            throw new StackUnderflow("empty");
        }
        return arr[top--];
    }
    public void  display()
    {
        for(int i=top;i>=0;i--)
        System.out.println(arr[i]+"\n");
    }
}
class lab9_1
{
    public static void main(String args[])
    {
        stack<employee> obj=new stack<employee>(3);
        stack<student>obj1=new stack<student>(5);
        try
        {
            obj.push(new employee("dfdf",1));
            obj.push(new employee("dfdfdfsd",2));
            obj.push(new employee("dffdfgsdasff",3));
            obj.push(new employee("dfdfdfsdkf",4));    
    }catch(StackOverflow s)
    {
        s.display();
    }
    obj.display();
    System.out.println("\n\n");
    try
    {
            obj1.push(new student("sdfjkhsdjk",10));
            obj1.push(new student("dfdf",22));
    }catch(StackOverflow s1)
    {
        s1.display();
    }
    obj1.display();
    try
    {
            System.out.println(obj1.pop());
            System.out.println(obj1.pop());
            System.out.println(obj1.pop());
            System.out.println(obj1.pop());
    }catch(StackUnderflow u)
    {
         u.display();
    }
}
}