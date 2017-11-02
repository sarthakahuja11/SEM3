package my_Packages;

public class Max 
{
	public int max(int a, int b, int c)
	{
		int m=Math.max(a, b);
		m=Math.max(m, c);
		return m;
	}
	
	public float max(float a, float b, float c)
	{
		float m=Math.max(a, b);
		m=Math.max(m, c);
		return m;
	}
	
	public int max(int[] arr)
	{
		int m=arr[0];
		for(int x:arr)
			if(x>m)	m=x;
		
		return m;
	}
	
	public int max(int[][] arr)
	{
		int m=arr[0][0];
		for (int[] u: arr)
		    for (int e: u)
		        if (e>m) m=e;
		return m;
	}
}