import java.util.Scanner;

class Item {
	String name;
	int qty;
	int id;
	double price;
	Item(String name,int qty,int id, double price){
		this.name=name;
		this.qty=qty;
		this.id=id;
		this.price=price;
	}
	void buy(int n) throws OutOfStock
	{
		if(qty-n<0)
			throw new OutOfStock();
		else
			qty-=n;
	}
}

class OutOfStock extends Exception{
	OutOfStock(){
		toString();
		printStackTrace();
	}

	@Override
	public String toString(){
		return "Item is Out Of Stock";
	}
}

class Shop{
	int n;
	Item [] item;
	Shop(int n){
		this.n=n;
		item=new Item[n];
	}

	Scanner in = new Scanner(System.in);
	void putItem(){

		for(int i=0;i<item.length;i++)
		{	
			String name;
			int qty,id;
			double price;
			System.out.println("Enter Details\nName");
			name=in.nextLine();
			System.out.println("Quantity");
			qty=in.nextInt();
			System.out.println("Id");
			id=in.nextInt();
			System.out.println("Price");
			price=in.nextDouble();
			item[i]=new Item(name,qty,id,price);
			name=in.nextLine();
		}
	}

	void displayItem(){
		for(int i=0;i<item.length;i++)
		System.out.println("\nName\t:"+item[i].name+"\nQty\t:"+item[i].qty+"\nId\t:"+item[i].id+"\nPrice\t:"+item[i].price);
	}

}

class Order extends Thread{
	Scanner in = new Scanner(System.in);
	Shop s;
	Order(Shop s){
		this.s=s;
		start();
	}
	public void run(){
			boolean check=true;			
			String Bill="";
			while(check){
			System.out.println("Enter details of Items");
			System.out.println("Name");
			String name=in.nextLine();
			System.out.println("Qty");
			int qty=in.nextInt();
			try
			{for(Item x:s.item)
			{
				if(x.name.equals(name))
					{x.buy(qty);
						break;}
			}
			Bill+=name+"\t"+qty+"\n";}
			catch(OutOfStock e)
			{System.out.println(e);}
			System.out.println("Continue? (boolean)");
			check=in.nextBoolean();
			in.nextLine();
		}
			System.out.println(Bill);
	}
}
class Q4{
	public static void main(String[] args) throws OutOfStock,InterruptedException{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter number of items");
		int n=in.nextInt();
		Shop s= new Shop(n);
		s.putItem();
		s.displayItem();
		System.out.println("Enter Number of Users");
		n=in.nextInt();
		Order [] order=new Order[n];
		for(int i=0;i<n;i++)
		{
			order[i]=new Order(s);
			order[i].join();
		}
	}
}