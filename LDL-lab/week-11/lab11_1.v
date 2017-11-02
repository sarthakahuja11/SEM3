module lab11_1(d,clk,reset,q);
input d,clk,reset;
output q;
reg q;
always@(posedge reset or negedge clk)
if(reset==1)
q<=0;
else
q<=d;
endmodule
