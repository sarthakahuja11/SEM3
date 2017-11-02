import java.util.Scanner;

class Employee{
	private String name,address,gender;
	private int age;
	Employee(String n, String a, String g,int age){
		name=n;
		address=a;
		gender=g;
		this.age=age;
	}
	void display(){
		System.out.println("Name\t"+name+"\nAddress\t"+address+"\nGender\t"+gender+"\nAge\t"+age);
	}
}

class FullTimeEmployee extends Employee{
	private float salary;
	private String designation;
	
	FullTimeEmployee(String n, String a, String g,int age,float s,String d){
		super(n,a,g,age);
		salary=s;
		designation=d;
	}

	void display(){
		super.display();
		System.out.println("Salary\t"+salary+"\nDesignation\t"+designation);
	}
}

class PartTimeEmployee extends Employee{
	private float workingHours,ratPerHour;
	
	PartTimeEmployee(String n, String a, String g,int age,float w,float r){
		super(n,a,g,age);
		workingHours=w;
		ratPerHour=r;
	}

	float calculate(){
		return workingHours*ratPerHour;	
	}

	void display(){
		super.display();
		System.out.println("Working Hours\t"+workingHours+"\nRate Per Hour\t"+ratPerHour+"\nAmount Payable\t"+calculate());
	}
}


class q1{
	public static void main(String args[])
	{
		String name,gender,address;
		int age;
		Scanner in = new Scanner (System.in);
		System.out.println("Enter details");
		name=in.nextLine();
		gender=in.nextLine();
		address=in.next();
		age=in.nextInt();
		Employee a = new Employee(name,address,gender,age);
		a.display();

		String designation;
		float salary;
		System.out.println("Details for Full Time Employee");
		salary=in.nextFloat();
		designation=in.next();
		FullTimeEmployee b = new FullTimeEmployee(name,address,gender,age,salary,designation);
		b.display();

		float workingHours, ratPerHour;
		System.out.println("Details for Part Time Employee");
		workingHours=in.nextFloat();
		ratPerHour=in.nextFloat();
		PartTimeEmployee c = new PartTimeEmployee(name,address,gender,age,workingHours,ratPerHour);
		c.calculate();
		c.display();
	}
}