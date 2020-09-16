import javax.swing.*;
import java.util.Scanner;
import java.util.ArrayList;
import javax.swing.JOptionPane;



public class Testing {
	//public static ArrayList <Integer> div_counter = new ArrayList<Integer>();
	public static String remainder = "0"; 
	public static String endl = "\n";
	/*
	public static void count(){
	   if (div_counter.isEmpty()){
	     div_counter.add(0);
	   }

	     div_counter.set(div_counter.size()-1, div_counter.get(div_counter.size()-1)+1);
	     for (int check = div_counter.size()-1;check>=0;check--){
	       if (div_counter.get(check)==10){
	         div_counter.set(check,0);
	         if (check!=0){
	           div_counter.set (check-1,div_counter.get(check-1)+1);
	         }
	         else {
	           div_counter.add(0,1);
	         }
	       }
	     }

	 }
*/
	public static int check(String y, String x){
		    int temp;
		    
		    if (x.length()>y.length()){
		      temp = y.length();
		      for (int counter=0;counter<x.length()-temp;counter++){
		        y = "0" + y;
		      }
		      
		    }
		    else if (x.length()<y.length()){
		       
		      temp = x.length();
		      for (int counter=0;counter<y.length()-temp;counter++){
		        x = "0" + x;
		       
		      } 
		      
		    }
		    for (int counter=0;counter<x.length();counter++){
		      if (Integer.parseInt(x.substring(counter,counter+1))<Integer.parseInt(y.substring(counter,counter+1))){
		    	  
		    	  return 1;
		      }
		      else if (Integer.parseInt(x.substring(counter,counter+1))>Integer.parseInt(y.substring(counter,counter+1))){
		    	  
		    	  return 2;
		      }
		    }
		    return 3;
		 }
		  
	public static String add(String x,String y) {
		ArrayList <Integer> result = new ArrayList <Integer>();
		ArrayList <Integer> x_num = new ArrayList <Integer>();
		ArrayList <Integer> y_num = new ArrayList <Integer>();
		
		for (int counter=0;counter<x.length();counter++) {
			x_num.add(Integer.parseInt(x.substring(counter,counter+1)));
		}
		for (int counter=0;counter<y.length();counter++) {
			y_num.add(Integer.parseInt(y.substring(counter,counter+1)));
		}
		
		
		int carry = 0;
		int temp;

		
		String val="";
		
		
		if (x_num.size()<y_num.size()) {
			
			for (int counter=0;counter<(y.length()-x.length());counter++) {
				x_num.add(0,0);
			}
			
			
		}
		else if (x_num.size()>y_num.size()) {
			for (int counter=0;counter<(x.length()-y.length());counter++) {
				y_num.add(0,0);
			}
		}

		for (int counter=x_num.size()-1;counter>=0;counter--) {
			temp = x_num.get(counter)+
					y_num.get(counter)+
					carry;
			
			result.add(0,temp%10);
			carry = temp/10;
			
		}
		
		if (carry!=0) {
			result.add(0,carry);
		}
		
		
		
		for (int counter=0; counter<result.size();counter++) {
		
			val+= result.get(counter);
		
		}

		
		
		return val;
	}
	
