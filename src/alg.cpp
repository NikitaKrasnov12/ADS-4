// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    if (count > 0) {
        return count;
    } else {
        return 0;
    }
}
int countPairs2(int *arr, int len, int value) {
  int countPairs2(int* arr, int len, int value) {
    int znak = 0;
    if (arr[len] > value) {
        for (int i = len; i > value; i--) {
            znak = i;
        }
    }
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[len] < value) {
            for (int j = len - i; j > i; j--) {
                if (arr[i] + arr[j] == value) {
                    count++;
                }
            }
        } else {
            for (int k = znak; k > i; k--) {
                if (arr[i] + arr[k] == value) {
                    count++;
                }
            }
        }
    }
    if (count > 0) {
        return count;
    } else {
        return 0;
    }
}
int cbinsearch(int* arr, int size, int value) {
    int start = 0;
    int end = size - 1;
    int count = 0;
    while (start <= end) {
        int half = (start + end) / 2;
        if (arr[half] == value) {
            count++;
            int i = half - 1;
            while (i >= start && arr[i] == value) {
                count++;
                i--;
            }
            int k = half + 1;
            while (k <= end && arr[k] == value) {
                count++;
                k++;
            }
            return count;
        }
        else if (arr[half] < value) {
            start = half + 1;
        }
        else {
            end = half - 1;
        }
    }
    return 0;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        count += cbinsearch(arr + i, len - i, value - arr[i]);
    }
    if (count > 0) {
        return count;
    }
    else {
        return 0;
    }
}
