
#include "search.h"
#include <cstring>

void getNext(const char *p, int next[]) {
	int length = strlen(p);
	next[0] = -1;
	int k = -1;
	for (int j = 0; j < length;) {
		if (k == -1 || p[j] == p[k]) {
			k++;
			j++;
			if (p[j] != p[k]) {
				next[j] = k;
			} else
				next[j] = next[k];
		} else {
			k = next[k];
		}
	}
}

int kmpSearch(const char *src, const char *dst) {
	int srcLength = strlen(src);
	int dstLength = strlen(dst);
	if (srcLength <= 0 || dstLength <= 0 || dstLength > srcLength) {
		return -1;
	}
	int next[dstLength];
	getNext(dst, next);
	int i = 0, j = 0;
	while (i < srcLength && j < dstLength) {
		if (j == -1 || src[i] == dst[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if (j >= dstLength)
		return i - j;
	return -1;
}

int main(int argc, char *argv[]) {
	char *src = "Hello World!";
	char *dst = "lo";
	cout << kmpSearch(src, dst) << endl;
}