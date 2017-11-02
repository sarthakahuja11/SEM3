module lab10_3(cin,x,y,co,s);
input cin,x,y;
output co,s;
wire [0:7]w;
wire [2:0]z;
assign z[0]=y;
assign z[1]=x;
assign z[2]=cin;
lab9_1 st(z,w,1'b1);
assign co=w[3]|w[5]|w[6]|w[7];
assign s=w[1]|w[2]|w[4]|w[7];
endmodule




module lab9_1(w,y,en);
input [2:0]w;
input en;
output [0:7]y;
reg [0:7]y;
always @(w or en)
case ({en,w})
4'b1000:y=~8'b01111111;
4'b1001:y=~8'b10111111;
4'b1010:y=~8'b11011111;
4'b1011:y=~8'b11101111;
4'b1100:y=~8'b11110111;
4'b1101:y=~8'b11111011;
4'b1110:y=~8'b11111101;
4'b1111:y=~8'b11111110;
default:y=~8'b11111111;
endcase
endmodule

