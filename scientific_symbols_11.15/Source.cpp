#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

// Глава 11, упр. 15 (стр. 460). complete

vector<double>v_int;
void string_to_int(vector<string>vs)
{
	string s;
	double x;
	for (int i = 0; i < vs.size(); i++)
	{
		s = vs[i];
		stringstream degree(s);
		degree >> x;
		v_int.push_back(x);
	}
}

int main()
{
	string file_name_1;
	string file_name_2;
	cout << "Enter file name for open: ";
	cin >> file_name_1;

	ifstream ifs(file_name_1);
	if (!ifs)
	{
		cerr;
	}
	cout << "Enter file name for record: ";
	cin >> file_name_2;

	vector<string> vi;
	string digit;
	double dig;

	for (char ch; ifs.get(ch);)
	{
		if (ch=='.')
		{
			digit += ch;
		}
		if (isspace(ch))
		{
			vi.push_back(digit);
			digit = "";
		}
		if (isdigit(ch))
		{
			digit += ch;
		}
	}

	string_to_int(vi);

	ifs.close();

	ofstream ofs(file_name_2);
	if (!ofs)
	{
		cerr;
	}

	for (int i = 0; i < v_int.size(); i++)
	{
		ofs << scientific << setprecision(8) << v_int[i] << '\t';
		i++;
		ofs << scientific << setprecision(8) << v_int[i] << '\t';
		i++;
		ofs << scientific << setprecision(8) << v_int[i] << '\t';
		i++;
		ofs << scientific << setprecision(8) << v_int[i] << '\n';
		i++;
		ofs << endl;
	}

	return 0;
}