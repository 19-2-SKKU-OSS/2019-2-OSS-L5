using System;

public class Program{

	public static void Swap(ref int x, ref int y){
		int tmp = x;
		x = y;
		y = tmp;
	}

	public static void Main(string[] args){
		int x = 5; y = 3;
		Swap( ref x, ref y);

	        System.Console.WriteLine(x);
		System.Console.WriteLine(y);
	
	}
}
