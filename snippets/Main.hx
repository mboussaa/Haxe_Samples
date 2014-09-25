import sys.db.Types;
import Functions;
using Std ;
 
class Main {
   public static function main()  {
    

    var fun = new Functions();

    //lookAndSay Function
    var test = "1";
        for (i in 0...11) {
            Sys.println(test);
            test = fun.lookAndSay(test);
        }

    //isValidEmail Function
    var resp = fun.isValidEmail("medmed@med.com");
    trace(resp);

    //FibIter
    var x = fun.FibIter(10);
    Sys.println(x);

    //100 doors
    fun.findOpenLockers(100);

 
 
}
}



