public class StackOverflow extends Exception
{
	String msg;
	StackOverflow(String m)
	{
		msg=m;
	}

	public void display()
	{
		System.out.println("Stack overflow");
	}
	
}