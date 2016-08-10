class Solution {
public:
	int compareVersion(string version1, string version2) {
		if (version1 == "" || version2 == "") {return 0;}
		unsigned int v1 = 0, v2 = 0;

		istringstream ss1(version1);
		istringstream ss2(version2);

		string t1 = "", t2 = "";

		while(getline(ss1, t1, '.')) {
			v1 = stoi(t1);
			if(getline(ss2, t2, '.')) {
				v2 = stoi(t2);
			} else v2 = 0;
			if (v1 > v2) return 1;
			if (v1 < v2) return -1;
		}
		while(getline(ss2, t2, '.')) {
			v2 = stoi(t2);
			if( v2 != 0 ) return -1;
		}
		return 0;
	}


};
