#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main() {
	char s[255]; //Ö÷´®
	char t[255]; //Ä£Ê½´®
	scanf("%s", s);
	getchar();
	scanf("%s", t);
	int lens = strlen(s);
	int lent = strlen(t);
	if (lens < lent) {
		printf("-1/n");
		return 0;
	}
	bool flag = false;
	for (int k = 0; k <= lens - lent; k++) {
		int i = k;
		int j = 0;
		while (j < lent) {
			if (s[i] == t[j]) {
				i++;
				j++;
			}
			else {
				break;
			}
		}
		if (j == lent) {
			printf("%d\n", k);
			flag = true;
			break;
		}
	}
	if (!flag) {
		printf("-1\n");
	}
	return 0;
}