import java.util.Scanner;

class Order{
	private String customerName,customerNumber;
	private int quantityOrdered;
	private float unitPrice,totalPrice;

	Scanner in = new Scanner(System.in);

	void setCustomerName(){
		System.out.println("\nEnter Customer Name");
		customerName=in.nextLine();
	}

	void setCustomerNumber(){
		System.out.println("\nEnter Customer Number");
		customerNumber=in.next();
	}

	void setQuantityOrdered(){
		System.out.println("\nEnter Quantity Ordered");
		quantityOrdered=in.nextInt();
	}

	void setUnitPrice(){
		System.out.println("\nEnter Unit Price");
		unitPrice=in.nextFloat();
	}

	String getCustomerName(){
		return customerNumber;
	}

	String getCustomerNumber(){
		return customerNumber;
	}

	int getQuantityOrdered(){
		return quantityOrdered;
	}

	float getUnitPrice(){
		return unitPrice;
	}

	void computePrice(){
		totalPrice=quantityOrdered*unitPrice;
	}

	void display(){
		System.out.println("Customer Name\t"+customerName+"\nCustomer Number\t"+customerNumber+"\nQuantity Ordered"+quantityOrdered+"\nUnit Price\t"+unitPrice+"\nTotal Price\t"+this.totalPrice);	
	}

}

class ShippedOrder extends Order{
	private float totalPrice;
	
	void computePrice(){
		totalPrice=getQuantityOrdered()*getUnitPrice()+40;
	}

	@Override
	void display(){
		System.out.println("Customer Name\t"+getCustomerName()+"\nCustomer Number\t"+getCustomerNumber()+"\nQuantity Ordered"+getQuantityOrdered()+"\nUnit Price\t"+getUnitPrice()+"\nTotal Price\t"+totalPrice);	
	}

}

class UseOrder{
	public static void main(String args[]){
		Order o = new Order();
		ShippedOrder so = new ShippedOrder();
		o.setCustomerName();
		o.setCustomerNumber();
		o.setQuantityOrdered();
		o.setUnitPrice();
		o.computePrice();
		o.display();
		so.setCustomerName();
		so.setCustomerNumber();
		so.setQuantityOrdered();
		so.setUnitPrice();
		so.computePrice();
		so.display();
	}
}