module lab11_4(in,op,clk,reset);
input [0:7]in;
output [0:7]op;
input clk,reset;
lab11_1 st0(in[0],clk,0,op[0]);
lab11_1 st1(in[1],clk,0,op[1]);
lab11_1 st2(in[2],clk,0,op[2]);
lab11_1 st3(in[3],clk,0,op[3]);
lab11_1 st4(in[4],clk,0,op[4]);
lab11_1 st5(in[5],clk,0,op[5]);
lab11_1 st6(in[6],clk,0,op[6]);
lab11_1 st7(in[7],clk,0,op[7]);
endmodule
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

