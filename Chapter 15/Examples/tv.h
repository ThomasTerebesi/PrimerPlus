#pragma once

class Tv
{
public:
	friend class Remote;	// Remote can access Tv private parts
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125)
		: state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV)
	{
	}

	void onOff() { state = (state == On) ? Off : On; }	// alternative: void onOff() {state ^= 1;}
	bool isOn() const { return state == On; }
	bool volUp();
	bool volDown();
	void chanUp();
	void chanDown();
	void setMode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void setInput() { input = (input == TV) ? DVD : TV; }
	void settings() const;	// display all settings

private:
	int state;			// on or off
	int volume;			// assumed to be digitized
	int maxchannel;		// maximum number of channels
	int channel;		// current channel setting
	int mode;			// broadcast or cable
	int input;			// TV or DVD
};

class Remote
{
private:
	int mode;
public:
	Remote(int m = Tv::TV)
		: mode(m)
	{
	}

	bool volUp(Tv & t) { return t.volUp(); }
	bool volDown(Tv & t) { return t.volDown(); }
	void onOff(Tv & t) { t.onOff(); }
	void chanUp(Tv & t) { t.chanUp(); }
	void chanDown(Tv & t) { t.chanDown(); }
	void setChan(Tv & t, int c) { t.channel = c; }
	void setMode(Tv & t) { t.setMode(); }
	void setInput(Tv & t) { t.setInput(); }
};