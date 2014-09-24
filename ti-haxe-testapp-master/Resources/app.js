(function () { "use strict";
var Main = function() { };
Main.main = function() {
	var win = Titanium.UI.createWindow({ title : "Window"});
	var label = Titanium.UI.createLabel({ text : "I am a Haxe Window", color : "black", textAlign : "right"});
	win.add(label);
	win.open();
};
Main.main();
})();
