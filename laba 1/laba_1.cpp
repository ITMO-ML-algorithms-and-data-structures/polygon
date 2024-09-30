
using namespace std;

int elements() {
	int k = 0;
	cout << "vvedite kolichstvo elementov v massive \n";

	cin >> k;
	int* maciv = new int[k];

	cout << "vvedite elementi massiva \n";
	for (int i = 0; i < k; i++) {
		int l;
		cin >> l;
		maciv[i] = l;

	}

	int y;
	cout << "vvedite iskomoe chislo \n";
	cin >> y;

	int u = 0;

	for (int o = 0; o < k; o++) {
		if (maciv[o] == y) {
			u = u + 1;
		}

	}
	cout << u;


	return 0;
}