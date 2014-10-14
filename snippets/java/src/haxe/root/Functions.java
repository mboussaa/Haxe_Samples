package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Functions extends haxe.lang.HxObject implements haxe.root.Interface
{
	public    Functions(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Functions()
	{
		haxe.root.Functions.__hx_ctor__Functions(this);
	}
	
	
	public static   void __hx_ctor__Functions(haxe.root.Functions __temp_me3)
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.Functions(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.Functions();
	}
	
	
	public   int compare(java.lang.String a, java.lang.String b)
	{
		java.lang.String a1 = a.toLowerCase();
		java.lang.String b1 = b.toLowerCase();
		if (( a1.compareTo(b1) < 0 )) 
		{
			return -1;
		}
		
		if (( a1.compareTo(b1) > 0 )) 
		{
			return 1;
		}
		
		return 0;
	}
	
	
	public   java.lang.String lookAndSay(java.lang.String s)
	{
		if (( ( s == null ) || haxe.lang.Runtime.valEq(s, "") )) 
		{
			return "";
		}
		
		java.lang.String results = "";
		java.lang.String repeat = haxe.lang.StringExt.charAt(s, 0);
		int amount = 1;
		{
			int _g1 = 1;
			int _g = s.length();
			while (( _g1 < _g ))
			{
				int i = _g1++;
				java.lang.String actual = haxe.lang.StringExt.charAt(s, i);
				if ( ! (haxe.lang.Runtime.valEq(actual, repeat)) ) 
				{
					results += haxe.lang.Runtime.toString(amount);
					results += repeat;
					repeat = actual;
					amount = 0;
				}
				
				amount++;
			}
			
		}
		
		results += haxe.lang.Runtime.toString(amount);
		results += repeat;
		return results;
	}
	
	
	public   int FibIter(int limit)
	{
		haxe.root.Array<java.lang.Object> limit1 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{limit});
		haxe.root.Array<java.lang.Object> current = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		haxe.root.Array<java.lang.Object> nextItem = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		int lim = 0;
		current.__set(0, 0);
		nextItem.__set(0, 1);
		lim = ((int) (haxe.lang.Runtime.toInt(limit1.__get(0))) );
		haxe.lang.Function hasNext = new haxe.root.Functions_FibIter_58__Fun(((haxe.root.Array<java.lang.Object>) (limit1) ));
		haxe.lang.Function next = new haxe.root.Functions_FibIter_60__Fun(((haxe.root.Array<java.lang.Object>) (nextItem) ), ((haxe.root.Array<java.lang.Object>) (current) ), ((haxe.root.Array<java.lang.Object>) (limit1) ));
		return lim;
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef32 = true;
			switch (field.hashCode())
			{
				case 799603607:
				{
					if (field.equals("FibIter")) 
					{
						__temp_executeDef32 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FibIter"))) );
					}
					
					break;
				}
				
				
				case 950484197:
				{
					if (field.equals("compare")) 
					{
						__temp_executeDef32 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("compare"))) );
					}
					
					break;
				}
				
				
				case -189995501:
				{
					if (field.equals("lookAndSay")) 
					{
						__temp_executeDef32 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("lookAndSay"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef32) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef33 = true;
			switch (field.hashCode())
			{
				case 799603607:
				{
					if (field.equals("FibIter")) 
					{
						__temp_executeDef33 = false;
						return this.FibIter(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 950484197:
				{
					if (field.equals("compare")) 
					{
						__temp_executeDef33 = false;
						return this.compare(haxe.lang.Runtime.toString(dynargs.__get(0)), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case -189995501:
				{
					if (field.equals("lookAndSay")) 
					{
						__temp_executeDef33 = false;
						return this.lookAndSay(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef33) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
}


