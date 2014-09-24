package titanium;

import titanium.ui.Label;
import titanium.ui.Window;

@:native("Titanium.UI")
extern class UI {
    public static inline var TEXT_ALIGNMENT_LEFT = "left";
    public static inline var TEXT_ALIGNMENT_CENTER = "center";
    public static inline var TEXT_ALIGNMENT_RIGHT = "right";


    public static function createLabel(?params : Dynamic) : Label;
    public static function createWindow(?params : Dynamic) : Window;
}
