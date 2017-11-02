import java.util.*;
public class oop_ass4_1
{
	public static <T> void exch(T[] arr,int a,int b)
	{
		T temp;
		temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
	

	public static void main(String[] args) 
	{
		Integer arr[]={1,2,3,4,5};
		exch(arr,1,2);
		Character arr2[]={'d','e', 'r' };
		exch(arr2,1,2);
		exch(arr2,0,2);
		
		for (int i=0;i<arr2.length;i++) {
			System.out.print(arr2[i]);	
		}
	}
}
