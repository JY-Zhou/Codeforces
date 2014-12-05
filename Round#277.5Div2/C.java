import java.io.*;
import java.math.*;
import java.util.Scanner;

public class Main {
    public static BigInteger dpmin[][];
    public static BigInteger dpmax[][];
    
    public static BigInteger dfsmin(int m, int s, boolean first) {
    	if(s < 0) return BigInteger.valueOf(-2);
	    if(m == 1) {
	    	if(s > 9) return dpmin[m][s] = BigInteger.valueOf(-2);
	    	return dpmin[m][s] = BigInteger.valueOf(s);
	    }
	    if(!dpmin[m][s].equals(BigInteger.valueOf(-1)))
	    	return dpmin[m][s];
	    BigInteger ret = BigInteger.TEN.pow(105);
	    for(int i = 9 ; i >= (first ? 1 : 0) ; i--) {
			BigInteger t = dfsmin(m-1,s-i,false);
			if(!t.equals(BigInteger.valueOf(-2))) {
			    BigInteger mul = BigInteger.TEN.pow(m-1);
			    ret = ret.min(t.add(mul.multiply(BigInteger.valueOf(i))));
			}
	    }
	    if(ret.equals(BigInteger.TEN.pow(105))) return dpmin[m][s] = BigInteger.valueOf(-2);
	    return dpmin[m][s] = ret;
    }
    
    public static BigInteger dfsmax(int m, int s, boolean first) {
    	if(s < 0) return BigInteger.valueOf(-2);
	    if(m == 1) {
			if(s > 9) return dpmax[m][s] = BigInteger.valueOf(-2);
			return dpmax[m][s] = BigInteger.valueOf(s);
	    }
	    if(!dpmax[m][s].equals(BigInteger.valueOf(-1))) 
	    	return dpmax[m][s];
	    BigInteger ret = BigInteger.TEN.negate();
	    for(int i = 9 ; i >= (first ? 1: 0) ; i--) {
			BigInteger t = dfsmax(m-1,s-i,false);
			if(!t.equals(BigInteger.valueOf(-2))) {
				BigInteger mul = BigInteger.TEN.pow(m-1);
			    ret = ret.max(t.add(mul.multiply(BigInteger.valueOf(i))));
			}
	    }
	    if(ret.equals(BigInteger.TEN.negate())) return dpmax[m][s] = BigInteger.valueOf(-2);
	    return dpmax[m][s] = ret;
    }
    
    public static void main(String [] args) {
    	int m,s;
    	Scanner cin = new Scanner(System.in);
    	m = cin.nextInt();
    	s = cin.nextInt();
    	dpmin = new BigInteger[105][];
    	dpmax = new BigInteger[105][];
    	for(int i = 0 ; i < 105; i++) {
    		dpmin[i] = new BigInteger[905];
    		dpmax[i] = new BigInteger[905];
    	}
    	for(int i = 0 ; i < 105 ; i++) {
    		for(int j = 0 ; j < 905 ; j++) {
    			dpmin[i][j] = BigInteger.valueOf(-1);
    			dpmax[i][j] = BigInteger.valueOf(-1);
    		}
    	}
    	BigInteger a1 = dfsmin(m,s,true);
    	BigInteger a2 = dfsmax(m,s,true);
    	if(a1.compareTo(BigInteger.ZERO) < 0) a1 = BigInteger.valueOf(-1);
    	if(a2.compareTo(BigInteger.ZERO) < 0) a2 = BigInteger.valueOf(-1);
    	System.out.println(a1 + " " + a2);
    }
}
