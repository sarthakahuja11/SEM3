import java.util.Scanner;

class HotelRoom{
	private int roomNumber;
	private float rentRate;

	int getRoomNumber()
	{
		return roomNumber;
	}

	float getRentRate()
	{
		return rentRate;
	}

	void setRentRate(float rent){
		rentRate=rent;
	}

	HotelRoom(int rNo)
	{
		roomNumber=rNo;
		if (rNo<=299)	
			rentRate=500;
		else
			rentRate=1000;
	}

	void display(){
		System.out.println("Room Number\t"+roomNumber+"\nRent Rate\t"+rentRate);
	}
}

class Suite extends HotelRoom{
	Suite(int rNo){
		super(rNo);
		setRentRate(getRentRate()+200);
	}
}

class UseHotelRoom{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);

		System.out.println("Enter Room No");
		int roomNumber=in.nextInt();
		HotelRoom h = new HotelRoom(roomNumber);
		h.display();

		System.out.println("\nEnter Room No");
		roomNumber=in.nextInt();
		Suite s= new Suite(roomNumber);
		s.display();

	}
}