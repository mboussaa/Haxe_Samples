package titanium.ui;

import titanium.core.BaseView;

typedef LabelParameters = {
    // mandatory
    text : String,
    // optional
    ?top : Int,
    ?color : String,
    ?textAlign : String,
}

@:native("Titanium.UI.Label")
extern class Label extends BaseView {
    // static constructor
    public inline static function create(?params : LabelParameters) : Label {
        return titanium.UI.createLabel(params);
    }
}
