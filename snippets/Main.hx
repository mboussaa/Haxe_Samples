import sys.db.Types;
import Functions;
using Std ;
 
class Main {
   public static function main()  {
    

    var fun = new Functions();

    
    //lookAndSay Function
    var test = "1";
        for (i in 0...11) {
            trace(test);
            test = fun.lookAndSay(test);
        }

    
    //isValidEmail Function
    //var resp = fun.isValidEmail("medmed@med.com");
    //trace(resp);

    
    //FibIter
    var x = fun.FibIter(10);
    trace(x);

    
    //100 doors
    //fun.findOpenLockers(100);

    
    //compare 
    var j = fun.compare("bla","blabla");
    trace(j);
    

    //hsl2rgb
    //var rgb= fun.hsl2rgb(2,3,4);
    //trace(rgb);
}
}



