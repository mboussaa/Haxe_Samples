(function () { "use strict";
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var FFT = function() {
};
FFT.newArray = function(len,fixed) {
	if(fixed == null) fixed = false;
	if(len == null) len = 0;
	return new Array();
};
FFT.prototype = {
	init: function(logN) {
		this.m_logN = logN;
		this.m_N = 1 << this.m_logN;
		this.m_invN = 1.0 / this.m_N;
		this.m_X = new Array();
		var _g1 = 0;
		var _g = this.m_N;
		while(_g1 < _g) {
			var k = _g1++;
			this.m_X[k] = new FFTElement();
		}
		var _g11 = 0;
		var _g2 = this.m_N - 1;
		while(_g11 < _g2) {
			var k1 = _g11++;
			this.m_X[k1].next = this.m_X[k1 + 1];
		}
		var _g12 = 0;
		var _g3 = this.m_N;
		while(_g12 < _g3) {
			var k2 = _g12++;
			this.m_X[k2].revTgt = this.BitReverse(k2,logN);
		}
	}
	,run: function(xRe,xIm,inverse) {
		if(inverse == null) inverse = false;
		var numFlies = this.m_N >> 1;
		var span = this.m_N >> 1;
		var spacing = this.m_N;
		var wIndexStep = 1;
		var x = this.m_X[0];
		var k = 0;
		var scale;
		if(inverse) scale = this.m_invN; else scale = 1.0;
		while(x != null) {
			x.re = scale * xRe[k];
			x.im = scale * xIm[k];
			x = x.next;
			k++;
		}
		var math = Math;
		var _g1 = 0;
		var _g = this.m_logN;
		while(_g1 < _g) {
			var stage = _g1++;
			var wAngleInc = wIndexStep * 2.0 * math.PI / this.m_N;
			if(!inverse) wAngleInc *= -1;
			var wMulRe = math.cos(wAngleInc);
			var wMulIm = math.sin(wAngleInc);
			var start = 0;
			while(start < this.m_N) {
				var xTop = this.m_X[start];
				var xBot = this.m_X[start + span];
				var wRe = 1.0;
				var wIm = 0.0;
				var _g2 = 0;
				while(_g2 < numFlies) {
					var flyCount = _g2++;
					var xTopRe = xTop.re;
					var xTopIm = xTop.im;
					var xBotRe = xBot.re;
					var xBotIm = xBot.im;
					xTop.re = xTopRe + xBotRe;
					xTop.im = xTopIm + xBotIm;
					xBotRe = xTopRe - xBotRe;
					xBotIm = xTopIm - xBotIm;
					xBot.re = xBotRe * wRe - xBotIm * wIm;
					xBot.im = xBotRe * wIm + xBotIm * wRe;
					xTop = xTop.next;
					xBot = xBot.next;
					var tRe = wRe;
					wRe = wRe * wMulRe - wIm * wMulIm;
					wIm = tRe * wMulIm + wIm * wMulRe;
				}
				start += spacing;
			}
			numFlies >>= 1;
			span >>= 1;
			spacing >>= 1;
			wIndexStep <<= 1;
		}
		x = this.m_X[0];
		while(x != null) {
			var target = x.revTgt;
			xRe[target] = x.re;
			xIm[target] = x.im;
			x = x.next;
		}
	}
	,BitReverse: function(x,numBits) {
		var y = 0;
		var _g = 0;
		while(_g < numBits) {
			var i = _g++;
			y <<= 1;
			y |= x & 1;
			x >>= 1;
		}
		return y;
	}
};
var FFTElementEssentials = function() {
	this.re = 0;
	this.im = 0;
};
var FFTElement = function() {
	FFTElementEssentials.call(this);
};
FFTElement.__super__ = FFTElementEssentials;
FFTElement.prototype = $extend(FFTElementEssentials.prototype,{
});
var FFTTimingTest = function() {
	this.initTest();
	this.print("Performing FFTs...");
	var xRe = new Array();
	var xIm = new Array();
	var _g = 0;
	while(_g < 1024) {
		var i = _g++;
		xRe[i] = Math.cos(2 * Math.PI * 2 * i / 1024);
		xIm[i] = 0.0;
	}
	var fft = new FFT();
	fft.init(10);
	var startTime = Std["int"](haxe.Timer.stamp() * 1000);
	var _g1 = 0;
	while(_g1 < 20) {
		var i1 = _g1++;
		fft.run(xRe,xIm,false);
		fft.run(xRe,xIm,true);
	}
	var endTime = Std["int"](haxe.Timer.stamp() * 1000);
	var elapsed = endTime - startTime;
	var timePerFFT = elapsed / 40.;
	this.print(20 + " fwd-inv pairs of " + 1024 + " pt FFTs took " + elapsed + " ms, or " + (timePerFFT * 1000 | 0) / 1000 + " ms per FFT.");
	this.checkIfHaxeTranslationIsCorrect();
};
FFTTimingTest.main = function() {
	new FFTTimingTest();
};
FFTTimingTest.prototype = {
	getTimer: function() {
		return Std["int"](haxe.Timer.stamp() * 1000);
	}
	,checkIfHaxeTranslationIsCorrect: function() {
		var xRe = new Array();
		var xIm = new Array();
		var xRe2 = new Array();
		var xIm2 = new Array();
		var _g = 0;
		while(_g < 1024) {
			var i = _g++;
			xRe[i] = xRe2[i] = Math.cos(2 * Math.PI * 2 * i / 1024);
			xIm[i] = xIm2[i] = 0.0;
		}
		var fft = new FFT();
		fft.init(10);
		fft.run(xRe,xIm,false);
		fft.run(xRe,xIm,true);
		var ok = true;
		var _g1 = 0;
		while(_g1 < 1024) {
			var i1 = _g1++;
			if(!this.almostEqual(xRe[i1],xRe2[i1])) {
				ok = false;
				break;
			}
		}
		this.print("Haxe translation is " + (ok?"":"in") + "correct.");
	}
	,almostEqual: function(a,b) {
		return a < b + .0001 && a > b - .0001;
	}
	,initTest: function() {
	}
	,print: function(s) {
		console.log(s);
	}
};
var Std = function() { };
Std["int"] = function(x) {
	return x | 0;
};
var haxe = {};
haxe.Timer = function() { };
haxe.Timer.stamp = function() {
	return new Date().getTime() / 1000;
};
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i1) {
	return isNaN(i1);
};
FFT.FORWARD = false;
FFT.INVERSE = true;
FFTTimingTest.LOG_N = 10;
FFTTimingTest.N = 1024;
FFTTimingTest.NUM_LOOPS = 20;
FFTTimingTest.PRECISION = .0001;
FFTTimingTest.main();
})();