	public static String minus (String x,String y) {
		String val="";
		
		ArrayList <Integer> result = new ArrayList <Integer>();
		ArrayList <Integer> x_num = new ArrayList <Integer>();
		ArrayList <Integer> y_num = new ArrayList <Integer>();
		
		for (int counter=0;counter<x.length();counter++) {
			x_num.add(Integer.parseInt(x.substring(counter,counter+1)));
		}
		for (int counter=0;counter<y.length();counter++) {
			y_num.add(Integer.parseInt(y.substring(counter,counter+1)));
		}
		
		boolean negative = false;
		boolean ylarge = false;
		
		int carry;
		
		if (x_num.size()==y_num.size()) {
			for (int counter=0;counter<x_num.size();counter++) {
				if (x_num.get(counter)<y_num.get(counter)) {
					ylarge=true;
					break;
				}
				else if (x_num.get(counter)>y_num.get(counter)) {
					break;
				}
			}
		}
		
		if (x_num.size()<y_num.size()||ylarge) {
			negative = true;
			if (!ylarge) {	
				for (int counter=0;counter<(y.length()-x.length());counter++) {
					x_num.add(0,0);
				}
			}
			
			for (int counter=x_num.size()-1;counter>=0;counter--) {
	
				if (y_num.get(counter)<x_num.get(counter)) {
					carry=1;
					while (y_num.get(counter-carry)==0) {
						if (y_num.get(counter-carry)==0) {
							y_num.set(counter-carry, 9);
						}
						carry++;
					}
					y_num.set(counter-carry, y_num.get(counter-carry)-1);
					result.add(0,y_num.get(counter)-x_num.get(counter)+10);
					
				}
				else {
					result.add(0,y_num.get(counter)-x_num.get(counter));
				}
			}
		}

		else {
			
			if (x_num.size()!=y_num.size()) {
				for (int counter=0;counter<(x.length()-y.length());counter++) {
					y_num.add(0,0);
				}
			}
			
			for (int counter=x_num.size()-1;counter>=0;counter--) {
	
				if (x_num.get(counter)<y_num.get(counter)) {
					carry=1;
					while (x_num.get(counter-carry)==0) {
						if (x_num.get(counter-carry)==0) {
							x_num.set(counter-carry, 9);
						}
						carry++;
					}
					x_num.set(counter-carry, x_num.get(counter-carry)-1);
					result.add(0,x_num.get(counter)-y_num.get(counter)+10);
					
				}
				else {
					result.add(0,x_num.get(counter)-y_num.get(counter));
				}
			}
		}
		

		while (result.get(0)==0 && result.size()>1)result.remove(0);

		for (int counter=0;counter<result.size();counter++) {
			val += result.get(counter);
		}
		if (negative)val = "-" + val;
		return val;
	}
	
