
class TestJava
{

    public static function main() 
    {
    	
    	var str:String = "test untyped";
		untyped __java__("java.lang.System.out.println(str)");
		//trace(s);
    	//Test.someTest("a",10,true);
    	Test.someTest("a",10,true);
    	//Test.someTest("a string", 10, true);
        var androidAlert = nme.JNI.createStaticMethod("Test", "showAlert", "(Ljava/lang/String;Ljava/lang/String;)V", true);
        trace("Hello TestJava");
    }

}

	 extern class Test
{ 		//public function new() {
        // some code
        //trace("aaaaaaaaaaaa");
    //}
    public static function someTest(a:String, b:Int, c:Bool):Void;
}

