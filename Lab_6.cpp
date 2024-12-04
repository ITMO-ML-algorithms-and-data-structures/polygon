#include <iostream>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

struct Car {
	int position;
	int speed;
	Car(int pos, int spd) : position(pos), speed(spd) {}
	bool operator == (const Car& otherCar) const {
		return position == otherCar.position && speed == otherCar.speed;
	}
};
template <> struct hash<Car> {
	size_t operator()(const Car& c) const {
		return hash<int>()(c.position) ^ hash<int>()(c.speed);
	}
};
class Solution {
public:
	int racecar(int target) {
		unordered_map<Car, bool> visited;
		queue<Car> q;
		q.push(Car(0, 1));
		visited[Car(0, 1)] = 1;
		int steps = 0;

		while (q.size()) {
			int sz = q.size();

			for (int i = 0; i < sz; i++) {
				Car current = q.front();
				q.pop();

				if (current.position == target) {
					return steps;
				}
				{ // A
					Car next = Car(current.position + current.speed, current.speed * 2);
					if (abs(next.position) <= target * 2 && visited[next] == 0) {
						q.push(next);
						visited[next] = 1;
					}
				}
				{ // R
					Car next = Car(current.position, current.speed > 0 ? -1 : 1);
					if (abs(next.position) <= target * 2 && visited[next] == 0) {
						q.push(next);
						visited[next] = 1;
					}
				}
			}
			steps++;
		}
		return -1;
	}
};
int main() {
	setlocale(LC_ALL, "Ru");
	int target;
	cout << "Укажите целевую позицию: ";
	cin >> target;
	Solution sol;
	cout << "Минимальное количество шагов: " << sol.racecar(target) << endl;
	return 0;
}