package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class TestJava extends haxe.lang.HxObject
{
	public static void main(String[] args)
	{
		main();
	}
	public    TestJava(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    TestJava()
	{
		haxe.root.TestJava.__hx_ctor__TestJava(this);
	}
	
	
	public static   void __hx_ctor__TestJava(haxe.root.TestJava __temp_me5)
	{
		{
		}
		
	}
	
	
	public static   void main()
	{
		java.lang.String str = "test untyped";
		java.lang.System.out.println(str);
		haxe.root.Test.someTest("a", 10, true);
		haxe.Log.trace.__hx_invoke2_o(0.0, "Hello TestJava", 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"TestJava", "TestJava.hx", "main"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (15) )) )})));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.TestJava(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.TestJava();
	}
	
	
}


