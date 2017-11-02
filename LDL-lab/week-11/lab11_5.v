module lab11_5(in,op,clk);
parameter n=4;
input in;
input clk;
output [n-1:0]op;
reg [n-1:0]op;
integer i;
always @(posedge clk)
begin 
op[n-1]<=in;
for(i=n-2;i>=0;i=i-1)
op[i]<=op[i+1];
end
endmodule




