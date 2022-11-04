module helloworldfpga(
	input a,
	input b,
	input c,
	input d,
	input e,
	input f,
	input g,
	input h,
	output wire p,
	output wire q,
	output wire r,
);
reg p,q,r;
always@(a,b,c,d,e,f,g,h)
begin
	p=(a&&e||!a&&!e)&&(b&&f||!b&&!f)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h);
	q= (d&&!h)||((c&&!g)&&(d&&h||!d&&!h))||((b&&!f)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h))||((a&&!e)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h)&&(b&&f||!b&&!f));
	r= (!d&&h)||((!c&&g)&&(d&&h||!d&&!h))||((!b&&f)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h))||((!a&&e)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h)&&(b&&f||!b&&!f));
end
endmodule