	public static String multiply (String x,String y) {
		String val="";
		String sum="0", temp_num;
		
		int carry =0;
		int temp;
		ArrayList <Integer> temp_result = new ArrayList <Integer>();
		ArrayList <Integer> result = new ArrayList <Integer>();
		ArrayList <Integer> x_num = new ArrayList <Integer>();
		ArrayList <Integer> y_num = new ArrayList <Integer>();
		
		for (int counter=0;counter<x.length();counter++) {
			x_num.add(Integer.parseInt(x.substring(counter,counter+1)));
		}
		for (int counter=0;counter<y.length();counter++) {
			y_num.add(Integer.parseInt(y.substring(counter,counter+1)));
		}
		
		int place = 0;

		for (int counter=y_num.size()-1;counter>=0;counter--) {
			temp_result.clear();
			for (int d=x_num.size()-1;d>=0;d--) {
				
				
				temp = y_num.get(counter)*x_num.get(d)+carry;
				carry = temp/10;
				
				temp_result.add(0,temp%10);
				
			}
			
			if (carry!=0) {
				temp_result.add(0,carry);
			}
			
			temp_num = "";
			
			for (int c=0;c<place;c++) {
				temp_result.add(0);
			}
			
			for (int c=0;c<temp_result.size();c++) {
				temp_num+= temp_result.get(c);
			}
			
			//System.out.println(sum);
			sum = add(sum,temp_num);
			place++;
		}
		
		val = sum;
		
		return val;
	}
/*
	public static String minus_divide (String x,String y) {
		String val="";
		
		boolean ylarge = false;
		
		int carry;
		
		if (y.equals("0"))return "undefined";
		
		if (x.length()<y.length())ylarge=true;
		if (x.length()==y.length()) {
			for (int counter=0;counter<x.length();counter++) {
				if (Integer.parseInt(x.substring(counter,counter+1))<Integer.parseInt(y.substring(counter,counter+1))) {
					ylarge=true;
					break;
				}
				else if (Integer.parseInt(x.substring(counter,counter+1))>Integer.parseInt(y.substring(counter,counter+1))) {
					break;
				}
			}
		}
		while (!ylarge && !x.equals("0")) {	
			count();
			System.out.println(div_counter);
			x = minus(x,y);
			
			ylarge=false;
			if (x.length()<y.length())ylarge=true;
			if (x.length()==y.length()) {
				for (int counter=0;counter<x.length();counter++) {
					if (Integer.parseInt(x.substring(counter,counter+1))<Integer.parseInt(y.substring(counter,counter+1))) {
						ylarge=true;
						break;
					}
					else if (Integer.parseInt(x.substring(counter,counter+1))>Integer.parseInt(y.substring(counter,counter+1))) {
						break;
					}
				}
			}

		}
		if (div_counter.isEmpty())div_counter.add(0);
		for (int counter=0;counter<div_counter.size();counter++) {
			val+=div_counter.get(counter);
		}
		remainder = x;
		return val;
	}
	*/
	public static String divide (String x, String y) {
		//for check(num1,num2), 1 means num1>num2, 2 means num1<num2, 3 means num1==num2
		String val="";

		int index;
	
		if (x.equals("0")) {
			return "0";
		}
		
		if (y.equals("0")) {
			return "";
		}
		
		while (check(x,y)==1||check(x,y)==3) {
			
			index = 1;
			String temp = x.substring(0,1);
			//finds first substring that is number larger than y
			for (int counter=1;check(y,temp) == 1;counter++){
				index = counter;
				temp = x.substring(0,counter);
				
			}
			
			String mult=y;
			String placeholder = "1";
			//starts multiplying numbers 1 to 9
			for (String counter="1";check(temp,mult)==1;counter=Integer.toString(Integer.parseInt(counter)+1)) {
				
				placeholder=counter;
				
				mult = multiply (y,counter);
			}
			
			if(check(temp,mult)!=3) {
				placeholder = minus (placeholder,"1");
				mult = minus(mult,y);
			}
			
			
			
			for (int counter=0;counter<x.length()-index;counter++) {
				placeholder+="0";
				mult+="0";
			}
			
			if (minus(x,mult).substring(0, 1).equals("-")) {
				break;
			}
			val = add(val,placeholder);
			x = minus(x,mult);
			
			
			//break;
		}
			
		remainder=x;
		return val;
	}
	// main method begins execution of Java application
public static void main( String args[] ){
	
	
	String out="";
	
	String num1, num2;
	
	String operation;
		
	

	num1 = JOptionPane.showInputDialog("Enter first number");
	
	operation = JOptionPane.showInputDialog("Enter '+' '-' '*' '/' ");
	
	num2 = JOptionPane.showInputDialog("Enter second number");

	
	if (operation.equals("+")) {
		out = add(num1,num2);
	}
	if (operation.equals("-")) {
		out = minus (num1,num2);
	}
	if (operation.equals("*")) {
		out = multiply(num1,num2);
	}
	if (operation.equals("/")) {
		out = divide(num1,num2);
		

	}
	int place=1;
	for (int counter=out.length()-1;counter>=0;counter--) {
		if (out.substring(0,counter+1).equals("-"))break;
		if (place%4==0) {
			out = out.substring(0,counter+1)+", "+out.substring(counter+1,out.length());
			counter++;
		}
		place++;
	}
	if (!remainder.equals("0")) {
		out +=endl + "remainder: "+remainder;
	}
	if (out.equals("")) {
		out = "Undefined";
	}
	JOptionPane.showMessageDialog(null, out,"Result",JOptionPane.INFORMATION_MESSAGE);
	
	
	
	
 	} // end method main
 
 } // end class LogicalOperators
