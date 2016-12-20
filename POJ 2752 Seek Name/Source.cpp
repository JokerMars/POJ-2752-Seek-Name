#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int MAX_LEN = 400005;
int suffix[MAX_LEN];

void GetSuffix(string s)
{
	suffix[0] = -1;
	suffix[1] = 0;

	int k = 0;
	for (int i = 2; i <= s.length(); i++)
	{
		while (k >= 0 && s[k] != s[i - 1])
			k = suffix[k];

		suffix[i] = ++k;
	}
}

int main()
{
	string str;
	vector<int>vec;
	while (getline(cin, str))
	{
		vec.clear();
		memset(suffix, 0, sizeof(suffix));
		GetSuffix(str);

		int k = str.length();
		while (k >= 0)
		{
			if (suffix[k] >= 0)vec.push_back(k);
			k = suffix[k];
		}

		int len = vec.size();
		for (k = len - 1; k >= 0; k--)
		{
			cout << vec[k];
			if (k != 0)cout << " ";
		}
		cout << endl;
		
	}
	return 0;
}
