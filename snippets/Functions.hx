

class Functions implements Interface  {

public function new()
    {
    }
  public function compare (a:String, b:String):Int
{
   var a = a.toLowerCase();
   var b = b.toLowerCase();
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
} 
 public function lookAndSay(s:String):String
    {
        if (s == null || s == "") return "";
 
        var results = "";
        var repeat = s.charAt(0);
        var amount = 1;
        for (i in 1...s.length)
        {
            var actual = s.charAt(i);
            if (actual != repeat)
            {
                results += amount;
                results += repeat;
                repeat = actual;
                amount = 0;
            }
            amount++;
        }
        results += amount;
        results += repeat;
 
        return results;
    }

//    public function isValidEmail(email:String):Bool
//{
//    var emailExpression : EReg = ~/^[\w-\.]{2,}@[ÅÄÖåäö\w-\.]{2,}\.[a-z]{2,6}$/i;
//    return emailExpression.match( email );
//}

public function  FibIter(limit:Int):Int
{
  var current:Int;
 var nextItem:Int;
   var lim:Int;
 
        current = 0;
        nextItem = 1;
        lim = limit;
    
 
     function hasNext() return limit > 0;
 
     function next()  {
        limit--;
        var ret = current;
        var temp = current + nextItem;
        current = nextItem;
        nextItem = temp;
        return ret;
    }
    return lim;
}

 /*  public function findOpenLockers(n : Int):Void
    {
        var i = 1;
 
        while((i*i) <= n)
        {
            //Sys.print(i*i + "\n");
            trace(i*i + "\n");
            i++;
        }
    }

        public function hsl2rgb(h:Float,s:Float,l:Float) : Array<Float>
    {
        var q:Float = if (l < 1 / 2)
        {
            l * (1 + s);
        } else
        {
            l + s - (l * s);
        }
        
        var p:Float = 2 * l - q;
        
        var hk:Float = (h % 360) / 360;
        
        var tr:Float = hk + 1 / 3;
        var tg:Float = hk;
        var tb:Float = hk - 1 / 3;
        
        var tc:Array<Float> = [tr,tg,tb];
        for (n in 0...tc.length)
        {
            var t:Float = tc[n];
            if (t < 0) t += 1;
            if (t > 1) t -= 1;
            tc[n] = if (t < 1 / 6)
            {
                p + ((q - p) * 6 * t);
            } else if (t < 1 / 2)
            {
                q;
            } else if (t < 2 / 3)
            {
                p + ((q - p) * 6 * (2 / 3 - t));
            } else
            {
                p;
            }
        }
          var ret:Array<Float> = [tc[0],tc[1],tc[2]];
        return ret;
    }

   */

}


