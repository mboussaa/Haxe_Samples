package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Functions_FibIter_51__Fun extends haxe.lang.Function
{
	public    Functions_FibIter_51__Fun(haxe.root.Array<java.lang.Object> limit1)
	{
		super(0, 0);
		this.limit1 = limit1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		return ( ((int) (haxe.lang.Runtime.toInt(this.limit1.__get(0))) ) > 0 );
	}
	
	
	public  haxe.root.Array<java.lang.Object> limit1;
	
}


