(function () { "use strict";
var Interface = function() { };
var Functions = function() {
};
Functions.__interfaces__ = [Interface];
Functions.prototype = {
	compare: function(a,b) {
		var a1 = a.toLowerCase();
		var b1 = b.toLowerCase();
		if(a1 < b1) return -1;
		if(a1 > b1) return 1;
		return 0;
	}
	,lookAndSay: function(s) {
		if(s == null || s == "") return "";
		var results = "";
		var repeat = s.charAt(0);
		var amount = 1;
		var _g1 = 1;
		var _g = s.length;
		while(_g1 < _g) {
			var i = _g1++;
			var actual = s.charAt(i);
			if(actual != repeat) {
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
	,FibIter: function(limit) {
		var current;
		var nextItem;
		var lim;
		current = 0;
		nextItem = 1;
		lim = limit;
		var hasNext = function() {
			return limit > 0;
		};
		var next = function() {
			limit--;
			var ret = current;
			var temp = current + nextItem;
			current = nextItem;
			nextItem = temp;
			return ret;
		};
		return lim;
	}
};
var Main = function() { };
Main.main = function() {
	var fun = new Functions();
	var test = "1";
	var _g = 0;
	while(_g < 11) {
		var i = _g++;
		console.log(test);
		test = fun.lookAndSay(test);
	}
	var x = fun.FibIter(10);
	console.log(x);
	var j = fun.compare("bla","blabla");
	console.log(j);
};
var haxe = {};
haxe.io = {};
haxe.io.Eof = function() { };
haxe.io.Eof.prototype = {
	toString: function() {
		return "Eof";
	}
};
Main.main();
})();
