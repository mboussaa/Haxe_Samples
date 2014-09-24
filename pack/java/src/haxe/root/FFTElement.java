package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FFTElement extends haxe.root.FFTElementEssentials
{
	public    FFTElement(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    FFTElement()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxe.root.FFTElement.__hx_ctor__FFTElement(this);
	}
	
	
	public static   void __hx_ctor__FFTElement(haxe.root.FFTElement __temp_me8)
	{
		haxe.root.FFTElementEssentials.__hx_ctor__FFTElementEssentials(__temp_me8);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.FFTElement(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.FFTElement();
	}
	
	
	public  haxe.root.FFTElement next;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef45 = true;
			switch (field.hashCode())
			{
				case 3377907:
				{
					if (field.equals("next")) 
					{
						__temp_executeDef45 = false;
						this.next = ((haxe.root.FFTElement) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef45) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef46 = true;
			switch (field.hashCode())
			{
				case 3377907:
				{
					if (field.equals("next")) 
					{
						__temp_executeDef46 = false;
						return this.next;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef46) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("next");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


