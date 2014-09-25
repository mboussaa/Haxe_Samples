package ;

class ColorConverter 
{


    
    public static function hsl2rgb(h:Float,s:Float,l:Float) : Array
    {
        var q:Float = if (hsl.l < 1 / 2)
        {
            hsl.l * (1 + hsl.s);
        } else
        {
            hsl.l + hsl.s - (hsl.l * hsl.s);
        }
        
        var p:Float = 2 * hsl.l - q;
        
        var hk:Float = (hsl.h % 360) / 360;
        
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
  }
