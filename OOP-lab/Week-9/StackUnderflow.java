public class StackUnderflow extends Exception
{
	String msg;
	StackUnderflow(String m)
	{
		msg=m;
	}

	public void display()
	{
		System.out.println("Stack underflow");
	}
	
}