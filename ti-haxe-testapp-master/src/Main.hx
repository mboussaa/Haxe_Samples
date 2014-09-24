package ;

import titanium.ui.Window;
import titanium.ui.Label;

class Main {
    public static function main() : Void {
        var win : Window = Window.create({
            // backgroundColor:'white',
            // exitOnClose: true,
            // fullscreen: false,
            //notSupportedParam: true,
            title: 'Window',
        });

        var label : Label = Label.create({
            text: 'I am a Haxe Window',
            color: 'black',
            textAlign: titanium.UI.TEXT_ALIGNMENT_RIGHT,
        });

        win.add(label);
        win.open();
    }
}
