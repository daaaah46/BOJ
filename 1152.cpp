#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char input[1000001];
	int sum = 0;
	cin.getline(input, sizeof(input));
	char *token = strtok(input, " ");
	while (token != NULL) {
		sum++;
		token = strtok(NULL, " ");
	}
	cout << sum << endl;
}
/*
  strtok...! Good!
*/
