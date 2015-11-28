int _abs (int num) {
	return (num > 0) ? num : -1*num;
}

int _pow2 (int base) {
	return base * base;
}

int _powX (int base, int exp) {
	int power = base;
	while (exp > 1) {
		exp--;
		base *= power;
	}
	return base;
}

float _round_up (float num){
	num *= 10;
	float bas = (int) num % 10;
	if (bas >= 5) return (int) num / 10 + 1;
		else return num / 10;
}

float _round_up2 (float num, float dec){
	return _round_up( num * dec ) / dec;
}

float _round_down (float num){
	num *= 10;
	float bas = (int) num % 10;
	if (bas < 5) return (int) num / 10;
		else return num / 10;
}

float _round_down2 (float num, float dec){
	return num = _round_down( num * dec ) / dec;
}

float _round_both (float num){
	num*= 10;
	float bas = (int) num % 10;
	if (bas >= 5) return (int) num / 10 + 1;
		else return (int) num / 10;
}

float _round_both2 (float num, float dec){
	return _round_both( num * dec ) / dec;
}

int _isPrime (int num) {
	int iter = 0, i;
	if (num < 1) return -1;
	for (i = 1; i <= num; i++){
		if (num % i == 0) iter++;
		if (iter > 2) break;
	}
	return (iter == 2) ? 1 : 0;
}

void _funcLoop (void (*f)(), int _tms) {
	int ctr;
	for ( ctr = 0; ctr < _tms; ctr++ ) {
		(*f)();
	}
}

void _qSwitch (int *a, int *b) {
    int mom = *a;
    *a = *b;
    *b = mom;
}

int _timeToS (int h, int m, int s) {
    return (h * 3600 + m * 60 + s);
}

void _sToTime (int secs, int *h, int *m, int *s) {
    *h = secs / 3600;
    *m = (secs / 60) % 60;
    *s = secs % 60;
}

void _breakFloat (float num, int *left, float *right) {
    *left = num;
    *right = num - (*left);
}

void _digits (int num, int *digits) {
    *digits = 0;
    while (num > 0) {
        (*digits)++;
        x /= 10;
    }
}

void _sum (int num, int *sum) {
    *sum = 0;
    while (num > 0) {
        *sum += x % 10;
        x /= 10;
    }
}

int __rectSpp (int x, int y, int xmax, int ymax) {
    if (x == 0 || x == --xmax || y == 0 || y == --ymax) return 1;
    else return 0;
}

void _rect (int heigth, int width, char filler, int filled) {
    int i, y;
    for (i = 0; i < heigth; i++) {
        printf ("\n");
        for (y = 0; y < width; y++) {
            if (filled || __rectSpp(i, y, heigth, width)) printf ("%c", filler);
        }
    }
}
