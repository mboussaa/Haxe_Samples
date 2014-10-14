package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Functions_FibIter_60__Fun extends haxe.lang.Function
{
	public    Functions_FibIter_60__Fun(haxe.root.Array<java.lang.Object> nextItem, haxe.root.Array<java.lang.Object> current, haxe.root.Array<java.lang.Object> limit1)
	{
		super(0, 1);
		this.nextItem = nextItem;
		this.current = current;
		this.limit1 = limit1;
	}
	
	
	@Override public   double __hx_invoke0_f()
	{
		{
			int __temp_arrIndex19 = 0;
			int __temp_arrVal17 = ((int) (haxe.lang.Runtime.toInt(this.limit1.__get(__temp_arrIndex19))) );
			int __temp_arrRet18 = __temp_arrVal17--;
			this.limit1.__set(__temp_arrIndex19, __temp_arrVal17);
			int __temp_expr34 = __temp_arrRet18;
		}
		
		int ret = ((int) (haxe.lang.Runtime.toInt(this.current.__get(0))) );
		int temp = ( ((int) (haxe.lang.Runtime.toInt(this.current.__get(0))) ) + ((int) (haxe.lang.Runtime.toInt(this.nextItem.__get(0))) ) );
		this.current.__set(0, ((int) (haxe.lang.Runtime.toInt(this.nextItem.__get(0))) ));
		this.nextItem.__set(0, temp);
		return ((double) (ret) );
	}
	
	
	public  haxe.root.Array<java.lang.Object> nextItem;
	
	public  haxe.root.Array<java.lang.Object> current;
	
	public  haxe.root.Array<java.lang.Object> limit1;
	
}


