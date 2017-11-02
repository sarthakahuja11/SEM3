module tflipflop(T,clk,Q);
	input T,clk;
	output Q;
	reg Q;
	always @(negedge clk)
		if(~T)
		Q<=Q;
		else
		Q<=~Q;
endmodule
module lab12_3_3(clk,x,Q);
	input clk,x;
	output [3:0]Q;
	
	wire [5:0]A;
	tflipflop st0(1,clk,Q[0]);
	assign A[0]=~x&Q[0];
	assign A[1]=x&~Q[0];

	tflipflop st1(A[0]|A[1],clk,Q[1]);
	assign A[2]=A[0]&Q[1];
	assign A[3]=A[1]&~Q[1];
	tflipflop st2(A[2]|A[3],clk,Q[2]);
	assign A[4]=A[2]&Q[2];
	assign A[5]=A[3]&~Q[2];
	tflipflop st3(A[4]|A[5],clk,Q[3]);
endmodule


