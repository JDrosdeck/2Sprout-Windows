import java.io.*;

public class Test{

	public static void main(String[] args)
	{
		System.loadLibrary("sproutJava");
		System.out.println("Starting Feed:"); 
		for(; ; )
		{
			System.out.println(sprout.getSproutItem());

		}  
	}
}
