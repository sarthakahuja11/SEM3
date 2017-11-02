module lab8_4(bcd,w);
input [3:0]bcd;
output [3:0]w;
wire [0:7]a,b,c,d;
assign d={1'b0,1'b0,bcd[0],1'b1,1'b1,1'b1,1'b1,1'b1};
assign c={1'b0,1'b0,~bcd[0],1'b1,1'b1,1'b1,1'b1,1'b1};
assign b={1'b0,1'b1,bcd[0],1'b0,1'b1,1'b1,1'b1,1'b1};
assign a={bcd[0],bcd[0],bcd[0],bcd[0],bcd[0],1'b1,1'b1,1'b1};
lab7_1 st0(d,bcd[3:1],w[3]);
lab7_1 st1(c,bcd[3:1],w[2]);
lab7_1 st2(b,bcd[3:1],w[1]);
lab7_1 st3(a,bcd[3:1],w[0]);
endmodule

module lab7_1(w,s,f);
input [0:7]w;
input [2:0]s;
output f;
reg f;

always @(w or s)
case (s)
0:f=w[0];
1:f=w[1];
2:f=w[2];
3:f=w[3];
4:f=w[4];
5:f=w[5];
6:f=w[6];
7:f=w[7];
endcase
endmodule



