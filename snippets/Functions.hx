

class Functions implements Interface  {

public function new()
    {
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

    public function isValidEmail(email:String):Bool
{
    var emailExpression : EReg = ~/^[\w-\.]{2,}@[ÅÄÖåäö\w-\.]{2,}\.[a-z]{2,6}$/i;
    return emailExpression.match( email );
}

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

   public function findOpenLockers(n : Int):Void
    {
        var i = 1;
 
        while((i*i) <= n)
        {
            Sys.print(i*i + "\n");
            i++;
        }
    }

}


