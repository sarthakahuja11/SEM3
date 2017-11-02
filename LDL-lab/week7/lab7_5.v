module lab7_5(w,s,f);
input [0:3]w;
input [1:0]s;
output f;

function mux4to1;
input [0:3] w;
input [1:0]s;
begin
mux4to1=s[1]?(s[0]?w[3]:w[2]):(s[0]?w[1]:w[0]);
end
endfunction

assign f=mux4to1 (w,s);

endmodule



