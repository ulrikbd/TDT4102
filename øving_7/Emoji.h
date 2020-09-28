#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window& w) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face: public Emoji {
	private:
		Circle face;
	public:
		Face(Point c, int r);
		virtual void attach_to(Graph_lib::Window&) override = 0;
};

class emptyFace: public Face {
	protected:
		Circle leftEye;
		Circle rightEye;
	public:
		emptyFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};

class smileyFace: public emptyFace {
	protected:
		Arc mouth;
	public:
		smileyFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};

class sadFace: public emptyFace {
	protected:
		Arc mouth;
	public:
		sadFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};

class AngryFace: public sadFace {
	protected:
		Line leftEyebrow;
		Line rightEyebrow;
	public:
		AngryFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};


class SurprisedFace: public emptyFace {
	private:
		Arc mouth;
	public:
		SurprisedFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};

class WinkingFace: public Face {
	private:
		Arc leftEye;
		Circle rightEye;
		Arc mouth;
	public:
		WinkingFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};