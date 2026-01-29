#ifndef __ISPRIMEFUNCTION_H
#define __ISPRIMEFUNCTION_H

bool isPrimeInteger(int pTest) {
	if (pTest == 2) {
		return true;
	}
	else if (pTest%2==0 or pTest < 2) {
		return false;
	}
	else {
		for (int i = 3; i*i <= pTest; i+=2) {
			if (pTest % i == 0) {
				return false;
			}
		}
	}
	return true;
}
#endif
