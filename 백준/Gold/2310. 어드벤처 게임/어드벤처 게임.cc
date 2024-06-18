#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
bool Flag = false;

struct Room {
	char type;
	int cost;
	vector<int> next;
};
Room Map[1001];
int Visit[1001];


void Input() {
	cin >> N;
	if (N == 0) exit(0);
	for (int i = 1; i <= N; i++)
	{
		Room room;
		cin >> room.type >> room.cost;
		while (true) 
		{
			int next; cin >> next;
			if (next == 0) break;
			room.next.push_back(next);
		}
		Map[i] = room;
	}
}

bool Check(int curr, int cost, int next) {
	char type = Map[next].type;
	if (type == 'T' && cost - Map[next].cost < 0) return false;
	return true;
}

void Dfs(int curr, int cost) {

	if (curr == N)
	{
		Flag = true;
		return;
	}

	if (Map[curr].type == 'L' && cost <= Map[curr].cost)
	{
		cost = Map[curr].cost;
	}

	if (Map[curr].type == 'T')
	{
		cost -= Map[curr].cost;
	}

	for (int i = 0; i < Map[curr].next.size(); i++)
	{
		int next = Map[curr].next[i];
		if (Check(curr, cost, next) == false) continue;
		if (Visit[next] == 1) continue;
		
		Visit[next] = 1;
		Dfs(next, cost);
		if (Flag == true) return;
		Visit[next] = 0;
	}
}

void Clear() {
	memset(Visit, 0, sizeof(Visit));
	Flag = false;
}

int main() {
	while (true)
	{
		Input();
		Visit[1] = 1;
		Dfs(1, 0);
		if (Flag == true) cout << "Yes" << '\n';
		else cout << "No" << '\n';
		Clear();
	}
}