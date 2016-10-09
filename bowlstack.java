import java.io.*;
import java.util.*;
class Pan {
	double h,r,R,y=0;
	boolean used=false;
}
class bowlstack_he {
	static Pan[] pan,stack;
	static double minheight;
	static int noofcases,n;
	static BufferedReader stdin;
	static String getLine() throws Exception {
		String line=null;
		line = stdin.readLine();
		return line;
	}
	static double lift(Pan pan1,Pan pan2) {
		double lift;
		if ((pan1.R-pan1.r)/pan1.h>(pan2.R-pan2.r)/pan2.h){
			lift = pan1.h*(pan2.r-pan1.r)/(pan1.R-pan1.r); 
		}
		else if (pan2.R<pan1.R){
			lift = pan1.h*(pan2.R-pan1.r)/(pan1.R-pan1.r) - pan2.h; 
		}
		else {
			lift = pan1.h - pan2.h*(pan1.R-pan2.r)/(pan2.R-pan2.r);
		}
		if (lift<0) return 0.0;
		if (lift>pan1.h) return pan1.h;
		return lift;
	}
	static void build(int k) {
		double y,maxy,height,stackheight=0.0;
		if (k==n) {
			for (int i=0;i<k;i++) {
				height = stack[i].y + stack[i].h;
				if(stackheight<height) stackheight=height;
			}
			if(stackheight<minheight) minheight = stackheight;
			return;
		}
		for (int j=0;j<n;j++) {
			Pan p = pan[j];
			if (p.used) continue;
			maxy = 0.0;
			for (int i=0;i<k;i++) {
				y = stack[i].y + lift(stack[i],p);
				if(maxy<y) maxy=y;
			}
			if(maxy+p.h>minheight) continue;
			p.y = maxy;
			p.used = true;
			stack[k] = p;
			build(k+1);
			p.used = false;
			p.y = 0.0;
		}
	}
	public static void main(String[] argv)throws Exception {
		Reader rdr = new InputStreamReader(System.in);
		stdin = new BufferedReader(rdr);
		noofcases = Integer.parseInt(getLine());
		for (int icase=0; icase<noofcases; ++icase) {
			String[] tokens;
			tokens = (getLine()+" $").split(" ");
			n = Integer.parseInt(tokens[0]);
			pan = new Pan[n];
			for (int i=0;i<n; ++i) {
				tokens = (getLine()+" $").split(" ");
				double h,r,R;
				h = (double)Integer.parseInt(tokens[0]);
				r = (double)Integer.parseInt(tokens[1]);
				R = (double)Integer.parseInt(tokens[2]);
				pan[i]=new Pan();
				pan[i].h = h;
				pan[i].r = r;
				pan[i].R = R;
			}
			stack = new Pan[n];
			minheight=1000000;
			build(0);
			System.out.println((int)minheight);
		}
	}
}