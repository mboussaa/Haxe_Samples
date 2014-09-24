# ti-haxe-testapp

## Description

This is a sample titanium app, showing how to obtain static type checking with haXe language.

I've just hand-written a minimal port of Titanium API, I need some help to port all of them programmatically from Titanium docs/json/jsca.

## Usage

Clone the repository, cd into it, then:

    haxe compile.hxml

You will obtain a compilation error, haXe is checking that `notSupportedParam` isn't a valid parameter for createWindow dictionary.

Comment `line 12` of `Main.hx`, compilation will succeed.

Copy the generated `Resources/app.js` in a new Titanium Mobile Project. The app does nothing special, just opens a new window with a label.
