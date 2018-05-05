const int LENGTH = 40;

class Golf
{
private:
	char fullName[LENGTH];
	int handicap;
public:
	Golf();
	Golf(const char* name, int hc);
	void SetGolf();
	void Handicap();
	void ShowGolf();
};