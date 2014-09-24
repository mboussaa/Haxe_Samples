package titanium.ui;

import titanium.core.BaseView;

typedef WindowParameters = {
    ?backgroundColor : String,
    ?exitOnClose: Bool,
    ?fullscreen: Bool,
    ?title : String
}

@:native("Titanium.UI.Window")
extern class Window extends BaseView {
    // static contructor
    public inline static function create(?params : WindowParameters) : Window {
        return titanium.UI.createWindow(params);
    }

    // methods
    public function open(?options : Dynamic) : Void;
}

