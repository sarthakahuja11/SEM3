

class Counter{
	private int count=0;
		synchronized void increment(){
			try{
			if(count==3)
				{
					Thread.sleep(300);
					System.out.println("Count is at its Maximum Value of 3");
					wait();
				}

			System.out.println(++count);
				Thread.sleep(500);
				if(count!=0)
					notify();
			
			
		}

		catch(InterruptedException e)
		{System.out.println("Interrupted");}	
		}


		synchronized void decrement(){
				try{
				if(count==0)
					{
						Thread.sleep(300);
						System.out.println("Count is at its Minimum Value of 0");
						wait();
					}

				System.out.println(--count);
				Thread.sleep(500);
					
					if(count!=3)
						notify();
				
				
			}

			catch(InterruptedException e)
			{System.out.println("Interrupted");}
		}
	}

class ThrInc implements Runnable{
	Counter c;
	ThrInc(Counter c){
		this.c=c;
		new Thread(this,"Increment").start();
	}

	public void run(){
		while(true){
			c.increment();
		}
	}
}

class ThrDec implements Runnable{
	Counter c;
	ThrDec(Counter c){
		this.c=c;
		new Thread(this,"Decrement").start();
	}

	public void run(){
		while(true){
			c.decrement();
		}
	}
}

class Q1 {
	public static void main(String[] args) {
		Counter c= new Counter();
		new ThrInc(c);
		new ThrDec(c);
		
	}
}