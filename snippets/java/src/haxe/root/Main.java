package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main extends haxe.lang.HxObject
{
	public static void main(String[] args)
	{
		main();
	}
	public    Main(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Main()
	{
		haxe.root.Main.__hx_ctor__Main(this);
	}
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me5)
	{
		{
		}
		
	}
	
	
	public static   void main()
	{
		haxe.root.Functions fun = new haxe.root.Functions();
		java.lang.String test = "1";
		{
			int _g = 0;
			while (( _g < 11 ))
			{
				int i = _g++;
				java.lang.System.out.println(((java.lang.Object) (test) ));
				test = fun.lookAndSay(test);
			}
			
		}
		
		boolean resp = fun.isValidEmail("medmed@med.com");
		haxe.Log.trace.__hx_invoke2_o(0.0, resp, 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "main"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (20) )) )})));
		int x = fun.FibIter(10);
		java.lang.System.out.println(((java.lang.Object) (x) ));
		fun.findOpenLockers(100);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.Main(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.Main();
	}
	
	
}


