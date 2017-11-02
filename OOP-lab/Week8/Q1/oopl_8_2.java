import java.util.*;
class rSum implements Runnable
{
	Thread t;
	int row[];
	int sum=0;
	rSum(int row[])
	{
		t=new Thread(this);
		this.row=row;
		t.start();
	}
	public void run()
	{
		for(int i=0;i<row.length;i++)
			sum=sum+row[i];
	}
}
public class oopl_8_2
{
	public static void main(String[] args) 
	{
		int r,c,total=0;
		Scanner sc=new Scanner(System.in);
		r=sc.nextInt();
		c=sc.nextInt();
		int a[][]=new int[r][c];
		int sum1[]=new int[r];
		rSum r1[]=new rSum[r];
		//input
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				a[i][j]=sc.nextInt();
		for(int i=0;i<r;i++)
		{
			r1[i]=new rSum(a[i]);
			try
			{
				r1[i].t.join();
			}catch(InterruptedException e)
			{
				System.out.println("Error");
			}
			sum1[i]=r1[i].sum;
		}
		for(int i=0;i<r;i++)
			total+=sum1[i];
		for(int i=0;i<r;i++)
			System.out.println(sum1[i]);
		System.out.print("total sum=");
		System.out.println(total);
	}
}