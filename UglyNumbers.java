package practice;

import java.util.Scanner;

public class UglyNumbers {

	public int ugly(int a,int b){
		while(a%b==0)
		  a=a/b;
		return a;
	}
	public int checkUglyNumbers(int n){
		n= ugly(n, 2);		
		n= ugly(n, 3);
		n= ugly(n, 5);
        return (n==1)?1:0;
	}
	
	public int count(int j){
		int t=1;
		int count=1;
		while(j>count){
			t++;
			if(checkUglyNumbers(t)==1){
				count++;
			}
		}
		return t;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i = sc.nextInt();
		System.out.println(i);
		UglyNumbers ug=new UglyNumbers();
		int k=ug.checkUglyNumbers(i);
		if(k==1){
		  System.out.println("It is a Ugly Number");
		}else{
		  System.out.println("It is not a Ugly Number");
		}
		
		int count=ug.count(i);
		System.out.println("Your i th position number is "+count);
	}
	
}
