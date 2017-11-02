module lab12_1(clk,a1);
input clk;
output [0:3]a1;
wire [1:0]temp;
twobit wqe(clk,temp);
dec2to4 fd(temp,1,a1);
endmodule

module twobit(clk,a);
input clk;
output [1:0]a;
lab11_2 st0(1,clk,0,a[0]);
lab11_2 st1(1,a[0],0,a[1]);
endmodule

module lab11_2(t,clk,reset,q);
input t,clk,reset;
output q;
reg q;
always@(negedge clk)
if(reset==1)
q<=0;
else if(t==0)
q<=q;
else if(t==1)
q<=~q;
endmodule


module dec2to4(w,en,y);
input [1:0]w;
output [0:3]y;
input en;
reg [0:3]y;
always @(w or en)
case({en,w})
3'b100:y=4'b1000;
3'b101:y=4'b0100;
3'b110:y=4'b0010;
3'b111:y=4'b0001;
default:y=4'b0000;
endcase 
endmodule
