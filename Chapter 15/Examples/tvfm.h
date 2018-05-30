#pragma once

class Tv;		// forward declaration

class Remote
{
public:
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
private:
	int mode;
public:
	Remote(int m = TV)
		: mode(m)
	{
	}

	bool volUp(Tv & t);
	bool volDown(Tv & t);
	void onOff(Tv & t);
	void chanUp(Tv & t);
	void chanDown(Tv & t);
	void setMode(Tv & t);
	void setInput(Tv & t);
	void setChan(Tv & t, int c);
};

class Tv
{
public:
	friend void Remote::setChan(Tv & t, int c);

	enum State{ Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125)
		: state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV)
	{
	}

	void onOff() { state = (state == On) ? Off : On; }
	bool isOn() const { return state == On; }
	bool volUp();
	bool volDown();
	void chanUp();
	void chanDown();
	void setMode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void setInput() { input = (input == TV) ? DVD : TV; }
	void settings() const;

private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

inline bool Remote::volUp(Tv & t) { return t.volUp(); }
inline bool Remote::volDown(Tv & t) { return t.volDown(); }
inline void Remote::onOff(Tv & t) { t.onOff(); }
inline void Remote::chanUp(Tv & t) { t.chanUp(); }
inline void Remote::chanDown(Tv & t) { t.chanDown(); }
inline void Remote::setMode(Tv & t) { t.setMode(); }
inline void Remote::setInput(Tv & t) { t.setInput(); }
inline void Remote::setChan(Tv & t, int c) { t.channel = c; }

