import java.util.Scanner;

class Point {
	private int x,y;
	Point(int x,int y){
		this.x=x;
		this.y=y;
	}
	void display()
	{
		System.out.println("X\t"+x+"\nY\t"+y);
	}
}

class Circle extends Point{
	private double radius,area;
	Circle(int x,int y,double r){
		super(x,y);
		radius=r;
	}

	double getRadius(){
		return radius;
	}

	double getArea(){
		area=3.141*radius*radius;
		return area;
	}

	void display()
	{
		super.display();
		System.out.println("Radius\t"+radius+"\nArea\t"+getArea());
	}
}

class Cylinder extends Circle{
	private double height,surfaceArea,volume;

	Cylinder(int x,int y,double radius,double height){
		super(x,y,radius);
		this.height=height;
	}

	double getSurfaceArea(){
		surfaceArea=4*3.141*super.getRadius()*height;
		return surfaceArea;
	}
	
	double getVolume(){
		volume=super.getArea()*height;
		return volume;
	}
	
	void display(){
		super.display();
		System.out.println("Height\t"+height+"\nSurfaceArea\t"+getSurfaceArea()+"\nVolume\t"+getVolume());
	}
}

class q3{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int x,y;
		System.out.println("Enter coordinates");
		x=in.nextInt();
		y=in.nextInt();
		Point p = new Point(x,y);
		p.display();

		
		double radius;
		System.out.println("Enter radius");
		radius=in.nextDouble();
		Circle c = new Circle(x,y,radius);
		c.display();

		double height;
		System.out.println("Enter Height");
		height=in.nextDouble();
		Cylinder cy = new Cylinder(x,y,radius,height);
		cy.display();

	}
}