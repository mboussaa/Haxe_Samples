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
	
	
	public static   void __hx_ctor__Functions(haxe.root.Functions __temp_me4)
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
	
	
	public   boolean isValidEmail(java.lang.String email)
	{
		haxe.root.EReg emailExpression = new haxe.root.EReg(haxe.lang.Runtime.toString("^[\\w-\\.]{2,}@[\u00c5\u00c4\u00d6\u00e5\u00e4\u00f6\\w-\\.]{2,}\\.[a-z]{2,6}$"), haxe.lang.Runtime.toString("i"));
		return emailExpression.match(email);
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
		haxe.lang.Function hasNext = new haxe.root.Functions_FibIter_51__Fun(((haxe.root.Array<java.lang.Object>) (limit1) ));
		haxe.lang.Function next = new haxe.root.Functions_FibIter_53__Fun(((haxe.root.Array<java.lang.Object>) (nextItem) ), ((haxe.root.Array<java.lang.Object>) (limit1) ), ((haxe.root.Array<java.lang.Object>) (current) ));
		return lim;
	}
	
	
	public   void findOpenLockers(int n)
	{
		int i = 1;
		while (( ( i * i ) <= n ))
		{
			java.lang.System.out.print(((java.lang.Object) (( ( i * i ) + "\n" )) ));
			i++;
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef36 = true;
			switch (field.hashCode())
			{
				case 1525935928:
				{
					if (field.equals("findOpenLockers")) 
					{
						__temp_executeDef36 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("findOpenLockers"))) );
					}
					
					break;
				}
				
				
				case -189995501:
				{
					if (field.equals("lookAndSay")) 
					{
						__temp_executeDef36 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("lookAndSay"))) );
					}
					
					break;
				}
				
				
				case 799603607:
				{
					if (field.equals("FibIter")) 
					{
						__temp_executeDef36 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FibIter"))) );
					}
					
					break;
				}
				
				
				case 2101634506:
				{
					if (field.equals("isValidEmail")) 
					{
						__temp_executeDef36 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isValidEmail"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef36) 
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
			boolean __temp_executeDef37 = true;
			switch (field.hashCode())
			{
				case 1525935928:
				{
					if (field.equals("findOpenLockers")) 
					{
						__temp_executeDef37 = false;
						this.findOpenLockers(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -189995501:
				{
					if (field.equals("lookAndSay")) 
					{
						__temp_executeDef37 = false;
						return this.lookAndSay(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 799603607:
				{
					if (field.equals("FibIter")) 
					{
						__temp_executeDef37 = false;
						return this.FibIter(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2101634506:
				{
					if (field.equals("isValidEmail")) 
					{
						__temp_executeDef37 = false;
						return this.isValidEmail(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef37) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
}


